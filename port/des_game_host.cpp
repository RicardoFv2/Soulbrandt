/* des_game_host.cpp: the port's part of the split build's exe (DES_SPLIT, docs/57).
 *
 * The lifted functions the port calls by name (DES_GAME_CALLS) are in the game
 * DLL. des_game_calls.h turns each name into a forwarder defined here, which
 * calls through a pointer that ps3_game_title_loaded resolves from the lift's
 * own function table when the DLL loads: the lifted function itself, not
 * whatever the address registry maps that address to (the port wraps some of
 * these addresses with its own functions, which call these).
 *
 * The names are the US disc's addresses. The DLL may be the European disc's
 * lift (des_region.h): when every function is at its US address the disc is
 * the US one, when every one is at its European address (regions/BLES00932.inc)
 * it is the European one, and this sets the region before any guest code runs. */
#ifdef PS3_GAME_SPLIT
#include "ps3emu/ppu_lift.h"   /* ppu_context, function_table: the fixed part of the lift's header */
#include "ps3emu/ps3_knob.h"   /* ps3_setenv: through the runtime's getenv cache */
#include "des_game_calls.h"
#include "des_region.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace des_game_calls {
#define DES_GAME_CALL_DEF_(a)                                                    \
    static void (*p_##a)(ppu_context*);                                          \
    void f_##a(ppu_context* ctx) { p_##a(ctx); }
DES_GAME_CALLS(DES_GAME_CALL_DEF_)
#undef DES_GAME_CALL_DEF_
}

namespace {
struct lift_entry { uint64_t addr; void (*func)(ppu_context*); const char* name; };
const lift_entry* s_lift = nullptr;   /* the DLL's table, for a call that is not in DES_GAME_CALLS */
uint64_t s_lift_n = 0;

void (*find_lifted(const lift_entry* t, uint64_t n, uint64_t addr))(ppu_context*)
{
    for (uint64_t i = 0; i < n; i++)
        if (t[i].addr == addr) return t[i].func;
    return nullptr;
}

/* Every game call's address on each disc, checked at compile time. */
#define DES_GAME_CALL_AT_(a)                                                                                   \
    constexpr uint32_t kAt_##a[kDesRegions] = {0x##a##u, des_region_detail::on_disc(DesRegion::EU, 0x##a##u),   \
                                               des_region_detail::on_disc(DesRegion::JP, 0x##a##u),            \
                                               des_region_detail::on_disc(DesRegion::ASIA, 0x##a##u)};         \
    static_assert(kAt_##a[1] != 0 && kAt_##a[2] != 0 && kAt_##a[3] != 0, "func_" #a " is not in every table in port/regions/");
DES_GAME_CALLS(DES_GAME_CALL_AT_)
#undef DES_GAME_CALL_AT_

/* How many game calls are in the table at the region's addresses. */
int count_found(const lift_entry* t, uint64_t n, DesRegion r)
{
    int found = 0;
#define DES_GAME_CALL_COUNT_(a) found += find_lifted(t, n, kAt_##a[static_cast<int>(r)]) != nullptr;
    DES_GAME_CALLS(DES_GAME_CALL_COUNT_)
#undef DES_GAME_CALL_COUNT_
    return found;
}

#define DES_GAME_CALL_ONE_(a) +1
constexpr int kGameCalls = 0 DES_GAME_CALLS(DES_GAME_CALL_ONE_);
#undef DES_GAME_CALL_ONE_
}

extern "C" int ps3_game_title_loaded(const void* func_table, uint64_t count)
{
    const lift_entry* t = static_cast<const lift_entry*>(func_table);
    s_lift = t;
    s_lift_n = count;
    /* The disc whose addresses have every call, the US disc's first. A DLL that
     * fits none is reported and treated as the US disc's. */
    DesRegion r = DesRegion::US;
    int found[kDesRegions] = {};
    bool any = false;
    for (int i = 0; i < kDesRegions && !any; i++) {
        found[i] = count_found(t, count, static_cast<DesRegion>(i));
        if (found[i] == kGameCalls) {
            r = static_cast<DesRegion>(i);
            any = true;
        }
    }
    g_des_region = static_cast<uint8_t>(r);
    if (!any)
        std::fprintf(stderr, "[des_game] the game DLL is no disc's lift: of %d calls, %d at the US addresses, %d at the "
                     "European ones, %d at the Japanese ones, %d at the Asian ones%c",
                     kGameCalls, found[0], found[1], found[2], found[3], 10);
    int missing = 0;
#define DES_GAME_CALL_RESOLVE_(a)                                                \
    if (!(des_game_calls::p_##a = find_lifted(t, count, kAt_##a[static_cast<int>(r)]))) { \
        std::fprintf(stderr, "[des_game] func_%s is not in the game DLL's function table%c", #a, 10); \
        missing++;                                                               \
    }
    DES_GAME_CALLS(DES_GAME_CALL_RESOLVE_)
#undef DES_GAME_CALL_RESOLVE_
    return missing;
}

/* A lifted function by the name in the DLL's table ("func_00924BB8" on the US
 * disc). Null before the load, or when this disc's lift uses another name.
 * The table is the DLL's own; it stays for the process. */
extern "C" void (*des_lift_find(const char* name))(ppu_context*)
{
    if (!name || !s_lift) return nullptr;
    for (uint64_t i = 0; i < s_lift_n; i++)
        if (s_lift[i].name && std::strcmp(s_lift[i].name, name) == 0) return s_lift[i].func;
    return nullptr;
}

/* The game DLL calls this from des_game_init when it was built without the
 * lifted libsre: setup had no PS3 system software, which is optional
 * (docs/133). libsre's LFQueue and SpursQueue families must then run on
 * ps3recomp's own code (LIBSRE_OWN=1). LIBSRE_OWN=0, or one family, would send
 * them to the old HLE, and the game would hang at the title. This runs as the
 * DLL loads, before any guest code, so before the first queue call reads
 * LIBSRE_OWN (libs/spurs/spurs_queue.c). */
extern "C" void des_game_without_libsre(void)
{
    const char* own = std::getenv("LIBSRE_OWN");
    if (own && (std::strcmp(own, "1") == 0 || std::strcmp(own, "all") == 0)) {
        std::fprintf(stderr, "[des_game] the game DLL has no libsre (setup had no PS3 system software): libsre's "
                     "queue families run on ps3recomp's own code%c", 10);
        return;
    }
    std::fprintf(stderr, "[des_game] LIBSRE_OWN=%s needs libsre, and the game DLL has none (setup had no PS3 system "
                 "software): libsre's queue families run on ps3recomp's own code instead (LIBSRE_OWN=1)%c",
                 own ? own : "(unset)", 10);
    ps3_setenv("LIBSRE_OWN", "1");
}
#endif
