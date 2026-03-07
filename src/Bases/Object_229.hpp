#include "StageEntity.hpp"

struct Object_229_Settings {
	u32 _pad0 : 20;	   // bits 0–19
	u32 setting_2 : 4; // bits 20–23
	u32 setting_1 : 4; // bits 24–27
	u32 direction : 4; // bits 28–31
};
class Object_229 : public StageEntity
{
      public:
	void (Object_229::*a)();
	u32 b;
	u32 c;
	u32 _404; /* 0x404 */
	u32 e;
	u8 setting_1;
	u8 setting_2; /* 0x40D */

	inline Object_229()
	{
	}
	inline ~Object_229()
	{
	}

	static void *create();

	bool onCreate();
	bool onDestroy();
	bool onRender();
	void pendingDestroy();
	bool onUpdate_0();

	void func_ov099_021860f0();
	void func_ov099_021860a4();
	void func_ov099_02186080();
	void func_ov099_0218602c();
	void func_ov099_02186028();
	void func_ov099_02185fdc();
	void func_ov099_02185fb4();
	void func_ov099_02185f5c();
	void func_ov099_02185f30(u32);
	void onUpdate_CallPTMF();
	static bool func_ov099_02185eb4();
	u32 func_ov099_02185e50();
	u32 func_ov099_02185df4();
};
ActorProfile Object229_Profile = {
    Object_229::create,
    0xe5,
    0xc0,
    Object_229::func_ov099_02185eb4,
};
