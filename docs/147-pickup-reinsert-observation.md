# Native pickup rejection and reinsertion observation

This change adds opt-in developer tracing for the native pickup rejection and
local reinsertion path. Set `DES_PICKUP_TRACE=1` in a `DES_DEV=ON` build to emit
the trace to host stderr. The hooks observe guest registers and memory; they do
not write guest memory, change the PPU context, or call back into guest code.

The `thread=` trace field is a `std::hash<std::thread::id>` host-thread hash.
It is not a PS3 guest PPU thread ID. The sequence number is local to that host
thread. The event lookup hook is instrumentation only and does not establish
co-op behavior.

The local lookup hook runs before the unlink call: US `0x0036D9A4`, Asia
`0x0036BD0C`, EU `0x0036E754`, and JP `0x0036BC94`. The event lookup hook also
runs before unlink: US `0x0036DE00`, Asia `0x0036C168`, EU `0x0036EBB0`, and JP
`0x0036C0F0`. The post-allocator hook is US `0x0036CE34` / Asia `0x0036B19C`.

## Isolated Asia evidence

Run25 used the authorized launcher with a fresh save copy verified against 14
source-file hashes. The live save and other game processes were not used. At
the pickup anchor, the Crescent Moon Grass pile was observed at
`(0, 479.457977, -41.69)` in manager `0x423F70D0`; the trace recorded key 1,
node `0x45608E20`, and item fields `40000000,000003E8,00000001,FFFFFFFF`.

With load `88.0/88.0`, the native UI displayed “It’s too heavy for you to
carry.” The trace recorded the native `-1` path and unchanged item fields. The
pile was reinserted under key 2 at node `0x45608D90`. On the next attempt, the
pre-unlink lookup reported manager `0x423F70D0`, key 2, node `0x45608D90`,
`node_key_matches=1`, `identity_match=1`, and `same_node_pointer=1`. A second
rejection reused that node under key 3 with the same position and item fields.

For the positive control, dropping one Half Moon Grass changed load from
`88.0` to `87.9`. One Cross on the same Crescent pile produced the native
“Crescent Moon Grass 1” result. Inventory changed from 20 to 21 Crescent Moon
Grass, and load returned to `88.0/88.0`. The lookup saw manager
`0x423F70D0`, key 3, node `0x45608D90`, and matching `node_key=3`. Afterward the
manager head referred to a separate Half Moon node, and the old Crescent node
was no longer linked as an item.

Screenshots, the full trace, memory reads, the isolated-copy manifest, and the
runtime are preserved locally under
`.local/task4-pickup-rejection-fresh/run25/`. They are intentionally excluded
from the PR because they contain a local save copy and runtime artifacts.

## Storage transaction boundary

Existing native Thomas withdrawal evidence shows one Crescent moved from
Storage 91 to 90 while load changed from `87.9` to `88.0`. A separate local
deposit record shows inventory `17→16`, Storage `93→94`, and load `87.8→87.7`.
Synthetic `storage_check` passed 59 checks and `storage_navigation_check`
passed 92 checks.

These results cover exact successful operations and simulated refusal/mismatch
handling. They do not prove rollback after a partial native box write. The
Storage wrapper detects a mismatched delta and disables later Send operations,
but does not restore the box or inventory. The native helper can clamp a
Storage stack while reporting success and remove the full requested amount.
The lift skips inventory removal on a `-1` result, but that alone does not
prove the box stayed unchanged on every failure path. Therefore this change is
observer-only; it does not add pickup-to-Storage transfer behavior. That work
still needs native partial/full/refusal and rollback evidence before it can
claim transaction safety.

## Verification

Run25's dynamic trace used the isolated Asia build with EXE SHA-256
`341224E23D8BFC5955D0CBB567942A12BFBB2D49BE199F26039736618AB4F7DB` and DLL
SHA-256 `D1DE83DB04618E79EE159CD7A4DE1342242E8994093BC3B7CB334CF05A3EC300`.
That run preceded rebasing this observer commit onto the current #519 head
`941e1ef`. The rebased candidate was then built with `DES_DEV=ON`,
`DES_SPLIT=ON`, `DES_REQUIRE_PIN=ON`, and the exact ps3recomp pin
`7d2cd5e92291cae5d93d664c90a7997074e87e20`. Its `des_host.exe` SHA-256 is
`055BD63EE9EE070F2CFAF16A050AE041A85C077A46EE87847EB9A02ACB0876CB`.
`des_game` was already up to date and was not relinked; its existing DLL SHA-256
is `D1DE83DB04618E79EE159CD7A4DE1342242E8994093BC3B7CB334CF05A3EC300`. The
existing gameplay process was preserved, so the rebased host was not launched
for a second dynamic replay.

- `storage_check`: 106 checks, 0 failures.
- `storage_navigation_check`: 92 checks, 0 failures.
- `git diff --check`: passed.
