/* Base */
#define D_Base_vtable               \
    bool (*onCreate)(void);         \
    bool (*preCreate)(void);        \
    void (*postCreate)(u16, u16);   \
    bool (*onDestroy)();            \
    bool (*preDestroy)();           \
    void (*postDestroy)(u16, u16);  \
    bool (*onUpdate)();             \
    bool (*preUpdate)();            \
    void (*postUpdate)();           \
    bool (*onRender)();             \
    bool (*preRender)();            \
    void (*postRender)();           \
    void (*pendingDestroy)();       \
    void (*prepareResourcesSafe)(); \
    void (*prepareResourcesFast)(); \
    bool (*onPrepareResources)();   \
    void (*destroy1)();             \
    void (*destroy2)();

#define D_Base_data           \
    u32 guid; /*Base*/        \
    u32 settings;             \
    u16 object_id;            \
    u8 state;                 \
    bool pending_destroy;     \
    bool pending_update;      \
    bool pending_create;      \
    u8 _12;                   \
    u8 skipFlags;             \
    ProcessLink process_link; \
    void *_54;                \
    void *heap;

/* Actor */
#define D_Actor_vtable               \
    D_Base_vtable void (*setPosX)(); \
    void (*incPosX)();

#define D_Actor_data       \
    D_Base_data            \
        Vec3_32 position;  \
    Vec3_32 lastPosition;  \
    Vec3_32 lastStep;      \
    Vec3_32 centerOffset;  \
    Vec3_16 rotation;      \
    Vec3_16 lastRotation;  \
    i32 velH;              \
    i32 minVelH;           \
    i32 accelV;            \
    i32 minVelV;           \
    i32 accelH;            \
    u32 _c8;               \
    Vec3_32 velocity;      \
    Vec3_32 minVelocity;   \
    Vec3_32 scale;         \
    Vec3_32 acceleration;  \
    Vec3_32 velocitylimit; \
    u8 actorType;          \
    bool visible;          \
    i8 linked_player;      \
    u8 actorCategory;

/* Stage Actor */
#define D_StageActor_vtable \
    D_Actor_vtable

#define D_StageActor_data               \
    D_Actor_data                        \
        ActiveCollider active_collider; \
    CollisionManager collision_manager; \
    PlatformManager platform_manager;   \
    u8 _2bc;                            \
    u8 direction;                       \
    u8 _2be;                            \
    u8 _2bf;                            \
    u32 empty; /* TODO: what does empty mean?*/

/* Stage Entity */
#define D_StageEntity_vtable                  \
    D_StageActor_vtable bool (*onUpdate_0)(); \
    unknown_pointer _1;                       \
    bool (*onUpdate_1)();                     \
    bool (*onUpdate_defeated)();              \
    bool (*onUpdate_3)();                     \
    bool (*onUpdate_4)();                     \
    bool (*onUpdate_5)();                     \
    bool (*onUpdate_6)();                     \
    bool (*onUpdate_7)();                     \
    bool (*onUpdate_8)();                     \
    bool (*onUpdate_9)();                     \
    unknown_pointer _11;                      \
    unknown_pointer _12;                      \
    unknown_pointer _13;                      \
    unknown_pointer _14;                      \
    unknown_pointer _15;                      \
    unknown_pointer _16;                      \
    unknown_pointer _17;                      \
    unknown_pointer _18;                      \
    unknown_pointer _19;                      \
    bool (*onUpdate_xx)();                    \
    unknown_pointer _21;                      \
    unknown_pointer _22;                      \
    unknown_pointer _23;                      \
    unknown_pointer _24;                      \
    unknown_pointer _25;                      \
    unknown_pointer _26;                      \
    unknown_pointer _27;                      \
    void (*stopVelocity)();                   \
    void (*onStomped)();                      \
    unknown_pointer _30;                      \
    unknown_pointer _31;                      \
    unknown_pointer _32;                      \
    void (*onMegaGroundPound)();              \
    void (*onStageComplete)();                \
    unknown_pointer _35;                      \
    unknown_pointer _36;                      \
    unknown_pointer _37;                      \
    unknown_pointer _38;                      \
    void (*playerCollision)();                \
    void (*entityCollision)();                \
    void (*damagePlayer)();                   \
    unknown_pointer _42;                      \
    unknown_pointer _43;                      \
    unknown_pointer _44;                      \
    unknown_pointer _45;                      \
    unknown_pointer _46;

#define D_StageEntity_Data       \
    D_StageActor_data;           \
    u8 _2c4;         /* 0x2C4 */ \
    u8 _2c5;         /* 0x2C5 */ \
    u16 _2c6;        /* 0x2C6 */ \
    u8 _pad13[0x02]; /* 0x2C0 */ \
    u16 _2ca;        /* 0x2CA */ \
    u8 _pad9[0x2];               \
    u32 _2d0; /* 0x2D0 */        \
    u8 _pad1[0x38];              \
    Vec3_32 _30c; /* 0x30C */    \
    Vec3_32 _31c; /* 0x31C */    \
    u8 _pad2[0x14];              \
    i32 _340; /* 0x340 */        \
    u8 _pad14[0x8];              \
    u32 _34c; /* 0x34C */        \
    i32 _350; /* 0x350 */        \
    u8 _pad6[0x4];               \
    u32 _358;     /* 0x358 */    \
    Vec3_32 _35c; /* 0x35C */    \
    Vec2_32 _36c; /* 0x36C */    \
    Vec2_32 _378; /* 0x378 */    \
    Vec2_32 _384; /* 0x384 */    \
    Vec2_32 _390; /* 0x390 */    \
    Vec2_32 _39c; /* 0x39C */    \
    u32 _3a8;     /* 0x3A8 */    \
    u8 _pad3[0x8];               \
    u32 _3b4; /* 0x3B4 */        \
    u32 _3b8; /* 0x3B8 */        \
    u16 _3bc; /* 0x3BC */        \
    u8 _pad11[0x4];              \
    u16 _3c2; /* 0x3C2 */        \
    u8 _pad_3c4[2];              \
    u16 _3c6[2]; /* 0x3C6 */     \
    u8 _pad_3ca[1];              \
    u16 *_3cc; /* 0x3CC */       \
    u8 _3d0;   /* 0x3D0 */       \
    u8 _pad15[0x1];              \
    u8 _3d2; /* 0x3D2 */         \
    u8 Pad5[0x3];                \
    u8 *_3d8; /* 0x3D8 */        \
    u8 _pad4[0x2];               \
    u8 _3de; /* 0x3DE */         \
    u8 _3df; /* 0x3DF */         \
    u8 _pad16[0x4];              \
    u8 _3e4; /* 0x3E4 */         \
    u8 _pad8[2];                 \
    i8 _3e7; /* 0x3E7 */         \
    u8 _3e8; /* 0x3E8 */         \
    u8 _3e9; /* 0x3E9 */         \
    u8 _3ea; /* 0x3EA */         \
    u8 _3eb; /* 0x3EB */         \
    u8 _3ec; /* 0x3EC */         \
    u8 _3ed; /* 0x3ED */         \
    u8 _3ee; /* 0x3EE */         \
    u8 _3ef; /* 0x3EF */         \
    u8 _3f0; /* 0x3F0 */         \
    u8 _3f1; /* 0x3F1 */

/* PlayerBase */
#define D_PlayerBase_vtable  \
    D_Actor_vtable;          \
    unknown_pointer virt_20; \
    unknown_pointer virt_21; \
    unknown_pointer virt_22; \
    unknown_pointer virt_23; \
    unknown_pointer virt_24; \
    unknown_pointer virt_25; \
    unknown_pointer virt_26; \
    unknown_pointer virt_27; \
    unknown_pointer virt_28; \
    unknown_pointer virt_29; \
    unknown_pointer virt_30; \
    unknown_pointer virt_31; \
    unknown_pointer virt_32; \
    unknown_pointer virt_33; \
    unknown_pointer virt_34; \
    unknown_pointer virt_35; \
    unknown_pointer virt_36; \
    unknown_pointer virt_37; \
    unknown_pointer virt_38; \
    unknown_pointer virt_39; \
    unknown_pointer virt_40; \
    unknown_pointer virt_41; \
    unknown_pointer virt_42; \
    unknown_pointer virt_43; \
    unknown_pointer virt_44; \
    unknown_pointer virt_45; \
    unknown_pointer virt_46; \
    unknown_pointer virt_47; \
    unknown_pointer virt_48; \
    unknown_pointer virt_49; \
    unknown_pointer virt_50; \
    unknown_pointer virt_51; \
    unknown_pointer virt_52; \
    unknown_pointer virt_53; \
    unknown_pointer virt_54; \
    unknown_pointer virt_55; \
    unknown_pointer virt_56; \
    unknown_pointer virt_57; \
    unknown_pointer virt_58; \
    unknown_pointer virt_59; \
    unknown_pointer virt_60; \
    unknown_pointer virt_61; \
    unknown_pointer virt_62; \
    unknown_pointer virt_63; \
    unknown_pointer virt_64; \
    unknown_pointer virt_65; \
    unknown_pointer virt_66; \
    unknown_pointer virt_67; \
    unknown_pointer virt_68; \
    unknown_pointer virt_69; \
    unknown_pointer virt_70;

#define D_PlayerBase_data \
    D_StageActor_data     \
        PlayerModel _000; \
    u8 _pad1[0x3c0];      \
    Actor *linkedActor;   \
    u8 _pad10[0x44];      \
    SpinClass _6d0;       \
    u8 _pad11[0x23];      \
    BlendColor _6f4;      \
    u8 _pad12[0x17];      \
    BlendColor _70c;      \
    u8 _pad_70a[22];      \
    Vec3_32 _724;         \
    Vec3_32 _734;         \
    Vec3_32 _744;         \
    u8 _pad9[0x24];       \
    u32 _778;             \
    u32 _77c;             \
    u32 _780;             \
    u8 _pad7[0x4];        \
    u32 _788;             \
    u8 _pad2[0x0b];       \
    i32 _798;             \
    i16 _79c;             \
    u8 _pad3[0xa];        \
    i8 _7a8;              \
    u8 _7a9;              \
    u8 _7aa;              \
    i8 _7ab;              \
    i8 _7ac;              \
    u8 _pad5[0x3];        \
    u8 _7b0;              \
    i8 _7b1;              \
    i8 _7b2;              \
    u8 _7b3;              \
    i8 _7b4;              \
    u8 _pad6[0xa];        \
    u8 _7bf;              \
    u8 _7c0;              \
    u8 _7c1;              \
    u32 _7c4;             \
    u32 _7c8;

/* PlayerActor */
#define D_PlayerActor_vtable \
    D_PlayerBase_vtable

#define D_PlayerActor_data   \
    D_PlayerBase_data        \
        u8 _pad0[0x48];      \
    ActiveCollider _814;     \
    PendulumController _8c4; \
    u8 _pad1[0x18];          \
    Unknown _8e0;            \
    u8 _pad2[0x24];          \
    Vec3_16 _914;            \
    Vec3_16 _920;            \
    Vec3_32 _92c;            \
    Vec3_32 _93c;            \
    Vec3_32 _94c;            \
    Vec2_32 _95c;            \
    Vec2_32 _968;            \
    Vec2_32 _974;