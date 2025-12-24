#include "StageActor.hpp"

class StageEntity : public StageActor {
public:
    u8 _pad0[0x10];
    u32 _2d0; // 0x2d0
    u8 _pad1[0x38];
    Vec3_32 _30c; // 0x30c
    Vec3_32 _31c; // 0x31c
    u8 _pad2[0x14];
    i32 _340; // 0x340
    u8 _pad6[0x18];
    Vec3_32 _35c; // 0x35c
    Vec2_32 _36c; // 0x36c
    Vec2_32 _378; // 0x378
    Vec2_32 _384; // 0x384
    Vec2_32 _390; // 0x390
    Vec2_32 _39c; // 0x39c
    u32 _3a8; // 0x3a8
    u8 _pad3[0x8];
    u32 _3b4; // 0x3b4
    u8 Pad5[0x20];
    u32 _3d8; // 0x3d8
    u8 _pad4[0xb];
    i8 _3e7; //0x3e7

    StageEntity();
    ~StageEntity();

    bool onUpdate();
    bool preUpdate();
    void postUpdate();
    bool preRender();

    virtual bool __00();
    virtual bool __01();
    virtual bool __02();
    virtual bool __03();
    virtual bool __04();
    virtual bool __05();
    virtual bool __06();
    virtual bool __07();
    virtual bool __08();
    virtual bool __09();
    virtual bool __10();
    virtual void __11();
    virtual void __12();
    virtual void __13();
    virtual void __14();
    virtual void __15();
    virtual void __16();
    virtual void __17();
    virtual void __18();
    virtual void __19();
    virtual void __20();
    virtual void __21();
    virtual void __22();
    virtual void __23();
    virtual void __24();
    virtual void __25();
    virtual void __26();
    virtual void __27();
    virtual void __28();
    virtual void __29();
    virtual void __30();
    virtual void __31();
    virtual void __32();
    virtual void __33();
    virtual void __34();
    virtual void __35();
    virtual void __36();
    virtual void __37();
    virtual void __38();
    virtual void __39();
    virtual void __40();
    virtual void __41();
    virtual void __42();
    virtual void __43();
    virtual void __44();
    virtual void __45();
    virtual void __46();
};