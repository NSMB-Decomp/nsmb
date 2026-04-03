// This file includes all types that are used within the Ghidra project
// Todo: Shalst we seperate this into different header files?

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;

// Placeholders
typedef u8 unknown1;
typedef u16 unknown2;
typedef u32 unknown4;
typedef void *unknown_pointer;
struct unknown_vtable {
};

// Math
struct Vec3_16 {
	unknown_vtable *vtable;
	i16 x;
	i16 y;
	i16 z;
	u8 _pad0[2];
};
struct Vec3_32 {
	unknown_vtable *vtable;
	i32 x;
	i32 y;
	i32 z;
};
struct Vec3_32s {
	i32 x;
	i32 y;
	i32 z;
};
struct Vec2_32 {
	unknown_vtable *vtable;
	i32 x;
	i32 y;
};

struct Heap {
	unknown_vtable *vtable;
	void *start;
	u32 size;
	Heap *parent;
	u32 flags;
};

// Process
// TODO: Can we improve these names at all?
struct ProcessNode {
	ProcessNode *prev;
	ProcessNode *next;
	struct Base *object;
};

struct PriorityNode {
	ProcessNode _;
	u16 currentPriority;
	u16 sortPriority;
};

struct SceneNode {
	SceneNode *parent;
	SceneNode *firstChild;
	SceneNode *prev;
	SceneNode *next;
	struct Base *object;
};

struct ProcessLink {
	SceneNode connect;
	PriorityNode update;
	PriorityNode render;
	ProcessNode idLookup;
};

struct PTMF // Pointer To Member Function
{
	void (*func)(void *, ...);
	u32 params;
};

struct SceneGraph {
	SceneNode *root;
	PTMF executor;
};

struct LinkedList {
	ProcessNode *first;
	ProcessNode *last;
};

struct ProcessManager {
	SceneGraph sceneGraph;
	ProcessLink updateProcess;
	ProcessLink deleteProcess;
	ProcessLink renderProcess;
	ProcessLink createProcess;
	LinkedList idLookupProcesses[8];
};

struct ProcessList {
	LinkedList _;
	PTMF executor;
};

struct Objectrofile {
	void *constructor;
	u16 updatePriority;
	u16 renderPriority;
};
struct ActorProfile {
	void *constructor;
	u16 updatePriority;
	u16 renderPriority;
	void *_unknownFunc;
};

// Class: Collider
struct Collider {
	u8 _pad[0x23];
	Vec2_32 a;
	Vec2_32 b;
	Vec2_32 c;
	Vec2_32 d;
	Vec2_32 e;
};

struct Rect {
	i32 x;
	i32 y;
	i32 halfWidth;
	i32 halfHeight;
};

// Class ActiveCollider
struct ActiveCollider_vtable {
	unknown_pointer __0;
	unknown_pointer __1;
};
struct ActiveCollider {
	ActiveCollider_vtable *vtable;
	u8 _pad_04[0x10];
	Rect rect;
	u8 _24;
	u8 _25;
	u16 _26;
	u8 _pad_28[4];
	void *_2c;
	u8 _pad_30[10];
	i32 _3c;
	u8 _pad_40[96];
	u16 _1c0; // 0x1C0
	u8 _pad_a2[4];
	u8 _1c6;
	u8 _pad_a7[9];
};

// Class: CollisionManager
struct CollisionManager_vtable {
	unknown_pointer __0;
	unknown_pointer __1;
};
struct CollisionManager {
	CollisionManager_vtable *vtable;
	u8 _pad0[0x1f];
	void *__1;
	u8 _pad1[0x8];
	CollisionManager *__2;
	u8 _pad2[0x5a];
	i8 _25e;
	u8 _pad3[40];
	u8 _b7;
};

// Struct PlatformManager
struct PlatformManager_vtable {
};
struct PlatformManager {
	PlatformManager_vtable *vtable;
	u8 _pad0[0x14];
	void *__1;
	u8 _pad1[0x18];
};

// Class: Base
struct Base_vtable {
	bool (*onCreate)(void);
	bool (*preCreate)(void);
	void (*postCreate)(u16, u16);
	bool (*onDestroy)();
	bool (*preDestroy)();
	void (*postDestroy)(u16, u16);
	bool (*onUpdate)();
	bool (*preUpdate)();
	void (*postUpdate)();
	bool (*onRender)();
	bool (*preRender)();
	void (*postRender)();
	void (*pendingDestroy)();
	void (*prepareResourcesSafe)();
	void (*prepareResourcesFast)();
	bool (*onPrepareResources)();
	void (*destroy1)();
	void (*destroy2)();
};
struct Base_data {
	u32 guid;
	u32 settings;
	u16 object_id;
	u8 state;
	bool pending_destroy;
	bool pending_update;
	bool pending_create;
	u8 _12;
	u8 skipFlags;
	ProcessLink process_link;
	void *_54;
	void *heap;
};
struct Base {
	Base_vtable *_;
	Base_data _;
};

// Class: Object
typedef Base_vtable Object_vtable;
typedef Base_data Object_data;
struct Object {
	Object_vtable _;
	Object_data _;
};

// Class: Actor
struct Actor_vtable {
	Object_vtable _;
	void (*setPosX)();
	void (*incPosX)();
};
struct Actor_data {
	Object_data _;
	Vec3_32 position;
	Vec3_32 lastPosition;
	Vec3_32 lastStep;
	Vec3_32 centerOffset;
	Vec3_16 rotation;
	Vec3_16 lastRotation;
	i32 velH;
	i32 minVelH;
	i32 accelV;
	i32 minVelV;
	i32 accelH;
	u32 _c8;
	Vec3_32 velocity;
	Vec3_32 minVelocity;
	Vec3_32 scale;
	Vec3_32 acceleration;
	Vec3_32 velocitylimit;
	u8 actorType;
	bool visible;
	i8 linked_player;
	u8 actorCategory;
};
struct Actor {
	Actor_vtable *_;
	Actor_data _;
};

// Class: StageActor
typedef Actor_vtable StageActor_vtable;
struct StageActor_data {
	Actor_data _;
	ActiveCollider active_collider;
	CollisionManager collision_manager;
	PlatformManager platform_manager;
	u8 _2bc;
	u8 direction;
	u8 _2be;
	u8 _2bf;
	u32 empty;
};
struct StageActor {
	StageActor_vtable *_;
	StageActor_data _;
};

// Class: StageEntity
struct StageEntity_vtable {
	StageActor_vtable _;
	bool (*onUpdate_0)();
	unknown_pointer _1;
	bool (*onUpdate_1)();
	bool (*onUpdate_defeated)();
	bool (*onUpdate_3)();
	bool (*onUpdate_4)();
	bool (*onUpdate_5)();
	bool (*onUpdate_6)();
	bool (*onUpdate_7)();
	bool (*onUpdate_8)();
	bool (*onUpdate_9)();
	unknown_pointer _11;
	unknown_pointer _12;
	unknown_pointer _13;
	unknown_pointer _14;
	unknown_pointer _15;
	unknown_pointer _16;
	unknown_pointer _17;
	unknown_pointer _18;
	unknown_pointer _19;
	bool (*onUpdate_xx)();
	unknown_pointer _21;
	unknown_pointer _22;
	unknown_pointer _23;
	unknown_pointer _24;
	unknown_pointer _25;
	unknown_pointer _26;
	unknown_pointer _27;
	void (*stopVelocity)();
	void (*onStomped)();
	unknown_pointer _30;
	unknown_pointer _31;
	unknown_pointer _32;
	void (*onMegaGroundPound)();
	void (*onStageComplete)();
	unknown_pointer _35;
	unknown_pointer _36;
	unknown_pointer _37;
	unknown_pointer _38;
	void (*playerCollision)();
	void (*entityCollision)();
	void (*damagePlayer)();
	unknown_pointer _42;
	unknown_pointer _43;
	unknown_pointer _44;
	unknown_pointer _45;
	unknown_pointer _46;
};
struct StageEntity_data {
	StageActor_data _;
	u8 _2c4;	 /* 0x2C4 */
	u8 _2c5;	 /* 0x2C5 */
	u16 _2c6;	 /* 0x2C6 */
	u8 _pad13[0x02]; /* 0x2C0 */
	u16 _2ca;	 /* 0x2CA */
	u8 _pad9[0x2];
	u32 _2d0; /* 0x2D0 */
	u8 _pad1[0x38];
	Vec3_32 _30c; /* 0x30C */
	Vec3_32 _31c; /* 0x31C */
	u8 _pad2[0x14];
	i32 _340; /* 0x340 */
	u8 _pad14[0x8];
	u32 _34c; /* 0x34C */
	i32 _350; /* 0x350 */
	u8 _pad6[0x4];
	u32 _358;     /* 0x358 */
	Vec3_32 _35c; /* 0x35C */
	Vec2_32 _36c; /* 0x36C */
	Vec2_32 _378; /* 0x378 */
	Vec2_32 _384; /* 0x384 */
	Vec2_32 _390; /* 0x390 */
	Vec2_32 _39c; /* 0x39C */
	u32 _3a8;     /* 0x3A8 */
	u8 _pad3[0x8];
	u32 _3b4; /* 0x3B4 */
	u32 _3b8; /* 0x3B8 */
	u16 _3bc; /* 0x3BC */
	u8 _pad11[0x4];
	u16 _3c2; /* 0x3C2 */
	u8 _pad_3c4[2];
	u16 _3c6[2]; /* 0x3C6 */
	u8 _pad_3ca[1];
	u16 *_3cc; /* 0x3CC */
	u8 _3d0;   /* 0x3D0 */
	u8 _pad15[0x1];
	u8 _3d2; /* 0x3D2 */
	u8 Pad5[0x3];
	u8 *_3d8; /* 0x3D8 */
	u8 _pad4[0x2];
	u8 _3de; /* 0x3DE */
	u8 _3df; /* 0x3DF */
	u8 _pad16[0x4];
	u8 _3e4; /* 0x3E4 */
	u8 _pad8[2];
	i8 _3e7; /* 0x3E7 */
	u8 _3e8; /* 0x3E8 */
	u8 _3e9; /* 0x3E9 */
	u8 _3ea; /* 0x3EA */
	u8 _3eb; /* 0x3EB */
	u8 _3ec; /* 0x3EC */
	u8 _3ed; /* 0x3ED */
	u8 _3ee; /* 0x3EE */
	u8 _3ef; /* 0x3EF */
	u8 _3f0; /* 0x3F0 */
	u8 _3f1; /* 0x3F1 */
};
struct StageEntity {
	StageEntity_vtable *_;
	StageEntity_data _;
};

// Class: PlayerBase
struct PlayerModel {
	u8 _2c4;
};
struct SpinClass {
	u8 _pad;
};
struct BlendColor {
	u8 _pad;
};

struct PlayerBase_vtable {
	Actor_vtable _;
	unknown_pointer virt_20;
	unknown_pointer virt_21;
	unknown_pointer virt_22;
	unknown_pointer virt_23;
	unknown_pointer virt_24;
	unknown_pointer virt_25;
	unknown_pointer virt_26;
	unknown_pointer virt_27;
	unknown_pointer virt_28;
	unknown_pointer virt_29;
	unknown_pointer virt_30;
	unknown_pointer virt_31;
	unknown_pointer virt_32;
	unknown_pointer virt_33;
	unknown_pointer virt_34;
	unknown_pointer virt_35;
	unknown_pointer virt_36;
	unknown_pointer virt_37;
	unknown_pointer virt_38;
	unknown_pointer virt_39;
	unknown_pointer virt_40;
	unknown_pointer virt_41;
	unknown_pointer virt_42;
	unknown_pointer virt_43;
	unknown_pointer virt_44;
	unknown_pointer virt_45;
	unknown_pointer virt_46;
	unknown_pointer virt_47;
	unknown_pointer virt_48;
	unknown_pointer virt_49;
	unknown_pointer virt_50;
	unknown_pointer virt_51;
	unknown_pointer virt_52;
	unknown_pointer virt_53;
	unknown_pointer virt_54;
	unknown_pointer virt_55;
	unknown_pointer virt_56;
	unknown_pointer virt_57;
	unknown_pointer virt_58;
	unknown_pointer virt_59;
	unknown_pointer virt_60;
	unknown_pointer virt_61;
	unknown_pointer virt_62;
	unknown_pointer virt_63;
	unknown_pointer virt_64;
	unknown_pointer virt_65;
	unknown_pointer virt_66;
	unknown_pointer virt_67;
	unknown_pointer virt_68;
	unknown_pointer virt_69;
	unknown_pointer virt_70;
};
struct PlayerBase_data {
	StageActor_data _;
	PlayerModel _000;
	u8 _pad1[0x3c0];
	Actor *linkedActor;
	u8 _pad10[0x44];
	SpinClass _6d0;
	u8 _pad11[0x23];
	BlendColor _6f4;
	u8 _pad12[0x17];
	BlendColor _70c;
	u8 _pad_70a[22];
	Vec3_32 _724;
	Vec3_32 _734;
	Vec3_32 _744;
	u8 _pad9[0x24];
	u32 _778;
	u32 _77c;
	u32 _780;
	u8 _pad7[0x4];
	u32 _788;
	u8 _pad2[0x0b];
	i32 _798;
	i16 _79c;
	u8 _pad3[0xa];
	i8 _7a8;
	u8 _7a9;
	u8 _7aa;
	i8 runtimePowerup;
	i8 powerup;
	u8 _pad5[0x3];
	u8 _7b0;
	i8 _7b1;
	i8 _7b2;
	u8 _7b3;
	i8 _7b4;
	u8 _pad6[0xa];
	u8 _7bf;
	u8 _7c0;
	u8 _7c1;
	u32 _7c4;
	u32 _7c8;
};
struct PlayerBase {
	PlayerBase_vtable *_;
	PlayerBase_data _;
};

// Class: Player
struct PendulumController {
	u8 pad;
};
struct Unknown {
	Vec3_32 a;
};

typedef PlayerBase_vtable PlayerActor_vtable;
struct PlayerActor_data {
	PlayerBase_data _;
	u8 _pad0[0x48];
	ActiveCollider _814;
	PendulumController _8c4;
	u8 _pad1[0x18];
	Unknown _8e0;
	u8 _pad2[0x24];
	Vec3_16 _914;
	Vec3_16 _920;
	Vec3_32 _92c;
	Vec3_32 _93c;
	Vec3_32 _94c;
	Vec2_32 _95c;
	Vec2_32 _968;
	Vec2_32 _974;
};
struct PlayerActor {
	PlayerBase_vtable *_;
	PlayerActor_data _;
};

// Class: Coin
typedef StageEntity_vtable Coin_vtable;
struct Coin_data {
	StageEntity_data _;
	u32 _3f4;      /* 0x3F4 */
	Vec3_32 _3f8;  /* 0x3F8 */
	Vec3_32 _408;  /* 0x408 */
	Vec2_32 _418;  /* 0x418 */
	Vec2_32 _424;  /* 0x424 */
	PTMF *_430;    /* 0x430 */
	Vec3_32 _434;  /* 0x434 */
	Collider _444; /* 0x444 */
	u8 _pad0[9];
	u8 _4ad;
	u8 _pad5[1];
	u32 _4b0;
	u32 _4b4;
	u32 _4b8;
	u32 _4bc;
	u32 _4c0;
	u32 _4c4;
	u16 _4ce;
	u16 _4d0;
	u16 _4d8;
	u16 _4da;
	u16 _4dc;
	u16 _4de;
	u16 _4e0;
	u16 _4e2;
	u8 _4e8; /* 0x4E8 */
	u8 _4e9;
	u8 _4ea;
	u8 _4eb;
	u8 _4ec;
	u8 _4ed;
	u8 _4ee;
	u8 _4ef;
	u8 _4f0;
	u8 _4f1;
	u8 _pad3[0x1];
	u8 _4e3;
	u8 _4e4;
};
struct Coin {
	Coin_vtable *_;
	Coin_data _;
};

// Class: Object229
typedef StageEntity_vtable Object229_vtable;
struct Object229_data {
	StageEntity_data _;
	PTMF a;
	u32 b;
	u32 c;
	u32 d;
	u32 e;
	u8 f;
};
struct Object229 {
	Object229_vtable *_;
	Object229_data _;
};

// Class: Scene
typedef Object_vtable Scene_vtable;
struct Scene_data {
	Object_data _;
	void *_5c;
	void *_60;
};
struct Scene {
	Scene_vtable *_;
	Scene_data _;
};

// Class: SoundTestScene
typedef Scene_vtable SoundTestScene_vtable;
typedef Scene_data SoundTestScene_data;
struct SoundTestScene {
	SoundTestScene_vtable *_;
	SoundTestScene_data _;
};

// Class: MainMenuScene
struct TitleScreenButton {
	i32 posX;
	i32 posY;
	i32 velX;
	i32 velY;
};
typedef enum SaveStateFlag { Empty = 1, Saved = 2, StoryCompleted = 4, StandardLevelsCompleted = 8, GameCompleted = 16 } SaveStateFlag;
struct SaveState {
	SaveStateFlag flags;
	u32 lives;
	u32 coins;
	u32 score;
	u32 starCoins;
	u32 currentWorld;
};

struct TitleScreenCutscene {
	u8 _pad[0x908];
};
struct TextLabel {
	u8 _pad[0xb0];
};
typedef Scene_vtable MainMenuScene_vtable;
struct MainMenuScene_data {
	Scene_data _;
	u8 menuID;
	u8 stateID;
	u8 _pad0;	    /* unused? */
	i8 buttonAnimTimer; /* used to animate the button pressed animation */
	u8 fileSelectCurrentButton;
	u8 fileCopySourceFile;	       /* 0-2=file id */
	u8 fileCopyDestinationFile;    /* 0-2=file id */
	u8 fileCopyIgnoredFile;	       /* the third unselected file (neither source nor destination) */
	u8 fileEraseFile;	       /* 0-2=file id */
	u8 fileEraseCurrentButton;     /* 0-2=file,3=back,4='Yes',5='No' */
	u8 optionsCurrentButton;       /* 0=sound mode,1=control mode,2='OK' */
	u8 fileConfirmOperationButton; /* 0='Yes',1='No' */
	bool backButtonSelected;       /* cancel operation */
	bool backButtonHighlighted;
	bool fileSelectionCompleted;  /* set to true when the (copy/erase) file selection is completed */
	bool fileConfirmRequest;      /* set to true when a file operation needs a confirmation (erase=always, copy=overwrite only) */
	bool copyingFile;	      /* used to render the icon */
	bool copyingFileAnimStopping; /* if set to true, the animation will continue until frame 0 is reached */
	u8 copyingFileFrame;	      /* used to animate the icon */
	u8 stateTimer;
	bool buttonsVisible; /* if not true, the enter state should be responsible for sliding them back on screen */
	u8 fileEraseSelected;
	u8 fileCopiedTimer;
	u8 fileCopyCurrentButton;
	u8 _pad1;		  /* used? */
	bool fileOperationFailed; /* set to true when a file operation fails */
	u8 _pad2;
	u8 _pad3;
	int buttonHitTimer;
	int button1Offset;	   /* copy/sound mode */
	int button2Offset;	   /* erase/control mode */
	int optionsOKButtonOffset; /* pos Y = pos X + offset */
	int optionsOKButtonPosX;   /* relative to the BNCL cell (ofc) */
	int guiTimer;		   /* used to move the GUI in/out of the screen */
	int buttonsTimer;	   /* used to move the buttons in/out of the screen */
	int backButtonOffset;
	int soundMode;
	int controlMode;
	int fileButtonsTargetY[3];
	TitleScreenButton mainMenuButtons[4];
	TitleScreenButton fileSelectFileButtons[3];
	TitleScreenButton fileSelectButtons1[2];
	TitleScreenButton fileSelectButtons2[2];
	SaveState saves[3];
	TitleScreenCutscene cutscene;
	TextLabel label;
};
struct MainMenuScene {
	MainMenuScene_vtable *_;
	MainMenuScene_data _;
};

struct Fader {
	u8 _pad0[0x5a4];
	i32 targetBrightness;
	u32 fadingMode;
	i32 brightnessFactor[2];
	i32 brightnessIncrement[2];
	u8 fadingTarget[2];
	u8 fadingState[2];
	u8 fadeMaskShape[2];
	u8 fadingType; /* 5C2 */
};

// Class: VsStar
typedef StageEntity_vtable VsStar_vtable;
typedef StageEntity_data VsStar_data;
struct VsStar {
	VsStar_vtable *_;
	VsStar_data _;
};