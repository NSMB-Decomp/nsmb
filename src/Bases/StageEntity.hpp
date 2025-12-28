#include "StageActor.hpp"
#include "Player/PlayerActor.hpp"

class StageEntity : public StageActor {
public:
    u8 _2c4; //0x2C4
    u8 _pad13[0x05]; // 0x2C0
    u16 _2ca; // 0x2CA
    u8 _pad9[0x2];
    u32 _2d0; // 0x2D0
    u8 _pad1[0x38];
    Vec3_32 _30c; // 0x30C
    Vec3_32 _31c; // 0x31C
    u8 _pad2[0x14];
    i32 _340; // 0x340
    u8 _pad14[0x8];
    u32 _34c; //0x34C
    i32 _350; // 0x350
    u8 _pad6[0x4];
    u32 _358; //0x358
    Vec3_32 _35c; // 0x35C
    Vec2_32 _36c; // 0x36C
    Vec2_32 _378; // 0x378
    Vec2_32 _384; // 0x384
    Vec2_32 _390; // 0x390
    Vec2_32 _39c; // 0x39C
    u32 _3a8; // 0x3A8
    u8 _pad3[0x8];
    u32 _3b4; // 0x3B4
    u8 _pad11[0xe];
    u16 _3c6; // 0x3C6
    u16 _3c8; // 0x3CA
    u8 pad12[0x6];
    u8 _3d0; //0x3D0
    u8 _pad15[0x1];
    u8 _3d2; // 0x3D2
    u8 Pad5[0x5];
    u32 _3d8; // 0x3D8
    u8 _pad4[0x2];
    u8 _3de; // 0x3DE
    u8 _3df; // 0x3DF
    u8 _pad16[0x4];
    u8 _3e4; // 0x3E4
    u8 _pad8[2];
    i8 _3e7; //0x3E7
    u8 _3e8; // 0x3E8
    u8 _3e9; //0x3E9
    u8 _3ea; //0x3EA
    u8 _3eb; //0x3EB
    u8 _3ec; //0x3EC
    u8 _3ed; //0x3ED
    u8 _3ee; //0x3EE
    u8 _3ef; //0x3EF
    u8 _3f0; //0x3F0
    u8 _3f1; //0x3F1

    StageEntity();
    inline ~StageEntity();

    void func_ov000_0209c820(u32);
    bool onUpdate();
    bool preUpdate();
    void postUpdate();
    bool preRender();
    static u16 * getObjectBank(u32);
    u32 getSpritePriority(u32, u32, u32);
    Vec3_32 tryNormalizeVec3(Vec3_32*);
    void func_ov000_020988ac(u32);
    void func_ov000_020988d0(u32);
    void assignView(Vec3_32*);
    void isPlayerInZone(PlayerActor*, u32);
    u32 stopPlayerInShell(ActiveCollider*, PlayerActor*);
    void damagePlayerCallback(ActiveCollider*, ActiveCollider*);
    static bool isBelowPlayer(i32, ActiveCollider*, u8);
    bool setGroundPoundCollision(PlayerActor*);

    virtual bool onUpdate_0();
    virtual bool _01();
    virtual bool onUpdate_1();
    virtual bool onUpdate_2();
    virtual bool onUpdate_3();
    virtual bool onUpdate_4();
    virtual bool onUpdate_5();
    virtual bool onUpdate_6();
    virtual bool onUpdate_7();
    virtual bool onUpdate_8();
    virtual bool onUpdate_9();
    virtual void _11();
    virtual void _12();
    virtual void _13();
    virtual void _14();
    virtual void _15();
    virtual void _16();
    virtual void _17();
    virtual void _18();
    virtual void _19();
    virtual void onUpdate_xx();
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
    virtual void onMegaGroundPound();
    virtual void onStageComplete(PlayerActor*);
    virtual void _35();
    virtual void _36();
    virtual void _37();
    virtual void _38();
    virtual bool playerCollision(ActiveCollider*, ActiveCollider*);
    virtual void entityCollision();
    virtual void damagePlayer(ActiveCollider*, PlayerBase*);
    virtual void _42(u32, u32, u32, u32);
    virtual void _43();
    virtual void _44();
    virtual void _45();
    virtual void _46();
};
StageEntity::~StageEntity() {}