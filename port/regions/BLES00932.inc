/* BLES00932, the European disc (01.00): its address for every BLUS30443 address the port
 * uses (des_region.h). Sorted by the US address; one line per address.
 * tools/region/region_table.py checks that every address in the port is here (CI), and
 * finds and checks the European address from both decrypted EBOOTs. */
DES_REGION_ADDR(0x000112E8, 0x000112E8)  /* hook des_body_sample */
DES_REGION_ADDR(0x00011720, 0x00011720)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00011768, 0x00011768)  /* hook des_kf_target */
DES_REGION_ADDR(0x00013874, 0x0001473C)  /* data kOnlineTagCases */
DES_REGION_ADDR(0x00023750, 0x00024338)  /* call */
DES_REGION_ADDR(0x00039210, 0x00039DF8)  /* hook + call des_luaheap: Lua's heap, alloc */
DES_REGION_ADDR(0x00039540, 0x0003A128)  /* hook + call des_luaheap: Lua's heap, block size */
DES_REGION_ADDR(0x00039790, 0x0003A378)  /* hook + call des_luaheap: Lua's heap, realloc */
DES_REGION_ADDR(0x00039870, 0x0003A458)  /* hook + call des_luaheap: Lua's heap, owns block */
DES_REGION_ADDR(0x00039940, 0x0003A528)  /* hook + call des_luaheap: Lua's heap, free */
DES_REGION_ADDR(0x00039A10, 0x0003A5F8)  /* hook + call des_luaheap: Lua's heap, alloc */
DES_REGION_ADDR(0x00039AE0, 0x0003A6C8)  /* hook + call des_luaheap: Lua's heap, free */
DES_REGION_ADDR(0x00039BB0, 0x0003A798)  /* hook + call des_luaheap: Lua's heap, realloc */
DES_REGION_ADDR(0x00039D50, 0x0003A938)  /* hook + call des_luaheap: Lua's heap, alloc aligned */
DES_REGION_ADDR(0x00039E30, 0x0003AA18)  /* hook + call des_luaheap: Lua's heap, realloc aligned */
DES_REGION_ADDR(0x00039F20, 0x0003AB08)  /* hook + call des_luaheap: Lua's heap, realloc aligned */
DES_REGION_ADDR(0x0003A0D8, 0x0003ACC0)  /* hook + call des_luaheap: Lua's heap, alloc aligned */
DES_REGION_ADDR(0x0003C758, 0x0003D340)  /* hook + call des_luaheap: Lua's small heap, free */
DES_REGION_ADDR(0x0003C9A8, 0x0003D590)  /* hook + call des_luaheap: Lua's small heap, realloc aligned */
DES_REGION_ADDR(0x0003CA98, 0x0003D680)  /* hook + call des_luaheap: Lua's small heap, alloc aligned */
DES_REGION_ADDR(0x0003CB78, 0x0003D760)  /* hook + call des_luaheap: Lua's small heap, block size */
DES_REGION_ADDR(0x0003CC48, 0x0003D830)  /* hook + call des_luaheap: Lua's small heap, owns block */
DES_REGION_ADDR(0x0003CDF8, 0x0003D9E0)  /* hook + call des_luaheap: Lua's small heap, realloc aligned */
DES_REGION_ADDR(0x0003CEE8, 0x0003DAD0)  /* hook + call des_luaheap: Lua's small heap, alloc aligned */
DES_REGION_ADDR(0x0003D208, 0x0003DDF0)  /* hook + call des_luaheap: Lua's small heap, realloc */
DES_REGION_ADDR(0x0003D2E8, 0x0003DED0)  /* hook + call des_luaheap: Lua's small heap, free */
DES_REGION_ADDR(0x0003D478, 0x0003E060)  /* hook + call des_luaheap: Lua's small heap, alloc */
DES_REGION_ADDR(0x0003D548, 0x0003E130)  /* hook + call des_luaheap: Lua's small heap, alloc */
DES_REGION_ADDR(0x0003D618, 0x0003E200)  /* hook + call des_luaheap: Lua's small heap, realloc */
DES_REGION_ADDR(0x0006C860, 0x0006D648)  /* hook des_coop_hook: the ghost colour upload returned (the material put back) */
DES_REGION_ADDR(0x00080E88, 0x00081C70)  /* hook des_coop_hook: the ghost colour upload starting (a player's own glow colour) */
DES_REGION_ADDR(0x000B14C8, 0x000B22B0)  /* call kSpacingPlay */
DES_REGION_ADDR(0x000B15C8, 0x000B23B0)  /* call kFontPlay */
DES_REGION_ADDR(0x000D5B24, 0x000D6B0C)  /* hook des_cam_own */
DES_REGION_ADDR(0x000E9650, 0x000EA638)  /* hook des_coop_hook: the ghost model draw (a player's own glow colour) */
DES_REGION_ADDR(0x00110608, 0x001115D0)  /* hook des_mouse_look */
DES_REGION_ADDR(0x001107C0, 0x00111788)  /* hook des_cam_step */
DES_REGION_ADDR(0x00119670, 0x0011A638)  /* hook des_mouse_look */
DES_REGION_ADDR(0x00119818, 0x0011A7E0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x001198D8, 0x0011A8A0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00119FAC, 0x0011AF74)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011A018, 0x0011AFE0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011A100, 0x0011B0C8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011B830, 0x0011C7F8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C0E8, 0x0011D0B0)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C15C, 0x0011D124)  /* hook des_cam_keep */
DES_REGION_ADDR(0x0011C2BC, 0x0011D284)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011C758, 0x0011D720)  /* hook des_mouse_look */
DES_REGION_ADDR(0x0011C910, 0x0011D8D8)  /* hook des_mouse_look */
DES_REGION_ADDR(0x0011CF84, 0x0011DF4C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011CF98, 0x0011DF60)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D2D4, 0x0011E29C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D6E4, 0x0011E6AC)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0011D820, 0x0011E7E8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00123100, 0x001240C8)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00123164, 0x0012412C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x00124188, 0x00125150)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0012554C, 0x00126514)  /* hook des_cam_rate */
DES_REGION_ADDR(0x001256D4, 0x0012669C)  /* hook des_cam_rate */
DES_REGION_ADDR(0x0012EE08, 0x0012FDD0)  /* call, wrapped (des_aspect) */
DES_REGION_ADDR(0x0012F074, 0x0013003C)  /* hook des_cam_ctor */
DES_REGION_ADDR(0x0012F0DC, 0x001300A4)  /* hook des_cam_ctor */
DES_REGION_ADDR(0x0012F19C, 0x00130164)  /* hook des_frustum_tall */
DES_REGION_ADDR(0x001381E8, 0x001391B0)  /* call */
DES_REGION_ADDR(0x0015AE10, 0x0015BDD8)  /* call kLoadSouls */
DES_REGION_ADDR(0x00162D0C, 0x00163BDC)  /* data kGameParamCases */
DES_REGION_ADDR(0x0017A4A8, 0x0017B390)  /* hook des_coop_hook: the summoned reload's load step */
DES_REGION_ADDR(0x0017B258, 0x0017C468)  /* call */
DES_REGION_ADDR(0x00196158, 0x00196FE0)  /* call */
DES_REGION_ADDR(0x001D17A0, 0x001D2628)  /* call */
DES_REGION_ADDR(0x001D1E64, 0x001D2CEC)  /* hook des_phys_rate */
DES_REGION_ADDR(0x001D35D8, 0x001D4460)  /* call */
DES_REGION_ADDR(0x001DF83C, 0x001E06C4)  /* hook des_phys_kf */
DES_REGION_ADDR(0x001EF6D0, 0x001F0558)  /* hook des_phys_kf */
DES_REGION_ADDR(0x001FEAF4, 0x001FF97C)  /* hook des_slide_rate */
DES_REGION_ADDR(0x001FED50, 0x001FFBD8)  /* hook des_slide_rate */
DES_REGION_ADDR(0x0020D3C0, 0x0020E248)  /* call des_seamless_game (by address): Tutorial_end's */
DES_REGION_ADDR(0x0020E788, 0x0020F610)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002107B8, 0x00211640)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00217E70, 0x00218CF8)  /* hook des_motion_blur */
DES_REGION_ADDR(0x002184DC, 0x00219364)  /* hook des_dof */
DES_REGION_ADDR(0x00226778, 0x00227608)  /* call */
DES_REGION_ADDR(0x0025C5EC, 0x0025D494)  /* call des_coop_hook: the area items' remove, its taken flag's set (a friend keeps its pickups) */
DES_REGION_ADDR(0x0025CB6C, 0x0025DA14)  /* hook des_coop_hook: the area items' add after lwz r9,0x8C(r9) (a friend gets the items too) */
DES_REGION_ADDR(0x0025CC34, 0x0025DADC)  /* hook des_coop_hook: the area items' add after bl 0x005087C8 (a friend's own taken flags) */
DES_REGION_ADDR(0x0025EB88, 0x0025FA30)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0025EC14, 0x0025FABC)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0026558C, 0x00266434)  /* hook des_fade_rate */
DES_REGION_ADDR(0x00265C88, 0x00266B30)  /* hook des_fade_rate */
DES_REGION_ADDR(0x0026FB20, 0x002709C8)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0026FC48, 0x00270AF0)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0026FC98, 0x00270B40)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00272A88, 0x00273930)  /* hook des_coop_hook: an enemy's souls, the guest test (a friend's full souls) */
DES_REGION_ADDR(0x00272C28, 0x00273AD0)  /* call des_dev (by address): the scripts' kill */
DES_REGION_ADDR(0x00273620, 0x002744C8)  /* call */
DES_REGION_ADDR(0x002737A0, 0x00274648)  /* call */
DES_REGION_ADDR(0x00273BE0, 0x00274A88)  /* call */
DES_REGION_ADDR(0x00273D38, 0x00274BE0)  /* hook des_move_post */
DES_REGION_ADDR(0x00273D4C, 0x00274BF4)  /* return address in 0x00273D38 */
DES_REGION_ADDR(0x0027882C, 0x002796D4)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002802E0, 0x00281188)  /* call */
DES_REGION_ADDR(0x00280724, 0x002815CC)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280C78, 0x00281B20)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280E64, 0x00281D0C)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00280F88, 0x00281E30)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002818D0, 0x00282778)  /* hook des_dev_hook */
DES_REGION_ADDR(0x00286614, 0x002873EC)  /* hook des_dev_hook */
DES_REGION_ADDR(0x0028B224, 0x0028BFFC)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002977C0, 0x00298598)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002986B8, 0x00299488)  /* call */
DES_REGION_ADDR(0x00299B74, 0x0029A944)  /* hook des_coop_hook: an NPC's setup after lbz r0,0xE8(r9) (a friend notes the NPCs it sets up as the host's) */
DES_REGION_ADDR(0x00299BB0, 0x0029A980)  /* hook des_coop_hook: an NPC's setup after mr r23,r3, its new character (the same) */
DES_REGION_ADDR(0x0029EC08, 0x0029F9D8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002A6AA8, 0x002A7880)  /* wrapped kChrInsThread */
DES_REGION_ADDR(0x002A6AF4, 0x002A78CC)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B14, 0x002A78EC)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B24, 0x002A78FC)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B34, 0x002A790C)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B50, 0x002A7928)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B60, 0x002A7938)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B7C, 0x002A7954)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6B98, 0x002A7970)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BA0, 0x002A7978)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BB0, 0x002A7988)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BD0, 0x002A79A8)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BEC, 0x002A79C4)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6BF8, 0x002A79D0)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C34, 0x002A7A0C)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C58, 0x002A7A30)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C60, 0x002A7A38)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6C70, 0x002A7A48)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002A6CA8, 0x002A7A80)  /* return address in 0x002A6AA8 */
DES_REGION_ADDR(0x002B2984, 0x002B375C)  /* hook des_coop_hook: a corpse's drop add after lwz r9,0x8C(r9) (a friend gets drops too) */
DES_REGION_ADDR(0x002C9600, 0x002CA3D8)  /* hook des_coop_hook: message 0x26's read (an area character's place, from the host), held after a load */
DES_REGION_ADDR(0x002C96A8, 0x002CA480)  /* hook des_coop_hook: message 0x26's read in its loop (the same) */
DES_REGION_ADDR(0x002C9740, 0x002CA518)  /* hook des_coop_hook: message 4's read (the area characters' states, from the host), held after a load */
DES_REGION_ADDR(0x002C98C4, 0x002CA69C)  /* hook des_coop_hook: message 0x21's read (the area characters' states, from a member), held after a load */
DES_REGION_ADDR(0x002C9AEC, 0x002CA8C4)  /* hook des_coop_hook: message 3's read (the area characters' places, from a member), held after a load */
DES_REGION_ADDR(0x002D0EB0, 0x002D1C88)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x002D8978, 0x002D9750)  /* call */
DES_REGION_ADDR(0x002DD368, 0x002DE140)  /* call kUseGoods */
DES_REGION_ADDR(0x002DDAA8, 0x002DE880)  /* hook des_coop_hook: a character's draw update (a friend's own phantom glow) */
DES_REGION_ADDR(0x002DDADC, 0x002DE8B4)  /* hook des_coop_hook: a character's draw update, the material kind's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002DDB48, 0x002DE920)  /* hook des_coop_hook: a character's draw update, the draw path's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002DDB90, 0x002DE968)  /* hook des_coop_hook: a character's draw update, 0x0025D418's type read (a friend draws an NPC of type 4 as the host does) */
DES_REGION_ADDR(0x002E1000, 0x002E1DD8)  /* hook des_coop_hook: a character's draw objects' build, the face's type read (a friend's NPCs of type 4 get their faces) */
DES_REGION_ADDR(0x002EC2B8, 0x002ED090)  /* call */
DES_REGION_ADDR(0x002EDEB0, 0x002EEC88)  /* hook des_dev_hook */
DES_REGION_ADDR(0x002F5B14, 0x002F68EC)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002F5CCC, 0x002F6AA4)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002F5DB8, 0x002F6B90)  /* hook des_ik_rate */
DES_REGION_ADDR(0x002FF8F0, 0x003006C8)  /* hook des_roll_dir */
DES_REGION_ADDR(0x00300BAC, 0x00301984)  /* hook des_kick */
DES_REGION_ADDR(0x00301C24, 0x003029FC)  /* hook des_roll_dir */
DES_REGION_ADDR(0x0030C330, 0x0030D108)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030C378, 0x0030D150)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030C46C, 0x0030D244)  /* hook des_net_sync */
DES_REGION_ADDR(0x0030F2BC, 0x00310094)  /* hook des_roll_tie */
DES_REGION_ADDR(0x0030F734, 0x0031050C)  /* hook des_roll_dir */
DES_REGION_ADDR(0x00310AA8, 0x00311880)  /* hook des_kick */
DES_REGION_ADDR(0x00313B24, 0x003148FC)  /* hook des_net_sync */
DES_REGION_ADDR(0x003147EC, 0x003155C4)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x00314ABC, 0x00315894)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x00315030, 0x00315E08)  /* hook des_ghost_rate */
DES_REGION_ADDR(0x0036CBD0, 0x0036D980)  /* pickup hook des_dev_hook: node key written before counter increment */
DES_REGION_ADDR(0x0036CBD4, 0x0036D984)  /* pickup hook des_dev_hook: counter increment after node key */
DES_REGION_ADDR(0x0036CDB8, 0x0036DA68)  /* pickup hook des_dev_hook: reinsertion helper entry */
DES_REGION_ADDR(0x0036CE34, 0x0036DBE4)  /* pickup hook des_dev_hook: post-call node return */
DES_REGION_ADDR(0x0036CE44, 0x0036DBF4)  /* pickup hook des_dev_hook: manager-root comparison */
DES_REGION_ADDR(0x0036CE4C, 0x0036DBFC)  /* pickup hook des_dev_hook: returned-node comparison */
DES_REGION_ADDR(0x0036D0D8, 0x0036DE88)  /* pickup hook des_dev_hook: native reinsertion */
DES_REGION_ADDR(0x0036D3BC, 0x0036E16C)  /* pickup hook des_dev_hook: reinsertion helper return */
DES_REGION_ADDR(0x0036D600, 0x0036E3B0)  /* pickup hook des_dev_hook: acquisition entry LR */
DES_REGION_ADDR(0x0036D678, 0x0036E428)  /* pickup hook des_dev_hook: add result */
DES_REGION_ADDR(0x0036D7FC, 0x0036E5AC)  /* pickup hook des_dev_hook: copied record */
DES_REGION_ADDR(0x0036D9A4, 0x0036E754)  /* pickup hook des_dev_hook: local lookup before unlink BL */
DES_REGION_ADDR(0x0036DE00, 0x0036EBB0)  /* pickup hook des_dev_hook: event lookup before unlink BL */
DES_REGION_ADDR(0x00391818, 0x003925E0)  /* hook des_net_replay */
DES_REGION_ADDR(0x003957B8, 0x00396580)  /* hook des_net_replay */
DES_REGION_ADDR(0x003A596C, 0x003A6734)  /* hook des_net_replay */
DES_REGION_ADDR(0x003A5CA8, 0x003A6A70)  /* hook des_net_show */
DES_REGION_ADDR(0x003A5EA0, 0x003A6C68)  /* hook des_net_replay */
DES_REGION_ADDR(0x003D42BC, 0x003D509C)  /* hook des_twist_rate */
DES_REGION_ADDR(0x003DBA18, 0x003DC7F8)  /* call */
DES_REGION_ADDR(0x003DBBB0, 0x003DC990)  /* call */
DES_REGION_ADDR(0x003E2DF0, 0x003E3BD0)  /* hook des_sun_gate */
DES_REGION_ADDR(0x003E6330, 0x003E7110)  /* hook des_sun_gate */
DES_REGION_ADDR(0x003E6518, 0x003E72F8)  /* hook des_sun_gate */
DES_REGION_ADDR(0x004117E4, 0x004125D4)  /* hook des_coop_hook: after RecvGlobalQwc's online blend (a friend plays in the host's world tendency) */
DES_REGION_ADDR(0x00419670, 0x0041A460)  /* call des_seamless_game (by address): the own bloodstain shown (ParamInitialize's type 0 path) */
DES_REGION_ADDR(0x00419DCC, 0x0041ABBC)  /* hook des_coop_hook: after a load's world swap of the flags (a guest's own world kept) */
DES_REGION_ADDR(0x00439358, 0x0043A140)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0043E4E0, 0x0043F2C8)  /* hook + call des_coop_hook, des_seamless_game: SetTextEffect (a friend's revival after its "The Demon Was Destroyed") */
DES_REGION_ADDR(0x0043EDE0, 0x0043FBC8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x004418B8, 0x004426A0)  /* call */
DES_REGION_ADDR(0x00441AB8, 0x004428A0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00443838, 0x00444620)  /* call */
DES_REGION_ADDR(0x00445F30, 0x00446D18)  /* call des_seamless_game (by address): SetChrType */
DES_REGION_ADDR(0x00446C68, 0x00447A50)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00447258, 0x00448040)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00447EA0, 0x00448C88)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044A368, 0x0044B150)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044A5E4, 0x0044B3CC)  /* hook des_coop_hook: SetClearBonus, the session's member count (everyone's full boss souls) */
DES_REGION_ADDR(0x0044C6F0, 0x0044D4D8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0044C780, 0x0044D568)  /* hook des_coop_hook: the end of WarpNextStageKick (a guest going home loads its own area) */
DES_REGION_ADDR(0x00451430, 0x00452218)  /* call */
DES_REGION_ADDR(0x00467628, 0x00468410)  /* hook des_coop_hook: a script event's name */
DES_REGION_ADDR(0x004C6DF0, 0x004C7BD8)  /* pickup hook des_dev_hook: native add entry */
DES_REGION_ADDR(0x004C733C, 0x004C8124)  /* pickup hook des_dev_hook: inventory result field */
DES_REGION_ADDR(0x004C74F0, 0x004C82D8)  /* pickup hook des_dev_hook: native -1 comparison */
DES_REGION_ADDR(0x004C9638, 0x004CA420)  /* hook des_coop_hook: the talk check after bl 0x0026F378 (a friend can talk to the NPCs) */
DES_REGION_ADDR(0x004C9C5C, 0x004CAA44)  /* hook des_coop_hook: the talk check after bl 0x0026F378 (a friend can talk to the NPCs) */
DES_REGION_ADDR(0x005086F8, 0x005094F0)  /* hook des_coop_hook: the event flags' set (progress kept for every player) */
DES_REGION_ADDR(0x00508820, 0x00509618)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00508C00, 0x005099F8)  /* hook des_coop_hook: a guest's join fills its flag copies (its own world's flags kept) */
DES_REGION_ADDR(0x0052C2D8, 0x0052D0D0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00532108, 0x00532F00)  /* call des_seamless_game (by address): a member's P2P message read */
DES_REGION_ADDR(0x00532358, 0x00533148)  /* call des_seamless_game (by address): the host's P2P message read */
DES_REGION_ADDR(0x0053B31C, 0x0053C10C)  /* hook des_coop_hook: the session's leave */
DES_REGION_ADDR(0x0053CFE8, 0x0053DDD8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x0053E368, 0x0053F158)  /* hook des_coop_hook: the session event dispatch's member-left case (a leave during a load taken at once) */
DES_REGION_ADDR(0x0053EA2C, 0x0053F81C)  /* hook des_coop_hook: the session's check of a joined guest (a friend joins in either form) */
DES_REGION_ADDR(0x00540D90, 0x00541B80)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00541B78, 0x00542968)  /* call des_seamless_game (by address): a connection's P2P message read */
DES_REGION_ADDR(0x0054E8C0, 0x0054F6B0)  /* hook des_net_show */
DES_REGION_ADDR(0x0054E8F8, 0x0054F6E8)  /* hook des_net_show */
DES_REGION_ADDR(0x0054E934, 0x0054F724)  /* hook des_net_grade_poll */
DES_REGION_ADDR(0x00558884, 0x00559674)  /* hook des_net_show */
DES_REGION_ADDR(0x00560904, 0x005616F4)  /* hook des_net_show */
DES_REGION_ADDR(0x00562BC4, 0x005639B4)  /* hook des_net_show */
DES_REGION_ADDR(0x00567E9C, 0x00568C8C)  /* hook des_qwc_local */
DES_REGION_ADDR(0x00595B80, 0x00596970)  /* call */
DES_REGION_ADDR(0x00597108, 0x00597EF8)  /* call */
DES_REGION_ADDR(0x00597388, 0x00598178)  /* call */
DES_REGION_ADDR(0x0059E3A8, 0x0059F198)  /* call */
DES_REGION_ADDR(0x005A5920, 0x005A6710)  /* call */
DES_REGION_ADDR(0x005C2810, 0x005C3600)  /* call */
DES_REGION_ADDR(0x005C2848, 0x005C3638)  /* call */
DES_REGION_ADDR(0x005F7254, 0x005F7E9C)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F72EC, 0x005F7F34)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F7394, 0x005F7FDC)  /* hook des_cut_cam */
DES_REGION_ADDR(0x005F743C, 0x005F8084)  /* hook des_cut_cam */
DES_REGION_ADDR(0x00609338, 0x00609F80)  /* hook des_coop_hook: a cutscene's copy of a character set up (its glow and colour) */
DES_REGION_ADDR(0x006A2E8C, 0x006A3A9C)  /* hook des_noise_rate */
DES_REGION_ADDR(0x006A3990, 0x006A45A0)  /* hook des_noise_rate */
DES_REGION_ADDR(0x00718D84, 0x00719994)  /* hook des_hud_canvas */
DES_REGION_ADDR(0x0071A6B8, 0x0071B2C8)  /* call kDlgBaseUpdate */
DES_REGION_ADDR(0x0071B5A0, 0x0071C1B0)  /* call kFontSpacing */
DES_REGION_ADDR(0x0071B728, 0x0071C338)  /* call kFontBegin */
DES_REGION_ADDR(0x00720F20, 0x00721B30)  /* code kGetMenuVarFn */
DES_REGION_ADDR(0x00720F50, 0x00721B60)  /* call */
DES_REGION_ADDR(0x00720F80, 0x00721B90)  /* call */
DES_REGION_ADDR(0x007212A8, 0x00721EB8)  /* call */
DES_REGION_ADDR(0x00721490, 0x007220A0)  /* call */
DES_REGION_ADDR(0x007216D0, 0x007222E0)  /* call */
DES_REGION_ADDR(0x007216F0, 0x00722300)  /* call */
DES_REGION_ADDR(0x00723450, 0x00723F90)  /* call */
DES_REGION_ADDR(0x00723498, 0x00723FD8)  /* call */
DES_REGION_ADDR(0x007234E0, 0x00724020)  /* code kPageSwitchFn */
DES_REGION_ADDR(0x00724AD0, 0x00725620)  /* call */
DES_REGION_ADDR(0x00724E40, 0x00725990)  /* hook des_menu_tick */
DES_REGION_ADDR(0x0072D970, 0x0072F1B8)  /* call */
DES_REGION_ADDR(0x00736BB0, 0x00738438)  /* code kEquipCloseFn */
DES_REGION_ADDR(0x007731F0, 0x00774A78)  /* call */
DES_REGION_ADDR(0x00776C98, 0x00778520)  /* code kGroupNoHookFn */
DES_REGION_ADDR(0x00776F68, 0x007787F0)  /* code kGroupPlaceFn */
DES_REGION_ADDR(0x00777C90, 0x00779518)  /* code kGroupInputFn */
DES_REGION_ADDR(0x00778AB8, 0x0077A340)  /* code kMenuBusyFn */
DES_REGION_ADDR(0x007814F0, 0x00782D78)  /* code kListPlaceFn */
DES_REGION_ADDR(0x00789BC0, 0x0078B448)  /* call kGaugeUpdate */
DES_REGION_ADDR(0x0078E2E8, 0x0078FB70)  /* call kSmoothGaugeUpdate */
DES_REGION_ADDR(0x0078EB60, 0x007903E8)  /* call kGaugeDraw */
DES_REGION_ADDR(0x0078EDC8, 0x00790650)  /* call kGaugeDraw */
DES_REGION_ADDR(0x0078F020, 0x007908A8)  /* call kGaugeDraw */
DES_REGION_ADDR(0x00798CD8, 0x0079A560)  /* call kScrollMsgUpdate */
DES_REGION_ADDR(0x0079EF7C, 0x007A0804)  /* hook des_hud_w2s */
DES_REGION_ADDR(0x007A6264, 0x007A7AEC)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007A8C60, 0x007AA4E8)  /* call kGetSoulUpdate */
DES_REGION_ADDR(0x007ADB80, 0x007AF408)  /* call kShortcutUpdate */
DES_REGION_ADDR(0x007B5AE8, 0x007B7370)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007B61D4, 0x007B7A5C)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x007C8260, 0x007C9AE8)  /* code kOptionCloseFn */
DES_REGION_ADDR(0x007CA320, 0x007CBBA8)  /* code kOptionPlaceFn */
DES_REGION_ADDR(0x007CA7E0, 0x007CC068)  /* code kOptionRightFn */
DES_REGION_ADDR(0x007CAA70, 0x007CC2F8)  /* code kOptionRowFn */
DES_REGION_ADDR(0x007CC598, 0x007CDE20)  /* code kOptionUpFn */
DES_REGION_ADDR(0x007DC7A0, 0x007DE028)  /* call */
DES_REGION_ADDR(0x007E4248, 0x007E5AD0)  /* call */
DES_REGION_ADDR(0x0081E110, 0x0081F9E0)  /* call kCmdChoice */
DES_REGION_ADDR(0x0081FA40, 0x00821310)  /* code kInvCloseFn */
DES_REGION_ADDR(0x00820DD0, 0x008226A0)  /* code kInvCategoryFn */
DES_REGION_ADDR(0x008219E0, 0x008232B0)  /* call kInvMessage */
DES_REGION_ADDR(0x0082A440, 0x0082BD10)  /* code kStatusCloseFn */
DES_REGION_ADDR(0x00835E10, 0x008376E0)  /* code kDepositCategoryFn */
DES_REGION_ADDR(0x00839748, 0x0083B018)  /* code kTakeCategoryFn */
DES_REGION_ADDR(0x00841A90, 0x00843360)  /* code kWorldCloseFn */
DES_REGION_ADDR(0x008725F8, 0x00873ED0)  /* code kShopCategoryFn */
DES_REGION_ADDR(0x00877980, 0x00879258)  /* code kRepairCategoryFn */
DES_REGION_ADDR(0x008ABD18, 0x008AD5F0)  /* code kSystemCloseFn */
DES_REGION_ADDR(0x008AEB68, 0x008B0440)  /* hook des_hud_onscreen */
DES_REGION_ADDR(0x008CD078, 0x008CE950)  /* call kNowLoadingUpdate */
DES_REGION_ADDR(0x008DA0E0, 0x008DB9B8)  /* hook des_viewer_rate */
DES_REGION_ADDR(0x008DB170, 0x008DCA48)  /* hook des_viewer_rate */
DES_REGION_ADDR(0x008EF430, 0x008F0DE0)  /* call kLogoUpdate */
DES_REGION_ADDR(0x008F2A58, 0x008F44D0)  /* call kBackPlateUpdate */
DES_REGION_ADDR(0x008F88D0, 0x008FA348)  /* call kStorageMovable */
DES_REGION_ADDR(0x008FB4F0, 0x008FCF68)  /* call */
DES_REGION_ADDR(0x008FD2A8, 0x008FED20)  /* call */
DES_REGION_ADDR(0x0090FCD0, 0x00911748)  /* call */
DES_REGION_ADDR(0x00923FD8, 0x00925A50)  /* call kStorageLimit */
DES_REGION_ADDR(0x00924BB8, 0x00926630)  /* call kStorageDeposit */
DES_REGION_ADDR(0x00924D58, 0x009267D0)  /* call kStorageCount */
DES_REGION_ADDR(0x009E0148, 0x009E1BC0)  /* call */
DES_REGION_ADDR(0x00A36220, 0x00A37C98)  /* call */
DES_REGION_ADDR(0x00A6B2F8, 0x00A6CD70)  /* hook des_coop_hook: the game's Lua reader (scripts edited for co-op) */
DES_REGION_ADDR(0x00A7CC60, 0x00A7E6D8)  /* hook + call des_luaheap: a new Lua state */
DES_REGION_ADDR(0x00A8B580, 0x00A8CFF8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8B770, 0x00A8D1E8)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8B9D0, 0x00A8D448)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8BCE0, 0x00A8D758)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8BEA8, 0x00A8D920)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00A8CA48, 0x00A8E4C0)  /* call */
DES_REGION_ADDR(0x00A8CBF0, 0x00A8E668)  /* call */
DES_REGION_ADDR(0x00A941F8, 0x00A95C70)  /* call */
DES_REGION_ADDR(0x00A9DD58, 0x00A9F7D0)  /* hook des_game_error */
DES_REGION_ADDR(0x00AC8078, 0x00AC9AF0)  /* boot patch (apply_boot_patches.py) */
DES_REGION_ADDR(0x00B495B8, 0x00B4B030)  /* call */
DES_REGION_ADDR(0x00B5CFA0, 0x00B5EA18)  /* call */
DES_REGION_ADDR(0x00B5D2F8, 0x00B5ED70)  /* call */
DES_REGION_ADDR(0x00B5D548, 0x00B5EFC0)  /* call */
DES_REGION_ADDR(0x00CA15A8, 0x00CA3020)  /* hook des_coop_hook: Lua's string reader (scripts edited for co-op) */
DES_REGION_ADDR(0x00CBA408, 0x00CBBE80)  /* code kLuaMemoryThrow */
DES_REGION_ADDR(0x00CD4854, 0x00CD62CC)  /* hook des_hud_ctx */
DES_REGION_ADDR(0x00D229A4, 0x00D2441C)  /* hook des_viewport_room */
DES_REGION_ADDR(0x00D67F80, 0x00D699F8)  /* call */
DES_REGION_ADDR(0x00D68218, 0x00D69C90)  /* call */
DES_REGION_ADDR(0x00DFE110, 0x00DFFB88)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE2F0, 0x00DFFD68)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE768, 0x00E001E0)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFE9F8, 0x00E00470)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00DFF0D0, 0x00E00B48)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E00D10, 0x00E02788)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2A098, 0x00E2BB10)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2A9D8, 0x00E2C450)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00E2B0B8, 0x00E2CB30)  /* call des_seamless_game (by address) */
DES_REGION_ADDR(0x00F60BD0, 0x00F62648)  /* call kDialogDraw */
DES_REGION_ADDR(0x00F62E68, 0x00F648E0)  /* call */
DES_REGION_ADDR(0x00FF54D4, 0x00FF6F4C)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FF5680, 0x00FF70F8)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FF58CC, 0x00FF7344)  /* hook des_ik_rate */
DES_REGION_ADDR(0x00FFDFF8, 0x00FFFA70)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x00FFEA68, 0x010004E0)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x00FFFFE4, 0x01001A5C)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x0100191C, 0x01003394)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x01005978, 0x010073F0)  /* hook des_refpose_rate */
DES_REGION_ADDR(0x0109F2C4, 0x010A0D3C)  /* hook des_body_xform */
DES_REGION_ADDR(0x011B1D6C, 0x011B37E4)  /* hook des_body_sampled */
DES_REGION_ADDR(0x012D86C4, 0x012DA13C)  /* hook des_rag_pose_a */
DES_REGION_ADDR(0x012D9354, 0x012DADCC)  /* hook des_rag_pose_b */
DES_REGION_ADDR(0x013B75A8, 0x013B9020)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B75D4, 0x013B904C)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7940, 0x013B93B8)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7B9C, 0x013B9614)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7CA4, 0x013B971C)  /* hook des_fx_state */
DES_REGION_ADDR(0x013B7CCC, 0x013B9744)  /* hook des_fx_state */
DES_REGION_ADDR(0x01610188, 0x01611C00)  /* hook + call des_luaheap: a new Lua state (second TOC) */
DES_REGION_ADDR(0x0167AC58, 0x0167C6D0)  /* hook ds_free */
DES_REGION_ADDR(0x0167AC88, 0x0167C700)  /* hook ds_malloc */
DES_REGION_ADDR(0x016EBB98, 0x016EDC68)  /* data kNoName */
DES_REGION_ADDR(0x0185A8B8, 0x0185A8B8)  /* data kEquipVt */
DES_REGION_ADDR(0x0185AF98, 0x0185AF98)  /* vtable */
DES_REGION_ADDR(0x01866068, 0x018660B0)  /* data kEquipSlotsVt */
DES_REGION_ADDR(0x01866570, 0x018665B8)  /* data kInvTabsVt */
DES_REGION_ADDR(0x01867F50, 0x01867F98)  /* data kCursorVt */
DES_REGION_ADDR(0x018692C0, 0x01869308)  /* data kStartTabVt */
DES_REGION_ADDR(0x018697B0, 0x018697F8)  /* data kShortcutVt */
DES_REGION_ADDR(0x018698A0, 0x018698E8)  /* data kHudDialogVt */
DES_REGION_ADDR(0x01869FB8, 0x0186A000)  /* data kPromptVt */
DES_REGION_ADDR(0x0186A398, 0x0186A3E0)  /* data kOptionVt */
DES_REGION_ADDR(0x0186A968, 0x0186A9B0)  /* data kTitleVt */
DES_REGION_ADDR(0x0186BE58, 0x0186BEA0)  /* data kProfileVt */
DES_REGION_ADDR(0x0186C318, 0x0186C360)  /* data kInventoryVt */
DES_REGION_ADDR(0x0186C8A0, 0x0186C8E8)  /* data kDepositVt */
DES_REGION_ADDR(0x0186C9F8, 0x0186CA40)  /* data kTakeVt */
DES_REGION_ADDR(0x0186DC08, 0x0186DC50)  /* data kShopVt */
DES_REGION_ADDR(0x0186DD88, 0x0186DDD0)  /* data kRepairVt */
DES_REGION_ADDR(0x0186E1E0, 0x0186E228)  /* data kFadePlateVt */
DES_REGION_ADDR(0x0186EF60, 0x0186EFA8)  /* data kSystemVt */
DES_REGION_ADDR(0x0186FBC0, 0x0186FC08)  /* data kLoadingVt */
DES_REGION_ADDR(0x01870830, 0x01870878)  /* data kMenuTitleVt */
DES_REGION_ADDR(0x01870C30, 0x01870C78)  /* data kBackPlateVt */
DES_REGION_ADDR(0x018B4810, 0x018B4858)  /* vtable */
DES_REGION_ADDR(0x018B4F98, 0x018B4FE0)  /* vtable */
DES_REGION_ADDR(0x018C8DB4, 0x018C8F20)  /* data kFrameDt */
DES_REGION_ADDR(0x018CEFB4, 0x018CF134)  /* data kCameraFov */
DES_REGION_ADDR(0x018CEFBC, 0x018CF13C)  /* data kCameraAspect */
DES_REGION_ADDR(0x018F96C0, 0x018F9818)  /* data kPreviewTurnStep */
DES_REGION_ADDR(0x0190433C, 0x01904494)  /* data kContextAspect */
DES_REGION_ADDR(0x019AD3B0, 0x019AD5E0)  /* data kSoulsConsts, a slot of the TOC */
DES_REGION_ADDR(0x019AD4FC, 0x019AD72C)  /* data kGameSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD560, 0x019AD790)  /* data kChrInsConsts, a slot of the TOC */
DES_REGION_ADDR(0x019AD694, 0x019AD8C4)  /* data kSignSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD7B4, 0x019AD9E4)  /* data kWorldSlot, a slot of the TOC */
DES_REGION_ADDR(0x019AD7BC, 0x019AD9EC)  /* data kDevConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADD50, 0x019ADF80)  /* data kMenusConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADE38, 0x019AE068)  /* data kScrollConsts, a slot of the TOC */
DES_REGION_ADDR(0x019ADF0C, 0x019AE13C)  /* data kMenuManConsts, a slot of the TOC */
DES_REGION_ADDR(0x019B5040, 0x019B5270)  /* data kToc, the TOC base (r2) */
DES_REGION_ADDR(0x019D8C88, 0x019D8F08)  /* data kLanguageIndex */
DES_REGION_ADDR(0x01AD6298, 0x01AD6518)  /* data kFlipModeObj */
DES_REGION_ADDR(0x01AD62C8, 0x01AD6548)  /* data kStepHeap */
DES_REGION_ADDR(0x01AD6358, 0x01AD65D8)  /* data kLocalBase */
DES_REGION_ADDR(0x01AD6498, 0x01AD6718)  /* data kArenaDebug */
DES_REGION_ADDR(0x01AD6530, 0x01AD67B0)  /* data kArenaTemp */
DES_REGION_ADDR(0x01AD65B0, 0x01AD6830)  /* data kArenaCoreRes */
DES_REGION_ADDR(0x01AD6638, 0x01AD68B8)  /* data kArenaLua */
DES_REGION_ADDR(0x01AD66C0, 0x01AD6940)  /* data kArenaNetwork */
DES_REGION_ADDR(0x01AD6748, 0x01AD69C8)  /* data kArenaServer */
DES_REGION_ADDR(0x01AD67D0, 0x01AD6A50)  /* data kArenaMenu */
DES_REGION_ADDR(0x01AD6858, 0x01AD6AD8)  /* data kArenaFfx */
DES_REGION_ADDR(0x01AD68E0, 0x01AD6B60)  /* data kArenaMo */
DES_REGION_ADDR(0x01AD6960, 0x01AD6BE0)  /* data kArenaHavok */
DES_REGION_ADDR(0x01AD69E0, 0x01AD6C60)  /* data kArenaHgsys */
DES_REGION_ADDR(0x01AD6A68, 0x01AD6CE8)  /* data kArenaIngame */
DES_REGION_ADDR(0x01AD6AF0, 0x01AD6D70)  /* data kArenaMain */
DES_REGION_ADDR(0x01B387B8, 0x01B38A38)  /* data kStepMan */
DES_REGION_ADDR(0x01B3A28C, 0x01B3A50C)  /* data kRemoMan */
DES_REGION_ADDR(0x01B3D6E0, 0x01B3D960)  /* data kChrMan */
DES_REGION_ADDR(0x01B42A80, 0x01B42D00)  /* data kLuaSystemA */
DES_REGION_ADDR(0x01B49BD8, 0x01B49E58)  /* data kLuaSystemB */
DES_REGION_ADDR(0x01B4B150, 0x01B4B3D0)  /* data kMenuSeMgr */
DES_REGION_ADDR(0x01B4EF9C, 0x01B4F21C)  /* data kPgdRoot */
