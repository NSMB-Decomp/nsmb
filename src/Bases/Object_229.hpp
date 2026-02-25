#include "StageEntity.hpp"

class Object_229 : public StageEntity
{
	u8 padding[0x1b];

	inline Object_229()
	{
	}
	inline ~Object_229()
	{
	}

	Object_229 *create();

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
    void func_ov099_02185f30();
    void func_ov099_02185ebc();
    bool func_ov099_02185eb4();
    u32 func_ov099_02185e50();
    u32 func_ov099_02185df4();
};