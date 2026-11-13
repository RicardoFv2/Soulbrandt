"""Check Storage's host-hook installation with synthetic code and injected OS failures.

No game file or executable memory is used. Compiles the production installer
against stand-ins for allocation/protection APIs; entry bytes and callback
publication must be all-or-nothing. Run with a C++17 compiler:

  python tools/ci/check_storage_hooks.py [--cxx clang++]
"""
from pathlib import Path
import argparse
import os
import shutil
import subprocess
import sys
import tempfile

root = Path(__file__).resolve().parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--cxx', default=os.environ.get('CXX') or shutil.which('clang++') or shutil.which('c++'))
args = parser.parse_args()
if not args.cxx:
    parser.error('a C++17 compiler is required (--cxx)')
source = (root / 'port/des_storage.cpp').read_text(encoding='utf-8')
section = source[source.index('int steal_len('):source.index('void install_pickup()')]
transactional = 'struct LiftHook' in section
prefix = r'''
#define PS3_GAME_SPLIT 1
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#ifndef _WIN32
#define _WIN32 1
#endif
#define VirtualAlloc test_VirtualAlloc
#define VirtualFree test_VirtualFree
#define VirtualProtect test_VirtualProtect
#define FlushInstructionCache test_FlushInstructionCache
#define GetCurrentProcess test_GetCurrentProcess
struct ppu_context {};
using Fn = void (*)(ppu_context*);
static unsigned char functions[3][64];
static int allocations, protections, fail_alloc, fail_protect;
static unsigned long page_protection = 0x20;
static std::vector<void*> blocks;
extern "C" void* VirtualAlloc(void*, size_t size, unsigned long, unsigned long) {
    if (++allocations == fail_alloc) return nullptr;
    auto p = std::malloc(size); blocks.push_back(p); return p;
}
extern "C" int VirtualFree(void* p, size_t, unsigned long) {
    for (auto& b : blocks) if (b == p) { std::free(b); b = nullptr; return 1; }
    std::abort();
}
extern "C" int VirtualProtect(void*, size_t, unsigned long value, unsigned long* old) {
    if (++protections == fail_protect) return 0;
    *old = page_protection; page_protection = value; return 1;
}
extern "C" int FlushInstructionCache(void*, const void*, size_t) { return 1; }
extern "C" void* GetCurrentProcess() { return nullptr; }
static int missing = -1;
Fn des_lift_find(const char* name) {
    int i = name[0] - 'a';
    return i == missing ? nullptr : reinterpret_cast<Fn>(functions[i]);
}
void replacement(ppu_context*) {}
'''
install = r'''
bool install(Fn* originals) {
    LiftHook hooks[] = {{"a", replacement, &originals[0]},
                        {"b", replacement, &originals[1]},
                        {"c", replacement, &originals[2]}};
    return hook_lifts(hooks, 3);
}
''' if transactional else r'''
bool install(Fn* originals) {
    return hook_lift("a", replacement, &originals[0]) &&
           hook_lift("b", replacement, &originals[1]) &&
           hook_lift("c", replacement, &originals[2]);
}
'''
suffix = r'''
int main() {
    int failed = 0, passed = 0;
    // Each fallible preflight step must leave every entry point and original
    // callback untouched; allocated trampolines must be released.
    for (int kind = 0; kind < 4; ++kind) for (int at = 0; at < 3; ++at) {
        for (auto& f : functions) { std::memset(f, 0x90, 64); std::memset(f, 0x50, 14); }
        allocations = protections = fail_alloc = fail_protect = 0;
        missing = -1; blocks.clear(); page_protection = 0x20;
        if (kind == 0) missing = at;
        if (kind == 1) functions[at][0] = 0xe9; // Relative branch cannot be relocated by this installer.
        if (kind == 2) fail_alloc = at + 1;
        if (kind == 3) fail_protect = at + 1;
        unsigned char before[sizeof functions]; std::memcpy(before, functions, sizeof functions);
        Fn originals[3] = {};
        bool ok = !install(originals) && !std::memcmp(before, functions, sizeof functions);
        for (auto f : originals) ok = ok && !f;
        for (auto b : blocks) ok = ok && !b;
        ok = ok && page_protection == 0x20;
        std::printf("%s failure-kind=%d position=%d\n", ok ? "PASS" : "FAIL", kind, at);
        if (ok) ++passed; else ++failed;
        for (auto b : blocks) std::free(b);
    }
    for (auto& f : functions) { std::memset(f, 0x90, 64); std::memset(f, 0x50, 14); }
    allocations = protections = fail_alloc = fail_protect = 0; missing = -1; blocks.clear(); page_protection = 0x20;
    Fn originals[3] = {};
    bool ok = install(originals) && page_protection == 0x20;
    for (int i = 0; i < 3; ++i) {
        auto gate = reinterpret_cast<unsigned char*>(originals[i]);
        ok = ok && gate && functions[i][0] == 0xff && functions[i][1] == 0x25;
        if (!gate) continue;
        for (int j = 0; j < 14; ++j) ok = ok && gate[j] == 0x50;
        void* target = nullptr; std::memcpy(&target, functions[i] + 6, sizeof target);
        ok = ok && target == reinterpret_cast<void*>(replacement);
        std::memcpy(&target, gate + 20, sizeof target);
        ok = ok && target == functions[i] + 14;
    }
    std::printf("%s all-hooks-and-trampolines\n", ok ? "PASS" : "FAIL");
    if (ok) ++passed; else ++failed;
    for (auto b : blocks) std::free(b);
    std::printf("%d passed, %d failed\n", passed, failed);
    return failed != 0;
}
'''
with tempfile.TemporaryDirectory(prefix='storage-hooks-') as folder:
    out = Path(folder)
    cpp = out / 'check.cpp'
    cpp.write_text(prefix + section + install + suffix, encoding='utf-8')
    exe = out / ('check.exe' if os.name == 'nt' else 'check')
    subprocess.run([args.cxx, '-std=c++17', str(cpp), '-o', str(exe)], check=True)
    code = subprocess.call([str(exe)])
sys.exit(code)
