#pragma once
#include "StageActor.hpp"

class PlayerBase;
class PlayerActor;

typedef u8 ScoreType;

enum PlayerStompType {
	PlayerStomp_None,
	PlayerStomp_Stomp,
	PlayerStomp_MiniStomp
};

struct SimplePlayerCollision {
	PlayerActor *player;
	fx32 dx;
	fx32 dy;
};
NTR_SIZE_GUARD(SimplePlayerCollision, 0xc);

struct SimplePlayerSpecialCollision {
	PlayerActor *player;
	fx32 dx;
	fx32 dy;
	u16 flags;
	u16 padding;
};
NTR_SIZE_GUARD(SimplePlayerSpecialCollision, 0x10);

typedef u64 EventMask;

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

	u8 unused2C4;
	u8 align2C5;
	u16 properties;
	u16 spawnSettings;
	u16 inactiveDestroyFlag;
	u8 cooldownA;
	u8 cooldownB;
	u8 align2CE[2];
	u32 unused2D0;
	SimplePlayerCollision simplePlayerCollision[2];
	SimplePlayerSpecialCollision simplePlayerSpecialCollision[2];
	Vec3_32 unusedVec;
	Vec3_32 externalForce;
	fx32 releaseForceX;
	fx32 releaseForceY;
	EventMask eventMask;
	u8 events[2];
	u8 align33E[2];
	i32 updateStateID;
	u32 unk344;
	u8 spawnPlayerID;
	u8 align349[3];
	u32 defeatSFX;
	fx32 liquidWaveHeight;
	u32 carriedAction;
	u32 collisionData;
	Vec3_32 wiggleScale;
	Vec2_32 activeSize; /* 0x36C */
	Vec2_32 renderSize; /* 0x378 */
	Vec2_32 viewOffset; /* 0x384 */
	Vec2_32 collisionSelfPos;
	Vec2_32 collisionActorPos;
	u32 wiggleFactor;
	u32 unused3AC;
	u32 unused3B0;
	u32 collisionType; /* 0x3B4 */
	u32 kickedInWallDistance;
	u16 wiggleTimer;
	u16 liquidFlag;
	u16 releaseMode;
	u16 thrownFlag;
	u16 unused3C4;
	u16 playerCollisionCooldown[2];
	u16 simplePlayerCollisionResult;
	u16 *objectRespawnTimer;
	u8 defeatedLeftLiquid;
	u8 defeatedInLiquid;
	u8 manualTimerA;
	u8 unk3CF;
	u8 cooldownC;
	u8 align3D1;
	u8 align3D2;
	u8 align3D3;
	u8 *objectSpawnFlags;
	u8 playerDirection;
	u8 scoreCombo;
	ScoreType scoreType;
	bool kickedFaster;
	bool unused3DC;
	u8 unused3DD;
	u8 blockHitDirection;
	u8 defeatedArg;
	bool permanentDestroy;
	u8 unused3E1;
	bool forceUpdate;
	s8 unused3E3;
	bool relativeDefeatSpin;
	bool forceRender;
	bool quicksandFlag;
	bool slipperyFlag;
	u8 stompTriggerHeight;
	u8 unused3E9;
	u8 collisionDirection;
	bool freezeFlag;
	u8 backLayer;
	bool kickedInWall;
	s8 functionStep;
	u8 tailPadding;

	StageEntity();
	inline ~StageEntity() {};

	static u32 checkLiquidCollision(const Vec3_32 &, const Vec3_32 &, fx32, bool = true);
	bool updateLiquidPhysics(const Vec3_32 &, fx32);
	void updateLiquidCollision(const Vec3_32 &, fx32);
	u32 updateLiquids(fx32);
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
	static bool isBelowCamera(fx32, ActiveCollider &, s8);
	bool setGroundPoundCollision(const PlayerActor &);
	void setStompCollision(const PlayerActor &);
	bool setMegaKickCollision(const PlayerActor &);
	bool setMegaCollision(const PlayerActor &);
	bool setFenceSlamCollision(const PlayerActor &);
	bool setSlidingCollision(const PlayerActor &);
	bool setStarmanCollision(const PlayerActor &);
	bool setSpinDrillCollision(const PlayerActor &);
	bool checkSquished();
	u32 updateSideSensors();
	u32 updateBottomSensors();
	bool checkLavaCollision(Vec3_32 *);
	u32 updateCollisionSensors();
	bool checkPlayersInRange(fx32, fx32) const;
	bool checkPlayersInRange(fx32) const;
	bool rotateToTarget(i16[2], i16[2]);
	void applyFireballWiggle();
	u16 getActorID(u8);
	void setTimedEvent(u32, i32, bool, bool, bool);
	void destroy(bool);
	void updateBounce(i32, i32, i32);
	static void damagePlayerCallback(ActiveCollider &, ActiveCollider &);
	static void damageEntityCallback(ActiveCollider *, ActiveCollider *);
	static void shellActiveCallback(ActiveCollider &, ActiveCollider &);
	static void simpleCallback(ActiveCollider *, ActiveCollider *);
	static bool spawnBrokenPipe(i32, i32, u32, u32, u8, u8, i8);
	static s8 unitDirection[2];
	static s16 directionalRotationY[2];
	void getScorePointsStageBeaten(u32, fx32, fx32, s32) const;
	static void getScorePointsStageBeaten(const Vec3_32 &, u32, s32);
	static void getScorePointsEnhanced(const Vec3_32 &, u32, s32);
	static void spawnRedCoinNumber(const Vec3_32 &, u32, s32);
	static void getCollectablePoints(u32, s32);
	void getScorePointsRegular(u32, fx32, fx32, s32) const;
	static void getScorePointsRegular(const Vec3_32 &, u32, s32);
	u8 getVerticalDirectionToPlayer(const Vec3_32 &) const;
	u8 getHorizontalDirectionToPlayer(const Vec3_32 &) const;
	u32 random();
	i32 tryAttachToPlayerHands(i32, i32, i32);
	void attachToPlayerHands(fx32, fx32, fx32);
	void applyMovement();
	bool destroyInactive(u32 flags);
	static bool isOutOfView(const Vec3_32 &, const FxRect &, u8);
	void func_ov000_0209e264(u32, u32, u32);
	bool setBlueShellCollision(const PlayerActor &);
	void func_ov000_0209da00();
	void func_ov000_0209da0c();
	void func_ov000_020a020c();
	void func_ov000_020a01b4();
	u32 updateSolidActiveCollider(bool, u32, u8);
	bool canPlayerStomp(ActiveCollider &, PlayerBase &, bool);
	void onPlayerStomp(PlayerBase &, fx32, bool);
	PlayerStompType updatePlayerStomp(ActiveCollider &, fx32, bool, bool);
	void getScorePointsEnhanced(u32, fx32, fx32, s32) const;
	bool updateCarriedCollision();

	virtual bool onUpdate_0();
	virtual bool _01();
	virtual bool onUpdate_1();
	virtual bool onUpdate_defeated();
	virtual bool onUpdate_3();
	virtual bool onUpdate_4();
	virtual bool updateCarried();
	virtual bool onUpdate_6();
	virtual bool onUpdate_7();
	virtual bool updateDroppedHeavy();
	virtual bool updateRolling();
	virtual void _11();
	virtual void _12();
	virtual void _13();
	virtual bool _14();
	virtual void _15();
	virtual void _16();
	virtual void _17();
	virtual void shellKicked();
	virtual void _19();
	virtual void onUpdate_xx();
	virtual void _21();
	virtual void _22();
	virtual void _23();
	virtual void _24();
	virtual void _25();
	virtual void _26();
	virtual void _27();
	virtual void onSpinDrillHit();
	virtual void onStomped();
	virtual void _30();
	virtual void _31();
	virtual void _32();
	virtual void onMegaGroundPound();
	virtual void onStageBeaten(PlayerActor &);
	virtual void _35();
	virtual void _36();
	virtual void _37();
	virtual void _38();
	virtual bool playerCollision(ActiveCollider &, ActiveCollider &);
	virtual void entityCollision(ActiveCollider &, StageActor &);
	virtual void damagePlayer(ActiveCollider &, PlayerBase &);
	virtual void _42(u32, u32, u32, u32);
	virtual void _43(u32, u32, u32);
	virtual void _44();
	virtual void _45();
	virtual void doPlayerJump(PlayerBase &, fx32);
};

NTR_SIZE_GUARD(StageEntity, 0x3f4);
NTR_OFFSET_GUARD(StageEntity, properties, 0x2c6);
NTR_OFFSET_GUARD(StageEntity, spawnSettings, 0x2c8);
NTR_OFFSET_GUARD(StageEntity, simplePlayerCollision, 0x2d4);
NTR_OFFSET_GUARD(StageEntity, simplePlayerSpecialCollision, 0x2ec);
NTR_OFFSET_GUARD(StageEntity, externalForce, 0x31c);
NTR_OFFSET_GUARD(StageEntity, eventMask, 0x334);
NTR_OFFSET_GUARD(StageEntity, updateStateID, 0x340);
NTR_OFFSET_GUARD(StageEntity, spawnPlayerID, 0x348);
NTR_OFFSET_GUARD(StageEntity, activeSize, 0x36c);
NTR_OFFSET_GUARD(StageEntity, collisionType, 0x3b4);
NTR_OFFSET_GUARD(StageEntity, simplePlayerCollisionResult, 0x3ca);
NTR_OFFSET_GUARD(StageEntity, objectRespawnTimer, 0x3cc);
NTR_OFFSET_GUARD(StageEntity, objectSpawnFlags, 0x3d8);
NTR_OFFSET_GUARD(StageEntity, blockHitDirection, 0x3e2);
NTR_OFFSET_GUARD(StageEntity, functionStep, 0x3f2);
