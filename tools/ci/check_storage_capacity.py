"""Exercise Storage's production capacity guard with stand-in native queries.

No game files are read. The 48-held/99-limit case represents the observed
clamping failure; the native queries, not a hard-coded item cap, supply room.
"""
from pathlib import Path
import argparse
import os
import shutil
import subprocess
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--cxx', default=os.environ.get('CXX') or shutil.which('clang++') or shutil.which('c++'))
args = parser.parse_args()
if not args.cxx:
    parser.error('a C++17 compiler is required (--cxx)')
root = Path(__file__).resolve().parents[2]
source = (root / 'port/des_storage.cpp').read_text(encoding='utf-8')
guard = source[source.index('int storage_room('):source.index('Entry entry_at(')]
prefix = r'''
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#define PS3_GAME_SPLIT 1
struct ppu_context {};
struct Entry { uint32_t cat, id; int32_t count; };
static int held = 48, maximum = 99, missing = 0;
static bool allocation_fails = false, invalid_box = false;
static uint32_t probe[8];
static int bad_write = 0, bad_query = 0;
static void count_fn(ppu_context*) {}
static void limit_fn(ppu_context*) {}
using Fn = void (*)(ppu_context*);
Fn des_lift_find(const char* name) {
    bool count = !std::strcmp(name, "func_00924D58");
    if ((count && missing == 1) || (!count && missing == 2)) return nullptr;
    return count ? count_fn : limit_fn;
}
bool guest_ok(uint32_t value, uint32_t) { return value == 8192 && !invalid_box; }
uint32_t guest_alloc(ppu_context*, uint32_t size) {
    if (size != 32) std::abort();
    return allocation_fails ? 0 : 4096;
}
void storage_write32(uint32_t at, uint32_t value) {
    if (at < 4096 || at >= 4128 || at % 4) { ++bad_write; return; }
    probe[(at - 4096) / 4] = value;
}
uint32_t call_game(ppu_context*, Fn fn, std::initializer_list<int64_t> args) {
    auto p = args.begin();
    if (fn == limit_fn) {
        if (args.size() != 2 || p[0] != 4096 || p[1] != 0 || probe[3] != (100u | 8u)) ++bad_query;
        return maximum;
    }
    if (args.size() != 3 || p[0] != 8192 || p[1] != 100 || p[2] != 8) ++bad_query;
    return held;
}
'''
suffix = r'''
int main(int argc, char** argv) {
    int test = argc > 1 ? std::atoi(argv[1]) : -1, expected = 0;
    switch (test) {
    case 0: expected = 51; break; // Sending 63 must be capped at 51, preserving 12.
    case 1: held = 98; expected = 1; break;
    case 2: held = 99; break;
    case 3: held = 100; break;
    case 4: held = -1; break;
    case 5: maximum = -1; break;
    case 6: maximum = 0; break;
    case 7: maximum = 999; held = 990; expected = 9; break;
    case 8: allocation_fails = true; break;
    case 9: missing = 1; break;
    case 10: missing = 2; break;
    case 11: invalid_box = true; break;
    case 12: expected = 51; break;
    default: return 2;
    }
    ppu_context ctx;
    int room = storage_room(&ctx, 8192, {100, 8, 63});
    bool ok = room == expected && !bad_write && !bad_query;
    if (test == 12) { held = 99; ok = ok && storage_room(&ctx, 8192, {100, 8, 63}) == 0; }
    std::printf("%s capacity-case=%d room=%d expected=%d\n", ok ? "PASS" : "FAIL", test, room, expected);
    return ok ? 0 : 1;
}
'''
with tempfile.TemporaryDirectory(prefix='storage-capacity-') as folder:
    out = Path(folder)
    cpp = out / 'check.cpp'
    cpp.write_text(prefix + guard + suffix, encoding='utf-8')
    exe = out / ('check.exe' if os.name == 'nt' else 'check')
    subprocess.run([args.cxx, '-std=c++17', str(cpp), '-o', str(exe)], check=True)
    for case in range(13):
        subprocess.run([str(exe), str(case)], check=True)
