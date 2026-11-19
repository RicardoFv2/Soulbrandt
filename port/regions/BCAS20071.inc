/* BCAS20071, the Asian disc with its 1.04 update: its address for every BLUS30443 address the port uses
 * (des_region.h). Sorted by the US address; one line per address. 0xFFFFFFFF: this program has no such thing
 * (only code that runs on the other discs uses it).
 * tools/region/region_table.py checks that every address in the port is here (CI). */
DES_REGION_ADDR(0x000112E8, 0x000112E8)  /* hook des_body_sample */
DES_REGION_ADDR(0x00011720, 0x00011720)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00011768, 0x00011768)  /* hook des_kf_target */
DES_REGION_ADDR(0x00013874, 0xFFFFFFFF)  /* data kOnlineTagCases */
DES_REGION_ADDR(0x00023750, 0x000219C0)  /* call */
DES_REGION_ADDR(0x00039210, 0x00036DD0)  /* hook + call des_luaheap: Lua's heap, alloc */
DES_REGION_ADDR(0x00039540, 0x00037100)  /* hook + call des_luaheap: Lua's heap, block size */
DES_REGION_ADDR(0x00039790, 0x00037350)  /* hook + call des_luaheap: Lua's heap, realloc */
DES_REGION_ADDR(0x00039870, 0x00037430)  /* hook + call des_luaheap: Lua's heap, owns block */
DES_REGION_ADDR(0x00039940, 0x00037500)  /* hook + call des_luaheap: Lua's heap, free */
DES_REGION_ADDR(0x00039A10, 0x000375D0)  /* hook + call des_luaheap: Lua's heap, alloc */
DES_REGION_ADDR(0x00039AE0, 0x000376A0)  /* hook + call des_luaheap: Lua's heap, free */
DES_REGION_ADDR(0x00039BB0, 0x00037770)  /* hook + call des_luaheap: Lua's heap, realloc */
DES_REGION_ADDR(0x00039D50, 0x00037910)  /* hook + call des_luaheap: Lua's heap, alloc aligned */
DES_REGION_ADDR(0x00039E30, 0x000379F0)  /* hook + call des_luaheap: Lua's heap, realloc aligned */
DES_REGION_ADDR(0x00039F20, 0x00037AE0)  /* hook + call des_luaheap: Lua's heap, realloc aligned */
DES_REGION_ADDR(0x0003A0D8, 0x00037C98)  /* hook + call des_luaheap: Lua's heap, alloc aligned */
DES_REGION_ADDR(0x0003C758, 0x0003A318)  /* hook + call des_luaheap: Lua's small heap, free */
DES_REGION_ADDR(0x0003C9A8, 0x0003A568)  /* hook + call des_luaheap: Lua's small heap, realloc aligned */
DES_REGION_ADDR(0x0003CA98, 0x0003A658)  /* hook + call des_luaheap: Lua's small heap, alloc aligned */
DES_REGION_ADDR(0x0003CB78, 0x0003A738)  /* hook + call des_luaheap: Lua's small heap, block size */
DES_REGION_ADDR(0x0003CC48, 0x0003A808)  /* hook + call des_luaheap: Lua's small heap, owns block */
DES_REGION_ADDR(0x0003CDF8, 0x0003A9B8)  /* hook + call des_luaheap: Lua's small heap, realloc aligned */
DES_REGION_ADDR(0x0003CEE8, 0x0003AAA8)  /* hook + call des_luaheap: Lua's small heap, alloc aligned */
DES_REGION_ADDR(0x0003D208, 0x0003ADC8)  /* hook + call des_luaheap: Lua's small heap, realloc */
DES_REGION_ADDR(0x0003D2E8, 0x0003AEA8)  /* hook + call des_luaheap: Lua's small heap, free */
DES_REGION_ADDR(0x0003D478, 0x0003B038)  /* hook + call des_luaheap: Lua's small heap, alloc */
DES_REGION_ADDR(0x0003D548, 0x0003B108)  /* hook + call des_luaheap: Lua's small heap, alloc */
DES_REGION_ADDR(0x0003D618, 0x0003B1D8)  /* hook + call des_luaheap: Lua's small heap, realloc */
DES_REGION_ADDR(0x0006C860, 0x0006A1F8)  /* hook des_coop_hook: the ghost colour upload returned (the material put back) */
DES_REGION_ADDR(0x00080E88, 0x0007E820)  /* hook des_coop_hook: the ghost colour upload starting (a player's own glow colour) */
DES_REGION_ADDR(0x000B14C8, 0x000AEE60)  /* call kSpacingPlay */
DES_REGION_ADDR(0x000B15C8, 0x000AEF60)  /* call kFontPlay */
DES_REGION_ADDR(0x000D5B24, 0x000D34BC)  /* hook des_cam_own */
DES_REGION_ADDR(0x000E9650, 0x000E6FE8)  /* hook des_coop_hook: the ghost model draw (a player's own glow colour) */
DES_REGION_ADDR(0x00110608, 0x0010DFA0)  /* hook des_mouse_look */
DES_REGION_ADDR(0x001107C0, 0x0010E158)  /* hook des_cam_step */
DES_REGION_ADDR(0x00119670, 0x00117748)  /* hook des_mouse_look */
DES_REGION_ADDR(0x00119818, 0x001178F0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x001198D8, 0x001179B0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00119FAC, 0x00118084)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011A018, 0x001180F0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011A100, 0x001181D8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011B830, 0x00119908)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C0E8, 0x0011A1C0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C15C, 0x0011A234)  /* hook des_cam_keep */
DES_REGION_ADDR(0x0011C2BC, 0x0011A394)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C758, 0x0011A830)  /* hook des_mouse_look */
DES_REGION_ADDR(0x0011C910, 0x0011A9E8)  /* hook des_mouse_look */
DES_REGION_ADDR(0x0011CF84, 0x0011B05C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011CF98, 0x0011B070)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D2D4, 0x0011B3AC)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D6E4, 0x0011B7BC)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D820, 0x0011B8F8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00123100, 0x001211D8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00123164, 0x0012123C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00124188, 0x00122260)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0012554C, 0x00123624)  /* hook des_cam_rate */
DES_REGION_ADDR(0x001256D4, 0x001237AC)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0012EE08, 0x0012CEE0)  /* call, wrapped (des_aspect) */
DES_REGION_ADDR(0x0012F074, 0x0012D14C)  /* hook des_cam_ctor */
DES_REGION_ADDR(0x0012F0DC, 0x0012D1B4)  /* hook des_cam_ctor */
DES_REGION_ADDR(0x0012F19C, 0x0012D274)  /* hook des_frustum_tall */
DES_REGION_ADDR(0x001381E8, 0x001362C0)  /* call */
DES_REGION_ADDR(0x0015AE10, 0x00158EE8)  /* call kLoadSouls */
DES_REGION_ADDR(0x00162D0C, 0x00160DE4)  /* data kGameParamCases */
DES_REGION_ADDR(0x0017A4A8, 0x00178580)  /* hook des_coop_hook: the summoned reload's load step */
DES_REGION_ADDR(0x0017B258, 0x00179330)  /* call */
DES_REGION_ADDR(0x00196158, 0x00194230)  /* call */
DES_REGION_ADDR(0x001D17A0, 0x001CF878)  /* call */
DES_REGION_ADDR(0x001D1E64, 0x001CFF3C)  /* hook des_phys_rate */
DES_REGION_ADDR(0x001D35D8, 0x001D16B0)  /* call */
DES_REGION_ADDR(0x001DF83C, 0x001DD914)  /* hook des_phys_kf */
DES_REGION_ADDR(0x001EF6D0, 0x001ED7A8)  /* hook des_phys_kf */
DES_REGION_ADDR(0x001FEAF4, 0x001FCBCC)  /* hook des_slide_rate */
DES_REGION_ADDR(0x001FED50, 0x001FCE28)  /* hook des_slide_rate */
DES_REGION_ADDR(0x0020D3C0, 0x0020B498)  /* call des_seamless_game (by address): Tutorial_end's */
DES_REGION_ADDR(0x0020E788, 0x0020C860)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002107B8, 0x0020E890)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00217E70, 0x00215F48)  /* hook des_motion_blur */
DES_REGION_ADDR(0x002184DC, 0x002165B4)  /* hook des_dof */
DES_REGION_ADDR(0x00226778, 0x00224850)  /* call */
DES_REGION_ADDR(0x0025C5EC, 0x0025A6C4)  /* call des_coop_hook: the area items' remove, its taken flag's set (a friend keeps its pickups) */
DES_REGION_ADDR(0x0025CB6C, 0x0025AC44)  /* hook des_coop_hook: the area items' add after lwz r9,0x8C(r9) (a friend gets the items too) */
DES_REGION_ADDR(0x0025CC34, 0x0025AD0C)  /* hook des_coop_hook: the area items' add after bl 0x005087C8 (a friend's own taken flags) */
DES_REGION_ADDR(0x0025EB88, 0x0025CC60)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0025EC14, 0x0025CCEC)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0026558C, 0x00263664)  /* hook des_fade_rate */
DES_REGION_ADDR(0x00265C88, 0x00263D60)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0026FB20, 0x0026DBF8)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0026FC48, 0x0026DD20)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0026FC98, 0x0026DD70)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00272A88, 0x00270B60)  /* hook des_coop_hook: an enemy's souls, the guest test (a friend's full souls) */
DES_REGION_ADDR(0x00272C28, 0x00270D00)  /* call des_dev (by address): the scripts' kill */
DES_REGION_ADDR(0x00273620, 0x002716F8)  /* call */
DES_REGION_ADDR(0x002737A0, 0x00271878)  /* call */
DES_REGION_ADDR(0x00273BE0, 0x00271CB8)  /* call */
DES_REGION_ADDR(0x00273D38, 0x00271E10)  /* hook des_move_post */
DES_REGION_ADDR(0x00273D4C, 0x00271E24)  /* return address in 0x00273D38 */
DES_REGION_ADDR(0x0027882C, 0x00276904)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002802E0, 0x0027E460)  /* call */
DES_REGION_ADDR(0x00280724, 0x0027E8A4)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280C78, 0x0027EDF8)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280E64, 0x0027EFE4)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280F88, 0x0027F108)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002818D0, 0x0027FA50)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00286614, 0x002846C4)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0028B224, 0x002892D4)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002977C0, 0x00295870)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002986B8, 0x00296768)  /* call */
DES_REGION_ADDR(0x00299B74, 0x00297C24)  /* hook des_coop_hook: an NPC's setup after lbz r0,0xE8(r9) (a friend notes the NPCs it sets up as the host's) */
DES_REGION_ADDR(0x00299BB0, 0x00297C60)  /* hook des_coop_hook: an NPC's setup after mr r23,r3, its new character (the same) */
DES_REGION_ADDR(0x0029EC08, 0x0029CCB8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002A6AA8, 0x002A4B58)  /* wrapped kChrInsThread */
DES_REGION_ADDR(0x002A6AF4, 0x002A4BA4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B14, 0x002A4BC4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B24, 0x002A4BD4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B34, 0x002A4BE4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B50, 0x002A4C00)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B60, 0x002A4C10)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B7C, 0x002A4C2C)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B98, 0x002A4C48)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BA0, 0x002A4C50)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BB0, 0x002A4C60)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BD0, 0x002A4C80)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BEC, 0x002A4C9C)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BF8, 0x002A4CA8)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C34, 0x002A4CE4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C58, 0x002A4D08)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C60, 0x002A4D10)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C70, 0x002A4D20)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6CA8, 0x002A4D58)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002B2984, 0x002B0A34)  /* hook des_coop_hook: a corpse's drop add after lwz r9,0x8C(r9) (a friend gets drops too) */
DES_REGION_ADDR(0x002C9600, 0x002C76B0)  /* hook des_coop_hook: message 0x26's read (an area character's place, from the host), held after a load */
DES_REGION_ADDR(0x002C96A8, 0x002C7758)  /* hook des_coop_hook: message 0x26's read in its loop (the same) */
DES_REGION_ADDR(0x002C9740, 0x002C77F0)  /* hook des_coop_hook: message 4's read (the area characters' states, from the host), held after a load */
DES_REGION_ADDR(0x002C98C4, 0x002C7974)  /* hook des_coop_hook: message 0x21's read (the area characters' states, from a member), held after a load */
DES_REGION_ADDR(0x002C9AEC, 0x002C7B9C)  /* hook des_coop_hook: message 3's read (the area characters' places, from a member), held after a load */
DES_REGION_ADDR(0x002D0EB0, 0x002CF350)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002D8978, 0x002D71B8)  /* call */
DES_REGION_ADDR(0x002DD368, 0x002DC0D0)  /* call kUseGoods */
DES_REGION_ADDR(0x002DDAA8, 0x002DC810)  /* hook des_coop_hook: a character's draw update (a friend's own phantom glow) */
DES_REGION_ADDR(0x002DDADC, 0x002DC844)  /* hook des_coop_hook: a character's draw update, the material kind's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002DDB48, 0x002DC8B0)  /* hook des_coop_hook: a character's draw update, the draw path's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002DDB90, 0x002DC8F8)  /* hook des_coop_hook: a character's draw update, 0x0025D418's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002E1000, 0x002DE438)  /* hook des_coop_hook: a character's draw objects' build, the face's type read (a friend's NPCs of type 4 get their faces) */
DES_REGION_ADDR(0x002EC2B8, 0x002EA328)  /* call */
DES_REGION_ADDR(0x002EDEB0, 0x002EBF20)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002F5B14, 0x002F3B84)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002F5CCC, 0x002F3D3C)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002F5DB8, 0x002F3E28)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002FF8F0, 0x002FD960)  /* hook des_roll_dir */
DES_REGION_ADDR(0x00300BAC, 0x002FEC1C)  /* hook des_kick */
DES_REGION_ADDR(0x00301C24, 0x002FFC94)  /* hook des_roll_dir */
DES_REGION_ADDR(0x0030C330, 0x0030A3A0)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030C378, 0x0030A3E8)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030C46C, 0x0030A4DC)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030F2BC, 0x0030D32C)  /* hook des_roll_tie */
DES_REGION_ADDR(0x0030F734, 0x0030D7A4)  /* hook des_roll_dir */
DES_REGION_ADDR(0x00310AA8, 0x0030EB18)  /* hook des_kick */
DES_REGION_ADDR(0x00313B24, 0x00311B94)  /* hook des_net_sync */
DES_REGION_ADDR(0x003147EC, 0x0031285C)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x00314ABC, 0x00312B2C)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x00315030, 0x003130A0)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x0036CBD0, 0x0036AF38)  /* pickup hook des_dev_hook: node key written before counter increment */
DES_REGION_ADDR(0x0036CBD4, 0x0036AF3C)  /* pickup hook des_dev_hook: counter increment after node key */
DES_REGION_ADDR(0x0036CDB8, 0x0036B120)  /* pickup hook des_dev_hook: reinsertion helper entry */
DES_REGION_ADDR(0x0036CE34, 0x0036B19C)  /* pickup hook des_dev_hook: post-call node return */
DES_REGION_ADDR(0x0036CE44, 0x0036B1AC)  /* pickup hook des_dev_hook: manager-root comparison */
DES_REGION_ADDR(0x0036CE4C, 0x0036B1B4)  /* pickup hook des_dev_hook: returned-node comparison */
DES_REGION_ADDR(0x0036D0D8, 0x0036B440)  /* pickup hook des_dev_hook: native reinsertion */
DES_REGION_ADDR(0x0036D3BC, 0x0036B724)  /* pickup hook des_dev_hook: reinsertion helper return */
DES_REGION_ADDR(0x0036D600, 0x0036B968)  /* pickup hook des_dev_hook: acquisition entry LR */
DES_REGION_ADDR(0x0036D678, 0x0036B9E0)  /* pickup hook des_dev_hook: add result */
DES_REGION_ADDR(0x0036D7FC, 0x0036BB64)  /* pickup hook des_dev_hook: copied record */
DES_REGION_ADDR(0x0036D9A4, 0x0036BD0C)  /* pickup hook des_dev_hook: local lookup before unlink BL */
DES_REGION_ADDR(0x0036DE00, 0x0036C168)  /* pickup hook des_dev_hook: event lookup before unlink BL */
DES_REGION_ADDR(0x00391818, 0x0038FB80)  /* hook des_net_replay */
DES_REGION_ADDR(0x003957B8, 0x00393B20)  /* hook des_net_replay */
DES_REGION_ADDR(0x003A596C, 0x003A3CD4)  /* hook des_net_replay */
DES_REGION_ADDR(0x003A5CA8, 0x003A4010)  /* hook des_net_show */
DES_REGION_ADDR(0x003A5EA0, 0x003A4208)  /* hook des_net_replay */
DES_REGION_ADDR(0x003D42BC, 0x003D2624)  /* hook des_twist_rate */
DES_REGION_ADDR(0x003DBA18, 0x003D9D80)  /* call */
DES_REGION_ADDR(0x003DBBB0, 0x003D9F18)  /* call */
DES_REGION_ADDR(0x003E2DF0, 0x003E1158)  /* hook des_sun_gate */
DES_REGION_ADDR(0x003E6330, 0x003E4698)  /* hook des_sun_gate */
DES_REGION_ADDR(0x003E6518, 0x003E4880)  /* hook des_sun_gate */
DES_REGION_ADDR(0x004117E4, 0x0040FB4C)  /* hook des_coop_hook: after RecvGlobalQwc's online blend (a friend plays in the host's world tendency) */
DES_REGION_ADDR(0x00419670, 0x004179D8)  /* call des_seamless_game (by address): the own bloodstain shown (ParamInitialize's type 0 path) */
DES_REGION_ADDR(0x00419DCC, 0x00418134)  /* hook des_coop_hook: after a load's world swap of the flags (a guest's own world kept) */
DES_REGION_ADDR(0x00439358, 0x004376C0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0043E4E0, 0x0043C848)  /* hook + call des_coop_hook, des_seamless_game: SetTextEffect (a friend's revival after its "The Demon Was Destroyed") */
DES_REGION_ADDR(0x0043EDE0, 0x0043D148)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x004418B8, 0x0043FC20)  /* call */
DES_REGION_ADDR(0x00441AB8, 0x0043FE20)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00443838, 0x00441BA0)  /* call */
DES_REGION_ADDR(0x00445F30, 0x00444298)  /* call des_seamless_game (by address): SetChrType */
DES_REGION_ADDR(0x00446C68, 0x00444FD0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00447258, 0x004455C0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00447EA0, 0x00446208)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044A368, 0x004486D0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044A5E4, 0x0044894C)  /* hook des_coop_hook: SetClearBonus, the session's member count (everyone's full boss souls) */
DES_REGION_ADDR(0x0044C6F0, 0x0044AA58)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044C780, 0x0044AAE8)  /* hook des_coop_hook: the end of WarpNextStageKick (a guest going home loads its own area) */
DES_REGION_ADDR(0x00451430, 0x0044F798)  /* call */
DES_REGION_ADDR(0x00467628, 0x00465990)  /* hook des_coop_hook: a script event's name */
DES_REGION_ADDR(0x004C6DF0, 0x004C5158)  /* pickup hook des_dev_hook: native add entry */
DES_REGION_ADDR(0x004C733C, 0x004C56A4)  /* pickup hook des_dev_hook: inventory result field */
DES_REGION_ADDR(0x004C74F0, 0x004C5858)  /* pickup hook des_dev_hook: native -1 comparison */
DES_REGION_ADDR(0x004C9638, 0x004C79A0)  /* hook des_coop_hook: the talk check after bl 0x0026F378 (a friend can talk to the NPCs) */
DES_REGION_ADDR(0x004C9C5C, 0x004C7FC4)  /* hook des_coop_hook: the talk check after bl 0x0026F378 (a friend can talk to the NPCs) */
DES_REGION_ADDR(0x005086F8, 0x00506A60)  /* hook des_coop_hook: the event flags' set (progress kept for every player) */
DES_REGION_ADDR(0x00508820, 0x00506B88)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00508C00, 0x00506F68)  /* hook des_coop_hook: a guest's join fills its flag copies (its own world's flags kept) */
DES_REGION_ADDR(0x0052C2D8, 0x0052A670)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00532108, 0x00530460)  /* call des_seamless_game (by address): a member's P2P message read */
DES_REGION_ADDR(0x00532358, 0x005306B0)  /* call des_seamless_game (by address): the host's P2P message read */
DES_REGION_ADDR(0x0053B31C, 0x00539674)  /* hook des_coop_hook: the session's leave */
DES_REGION_ADDR(0x0053CFE8, 0x0053B340)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0053E368, 0x0053C6C0)  /* hook des_coop_hook: the session event dispatch's member-left case (a leave during a load taken at once) */
DES_REGION_ADDR(0x0053EA2C, 0x0053CD84)  /* hook des_coop_hook: the session's check of a joined guest (a friend joins in either form) */
DES_REGION_ADDR(0x00540D90, 0x0053F0E8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00541B78, 0x0053FED0)  /* call des_seamless_game (by address): a connection's P2P message read */
DES_REGION_ADDR(0x0054E8C0, 0x00550870)  /* hook des_net_show */
DES_REGION_ADDR(0x0054E8F8, 0x005508A8)  /* hook des_net_show */
DES_REGION_ADDR(0x0054E934, 0x005508E4)  /* hook des_net_grade_poll */
DES_REGION_ADDR(0x00558884, 0x0055961C)  /* hook des_net_show */
DES_REGION_ADDR(0x00560904, 0x0056169C)  /* hook des_net_show */
DES_REGION_ADDR(0x00562BC4, 0x0056395C)  /* hook des_net_show */
DES_REGION_ADDR(0x00567E9C, 0x00568C34)  /* hook des_qwc_local */
DES_REGION_ADDR(0x00595B80, 0x00596E18)  /* call */
DES_REGION_ADDR(0x00597108, 0x005983A0)  /* call */
DES_REGION_ADDR(0x00597388, 0x00598620)  /* call */
DES_REGION_ADDR(0x0059E3A8, 0x0059F640)  /* call */
DES_REGION_ADDR(0x005A5920, 0x005A6BB8)  /* call */
DES_REGION_ADDR(0x005C2810, 0x005C3AA8)  /* call */
DES_REGION_ADDR(0x005C2848, 0x005C3AE0)  /* call */
DES_REGION_ADDR(0x005F7254, 0x005F84EC)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F72EC, 0x005F8584)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F7394, 0x005F862C)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F743C, 0x005F86D4)  /* hook des_cut_cam */
DES_REGION_ADDR(0x00609338, 0x0060A5D0)  /* hook des_coop_hook: a cutscene's copy of a character set up (its glow and colour) */
DES_REGION_ADDR(0x006A2E8C, 0x006A3FEC)  /* hook des_noise_rate */
DES_REGION_ADDR(0x006A3990, 0x006A4AF0)  /* hook des_noise_rate */
DES_REGION_ADDR(0x00718D84, 0x00719EE4)  /* hook des_hud_canvas */
DES_REGION_ADDR(0x0071A6B8, 0x0071B818)  /* call kDlgBaseUpdate */
DES_REGION_ADDR(0x0071B5A0, 0x0071C700)  /* call kFontSpacing */
DES_REGION_ADDR(0x0071B728, 0x0071C888)  /* call kFontBegin */
DES_REGION_ADDR(0x00720F20, 0x00722080)  /* code kGetMenuVarFn */
DES_REGION_ADDR(0x00720F50, 0x007220B0)  /* call */
DES_REGION_ADDR(0x00720F80, 0x007220E0)  /* call */
DES_REGION_ADDR(0x007212A8, 0x00722408)  /* call */
DES_REGION_ADDR(0x00721490, 0x007225F0)  /* call */
DES_REGION_ADDR(0x007216D0, 0x00722830)  /* call */
DES_REGION_ADDR(0x007216F0, 0x00722850)  /* call */
DES_REGION_ADDR(0x00723450, 0x007245B0)  /* call */
DES_REGION_ADDR(0x00723498, 0x007245F8)  /* call */
DES_REGION_ADDR(0x007234E0, 0x00724640)  /* code kPageSwitchFn */
DES_REGION_ADDR(0x00724AD0, 0x00725C30)  /* call */
DES_REGION_ADDR(0x00724E40, 0x00725FA0)  /* hook des_menu_tick */
DES_REGION_ADDR(0x0072D970, 0x0072EAD0)  /* call */
DES_REGION_ADDR(0x00736BB0, 0x00737D10)  /* code kEquipCloseFn */
DES_REGION_ADDR(0x007731F0, 0x00774350)  /* call */
DES_REGION_ADDR(0x00776C98, 0x00777E20)  /* code kGroupNoHookFn */
DES_REGION_ADDR(0x00776F68, 0x007780F0)  /* code kGroupPlaceFn */
DES_REGION_ADDR(0x00777C90, 0x00778E18)  /* code kGroupInputFn */
DES_REGION_ADDR(0x00778AB8, 0x00779C40)  /* code kMenuBusyFn */
DES_REGION_ADDR(0x007814F0, 0x00782678)  /* code kListPlaceFn */
DES_REGION_ADDR(0x00789BC0, 0x0078AD48)  /* call kGaugeUpdate */
DES_REGION_ADDR(0x0078E2E8, 0x0078F470)  /* call kSmoothGaugeUpdate */
DES_REGION_ADDR(0x0078EB60, 0x0078FCE8)  /* call kGaugeDraw */
DES_REGION_ADDR(0x0078EDC8, 0x0078FF50)  /* call kGaugeDraw */
DES_REGION_ADDR(0x0078F020, 0x007901A8)  /* call kGaugeDraw */
DES_REGION_ADDR(0x00798CD8, 0x00799E60)  /* call kScrollMsgUpdate */
DES_REGION_ADDR(0x0079EF7C, 0x007A0104)  /* hook des_hud_w2s */
DES_REGION_ADDR(0x007A6264, 0x007A73EC)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007A8C60, 0x007A9DE8)  /* call kGetSoulUpdate */
DES_REGION_ADDR(0x007ADB80, 0x007AED08)  /* call kShortcutUpdate */
DES_REGION_ADDR(0x007B5AE8, 0x007B6C70)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007B61D4, 0x007B735C)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007C8260, 0x007C93E8)  /* code kOptionCloseFn */
DES_REGION_ADDR(0x007CA320, 0x007CB4A8)  /* code kOptionPlaceFn */
DES_REGION_ADDR(0x007CA7E0, 0x007CB968)  /* code kOptionRightFn */
DES_REGION_ADDR(0x007CAA70, 0x007CBBF8)  /* code kOptionRowFn */
DES_REGION_ADDR(0x007CC598, 0x007CD720)  /* code kOptionUpFn */
DES_REGION_ADDR(0x007DC7A0, 0x007DD928)  /* call */
DES_REGION_ADDR(0x007E4248, 0x007E53D0)  /* call */
DES_REGION_ADDR(0x0081E110, 0x0081F298)  /* call kCmdChoice */
DES_REGION_ADDR(0x0081FA40, 0x00820BC8)  /* code kInvCloseFn */
DES_REGION_ADDR(0x00820DD0, 0x00821F58)  /* code kInvCategoryFn */
DES_REGION_ADDR(0x008219E0, 0x00822B68)  /* call kInvMessage */
DES_REGION_ADDR(0x0082A440, 0x0082B5C8)  /* code kStatusCloseFn */
DES_REGION_ADDR(0x00835E10, 0x00836F98)  /* code kDepositCategoryFn */
DES_REGION_ADDR(0x00839748, 0x0083A8D0)  /* code kTakeCategoryFn */
DES_REGION_ADDR(0x00841A90, 0x00842C18)  /* code kWorldCloseFn */
DES_REGION_ADDR(0x008725F8, 0x00873780)  /* code kShopCategoryFn */
DES_REGION_ADDR(0x00877980, 0x00878B08)  /* code kRepairCategoryFn */
DES_REGION_ADDR(0x008ABD18, 0x008ACEA0)  /* code kSystemCloseFn */
DES_REGION_ADDR(0x008AEB68, 0x008AFCF0)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x008CD078, 0x008CE200)  /* call kNowLoadingUpdate */
DES_REGION_ADDR(0x008DA0E0, 0x008DB268)  /* hook des_viewer_rate */
DES_REGION_ADDR(0x008DB170, 0x008DC2F8)  /* hook des_viewer_rate */
DES_REGION_ADDR(0x008EF430, 0x008F0380)  /* call kLogoUpdate */
DES_REGION_ADDR(0x008F2A58, 0x008F3F20)  /* call kBackPlateUpdate */
DES_REGION_ADDR(0x008F88D0, 0x008F9D98)  /* call kStorageMovable */
DES_REGION_ADDR(0x008FB4F0, 0x008FC9B8)  /* call */
DES_REGION_ADDR(0x008FD2A8, 0x008FE770)  /* call */
DES_REGION_ADDR(0x0090FCD0, 0x00911198)  /* call */
DES_REGION_ADDR(0x00923FD8, 0x009254A0)  /* call kStorageLimit */
DES_REGION_ADDR(0x00924BB8, 0x00926080)  /* call kStorageDeposit */
DES_REGION_ADDR(0x00924D58, 0x00926220)  /* call kStorageCount */
DES_REGION_ADDR(0x009E0148, 0x009E1610)  /* call */
DES_REGION_ADDR(0x00A36220, 0x00A376E8)  /* call */
DES_REGION_ADDR(0x00A6B2F8, 0x00A6C7C0)  /* hook des_coop_hook: the game's Lua reader (scripts edited for co-op) */
DES_REGION_ADDR(0x00A7CC60, 0x00A7E128)  /* hook + call des_luaheap: a new Lua state */
DES_REGION_ADDR(0x00A8B580, 0x00A8CA48)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8B770, 0x00A8CC38)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8B9D0, 0x00A8CE98)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8BCE0, 0x00A8D1A8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8BEA8, 0x00A8D370)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8CA48, 0x00A8DF10)  /* call */
DES_REGION_ADDR(0x00A8CBF0, 0x00A8E0B8)  /* call */
DES_REGION_ADDR(0x00A941F8, 0x00A956C0)  /* call */
DES_REGION_ADDR(0x00A9DD58, 0x00A9F220)  /* hook des_game_error */
DES_REGION_ADDR(0x00AC8078, 0x00AC9540)  /* boot patch (apply_boot_patches.py) */
DES_REGION_ADDR(0x00B495B8, 0x00B4AA80)  /* call */
DES_REGION_ADDR(0x00B5CFA0, 0x00B5E468)  /* call */
DES_REGION_ADDR(0x00B5D2F8, 0x00B5E7C0)  /* call */
DES_REGION_ADDR(0x00B5D548, 0x00B5EA10)  /* call */
DES_REGION_ADDR(0x00CA15A8, 0x00CA2A70)  /* hook des_coop_hook: Lua's string reader (scripts edited for co-op) */
DES_REGION_ADDR(0x00CBA408, 0x00CBB8D0)  /* code kLuaMemoryThrow */
DES_REGION_ADDR(0x00CD4854, 0x00CD5D1C)  /* hook des_hud_ctx */
DES_REGION_ADDR(0x00D229A4, 0x00D23E6C)  /* hook des_viewport_room */
DES_REGION_ADDR(0x00D67F80, 0x00D69448)  /* call */
DES_REGION_ADDR(0x00D68218, 0x00D696E0)  /* call */
DES_REGION_ADDR(0x00DFE110, 0x00DFF5D8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE2F0, 0x00DFF7B8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE768, 0x00DFFC30)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE9F8, 0x00DFFEC0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFF0D0, 0x00E00598)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E00D10, 0x00E021D8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2A098, 0x00E2B560)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2A9D8, 0x00E2BEA0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2B0B8, 0x00E2C580)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00F60BD0, 0x00F62008)  /* call kDialogDraw */
DES_REGION_ADDR(0x00F62E68, 0x00F642A0)  /* call */
DES_REGION_ADDR(0x00FF54D4, 0x00FF690C)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FF5680, 0x00FF6AB8)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FF58CC, 0x00FF6D04)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FFDFF8, 0x00FFF430)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x00FFEA68, 0x00FFFEA0)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x00FFFFE4, 0x0100141C)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x0100191C, 0x01002D54)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x01005978, 0x01006DB0)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x0109F2C4, 0x010A06FC)  /* hook des_body_xform */
DES_REGION_ADDR(0x011B1D6C, 0x011B31A4)  /* hook des_body_sampled */
DES_REGION_ADDR(0x012D86C4, 0x012D9AFC)  /* hook des_rag_pose_a */
DES_REGION_ADDR(0x012D9354, 0x012DA78C)  /* hook des_rag_pose_b */
DES_REGION_ADDR(0x013B75A8, 0x013B89E0)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B75D4, 0x013B8A0C)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7940, 0x013B8D78)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7B9C, 0x013B8FD4)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7CA4, 0x013B90DC)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7CCC, 0x013B9104)  /* hook des_fx_state */
DES_REGION_ADDR(0x01610188, 0x016115C0)  /* hook + call des_luaheap: a new Lua state (second TOC) */
DES_REGION_ADDR(0x0167AC58, 0x0167C090)  /* hook ds_free */
DES_REGION_ADDR(0x0167AC88, 0x0167C0C0)  /* hook ds_malloc */
DES_REGION_ADDR(0x016EBB98, 0x016ED0A0)  /* data kNoName */
DES_REGION_ADDR(0x0185A8B8, 0x0185A8B8)  /* data kEquipVt */
DES_REGION_ADDR(0x0185AF98, 0x0185AF98)  /* vtable */
DES_REGION_ADDR(0x01866068, 0x01866068)  /* data kEquipSlotsVt */
DES_REGION_ADDR(0x01866570, 0x01866570)  /* data kInvTabsVt */
DES_REGION_ADDR(0x01867F50, 0x01867F50)  /* data kCursorVt */
DES_REGION_ADDR(0x018692C0, 0x018692C0)  /* data kStartTabVt */
DES_REGION_ADDR(0x018697B0, 0x018697B0)  /* data kShortcutVt */
DES_REGION_ADDR(0x018698A0, 0x018698A0)  /* data kHudDialogVt */
DES_REGION_ADDR(0x01869FB8, 0x01869FB8)  /* data kPromptVt */
DES_REGION_ADDR(0x0186A398, 0x0186A398)  /* data kOptionVt */
DES_REGION_ADDR(0x0186A968, 0x0186A968)  /* data kTitleVt */
DES_REGION_ADDR(0x0186BE58, 0x0186BE58)  /* data kProfileVt */
DES_REGION_ADDR(0x0186C318, 0x0186C318)  /* data kInventoryVt */
DES_REGION_ADDR(0x0186C8A0, 0x0186C8A0)  /* data kDepositVt */
DES_REGION_ADDR(0x0186C9F8, 0x0186C9F8)  /* data kTakeVt */
DES_REGION_ADDR(0x0186DC08, 0x0186DC08)  /* data kShopVt */
DES_REGION_ADDR(0x0186DD88, 0x0186DD88)  /* data kRepairVt */
DES_REGION_ADDR(0x0186E1E0, 0x0186E1E0)  /* data kFadePlateVt */
DES_REGION_ADDR(0x0186EF60, 0x0186EF60)  /* data kSystemVt */
DES_REGION_ADDR(0x0186FBC0, 0x0186FBC0)  /* data kLoadingVt */
DES_REGION_ADDR(0x01870830, 0x01870830)  /* data kMenuTitleVt */
DES_REGION_ADDR(0x01870C30, 0x01870C18)  /* data kBackPlateVt */
DES_REGION_ADDR(0x018B4810, 0x018B47F8)  /* vtable */
DES_REGION_ADDR(0x018B4F98, 0x018B4F80)  /* vtable */
DES_REGION_ADDR(0x018C8DB4, 0x018C8BF8)  /* data kFrameDt */
DES_REGION_ADDR(0x018CEFB4, 0x018CEE0C)  /* data kCameraFov */
DES_REGION_ADDR(0x018CEFBC, 0x018CEE14)  /* data kCameraAspect */
DES_REGION_ADDR(0x018F96C0, 0x018F9698)  /* data kPreviewTurnStep */
DES_REGION_ADDR(0x0190433C, 0x0190430C)  /* data kContextAspect */
DES_REGION_ADDR(0x019AD3B0, 0x019AD3C4)  /* data kSoulsConsts, a slot of the TOC */
DES_REGION_ADDR(0x019AD4FC, 0x019AD510)  /* data kGameSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD560, 0x019AD574)  /* data kChrInsConsts, a slot of the TOC */
DES_REGION_ADDR(0x019AD694, 0x019AD6A8)  /* data kSignSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD7B4, 0x019AD7C8)  /* data kWorldSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD7BC, 0x019AD7D0)  /* data kDevConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADD50, 0x019ADD64)  /* data kMenusConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADE38, 0x019ADE4C)  /* data kScrollConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADF0C, 0x019ADF20)  /* data kMenuManConsts, a slot of the TOC */
DES_REGION_ADDR(0x019B5040, 0x019B5058)  /* data kToc, the TOC base (r2) */
DES_REGION_ADDR(0x019D8C88, 0x019D8D08)  /* data kLanguageIndex */
DES_REGION_ADDR(0x01AD6298, 0x01AD62C8)  /* data kFlipModeObj */
DES_REGION_ADDR(0x01AD62C8, 0x01AD62F8)  /* data kStepHeap */
DES_REGION_ADDR(0x01AD6358, 0x01AD6388)  /* data kLocalBase */
DES_REGION_ADDR(0x01AD6498, 0x01AD64C8)  /* data kArenaDebug */
DES_REGION_ADDR(0x01AD6530, 0x01AD6560)  /* data kArenaTemp */
DES_REGION_ADDR(0x01AD65B0, 0x01AD65E0)  /* data kArenaCoreRes */
DES_REGION_ADDR(0x01AD6638, 0x01AD6668)  /* data kArenaLua */
DES_REGION_ADDR(0x01AD66C0, 0x01AD66F0)  /* data kArenaNetwork */
DES_REGION_ADDR(0x01AD6748, 0x01AD6778)  /* data kArenaServer */
DES_REGION_ADDR(0x01AD67D0, 0x01AD6800)  /* data kArenaMenu */
DES_REGION_ADDR(0x01AD6858, 0x01AD6888)  /* data kArenaFfx */
DES_REGION_ADDR(0x01AD68E0, 0x01AD6910)  /* data kArenaMo */
DES_REGION_ADDR(0x01AD6960, 0x01AD6990)  /* data kArenaHavok */
DES_REGION_ADDR(0x01AD69E0, 0x01AD6A10)  /* data kArenaHgsys */
DES_REGION_ADDR(0x01AD6A68, 0x01AD6A98)  /* data kArenaIngame */
DES_REGION_ADDR(0x01AD6AF0, 0x01AD6B20)  /* data kArenaMain */
DES_REGION_ADDR(0x01B387B8, 0x01B387E8)  /* data kStepMan */
DES_REGION_ADDR(0x01B3A28C, 0x01B3A2BC)  /* data kRemoMan */
DES_REGION_ADDR(0x01B3D6E0, 0x01B3D710)  /* data kChrMan */
DES_REGION_ADDR(0x01B42A80, 0x01B42AB0)  /* data kLuaSystemA */
DES_REGION_ADDR(0x01B49BD8, 0x01B49C60)  /* data kLuaSystemB */
DES_REGION_ADDR(0x01B4B150, 0x01B4B1D8)  /* data kMenuSeMgr */
DES_REGION_ADDR(0x01B4EF9C, 0x01B4F02C)  /* data kPgdRoot */
