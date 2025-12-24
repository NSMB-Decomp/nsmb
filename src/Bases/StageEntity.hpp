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

    virtual bool _00();
    virtual bool _01();
    virtual bool _02();
    virtual bool _03();
    virtual bool _04();
    virtual bool _05();
    virtual bool _06();
    virtual bool _07();
    virtual bool _08();
    virtual bool _09();
    virtual bool _10();
    virtual void _11();
    virtual void _12();
    virtual void _13();
    virtual void _14();
    virtual void _15();
    virtual void _16();
    virtual void _17();
    virtual void _18();
    virtual void _19();
    virtual void _20();
    virtual void _21();
    virtual void _22();
    virtual void _23();
    virtual void _24();
    virtual void _25();
    virtual void _26();
    virtual void _27();
    virtual void _28();
    virtual void _29();
    virtual void _30();
    virtual void _31();
    virtual void _32();
    virtual void _33();
    virtual void _34();
    virtual void _35();
    virtual void _36();
    virtual void _37();
    virtual void _38();
    virtual void _39();
    virtual void _40();
    virtual void _41();
    virtual void _42();
    virtual void _43();
    virtual void _44();
    virtual void _45();
    virtual void _46();
};