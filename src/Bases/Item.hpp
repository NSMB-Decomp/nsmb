#include "../graphics//3d/model.hpp"
#include "../graphics//3d/modelanm.hpp"
#include "../nsmb_nitro.hpp"
#include "StageEntity.hpp"

class Item : public StageEntity
{
      public:
	u32 _3f4;
	ModelAnm modelAnm; /* 0x3F8 */
	Model model;       /* 0x4A0 */
	u8 _pad0[0x14];
	u32 _544;     /* 0x544 */
	Vec3_32 _548; /* 0x548 */
	Vec2_32 _558; /* 0x558 */
	u8 _pad1[0x4];
	s32 _568;     /* 0x568 */
	u8 _pad2[0x4];
	s32 _570;     /* 0x570 */
	u32 _574;     /* 0x574 */
	u32 player_id; /* 0x578 */ // I believe this would be the player that dropped the item from their held?
	u32 _57c;     /* 0x57C */
	u32 _580;     /* 0x580 */
	u32 _584;     /* 0x584 */
	u32 _588;     /* 0x588 */
	u32 _58c;     /* 0x58C */
	u32 _590;     /* 0x590 */
	u32 _594;     /* 0x594 */
	u16 _598;     /* 0x598 */
	u16 _59a;     /* 0x59A */
	u16 _59c;     /* 0x59C */
	u8 _pad3[0x2];
	u16 _5a0;     /* 0x5A0 */
	u16 _5a2;     /* 0x5A2 */
	u16 _5a4;     /* 0x5A4 */
	u8 _pad4[0x4];
	u16 _5aa;     /* 0x5AA */
	u16 _5ac;     /* 0x5AC */
	u8 _pad5[0x2];
	u16 _5b0;     /* 0x5B0 */
	u16 _5b2;     /* 0x5B2 */
	u8 _pad6[0x4];
	u8 _5b8;      /* 0x5B8 */
	u8 _pad7[0x3];
	u8 _5bc;      /* 0x5BC */
	u8 _pad8[0x2];
	u8 _5bf;      /* 0x5BF */
	u8 _5c0;      /* 0x5C0 */
	u8 _pad9[0x1];
	u8 _5c2;      /* 0x5C2 */
	u8 _5c3;      /* 0x5C3 */
	u8 _5c4;      /* 0x5C4 */
	u8 _5c5;      /* 0x5C5 */
	u8 _5c6;      /* 0x5C6 */
	u8 _5c7;      /* 0x5C7 */
	u8 _5c8;      /* 0x5C8 */
	u8 _5c9;      /* 0x5C9 */
	u8 _5ca;      /* 0x5CA */
	u8 _5cb;      /* 0x5CB */
	s8 _5cc;      /* 0x5CC */
	u8 _5cd;      /* 0x5CD */
	u8 _pad10[0x1];
	u8 _5cf;      /* 0x5CF */

	static Item *create();
	inline Item() {};
	inline ~Item() {};

	virtual s32 onCreate();
	virtual s32 onDestroy();

	void func_ov010_020d1fd8();
	void func_ov010_020d2090();
	void func_ov010_020d2dc0();
	void func_ov010_020d2e00();
	void func_ov010_020d31ac();
	void func_ov010_020d33c8();
	void func_ov010_020d34cc();
	void func_ov010_020d3574();
	void func_ov010_020d361c();
	void func_ov010_020d3e88();
	void func_ov010_020d4340();
	void func_ov010_020d438c();
	void func_ov010_020d43f4();
	void func_ov010_020d4eb8(void (Item::*)());
};

NTR_SIZE_GUARD(Item, 0x5d0);

class ToadItem : public Item
{
      public:
	static ToadItem *create();
	inline ToadItem() {};
	inline ~ToadItem() {};
};
