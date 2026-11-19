/* Demon's Souls: developer cheats (docs/55). Compiled only into developer
 * builds (cmake -DDES_DEV=ON). A release build links the empty des_dev_hook
 * in des_options.cpp instead, and its settings window has no Developer tab.
 *
 * DES_GOD=1 — the player's HP, MP and stamina never drop: hits, falls,
 *   poison-type ticks, script damage, spells, attacks, rolls, guarding and
 *   the dash cost nothing. Gains (healing, regen, level-ups) still count.
 *   Instant deaths (a fall out of the level, lethal grabs, scripted deaths)
 *   and SetHP (respawns, loads, Lua) are left alone, so no event waits on a
 *   death that cannot happen.
 * DES_ATK=<x> — the HP damage of the player's hits on others, times x (0 to
 *   1000; 0 = no damage).
 * DES_SPEED=<x> — how far the player moves each step, times x (0.25 to 10):
 *   walk, run, dash, roll and attack lunges. Animations keep their speed, so
 *   the feet slide.
 * DES_WARP=x,y,z — put the player at x, y, z the way the level scripts'
 *   LoadChrPos does. Each new value warps once. DES_WARP_CLEAR=<m> first
 *   sends the enemies within m metres of the target to the tutorial's start.
 *   Test scripts use it to reach a spot quickly.
 * DES_GIVE=<items> — add items to the player's inventory through the game's
 *   own add-item function, so weight, stacks and quick slots work as for a
 *   pickup. A comma list of goods ids, each with an optional *count, or
 *   "online": 10 Stones of Ephemeral Eyes, the Black, Red, Blue and White Eye
 *   Stones, the Kick Item (9998) and the Friend's and Foe's Rings (a ring is
 *   ring:<id>). Each new value gives once, when the player is loaded and no
 *   cutscene runs, then asks the game to save (tools/des/online_save.sh).
 * DES_KILLSELF=<v> — each new value (not 0) kills the player once, through
 *   the function the scripts' deaths use (0x00272C28: HP 0, then the
 *   game's own death). Test scripts use it to die on cue.
 * DES_KILLALL=<v> — each new value kills the area's living enemies once:
 *   "all" every one (a boss too), a number those within that many metres of
 *   the player.
 *   The same function, so souls, drops and the scripts' kill events work as
 *   for any kill.
 * DES_AREA=w,b[,point] — each new value loads area mWW_BB once, the way the
 *   scripts' WarpNextStage does: w and b are the map name's numbers
 *   (m02_01: 2,1). The point is where the player arrives; by default the
 *   block's Archstone, as the Nexus's warps use (999 for block 0, then 997,
 *   996, 995), and the Nexus's own start (-1) for world 1.
 * DES_KILLSELF, DES_KILLALL, DES_AREA and DES_GIVE wait for the player to be
 *   in a level (no cutscene) when set at start.
 * DES_FLAGWATCH=a,b,... — a log line with each of these event flags' value
 *   (up to 16) when first seen and whenever it changes. It only reads, so
 *   it is not a cheat and works in any session.
 * DES_DEVLOG=1 — a line for each change a cheat makes, at most one a site
 *   every 250 ms (with the count of the ones in between).
 * RSX_DEV_HOTKEYS — not a cheat: des_dev_boot sets it to 1 when it is unset,
 *   so the developer keys work (F8 in a frame log, ps3recomp's F9 to F11).
 *
 * All live (the console's setenv and the Developer tab change them), all off
 * by default, none kept in settings.ini. Out-of-range values are clamped; a
 * value that does not parse counts as the default.
 *
 * The offline rule: cheats must never reach other players. At start
 * (des_dev_boot, from ps3_title_options_init, before the network modules
 * read their knobs) the session is:
 *   - a cheat set at start: a cheat session. PS3_NET_ONLINE, PSNR_SERVER and
 *     PS3_NET_HOSTS are cleared, so the host sockets are never registered and
 *     cellNetCtl and NP report no connection;
 *   - the network on at start (PS3_NET_ONLINE or PSNR_SERVER) and no cheat:
 *     an online session, and the cheats stay off until the next start;
 *   - neither: an offline session. A cheat can be turned on at any time; the
 *     first one sets the "cheats used" latch (des_dev_cheats_used) for the
 *     rest of the session and clears the network knobs again.
 * Later the debug console can set the network knobs again, and cellNetCtl and
 * NP read them live. So every cheat and DES_WARP checks them where it acts,
 * and des_debug_tick after each setenv: once PS3_NET_ONLINE or PSNR_SERVER is
 * seen set, the session is online for good and the cheats do nothing until
 * the next start (one log line). ps3recomp may still connect then; a lock
 * there closes that (docs/55 section 6). DES_DEV_SESSION tells the UI which
 * session it is: cheats, online or offline.
 *
 * The hooks: --insn-hooks makes the lifter call des_dev_hook(ctx, addr) right
 * after each instruction in the dev block of port/insn_hooks.txt. The same
 * code runs for every character, so each site first checks that it is the
 * player's. The sites and their registers are in docs/55 section 2.4; each
 * was checked against the instructions around it. */
#include "ps3emu/ppu_lift.h"   /* ppu_context: the fixed part of the lift's header */
#include "des_region.h"      /* DES_AT: the running disc's addresses */
#include "des_game_calls.h"     /* the lifted functions below (the game DLL's with DES_SPLIT) */
#include "ps3emu/ps3_knob.h"   /* ps3_setenv: through the runtime's getenv cache */
#include "ps3emu/ps3_net.h"    /* ps3_net_lock_offline */
#include "des_dev_marker.h"
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <thread>

#if !DES_DEV
#error "des_dev.cpp is only for developer builds (cmake -DDES_DEV=ON)"
#endif

#ifndef PS3_GAME_SPLIT   /* DES_SPLIT: the game DLL's (ps3emu/game_split.h) */
extern "C" PPU_THREAD_LOCAL void (*g_trampoline_fn)(void*);
#endif
extern "C" const char* cellGame_get_title(void);   /* PARAM.SFO's TITLE (ps3recomp libs/system/cellGame.c) */
extern "C" void ps3_indirect_call(ppu_context* ctx);   /* ppu_loader.cpp: a call to the guest address in CTR */

namespace {

constexpr uint32_t kChrMan      = 0x01B3D6E0u;   /* *(*kChrMan + 0x1BC) = the player, as player_pos in des_options.cpp */
constexpr uint32_t kChrMp       = 0x3CCu;        /* ints */
constexpr uint32_t kChrStamina  = 0x3D4u;
constexpr uint32_t kChrMove     = 0x20u;         /* the movement object */
constexpr uint32_t kRecHpDamage = 0x14Cu;        /* a damage record's final HP damage, an int */
constexpr uint32_t kRecType     = 0x28u;         /* a damage record's type, an int */
constexpr int32_t  kRecTypeKept = 0x40;          /* the type the calculation leaves rec+0x14C alone for (H3) */
constexpr float    kAtkMax      = 1000.0f;
constexpr float    kSpeedMin    = 0.25f, kSpeedMax = 10.0f;
constexpr double   kDamageCap   = 10000000.0;

bool guest_ptr_ok(uint32_t a)   /* as in des_options.cpp: the stack area too */
{
    return ((a >= 0x00010000u && a < 0x50000000u) || (a >= 0xD0000000u && a < 0xE0000000u)) && !(a & 3u);
}

float vm_readf(uint32_t ea)
{
    const uint32_t bits = vm_read32(ea);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

/* The word at a, or 0 when a is not a guest pointer: for chains of pointers that are 0 before the game sets them. */
uint32_t rd(uint32_t a)
{
    return guest_ptr_ok(a) ? vm_read32(a) : 0;
}

uint32_t player_chr()
{
    uint32_t p = vm_read32(DES_AT(kChrMan));
    if (!guest_ptr_ok(p) || !guest_ptr_ok(p = vm_read32(p + 0x1BC))) return 0;
    return p;
}

bool env_on(const char* name)
{
    const char* v = getenv(name);
    return v && *v && strcmp(v, "0") != 0;
}

/* "" for an unset knob, so a knob set and then cleared counts as a new value. */
const char* knob_s(const char* name)
{
    const char* v = getenv(name);
    return v ? v : "";
}

/* A float knob: def when unset or not a number, else clamped to [lo, hi]. */
float knob_f(const char* name, float def, float lo, float hi)
{
    const char* v = getenv(name);
    if (!v || !*v) return def;
    char* end = nullptr;
    const float f = strtof(v, &end);
    if (end == v || !std::isfinite(f)) return def;
    return f < lo ? lo : f > hi ? hi : f;
}

int   god_knob()   { return env_on("DES_GOD") ? 1 : 0; }
float atk_knob()   { return knob_f("DES_ATK", 1.0f, 0.0f, kAtkMax); }
float speed_knob() { return knob_f("DES_SPEED", 1.0f, kSpeedMin, kSpeedMax); }

enum Session { kOffline, kCheats, kOnline };
std::atomic<int> s_session{kOffline};   /* des_dev_boot sets it before any game thread runs; online() can make it kOnline */
std::atomic<bool> s_used{false};

const char* session_name(int s) { return s == kCheats ? "cheats" : s == kOnline ? "online" : "offline"; }

/* ps3recomp goes online with the first two: PS3_NET_ONLINE (host sockets, cellNetCtl, NP) and PSNR_SERVER (NP's
 * server). Any value counts, as there (getenv(...) ? 1 : 0). PS3_NET_HOSTS (docs/46's planned host map) and
 * PS3_NET_SIGNIN (a cheat session never signs in with the install's key) are only cleared with them. */
const char* const kNetKnobs[] = {"PS3_NET_ONLINE", "PSNR_SERVER", "PS3_NET_HOSTS", "PS3_NET_SIGNIN"};
constexpr int kNetKnobsOnline = 2;

/* The first of the network knobs that is set, or null. getenv is boot_main's lock-free cache, cheap at a hook. */
const char* net_knob()
{
    for (int i = 0; i < kNetKnobsOnline; i++)
        if (getenv(kNetKnobs[i])) return kNetKnobs[i];
    return nullptr;
}

void clear_network()
{
    for (const char* k : kNetKnobs) ps3_setenv(k, "");   /* an empty value reads as unset (cached_setenv) */
}

/* True once a network knob has been seen set, at start or since: the session is then online until the next start.
 * Checked where the cheats act, so a knob set from the debug console turns them off at once. Says so once. */
bool online()
{
    if (s_session.load() == kOnline) return true;
    const char* k = net_knob();
    if (!k) return false;
    if (s_session.exchange(kOnline) != kOnline) {
        ps3_setenv("DES_DEV_SESSION", "online");
        fprintf(stderr, "[dev] %s is set: the session is online, and the cheats are off until the next start%s\n", k,
                s_used.load() ? " (cheats were used earlier in this session)" : "");
    }
    return true;
}

/* The first cheat of the session: it stays offline from here on. The knobs are cleared, and the runtime is locked
 * offline too: every network module refuses from here, and a co-op session already open ends. */
void mark_used(const char* what)
{
    if (s_used.exchange(true)) return;
    clear_network();
    ps3_net_lock_offline();
    fprintf(stderr, "[dev] cheat in use (%s): this session stays offline\n", what);
}

/* An online session ignores the cheats, and says so once. */
bool refused(const char* what)
{
    if (!online()) return false;
    static std::atomic<bool> said{false};
    if (!said.exchange(true))
        fprintf(stderr, "[dev] %s ignored: the session is online; start the game without PS3_NET_ONLINE and "
                "PSNR_SERVER to use the cheats\n", what);
    return true;
}

/* cr7 as the lifter's cmpwi leaves it: LT 8, GT 4 or EQ 2 in the low nibble, no SO. */
void set_cr7(ppu_context* ctx, int32_t a, int32_t b)
{
    ppu_cr_set(ctx, 7, (uint8_t)(a < b ? 8u : a > b ? 4u : 2u));
}

uint32_t gpr32(const ppu_context* ctx, int r) { return (uint32_t)ctx->gpr[r]; }
int32_t  sgpr32(const ppu_context* ctx, int r) { return (int32_t)(uint32_t)ctx->gpr[r]; }

/* DES_DEVLOG: at most one line a site every 250 ms. */
void dev_log(int site, const char* what, double before, double after, uint32_t chr)
{
    static double last[16];
    static bool seen[16];
    static unsigned between[16];
    using clock = std::chrono::steady_clock;
    static const clock::time_point t0 = clock::now();
    const double ms = std::chrono::duration<double, std::milli>(clock::now() - t0).count();
    if (seen[site] && ms - last[site] < 250.0) {
        between[site]++;
        return;
    }
    fprintf(stderr, "[dev] H%d %s: %g -> %g (chr %08X)", site, what, before, after, chr);
    if (between[site]) fprintf(stderr, ", %u more since the last line", between[site]);
    fputc('\n', stderr);
    seen[site] = true;
    last[site] = ms;
    between[site] = 0;
}

constexpr uint32_t kPickupTraceCopied = 0x0036D7FCu;
constexpr uint32_t kPickupTraceAddEntry = 0x004C6DF0u;
constexpr uint32_t kPickupTraceReasonLoad = 0x004C733Cu;
constexpr uint32_t kPickupTraceMinusOneTest = 0x004C74F0u;
constexpr uint32_t kPickupTraceAddReturn = 0x0036D678u;
constexpr uint32_t kPickupTraceReinsert = 0x0036D0D8u;
constexpr uint32_t kPickupTraceAcquireEntry = 0x0036D600u;
constexpr uint32_t kPickupTraceReinsertHelperEntry = 0x0036CDB8u;
constexpr uint32_t kPickupTraceNodeReturn = 0x0036CE34u;
constexpr uint32_t kPickupTraceRootCompare = 0x0036CE44u;
constexpr uint32_t kPickupTraceNodeCompare = 0x0036CE4Cu;
constexpr uint32_t kPickupTraceKeyWritten = 0x0036CBD0u;
constexpr uint32_t kPickupTraceCounterIncremented = 0x0036CBD4u;
constexpr uint32_t kPickupTraceReinsertReturn = 0x0036D3BCu;
constexpr uint32_t kPickupTraceLocalLookup = 0x0036D9A4u;
constexpr uint32_t kPickupTraceEventLookup = 0x0036DE00u;

struct PickupTraceState {
    bool active = false;
    bool native_add_active = false;
    bool reason_seen = false;
    bool minus_one_path = false;
    bool rejected = false;
    bool copy_pending = false;
    bool offline_reinsert = false;
    bool key_written = false;
    uint32_t source_manager = 0;
    uint32_t source_lookup_key = 0;
    uint32_t source_node = 0;
    uint32_t source_record = 0;
    uint32_t add_manager = 0;
    uint32_t add_record = 0;
    uint32_t reinsert_manager = 0;
    uint32_t reinsert_record = 0;
    uint32_t node_manager = 0;
    uint32_t node = 0;
    uint32_t key = 0;
    uint32_t reinsert_lr = 0;
    uint32_t fields[4]{};
    uint32_t node_position[4]{};
    uint32_t node_fields[4]{};
    int32_t reason_field = 0;
    uint32_t sequence = 0;
};

/* Host-only correlation, indexed by thread. These slots never touch the PPU
 * context or guest memory; the ring tolerates nested pickup checks on a thread. */
thread_local PickupTraceState s_pickup_trace[8];
thread_local uint32_t s_pickup_trace_sequence = 0;

uint64_t pickup_trace_thread_id()
{
    return static_cast<uint64_t>(std::hash<std::thread::id>{}(std::this_thread::get_id()));
}

bool pickup_trace_read_fields(uint32_t record, uint32_t (&fields)[4])
{
    if (!guest_ptr_ok(record) || record > 0xFFFFFFF3u) return false;
    for (unsigned i = 0; i < 4; i++) fields[i] = vm_read32(record + i * 4u);
    return true;
}

bool pickup_trace_read_words(uint32_t address, uint32_t (&words)[4])
{
    if (!guest_ptr_ok(address) || address > 0xFFFFFFF3u) return false;
    for (unsigned i = 0; i < 4; i++) words[i] = vm_read32(address + i * 4u);
    return true;
}

bool pickup_trace_read_node(uint32_t node, uint32_t& key, uint32_t (&position)[4], uint32_t (&fields)[4])
{
    if (!guest_ptr_ok(node) || node > 0xFFFFFFD3u) return false;
    key = vm_read32(node + 0x8u);
    return pickup_trace_read_words(node + 0x10u, position) &&
           pickup_trace_read_words(node + 0x20u, fields);
}

bool pickup_trace_fields_equal(const uint32_t (&a)[4], const uint32_t (&b)[4])
{
    for (unsigned i = 0; i < 4; i++) if (a[i] != b[i]) return false;
    return true;
}

PickupTraceState* pickup_trace_find_fields(const uint32_t (&fields)[4], bool rejected_only = false)
{
    PickupTraceState* found = nullptr;
    for (PickupTraceState& state : s_pickup_trace) {
        if (!state.active || (rejected_only && !state.rejected) ||
            !pickup_trace_fields_equal(state.fields, fields)) continue;
        if (!found || static_cast<int32_t>(state.sequence - found->sequence) > 0) found = &state;
    }
    return found;
}

PickupTraceState* pickup_trace_new(const uint32_t (&fields)[4], uint32_t record)
{
    const uint32_t sequence = ++s_pickup_trace_sequence;
    PickupTraceState& state = s_pickup_trace[sequence % 8u];
    state = {};
    state.active = true;
    state.source_record = record;
    state.sequence = sequence;
    memcpy(state.fields, fields, sizeof(fields));
    return &state;
}

PickupTraceState* pickup_trace_find_native_add()
{
    PickupTraceState* found = nullptr;
    for (PickupTraceState& state : s_pickup_trace) {
        if (!state.active || !state.native_add_active) continue;
        if (!found || static_cast<int32_t>(state.sequence - found->sequence) > 0) found = &state;
    }
    return found;
}

PickupTraceState* pickup_trace_find_rejected(bool offline_only = false)
{
    PickupTraceState* found = nullptr;
    for (PickupTraceState& state : s_pickup_trace) {
        if (!state.active || !state.rejected || (offline_only && !state.offline_reinsert)) continue;
        if (!found || static_cast<int32_t>(state.sequence - found->sequence) > 0) found = &state;
    }
    return found;
}

PickupTraceState* pickup_trace_find_lookup(uint32_t manager, uint32_t key,
                                          const uint32_t (&position)[4], const uint32_t (&fields)[4])
{
    PickupTraceState* found = nullptr;
    for (PickupTraceState& state : s_pickup_trace) {
        if (!state.active || !state.rejected || !state.key_written || state.node_manager != manager ||
            state.key != key || !pickup_trace_fields_equal(state.node_position, position) ||
            !pickup_trace_fields_equal(state.node_fields, fields)) continue;
        if (!found || static_cast<int32_t>(state.sequence - found->sequence) > 0) found = &state;
    }
    return found;
}

bool pickup_trace_site(uint32_t addr)
{
    return addr == kPickupTraceCopied || addr == kPickupTraceAddEntry || addr == kPickupTraceReasonLoad ||
           addr == kPickupTraceMinusOneTest || addr == kPickupTraceAddReturn || addr == kPickupTraceReinsert ||
           addr == kPickupTraceAcquireEntry || addr == kPickupTraceReinsertHelperEntry ||
           addr == kPickupTraceNodeReturn || addr == kPickupTraceRootCompare || addr == kPickupTraceNodeCompare ||
           addr == kPickupTraceKeyWritten || addr == kPickupTraceCounterIncremented ||
           addr == kPickupTraceReinsertReturn ||
           addr == kPickupTraceLocalLookup || addr == kPickupTraceEventLookup;
}

void pickup_trace_hook(ppu_context* ctx, uint32_t addr)
{
    const uint64_t tid = pickup_trace_thread_id();
    const char* region = des_region_title_id(des_region());
    if (addr == kPickupTraceAcquireEntry) {
        const uint32_t lr = static_cast<uint32_t>(ctx->lr);
        fprintf(stderr, "[pickup-trace] acquire-entry region=%s thread=%016llX lr=%08X args=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), lr, gpr32(ctx, 3), gpr32(ctx, 4),
                gpr32(ctx, 5), gpr32(ctx, 6));
        return;
    }

    if (addr == kPickupTraceCopied) {
        const uint32_t sp = gpr32(ctx, 1), manager = gpr32(ctx, 31);
        const uint32_t key = gpr32(ctx, 4), node = gpr32(ctx, 11);
        const bool address_ok = sp <= 0xFFFFFF8Fu;
        const uint32_t record = address_ok ? sp + 0x70u : 0;
        uint32_t fields[4]{};
        const bool readable = address_ok && pickup_trace_read_fields(record, fields);
        PickupTraceState* state = readable ? pickup_trace_new(fields, record) : nullptr;
        if (state) {
            state->copy_pending = true;
            state->source_manager = manager;
            state->source_lookup_key = key;
            state->source_node = node;
            state->source_record = record;
        }
        fprintf(stderr, "[pickup-trace] pre-add-copy region=%s thread=%016llX seq=%u manager=%08X lookup_key=%08X node=%08X sp=%08X record=%08X readable=%d fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, manager, key, node, sp, record, readable ? 1 : 0,
                fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceAddEntry) {
        const uint32_t fields[4] = {gpr32(ctx, 4), gpr32(ctx, 5), gpr32(ctx, 6), gpr32(ctx, 7)};
        PickupTraceState* state = pickup_trace_find_fields(fields);
        if (!state || !state->copy_pending) state = pickup_trace_new(fields, 0);
        state->copy_pending = false;
        state->reason_seen = false;
        state->minus_one_path = false;
        state->rejected = false;
        state->offline_reinsert = false;
        state->key_written = false;
        state->reinsert_lr = 0;
        state->add_record = 0;
        state->reinsert_record = 0;
        state->node_manager = 0;
        state->node = 0;
        state->key = 0;
        memset(state->node_position, 0, sizeof(state->node_position));
        memset(state->node_fields, 0, sizeof(state->node_fields));
        state->native_add_active = true;
        state->add_manager = gpr32(ctx, 3);
        fprintf(stderr, "[pickup-trace] native-add-entry region=%s thread=%016llX seq=%u manager_arg=%08X candidate=%d fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state->sequence, state->add_manager, state->source_record ? 1 : 0,
                fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceReasonLoad) {
        const int32_t reason = sgpr32(ctx, 0);
        PickupTraceState* state = pickup_trace_find_native_add();
        if (state) {
            state->reason_seen = true;
            state->reason_field = reason;
        }
        fprintf(stderr, "[pickup-trace] inventory-result-field region=%s thread=%016llX seq=%u candidate=%d inventory=%08X reason=%d\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, state ? 1 : 0, gpr32(ctx, 29), reason);
        return;
    }

    if (addr == kPickupTraceMinusOneTest) {
        const int32_t reason = sgpr32(ctx, 0);
        const bool cr7_equal = (ctx->crf[7] & 2u) != 0;
        const bool minus_one_path = reason == 1 && cr7_equal;
        PickupTraceState* state = pickup_trace_find_native_add();
        if (state) state->minus_one_path = minus_one_path;
        fprintf(stderr, "[pickup-trace] native-minus-one-test region=%s thread=%016llX seq=%u candidate=%d reason=%d cr7_equal=%d minus_one_path=%d reason_matches_load=%d\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, state ? 1 : 0, reason, cr7_equal ? 1 : 0,
                minus_one_path ? 1 : 0, state && state->reason_seen && state->reason_field == reason ? 1 : 0);
        return;
    }

    if (addr == kPickupTraceAddReturn) {
        const uint32_t manager = gpr32(ctx, 31), record = gpr32(ctx, 29);
        uint32_t fields[4]{};
        const bool readable = pickup_trace_read_fields(record, fields);
        PickupTraceState* state = pickup_trace_find_native_add();
        if (state && readable && !pickup_trace_fields_equal(state->fields, fields)) state = nullptr;
        if (!state && readable) state = pickup_trace_find_fields(fields);
        if (!state) state = pickup_trace_find_native_add();
        const bool same_fields = state && readable && pickup_trace_fields_equal(state->fields, fields);
        const int32_t result = sgpr32(ctx, 3);
        fprintf(stderr, "[pickup-trace] add-return region=%s thread=%016llX seq=%u manager=%08X record=%08X result=%d rejected_minus_one=%d correlated=%d reason_seen=%d reason_field=%d minus_one_path=%d fields_same=%d fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, manager, record, result, result == -1 ? 1 : 0,
                state ? 1 : 0, state && state->reason_seen ? 1 : 0, state ? state->reason_field : 0,
                state && state->minus_one_path ? 1 : 0,
                same_fields ? 1 : 0, fields[0], fields[1], fields[2], fields[3]);
        if (state) {
            state->native_add_active = false;
            state->add_manager = manager;
            state->add_record = record;
            state->rejected = result == -1;
        }
        return;
    }

    if (addr == kPickupTraceReinsert) {
        const uint32_t manager = gpr32(ctx, 3), record = gpr32(ctx, 4), mode = gpr32(ctx, 5);
        uint32_t fields[4]{};
        const bool readable = pickup_trace_read_fields(record, fields);
        PickupTraceState* state = readable ? pickup_trace_find_fields(fields, true) : pickup_trace_find_rejected();
        const bool same_fields = state && readable && pickup_trace_fields_equal(state->fields, fields);
        if (state) {
            state->reinsert_manager = manager;
            state->reinsert_record = record;
        }
        fprintf(stderr, "[pickup-trace] native-reinsert region=%s thread=%016llX seq=%u manager=%08X source_manager=%08X source_key=%08X source_node=%08X record=%08X add_record=%08X mode=%08X correlated_reject=%d minus_one_path=%d record_same=%d fields_same=%d readable=%d fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, manager,
                state ? state->source_manager : 0, state ? state->source_lookup_key : 0,
                state ? state->source_node : 0, record, state ? state->add_record : 0, mode,
                state ? 1 : 0, state && state->minus_one_path ? 1 : 0,
                state && state->add_record == record ? 1 : 0, same_fields ? 1 : 0, readable ? 1 : 0,
                fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceReinsertHelperEntry) {
        const uint32_t lr = static_cast<uint32_t>(ctx->lr);
        const uint32_t expected_lr = DES_AT(kPickupTraceReinsertReturn);
        const uint32_t manager = gpr32(ctx, 3), record = gpr32(ctx, 4);
        uint32_t fields[4]{};
        const bool readable = pickup_trace_read_fields(record, fields);
        PickupTraceState* state = readable ? pickup_trace_find_fields(fields, true) : nullptr;
        if (!state && lr == expected_lr) state = pickup_trace_find_rejected();
        if (state && lr == expected_lr) {
            state->offline_reinsert = true;
            state->reinsert_lr = lr;
            state->reinsert_manager = manager;
            state->reinsert_record = record;
        }
        fprintf(stderr, "[pickup-trace] reinsert-helper-entry region=%s thread=%016llX seq=%u lr=%08X expected_offline_lr=%08X offline_path=%d manager=%08X record=%08X readable=%d fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0, lr, expected_lr,
                lr == expected_lr ? 1 : 0, manager, record, readable ? 1 : 0,
                fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceKeyWritten) {
        const uint32_t node = gpr32(ctx, 31), manager = gpr32(ctx, 27);
        uint32_t key = 0, position[4]{}, fields[4]{};
        const bool readable = pickup_trace_read_node(node, key, position, fields);
        PickupTraceState* state = pickup_trace_find_rejected(true);
        const uint32_t counter = guest_ptr_ok(manager) ? vm_read32(manager + 4u) : 0;
        const uint32_t head = guest_ptr_ok(manager) ? vm_read32(manager + 0xCu) : 0;
        if (state && readable) {
            state->node_manager = manager;
            state->node = node;
            state->key = key;
            state->key_written = true;
            memcpy(state->node_position, position, sizeof(position));
            memcpy(state->node_fields, fields, sizeof(fields));
        }
        fprintf(stderr, "[pickup-trace] node-key-written region=%s thread=%016llX seq=%u offline_reinsert=%d manager=%08X manager_counter=%08X manager_head=%08X node=%08X key=%08X key_matches_counter=%d readable=%d pos=%08X,%08X,%08X,%08X fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                state && state->offline_reinsert ? 1 : 0, manager, counter, head, node, key,
                readable && key == counter ? 1 : 0, readable ? 1 : 0,
                position[0], position[1], position[2], position[3], fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceCounterIncremented) {
        const uint32_t node = gpr32(ctx, 31), manager = gpr32(ctx, 27);
        const uint32_t key = guest_ptr_ok(node) ? vm_read32(node + 8u) : 0;
        const uint32_t counter = guest_ptr_ok(manager) ? vm_read32(manager + 4u) : 0;
        PickupTraceState* state = pickup_trace_find_rejected(true);
        fprintf(stderr, "[pickup-trace] node-key-counter-incremented region=%s thread=%016llX seq=%u offline_reinsert=%d manager=%08X node=%08X key=%08X manager_counter=%08X counter_is_key_plus_one=%d same_key_as_preincrement=%d\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                state && state->offline_reinsert ? 1 : 0, manager, node, key, counter,
                counter == key + 1u ? 1 : 0, state && state->key_written && state->key == key ? 1 : 0);
        return;
    }

    if (addr == kPickupTraceNodeReturn) {
        const uint32_t node = gpr32(ctx, 3), manager = gpr32(ctx, 29);
        uint32_t key = 0, position[4]{}, fields[4]{};
        const bool readable = pickup_trace_read_node(node, key, position, fields);
        const uint32_t head = guest_ptr_ok(manager) ? vm_read32(manager + 0xCu) : 0;
        PickupTraceState* state = pickup_trace_find_rejected(true);
        const bool same_node = state && state->node == node;
        const bool same_key = state && state->key_written && state->key == key;
        const bool same_fields = state && pickup_trace_fields_equal(state->node_fields, fields);
        const bool same_position = state && pickup_trace_fields_equal(state->node_position, position);
        fprintf(stderr, "[pickup-trace] reinsertion-node-return region=%s thread=%016llX seq=%u offline_reinsert=%d reinsert_lr=%08X manager=%08X manager_head=%08X node=%08X key=%08X node_key_matches=%d same_node_as_key_write=%d same_key=%d same_fields=%d same_position=%d readable=%d pos=%08X,%08X,%08X,%08X fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                state && state->offline_reinsert ? 1 : 0, state ? state->reinsert_lr : 0, manager, head, node, key,
                readable && vm_read32(node + 8u) == key ? 1 : 0, same_node ? 1 : 0,
                same_key ? 1 : 0, same_fields ? 1 : 0, same_position ? 1 : 0, readable ? 1 : 0,
                position[0], position[1], position[2], position[3], fields[0], fields[1], fields[2], fields[3]);
        return;
    }

    if (addr == kPickupTraceRootCompare || addr == kPickupTraceNodeCompare) {
        const uint32_t manager = gpr32(ctx, 27), node = gpr32(ctx, 29);
        const uint32_t root = guest_ptr_ok(manager) ? vm_read32(manager) : 0;
        const bool equal = (ctx->crf[7] & 2u) != 0;
        PickupTraceState* state = pickup_trace_find_rejected(true);
        fprintf(stderr, "[pickup-trace] reinsert-branch-check region=%s thread=%016llX seq=%u site=%08X compare=%s equal=%d manager=%08X root=%08X returned_node=%08X lr=%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                addr, addr == kPickupTraceRootCompare ? "manager-root" : "returned-node-null",
                equal ? 1 : 0, manager, root, node, static_cast<uint32_t>(ctx->lr));
        return;
    }

    if (addr == kPickupTraceReinsertReturn) {
        PickupTraceState* state = pickup_trace_find_rejected(true);
        fprintf(stderr, "[pickup-trace] reinsert-helper-return region=%s thread=%016llX seq=%u lr=%08X result=%08X manager=%08X node=%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                static_cast<uint32_t>(ctx->lr), gpr32(ctx, 3), gpr32(ctx, 27), gpr32(ctx, 31));
        return;
    }

    if (addr == kPickupTraceLocalLookup || addr == kPickupTraceEventLookup) {
        const bool event = addr == kPickupTraceEventLookup;
        const uint32_t manager = gpr32(ctx, 3), manager_alt = event ? 0 : gpr32(ctx, 31);
        const uint32_t key = gpr32(ctx, 4), node = event ? gpr32(ctx, 9) : gpr32(ctx, 11);
        uint32_t node_key = 0, position[4]{}, fields[4]{};
        const bool readable = pickup_trace_read_node(node, node_key, position, fields);
        const bool node_key_matches = readable && node_key == key;
        PickupTraceState* state = pickup_trace_find_lookup(manager, key, position, fields);
        if (!event && manager_alt != manager && !state)
            state = pickup_trace_find_lookup(manager_alt, key, position, fields);
        const bool same_node = state && state->node == node;
        fprintf(stderr, "[pickup-trace] lookup-candidate region=%s thread=%016llX seq=%u path=%s site=%08X manager_r3=%08X manager_r31=%08X key=%08X node=%08X node_key=%08X node_key_matches=%d identity_match=%d same_node_pointer=%d readable=%d pos=%08X,%08X,%08X,%08X fields=%08X,%08X,%08X,%08X\n",
                region, static_cast<unsigned long long>(tid), state ? state->sequence : 0,
                event ? "event" : "local", addr, manager, manager_alt, key, node, node_key,
                node_key_matches ? 1 : 0, state ? 1 : 0, same_node ? 1 : 0, readable ? 1 : 0,
                position[0], position[1], position[2], position[3], fields[0], fields[1], fields[2], fields[3]);
    }
}

} // namespace

/* Every dev hook site (insn_hooks.txt) comes here; the switch picks the site. */
extern "C" void des_dev_hook(ppu_context* ctx, uint32_t addr)
{
    if (pickup_trace_site(addr)) {
        if (env_on("DES_PICKUP_TRACE")) {
            pickup_trace_hook(ctx, addr);
        } else {
            for (PickupTraceState& pending : s_pickup_trace) pending.active = false;
        }
        return;
    }
    static int god = 0, devlog = 0;
    static float atk = 1.0f, speed = 1.0f;
    PS3_KNOB(god, god_knob());
    PS3_KNOB(atk, atk_knob());
    PS3_KNOB(speed, speed_knob());
    PS3_KNOB(devlog, env_on("DES_DEVLOG") ? 1 : 0);
    if (!god && atk == 1.0f && speed == 1.0f) return;
    if (refused(god ? "DES_GOD" : atk != 1.0f ? "DES_ATK" : "DES_SPEED")) return;
    if (!s_used.load(std::memory_order_relaxed)) mark_used(god ? "DES_GOD" : atk != 1.0f ? "DES_ATK" : "DES_SPEED");
    const uint32_t me = player_chr();
    if (!me) return;
    switch (addr) {
    case 0x00280E64u:   /* H1, ApplyDamage 0x00280DC8: r0 = the hit's HP damage (target r27); neg and cmpwi follow */
        if (god && gpr32(ctx, 27) == me && sgpr32(ctx, 0) > 0) {
            if (devlog) dev_log(1, "hit HP damage", sgpr32(ctx, 0), 0, me);
            ctx->gpr[0] = 0;
        }
        break;
    case 0x00280F88u:   /* H2, ApplyDamage: r9 = the hit's stamina damage (guarding); cmpwi and ble follow */
        if (god && gpr32(ctx, 27) == me && sgpr32(ctx, 9) > 0) {
            if (devlog) dev_log(2, "hit stamina damage", sgpr32(ctx, 9), 0, me);
            ctx->gpr[9] = 0;
        }
        break;
    case 0x0028B224u: {   /* H3, the damage handler 0x0028B1D8 after the calculation: attacker r29, record r28 */
        if (atk == 1.0f || gpr32(ctx, 29) != me) break;
        const uint32_t rec = gpr32(ctx, 28);
        if (!guest_ptr_ok(rec)) break;
        const int32_t d = (int32_t)vm_read32(rec + kRecHpDamage);
        /* Only a damage the calculation 0x00285678 wrote on this pass is scaled, never one this hook wrote before. The
         * calculation (record in r31) has one store to rec+0x14C, at 0x00285AC8, on every path but one: when
         * rec+0x28 is 0x40 it branches from 0x00285808 straight to its epilogue, and rec+0x14C keeps what the record
         * held, which may be this hook's result from an earlier hit. On that path the calculation returns right
         * after the test, with no call in between, so the type read here is the one tested; a type that became 0x40
         * during the calculation only leaves that hit unscaled. */
        if ((int32_t)vm_read32(rec + kRecType) == kRecTypeKept) {
            if (devlog && d > 0) dev_log(3, "hit damage left as it was (record type 0x40)", d, d, gpr32(ctx, 31));
            break;
        }
        if (d <= 0) break;
        const double x = std::nearbyint((double)d * atk);
        const int32_t nd = (int32_t)(x > kDamageCap ? kDamageCap : x);
        vm_write32(rec + kRecHpDamage, (uint32_t)nd);
        if (devlog) dev_log(3, "hit damage dealt", d, nd, gpr32(ctx, 31));
        break;
    }
    case 0x002818D0u:   /* H4, 0x002816D0: r0 = a damage worked out from a fraction (falls, inferred), chr r31 */
        if (god && gpr32(ctx, 31) == me && sgpr32(ctx, 0) > 0) {
            if (devlog) dev_log(4, "fraction damage", sgpr32(ctx, 0), 0, me);
            ctx->gpr[0] = 0;
        }
        break;
    case 0x00280724u:   /* H5, 0x002806D8 after cmpwi cr7,r3,0: r3 = this update's SpEffect HP change, chr r31 */
        if (god && gpr32(ctx, 31) == me && sgpr32(ctx, 3) < 0) {
            if (devlog) dev_log(5, "SpEffect HP change", sgpr32(ctx, 3), 0, me);
            ctx->gpr[3] = 0;
            set_cr7(ctx, 0, 0);   /* EQ: the beq skips the change */
        }
        break;
    case 0x00280C78u:   /* H6, 0x00280A08: r9 = this update's SpEffect MP change, chr r31; cmpwi follows */
        if (god && gpr32(ctx, 31) == me && sgpr32(ctx, 9) < 0) {
            if (devlog) dev_log(6, "SpEffect MP change", sgpr32(ctx, 9), 0, me);
            ctx->gpr[9] = 0;
        }
        break;
    case 0x0026FB20u:   /* H7, AddHP(chr r3, delta r4), after cmpwi cr7,r4,0 */
        if (god && gpr32(ctx, 3) == me && sgpr32(ctx, 4) < 0) {
            if (devlog) dev_log(7, "AddHP", sgpr32(ctx, 4), 0, me);
            ctx->gpr[4] = 0;
            set_cr7(ctx, 0, 0);
        }
        break;
    case 0x0026FC48u: {   /* H8, SetMP(chr r3, value r4), after cmpwi cr7,r4,0 */
        if (!god || gpr32(ctx, 3) != me) break;
        const int32_t mp = (int32_t)vm_read32(me + kChrMp), v = sgpr32(ctx, 4);
        if (v >= mp) break;   /* a gain, or no change */
        if (devlog) dev_log(8, "SetMP", v, mp, me);
        ctx->gpr[4] = (uint32_t)mp;
        set_cr7(ctx, mp, 0);
        break;
    }
    case 0x0026FC98u: {   /* H9, SetStamina(chr r3, value r4), after cmpwi cr7,r4,-50 */
        if (!god || gpr32(ctx, 3) != me) break;
        const int32_t st = (int32_t)vm_read32(me + kChrStamina), v = sgpr32(ctx, 4);
        if (v >= st) break;
        if (devlog) dev_log(9, "SetStamina", v, st, me);
        ctx->gpr[4] = (uint32_t)st;
        set_cr7(ctx, st, -50);
        break;
    }
    case 0x00286614u: {   /* H10, the dash cost in 0x00286020: r9 = stamina - 1 (chr r31); the clamp follows */
        if (!god || gpr32(ctx, 31) != me) break;
        const uint32_t st = vm_read32(me + kChrStamina);
        if (devlog) dev_log(10, "dash cost", sgpr32(ctx, 9), (int32_t)st, me);
        ctx->gpr[9] = st;
        break;
    }
    case 0x002EDEB0u:   /* H11, the root-motion step 0x002EDDA0, fcmpu cr7,f0,f13: f0 = the speed factor (mv r31), f13 = 1 */
        if (speed == 1.0f || vm_read32(me + kChrMove) != gpr32(ctx, 31)) break;
        if (devlog) dev_log(11, "step factor", ctx->fpr[0], ctx->fpr[0] * speed, me);
        ctx->fpr[0] = (float)(ctx->fpr[0] * speed);
        ppu_cr_set(ctx, 7, 8u);   /* LT: the branch that scales the step (mv+0xF0) by f0 */
        break;
    case 0x0027882Cu:   /* H12, 0x002784C0: r0 = a weapon action's stamina cost (chr r28); subf follows */
        if (god && gpr32(ctx, 28) == me && sgpr32(ctx, 0) > 0) {
            if (devlog) dev_log(12, "weapon action cost", sgpr32(ctx, 0), 0, me);
            ctx->gpr[0] = 0;
        }
        break;
    default:
        break;
    }
}

/* Called once from ps3_title_options_init, after settings.ini and before the
 * network modules start and the window opens: prints the marker, decides the
 * session and adds "(developer build)" to the window title. */
extern "C" void des_dev_boot(void)
{
    fprintf(stderr, "[dev] %s\n", DES_DEV_MARKER);
    /* The developer keys in the game window (F8 here, F9 to F11 in ps3recomp) are on in a developer build;
     * RSX_DEV_HOTKEYS=0 turns them off, to see what a player's build does. */
    if (!getenv("RSX_DEV_HOTKEYS")) ps3_setenv("RSX_DEV_HOTKEYS", "1");
    const char* warp = getenv("DES_WARP");
    const char* give = getenv("DES_GIVE");
    const bool cheat = god_knob() || atk_knob() != 1.0f || speed_knob() != 1.0f || (warp && *warp) ||
                       (give && *give) || env_on("DES_KILLSELF") || env_on("DES_KILLALL") || env_on("DES_AREA");
    if (cheat) {
        s_session = kCheats;
        mark_used("set at start");
    } else if (net_knob()) {
        s_session = kOnline;
    }
    const int s = s_session.load();
    ps3_setenv("DES_DEV_SESSION", session_name(s));
    fprintf(stderr, "[dev] session: %s%s\n", session_name(s),
            s == kCheats   ? " (a cheat was set at start: the network knobs are cleared)"
            : s == kOnline ? " (the network is on: the cheats stay off until the next start)"
                           : " (the first cheat turned on keeps it offline)");
    /* The window caption says so too. boot_main opens the window after this and captions it with PS3_TITLE, else
     * PARAM.SFO's title, else "ps3recomp"; the frame rate is added after it. */
    const char* title = getenv("PS3_TITLE");
    if (!title || !*title) {
        title = cellGame_get_title();
        if (!title || !*title || !strcmp(title, "Unknown Title")) title = "ps3recomp";
    }
    char caption[160];
    snprintf(caption, sizeof caption, "%s (developer build)", title);
    ps3_setenv("PS3_TITLE", caption);
}

/* True from the first cheat to the end of the session: future network code
 * must stay offline while it is (docs/46, docs/55 section 6). */
extern "C" int des_dev_cheats_used(void)
{
    return s_used.load() ? 1 : 0;
}

/* DES_WARP (see the top). Lua's LoadChrPos is 0x004428F0 -> 0x00273BE0, r3 =
 * the character, vr2 = x y z 0. Enemies (vtable 0x0185AF98) are in the array
 * at *(ChrMan + 0xC). Main thread: des_menu_tick calls des_debug_tick once a
 * frame. */
static void warp_chr(ppu_context* ctx, uint32_t chr, const float* p)
{
    uint64_t g[32]; double f[32]; uint8_t v[32][16];
    memcpy(g, ctx->gpr, sizeof g); memcpy(f, ctx->fpr, sizeof f); memcpy(v, ctx->vr, sizeof v);
    const uint64_t lr = ctx->lr, ctr = ctx->ctr;
    const uint32_t cr = ppu_cr_pack(ctx), xer = ctx->xer;
    uint8_t be[16] = {};
    for (int i = 0; i < 3; i++) {
        uint32_t b; memcpy(&b, &p[i], 4);
        be[4 * i] = (uint8_t)(b >> 24); be[4 * i + 1] = (uint8_t)(b >> 16);
        be[4 * i + 2] = (uint8_t)(b >> 8); be[4 * i + 3] = (uint8_t)b;
    }
    memcpy(&ctx->vr[2], be, 16);
    ctx->gpr[3] = chr;
    ctx->lr = DES_AT(0x00724E40u);
    func_00273BE0(ctx);
    while (g_trampoline_fn) {
        void (*tf)(void*) = g_trampoline_fn;
        g_trampoline_fn = nullptr;
        tf(ctx);
    }
    memcpy(ctx->gpr, g, sizeof g); memcpy(ctx->fpr, f, sizeof f); memcpy(ctx->vr, v, sizeof v);
    ctx->lr = lr; ctx->ctr = ctr; ppu_cr_unpack(ctx, cr); ctx->xer = xer;
}

static bool chr_pos(uint32_t chr, float* p)
{
    uint32_t q = vm_read32(chr + 0x20);
    if (!guest_ptr_ok(q) || !guest_ptr_ok(q = vm_read32(q + 0x10))) return false;
    for (int i = 0; i < 3; i++) p[i] = vm_readf(q + 0x10 + 4 * i);
    return true;
}

/* Calls a game function with up to six arguments (r3-r8) and returns r3. Like warp_chr, on the main thread's own
 * registers, which are put back after, with the EBOOT's TOC and a stack below the caller's 288-byte red zone. */
static uint32_t call_game(ppu_context* ctx, void (*fn)(ppu_context*), const uint32_t* a, int na)
{
    uint64_t g[32]; double f[32]; uint8_t v[32][16];
    memcpy(g, ctx->gpr, sizeof g); memcpy(f, ctx->fpr, sizeof f); memcpy(v, ctx->vr, sizeof v);
    const uint64_t lr = ctx->lr, ctr = ctx->ctr;
    const uint32_t cr = ppu_cr_pack(ctx), xer = ctx->xer;
    ctx->gpr[1] -= 0x1000; ctx->gpr[2] = DES_AT(0x019B5040u);
    for (int i = 0; i < na && i < 6; i++) ctx->gpr[3 + i] = a[i];
    ctx->lr = DES_AT(0x00724E40u);
    fn(ctx);
    while (g_trampoline_fn) {
        void (*tf)(void*) = g_trampoline_fn;
        g_trampoline_fn = nullptr;
        tf(ctx);
    }
    const uint32_t r3 = (uint32_t)ctx->gpr[3];
    memcpy(ctx->gpr, g, sizeof g); memcpy(ctx->fpr, f, sizeof f); memcpy(ctx->vr, v, sizeof v);
    ctx->lr = lr; ctx->ctr = ctr; ppu_cr_unpack(ctx, cr); ctx->xer = xer;
    return r3;
}

/* DES_GIVE (see the top). Add-item is 0x008FB4F0 (inventory r3, category r4, id r5, count r6, 1, 1), the function
 * the AddInventoryItem script binding calls; the inventory is the player's game data + 0x128. It returns the slot,
 * or -1 with the reason at inventory + 0x1B0 (1 over the burden limit, 2 a stack past 99, 3 no sort entry, 4 no free
 * slot). The save afterwards is the SaveRequest script binding (0x004418B8, no arguments). */
static int32_t add_item(ppu_context* ctx, uint32_t inv, uint32_t cat, uint32_t id, uint32_t n)
{
    const uint32_t a[6] = { inv, cat, id, n, 1, 1 };
    return (int32_t)call_game(ctx, func_008FB4F0, a, 6);
}

/* The player's game data while a level is in play and no cutscene runs, else 0. Read the way the AddInventoryItem
 * script binding (0x00447748) reads it: *(*(*(*(TOC - 0x7884) - 0x8000)) + 8). AddItem checks the item burden, so
 * the character's stats must be there too (the burden limit AddItem reads, *(inv + 0x1A8) + 0x498); a cutscene is
 * RemoMan 0x01B3A28C's slots. */
static uint32_t level_pgd()
{
    const uint32_t man = vm_read32(DES_AT(kChrMan)), base = vm_read32(DES_AT(0x019AD7BCu));
    uint32_t slot_p = 0, gm = 0, pgd = 0;
    if (!guest_ptr_ok(man) || !guest_ptr_ok(vm_read32(man + 0x1BC)) || !guest_ptr_ok(base) ||
        !guest_ptr_ok(slot_p = vm_read32(base - 0x8000u)) || !guest_ptr_ok(gm = vm_read32(slot_p)) ||
        !guest_ptr_ok(pgd = vm_read32(gm + 8)))
        return 0;   /* not in a level yet */
    const uint32_t stats = vm_read32(pgd + 0x128 + 0x1A8), remo = vm_read32(DES_AT(0x01B3A28Cu));
    const bool cut = guest_ptr_ok(remo) && (vm_read32(remo + 0x28) || vm_read32(remo + 0x40) ||
                                            vm_read32(remo + 0x58) || vm_read32(remo + 0x70));
    if (!guest_ptr_ok(stats) || !(vm_readf(stats + 0x498) > 0.0f) || cut) return 0;
    return pgd;
}

/* Frames level_pgd has held in a row, counted by des_debug_tick once a frame. The level switches wait for 90. */
static int s_level_frames = 0;
static bool level_ready() { return s_level_frames >= 90; }

/* Gives the pending DES_GIVE list once the player is loaded; called every frame, so a value set at start waits for
 * the level. */
static void give_tick(ppu_context* ctx)
{
    static char done[256] = "";
    const char* e = getenv("DES_GIVE");
    if (!e || !*e || !strcmp(e, done) || !level_ready()) return;
    const uint32_t pgd = level_pgd();
    if (!pgd) return;
    snprintf(done, sizeof done, "%s", e);
    if (refused("DES_GIVE")) return;
    mark_used("DES_GIVE");
    char list[256];
    snprintf(list, sizeof list, "%s", strcmp(e, "online") ? e
             : "1021*10,9995,9996,9997,9998,9999,ring:114,ring:115");
    int added = 0;
    for (char* tok = strtok(list, ","); tok; tok = strtok(nullptr, ",")) {
        uint32_t cat = 0x40000000u;   /* goods */
        if (!strncmp(tok, "ring:", 5)) { cat = 0x20000000u; tok += 5; }
        char* end;
        const unsigned long id = strtoul(tok, &end, 10);
        unsigned long n = *end == '*' ? strtoul(end + 1, nullptr, 10) : 1;
        if (end == tok || n < 1 || n > 99) { fprintf(stderr, "[dev] DES_GIVE: skipped \"%s\"\n", tok); continue; }
        const int32_t slot = add_item(ctx, pgd + 0x128, cat, (uint32_t)id, (uint32_t)n);
        added += slot >= 0;
        if (slot >= 0) fprintf(stderr, "[dev] DES_GIVE %s %lu x%lu: slot %d\n", cat == 0x40000000u ? "goods" : "ring", id, n, slot);
        else fprintf(stderr, "[dev] DES_GIVE %s %lu x%lu: refused, reason %u\n", cat == 0x40000000u ? "goods" : "ring",
                     id, n, vm_read32(pgd + 0x128 + 0x1B0));
    }
    if (added) {   /* the game saves when asked; adding an item does not ask */
        call_game(ctx, func_004418B8, nullptr, 0);
        fprintf(stderr, "[dev] DES_GIVE: %d item(s) added, save requested\n", added);
    }
}

/* A game function by its address (the running disc's: DES_AT at the call), through the runtime's indirect call, for
 * the ones that are not in DES_GAME_CALLS. call_game puts CTR back as it found it, so this sets it around the call. */
static uint32_t call_addr(ppu_context* ctx, uint32_t code, const uint32_t* a, int na)
{
    const uint64_t ctr = ctx->ctr;
    ctx->ctr = code;
    const uint32_t r3 = call_game(ctx, ps3_indirect_call, a, na);
    ctx->ctr = ctr;
    return r3;
}

/* The function the scripts' deaths use: HP 0, the dead flag and the game's death (docs/55 section 2.6). */
constexpr uint32_t kKillChr = 0x00272C28u;
/* TOC - 0x788C: the area's characters = *(*(*this - 0x7FFC)), the count at +0x14 and the array at +0xC. */
constexpr uint32_t kWorldSlot = 0x019AD7B4u;

/* DES_KILLSELF and DES_KILLALL (see the top): each new value acts once, in a level. */
static void kill_tick(ppu_context* ctx)
{
    static char self_done[64] = "", all_done[64] = "";
    const char* s = knob_s("DES_KILLSELF");
    const char* a = knob_s("DES_KILLALL");
    const bool self_new = strcmp(s, self_done) != 0, all_new = strcmp(a, all_done) != 0;
    if ((!self_new && !all_new) || !level_ready()) return;
    const uint32_t me = player_chr();
    if (!me) return;
    if (self_new) {
        snprintf(self_done, sizeof self_done, "%s", s);
        if (*s && strcmp(s, "0") && (int32_t)vm_read32(me + 0x3C4) > 0 && !refused("DES_KILLSELF")) {
            mark_used("DES_KILLSELF");
            const uint32_t arg[1] = {me};
            call_addr(ctx, DES_AT(kKillChr), arg, 1);
            fprintf(stderr, "[dev] DES_KILLSELF: the player killed (chr %08X)\n", me);
        }
    }
    if (all_new) {
        snprintf(all_done, sizeof all_done, "%s", a);
        const bool all = !strcmp(a, "all");
        const float r = all ? 0.0f : (float)atof(a);
        if ((!all && !(r > 0.0f)) || refused("DES_KILLALL")) return;
        const uint32_t wl = rd(rd(rd(DES_AT(kWorldSlot)) - 0x7FFCu));
        if (!guest_ptr_ok(wl)) return;
        mark_used("DES_KILLALL");
        float p[3] = {};
        const bool here = chr_pos(me, p);
        const uint32_t cnt = vm_read32(wl + 0x14), arr = vm_read32(wl + 0xC);
        int n = 0;
        for (uint32_t i = 0; i < cnt && i < 4096 && guest_ptr_ok(arr); i++) {
            const uint32_t c = vm_read32(arr + 4 * i);
            float q[3];
            if (!guest_ptr_ok(c) || c == me || vm_read32(c) != DES_AT(0x0185AF98u) || (int32_t)vm_read32(c + 0x3C4) <= 0)
                continue;
            if (!all && (!here || !chr_pos(c, q) ||
                         std::sqrt((q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) +
                                   (q[2] - p[2]) * (q[2] - p[2])) > r))
                continue;
            const uint32_t arg[1] = {c};
            call_addr(ctx, DES_AT(kKillChr), arg, 1);
            n++;
        }
        fprintf(stderr, "[dev] DES_KILLALL %s: %d enem%s killed\n", a, n, n == 1 ? "y" : "ies");
    }
}

/* DES_AREA (see the top): the scripts' WarpNextStage(world, block, 0, 0, point) is 0x00451430 (r4 to r8). */
static void area_tick(ppu_context* ctx)
{
    static char done[64] = "";
    const char* e = knob_s("DES_AREA");
    if (!strcmp(e, done) || !level_ready()) return;
    snprintf(done, sizeof done, "%s", e);
    if (!*e) return;
    int w = 0, b = 0, point = 0;
    const int n = sscanf(e, "%d,%d,%d", &w, &b, &point);
    if (n < 2 || w < 1 || w > 8 || b < 0 || b > 3) {
        fprintf(stderr, "[dev] DES_AREA: \"%s\" is not world,block[,point] (m02_01: 2,1)\n", e);
        return;
    }
    if (n < 3) point = w == 1 ? -1 : b == 0 ? 999 : 998 - b;
    if (refused("DES_AREA")) return;
    mark_used("DES_AREA");
    const uint32_t a[6] = {0, (uint32_t)w, (uint32_t)b, 0, 0, (uint32_t)point};
    call_addr(ctx, DES_AT(0x00451430u), a, 6);
    fprintf(stderr, "[dev] DES_AREA: loading m%02d_%02d, arriving at point %d\n", w, b, point);
}

/* DES_FLAGWATCH (see the top). The flags are bits from *(*(*(TOC - 0x7B44) - 0x8000)), flag f at byte f >> 3, bit
 * f & 7, as the game's flag read 0x005087C8 takes them; ids 0 to 0x427F. */
constexpr uint32_t kGameSlot = 0x019AD4FCu;
constexpr uint32_t kFlagLast = 0x427Fu;

static void flag_tick()
{
    static char list[256] = "";
    static uint32_t ids[16];
    static int last[16], n = 0;
    const char* e = knob_s("DES_FLAGWATCH");
    if (strcmp(e, list)) {
        snprintf(list, sizeof list, "%s", e);
        n = 0;
        for (const char* p = list; *p && n < 16;) {
            char* end;
            const unsigned long f = strtoul(p, &end, 10);
            if (end == p) break;
            if (f <= kFlagLast) { ids[n] = (uint32_t)f; last[n++] = -1; }
            else fprintf(stderr, "[dev] DES_FLAGWATCH: flag %lu is past %u, skipped\n", f, kFlagLast);
            p = *end == ',' ? end + 1 : end;
        }
        if (*list) fprintf(stderr, "[dev] DES_FLAGWATCH: watching %d flag(s)\n", n);
    }
    if (!n) return;
    const uint32_t base = rd(rd(rd(DES_AT(kGameSlot)) - 0x8000u));
    if (!guest_ptr_ok(base)) return;
    for (int i = 0; i < n; i++) {
        const int v = (vm_read8(base + (ids[i] >> 3)) >> (ids[i] & 7)) & 1;
        if (v == last[i]) continue;
        fprintf(stderr, "[dev] flag %u: %d%s\n", ids[i], v, last[i] < 0 ? " (first seen)" : "");
        last[i] = v;
    }
}

extern "C" void des_debug_tick(ppu_context* ctx)
{
    static int gen = 0;
    static char last[96] = "";
    s_level_frames = level_pgd() ? (s_level_frames < 90 ? s_level_frames + 1 : 90) : 0;
    give_tick(ctx);
    kill_tick(ctx);
    area_tick(ctx);
    flag_tick();
    const int before = gen;
    PS3_KNOB(gen, gen + 1);
    if (gen == before) return;
    online();   /* after each setenv: a network knob set now turns the cheats off even while none is on (the top) */
    const char* e = getenv("DES_WARP");
    if (!e || !strcmp(e, last)) return;
    snprintf(last, sizeof last, "%s", e);
    float p[3];
    if (sscanf(e, "%f,%f,%f", &p[0], &p[1], &p[2]) != 3) return;
    if (refused("DES_WARP")) return;
    const uint32_t man = vm_read32(DES_AT(kChrMan));
    uint32_t chr;
    if (!guest_ptr_ok(man) || !guest_ptr_ok(chr = vm_read32(man + 0x1BC))) return;
    mark_used("DES_WARP");
    const char* c = getenv("DES_WARP_CLEAR");
    const float r = c ? (float)atof(c) : 0.0f;
    const uint32_t list = vm_read32(man + 0xC);
    if (r > 0.0f && guest_ptr_ok(list)) {
        int moved = 0;
        for (uint32_t i = 0; i < 64; i++) {
            const uint32_t q = vm_read32(list + 4 * i);
            float qp[3];
            if (!guest_ptr_ok(q) || q == chr || vm_read32(q) != DES_AT(0x0185AF98u) || !chr_pos(q, qp)) continue;
            const float d = std::sqrt((qp[0] - p[0]) * (qp[0] - p[0]) + (qp[1] - p[1]) * (qp[1] - p[1]) +
                                      (qp[2] - p[2]) * (qp[2] - p[2]));
            if (d > r) continue;
            const float away[3] = {201.0f + 1.5f * moved, -1.1f, -96.2f};   /* the tutorial's start */
            warp_chr(ctx, q, away);
            fprintf(stderr, "[des] DES_WARP_CLEAR: enemy %08X (%.1f m) sent away\n", q, d);
            moved++;
        }
    }
    warp_chr(ctx, chr, p);
    fprintf(stderr, "[des] DES_WARP %.3f %.3f %.3f (chr %08X)\n", p[0], p[1], p[2], chr);
}
