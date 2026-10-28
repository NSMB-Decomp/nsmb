#pragma once
#include "StageActor.hpp"

class PlayerBase;
class PlayerActor;

struct ObjectInfo {

	enum EntityProperties {
		EP_None = 0,
		EP_Immune				= (1U << 0),	// Immune to all collisions?
		EP_InactiveFocus		= (1U << 1),	// Permanently destroy the object if inactive
		EP_LiquidParticles		= (1U << 2),	// Spawn particles and play SFX on liquid collision
		EP_NoLevelBeaten		= (1U << 4),	// Ignore defeat on level beaten
		EP_NoGroundPound		= (1U << 5),	// Ignore groundpound collision
		EP_NoMegaKick			= (1U << 6),	// Ignore mega player kick collision
		EP_NoMega				= (1U << 7),	// Ignore mega player collision
		EP_NoStarman			= (1U << 8),	// Ignore starman collision
		EP_NoSliding			= (1U << 9),	// Ignore sliding player collision
		EP_NoBlueShell			= (1U << 10),	// Ignore shell player collision
		EP_FenceSlam			= (1U << 11),	// Enable fence slam collision
		EP_SpinDrill			= (1U << 12),	// Enable spin drill collision
		// 1U << 13 - used in Manhole
		EP_NoFireball			= (1U << 14),	// Ignore fireball collision
	};

	enum SpawnSettings {
		SS_None = 0,
		SS_SinglePlayerOnly	= (1U << 0),
		SS_MvsLOnly			= (1U << 1),
		SS_AlwaysLoad		= (1U << 2),
		SS_IgnoreView		= (1U << 3),
	};

	struct { s16 x, y; }

	// Used to offset the sprite position in the stage
	position,

	// StageEntity::renderSize, StageEntity::existSize
	size,

	// Only used when assigning the view, does not affect the object's position
	spawnOffset,

	// StageEntity::viewOffset
	viewOffset;

	// StageEntity::properties
	u16 properties;

	// StageEntity::spawnSettings
	u16 spawnSettings;


	// inline ObjectInfo() :
	// 	position{ 0, 0 },
	// 	size{ 0, 0 },
	// 	spawnOffset{ 0, 0 },
	// 	viewOffset{ 0, 0 },
	// 	properties(EP_None),
	// 	spawnSettings(SS_None)
	// {}


	// inline ObjectInfo(
	// 	s16 positionX, s16 positionY,
	// 	s16 renderSizeX = 0, s16 renderSizeY = 0,
	// 	s16 spawnOffsetX = 0, s16 spawnOffsetY = 0,
	// 	s16 viewOffsetX = 0, s16 viewOffsetY = 0,
	// 	u16 properties = EP_None,
	// 	u16 spawnSettings = SS_None
	// ) :
	// 	position{ positionX, positionY },
	// 	size{ renderSizeX, renderSizeY },
	// 	spawnOffset{ spawnOffsetX, spawnOffsetY },
	// 	viewOffset{ viewOffsetX, viewOffsetY },
	// 	properties(properties),
	// 	spawnSettings(spawnSettings)
	// {}

};

struct UnkTouch12 {
	Actor *actor;
	s32 _4;
	s32 _8;
};

struct UnkTouch16 {
	Actor *actor;
	s32 _4;
	s32 _8;
	u16 _c;
};

class StageEntity : public StageActor {
public:

	enum CollisionType {
		CT_None = 0,
		CT_Collisionless	= (1U << 0),

		// Mega Ground-Pound by player 0 while the entity is on the ground
		CT_MGPGroundP0		= (1U << 1),

		// Mega Ground-Pound by player 1 while the entity is on the ground
		CT_MGPGroundP1		= (1U << 2),

		// Mega Ground-Pound by player 0 while the entity is in midair
		CT_MGPAirP0			= (1U << 3),

		// Mega Ground-Pound by player 1 while the entity is in midair
		CT_MGPAirP1			= (1U << 4),

		CT_Fireball			= (1U << 5),
		CT_Entity			= (1U << 6),
		CT_Block			= (1U << 7),
		CT_StageBeaten		= (1U << 8),
		CT_Starman			= (1U << 9),
		CT_Mega				= (1U << 10),
		CT_SpinDrill		= (1U << 11),
		CT_Sliding			= (1U << 12),
		CT_Stomp			= (1U << 13),
		CT_GroundPound		= (1U << 14),
		CT_BlueShell		= (1U << 15),
		CT_FenceSlam		= (1U << 16),

	};

	u8 _2c4;	 /* 0x2C4 */
	u8 _2c5;	 /* 0x2C5 */
	u16 _2c6;	 /* 0x2C6 */
	u16 _2c8; /* 0x2C8 */
	u16 _2ca;	 /* 0x2CA */
	u8 _pad9[0x2];
	u32 _2d0; /* 0x2D0 */
	UnkTouch12 _2d4[2]; /* 0x2D4 */
	UnkTouch16 _2ec[2]; /* 0x2EC */
	Vec3_32 _30c; /* 0x30C */
	Vec3_32 _31c; /* 0x31C */
	u8 _pad2[8];
	u64 _334; /* 0x334 */
	u8 _pad99[4];
	s32 _340; /* 0x340 */
	u8 _pad14[0x8];
	u32 _34c;     /* 0x34C */
	s32 _350;     /* 0x350 */
	u32 _354;     /* 0x354 */
	u32 _358;     /* 0x358 */
	Vec3_32 _35c; /* 0x35C */
	Vec2_32 activeSize; /* 0x36C */
	Vec2_32 renderSize; /* 0x378 */
	Vec2_32 viewOffset; /* 0x384 */
	Vec2_32 _390; /* 0x390 */
	Vec2_32 _39c; /* 0x39C */
	u32 _3a8;     /* 0x3A8 */
	u8 _pad3[0x8];
	u32 collisionType; /* 0x3B4 */
	u32 _3b8; /* 0x3B8 */
	u16 _3bc; /* 0x3BC */
	u16 _3be /* 0x3BE */;
	u16 _3c0; /* 0x3C0 */
	u16 _3c2; /* 0x3C2 */
	u8 _pad_3c4[2];
	u16 _3c6[2]; /* 0x3C6 */
	u16 _3ca; /* 0x3CA */
	u16 *_3cc; /* 0x3CC */
	u8 _3d0;   /* 0x3D0 */
	u8 _3d1; /* 0x3D1 */
	u8 _3d2; /* 0x3D2 */
	u8 Pad5[0x3];
	u8 *_3d8; /* 0x3D8 */
	u8 _pad4[0x2];
	u8 _3de; /* 0x3DE */
	u8 _3df; /* 0x3DF */
	u8 _3e0; /* 0x3E0 */
	u8 _3e1; /* 0x3E1 */
	u8 _3e2; /* 0x3E2 */
	u8 _3e3; /* 0x3E3 */
	u8 _3e4; /* 0x3E4 */
	u8 _pad8[1];
    u8 _3e6; /* 0x3E6 */
	s8 _3e7; /* 0x3E7 */
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

	StageEntity();
	inline ~StageEntity() {};

	void func_ov000_0209c820(u32);
	s32 onUpdate();
	bool preUpdate();
	void postUpdate(u32);
	bool preRender();
	static u16 *getObjectBank(u32);
	u32 getSpritePriority(u32);
	Vec3_32 tryNormalizeVec3(Vec3_32 *);
	void func_ov000_020988ac(u32);
	void func_ov000_020988d0(u32);
	void assignView(Vec3_32 *);
	bool isPlayerInZone(PlayerActor *, u32);
	u32 stopPlayerInShell(ActiveCollider *, PlayerActor *);
	static bool isBelowPlayer(s32, ActiveCollider *, u8);
	bool setGroundPoundCollision(PlayerActor *);
	bool checkSquished();
	u32 updateSideSensors();
	u32 updateBottomSensors();
	bool checkLavaCollision(Vec3_32 *);
	u32 updateCollisionSensors();
	bool checkPlayersInOffset(s32, s32);
	bool checkPlayersInOffset(s32);
	bool rotateToTarget(s16[2], s16[2]);
	void applyFireballWiggle();
	u16 getActorID(u8);
	void setTimedEvent(u32, s32, bool, bool, bool);
	void destroy(bool);
	void updateBounce(s32, s32, s32);
	static void damagePlayerCallback(ActiveCollider *, ActiveCollider *); // These callbacks should not be static, set as static temporarily to match code.
	static void damageEntityCallback(ActiveCollider *);
	static void shellCallback(ActiveCollider *);
	static void simpleCallback(ActiveCollider *, ActiveCollider *);
	static bool spawnBrokenPipe(s32, s32, u32, u32, u8, u8, s8);
	static u8 func_ov000_0209aad0(Vec3_32 *, u32, u32);
	u32 random();
	s32 tryAttachToPlayerHands(s32, s32, s32);
	void attachToPlayerHands(s32, s32, s32);
	void func_ov000_0209c85c();
	bool destroyInactive(u32 flags);
	void func_ov000_0209e264(u32, u32, u32);
	bool func_ov000_0209ccd0(PlayerBase *);
	void func_ov000_0209da00();
	void func_ov000_0209da0c();
	static void func_ov000_0209e5a8(u32, u32, u32);
	Actor *func_ov000_0209e3f8(Vec3_32 *, u32, u32, u32, u8);
	void func_ov000_020a020c();
	void func_ov000_020a01b4();
	bool func_ov000_0209acd4(Vec3_32 *);
	void func_ov000_0209cfc4(StageEntity *);
	bool func_ov000_0209ac8c(Vec3_32 *);
	static bool func_ov000_0209aff8(u32, u32);
	static void func_ov000_0209c2f8(u32);
	bool func_ov000_0209d240(StageEntity *);
	static void func_ov000_0209e13c(PlayerBase *, u32, u32);
	u32 func_ov000_0209a80c(ActiveCollider *, s32, u32, u8);
	static void func_ov000_0209e2c8(s32, s32, u32);
	static void func_ov000_0209bf10(UnkEntry_0208b168 *, UnkSpawnCfg_020c529c *, u8 *, u16 *, u32, u32);
	void func_ov000_0209a5bc(PlayerBase *, s32, u32);
	static StageEntity *func_ov000_0209c178(u32, u32, Vec3_32 *);
	static void func_ov000_0209e038();
	Actor *func_ov000_0209e49c(Vec3_32 *, u32, u32, u32, u8, u8);
	static bool func_ov000_0209ae88(Vec3_32 *, FxRect *, u8);
	static bool func_ov000_0209ec28(PlayerBase *, s32, s32, u32, u8, u8);
	static void func_ov000_0209ee64(s32, s32, u32, u32, u8, s8, u16);
	static void func_ov000_0209eefc(s32, s32, u32, u32, u8, s8, u16);
	static void func_ov000_0209ab04(s32, s32);
	static void func_ov000_0209b764();
	static void func_ov000_0209b7e8(u32);
	u16 func_ov000_0209c6d4(Vec3_32 *, u32);
	void func_ov000_0209ab90(u32, s32, s32, s32);
	static void func_ov000_0209ac0c(Vec3_32 *, s32, s32);
	void func_ov000_0209d694();
	static void func_ov000_0209c288();
	bool func_ov000_0209d0ec(StageEntity *);
	bool func_ov000_0209d3d0(StageEntity *);
	bool func_ov000_0209d708(StageEntity *);
	bool func_ov000_0209d774(StageEntity *);
	bool func_ov000_0209d7e0(StageEntity *);
	bool func_ov000_020a0048(PlayerBase *);
	void func_ov000_0209a938(u32, s32, s32, s32);
	static void func_ov000_0209a990(Vec3_32 *, s32, s32);
	static bool func_ov000_0209b040(u32, u32);
	static bool func_ov000_0209b320(u32, u32);
	static bool func_ov000_0209b688(u32, u32);
	void func_ov000_0209c7a0(Vec3_32 *, u32);
	static u32 func_ov000_0209c590(Vec3_32 *, Vec3_32 *, s32, u32);
	s32 func_ov000_0209a23c();
	bool func_ov000_0209a4f0(ActiveCollider *, PlayerBase *, u32);
	void func_ov000_0209aa04(u32 type,s32 x,s32 y,s32 player_id);
	static void func_ov000_0209aa5c(Vec3_32 *, s32, s32);
	bool func_ov000_0209ff98();

	virtual bool onUpdate_0();
	virtual bool _01();
	virtual bool onUpdate_1();
	virtual bool onUpdate_defeated();
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
	virtual bool _14();
	virtual void _15();
	virtual void _16();
	virtual void _17(PlayerBase *);
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
	virtual void stopVelocity();
	virtual void onStomped();
	virtual void _30();
	virtual void _31();
	virtual void _32();
	virtual void onMegaGroundPound();
	virtual void onStageComplete(PlayerActor *);
	virtual void _35();
	virtual void _36();
	virtual void _37();
	virtual void _38();
	virtual bool playerCollision(ActiveCollider *, ActiveCollider *);
	virtual void entityCollision();
	virtual void damagePlayer(ActiveCollider *, PlayerBase *);
	virtual void _42(u32, u32, u32, u8);
	virtual void _43(u32, u32, u32);
	virtual void _44();
	virtual void _45();
	virtual void _46(PlayerBase *, s32);
};
