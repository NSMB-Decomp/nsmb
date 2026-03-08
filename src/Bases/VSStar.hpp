#include "StageEntity.hpp"

class VsStar : public StageEntity
{
      public:
	u8 _pad0[0x8a];
	u16 field_0x47c;
	u8 _pad2[0x3f];
	u32 setting_0; /*0x4C0*/
	u32 _4c4;      /*0x4C4*/
	u32 setting_1; /*0x4C8*/
	u32 _4cc;
	u8 _pad1[0x20];

	inline VsStar() {};
	~VsStar();

	void func_ov020_02131bbc();
	bool func_ov020_02131c54();
	bool func_ov020_02131f7c();
	bool func_ov020_0213203c();
	void func_ov020_021320dc(u32);
	bool func_ov020_021322a4();
	void func_ov020_0213238c();
	void func_ov020_02132510();
	void func_ov020_02132618();
	bool func_ov020_02132660(u32);

	static void *create();
	bool onDestroy();
	bool onCreate();
	bool onRender();
	void _21();
	void _24();
	void _25();
	void _26();
	void _27();
	void _30();
	void _31();
	bool onUpdate_0();
	void damagePlayer(ActiveCollider *, PlayerBase *);
};
