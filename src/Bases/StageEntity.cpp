#include "StageEntity.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/game/score.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov010/symbols.hpp>
#include <nsmb/overlays/ov054/symbols.hpp>
#include "Player/PlayerActor.hpp"

StageEntity::StageEntity()
{
	// this->_40 = 0x2;
	this->actorType = 0x2;
	this->actorCategory = (1 << this->actorType) | 0x80;
	this->actorCategory = this->actorCategory | 0x20;
	this->unused2D0 = 0;
	this->unused3E3 = ~0;
	this->collisionType = 0x107;
	this->accelV = -0x300;
	this->minVelocity.x = 0;
	this->minVelocity.y = -0x4000;
	this->minVelocity.z = 0;
	this->objectSpawnFlags = 0;
	this->wiggleFactor = 0x1000;
	this->activeSize.x = 0;
	this->activeSize.y = 0;
	this->viewOffset.x = 0;
	this->viewOffset.y = 0;
	this->renderSize.x = 0;
	this->renderSize.y = 0;
	this->externalForce.x = 0;
	this->externalForce.y = 0;
	this->externalForce.z = 0;
	this->inactiveDestroyFlag = 0;
	this->playerCollisionCooldown[0] = 0;
	this->playerCollisionCooldown[1] = 0;
	this->manualTimerA = 0;
	this->relativeDefeatSpin = 0;
	this->quicksandFlag = 0;
	this->permanentDestroy = 0;
	this->slipperyFlag = 0;
	this->collisionData = 0;
	this->stompTriggerHeight = 0;
	this->unused2C4 = 0;
	this->defeatSFX = 0x6e;
	this->_2be = func_0201f000(&this->position);
	this->unused3E9 = 0;
	this->freezeFlag = 0;
	this->linked_player = ~0;
	this->kickedFaster = 0;
	this->defeatedLeftLiquid = 0;
	this->scoreType = 0;
	this->liquidWaveHeight = 1;
	this->kickedInWall = 0;
}

bool StageEntity::onUpdate_0()
{
	return true;
}

s32 StageEntity::onUpdate()
{
	this->onUpdate_xx();
	i32 state = this->updateStateID;
	if (state == 0) {
		return this->onUpdate_0();
	}
	if (state == 1) {
		return this->onUpdate_1();
	}
	if (state == 2) {
		return this->onUpdate_defeated();
	}
	if (state == 3) {
		return this->onUpdate_3();
	}
	if (state == 4) {
		return this->onUpdate_4();
	}
	if (state == 5) {
		return this->updateCarried();
	}
	if (state == 6) {
		return this->onUpdate_6();
	}
	if (state == 7) {
		return this->onUpdate_7();
	}
	if (state == 8) {
		return this->updateDroppedHeavy();
	}
	if (state == 9) {
		return this->updateRolling();
	}
	this->updateStateID = 0;
	return this->onUpdate_0();
}































void StageEntity::_12()
{
	this->playerCollisionCooldown[this->linked_player] = 0xc;
	(this->activeCollider).detectGroups |= 0x140;
	if (this->thrownFlag != 0) {
		(this->activeCollider).attack = 0xa;
		(this->activeCollider).callback = (void *)shellActiveCallback;
	}
}

void StageEntity::_13()
{
	(this->activeCollider).detectGroups &= ~0x140;
	(this->activeCollider).attack = 0x0;
	(this->activeCollider).callback = (void *)damagePlayerCallback;
	this->accelH = 0;
	(this->minVelocity).x = 0;
	this->properties &= 0xfffe;
}

u32 data_ov000_020c1f60[2];
void StageEntity::_19()
{
	if (this->kickedInWall != 0x0) {
		(this->velocity).x = data_ov000_020c1f60[this->direction];
	} else {
		this->scoreCombo = 0x0;
	}
	this->activeCollider.detectGroups &= ~0x140;
	this->activeCollider.attack = 0x0;
	this->activeCollider.callback = (void *)damagePlayerCallback;
	this->kickedInWall = 0x0;
	this->accelH = 0;
	this->minVelocity.x = 0;
	this->minVelocity.y = -0x4000;
	this->minVelocity.z = 0;
	this->properties = this->properties & 0xfffe;
	this->updateStateID = 0;
	return;
}

bool StageEntity::_14()

{
	this->activeCollider.attack = 0xa;
	this->activeCollider.detectGroups = 0x113;
	return 0;
}

void StageEntity::applyMovement()
{
	Vec3_32 movement;
	i32 speed = this->velocity.x < 0 ? -this->velocity.x : this->velocity.x;
	u16 angle = (u16)this->collisionMgr.getGroundAngle(
		((u32)this->velocity.x & 0x80000000) >> 31);
	if (this->quicksandFlag) {
		movement.x = 0;
		movement.y = 0;
		movement.z = 0;
	} else {
		movement.x = _FixedMul(speed, _FixedCos(angle));
		movement.y = this->velocity.y + _FixedMul(speed, _FixedSin(angle));
		movement.z = this->velocity.z;
		if (this->liquidFlag) {
			movement.x >>= 1;
		}
	}
	movement.add2(this->externalForce);
	Vec3_32::add4(this->position, &movement, this->position);
}

u32 StageEntity::updateLiquids(fx32 defaultAccelY)
{
	this->updateLiquidCollision(this->position, defaultAccelY);
	u32 result = this->properties & 4;
	if (result == 0) {
		return result;
	}
	return checkLiquidCollision(
		this->position, this->lastPosition, this->liquidWaveHeight, true);
}

void StageEntity::updateLiquidCollision(const Vec3_32 &position, fx32 defaultAccelY)
{
	if (this->checkLavaCollision(const_cast<Vec3_32 *>(&position))) {
		this->_35();
		return;
	}
	if (this->defeatedLeftLiquid) {
		return;
	}
	this->liquidFlag = this->updateLiquidPhysics(position, defaultAccelY);
	if (this->permanentDestroy && this->defeatedInLiquid && !this->liquidFlag) {
		this->defeatedLeftLiquid = true;
	}
}

bool StageEntity::updateLiquidPhysics(const Vec3_32 &position, fx32 defaultAccelY)
{
	if (CollisionMgr::getLiquidCollision(position.x, position.y, 0, -1) !=
	    CollisionMgr::LIQUID_NONE) {
		this->accelV = -0x100;
		if (this->minVelocity.y < -0x1000) {
			this->minVelocity.y = -0x1000;
		} else if (this->minVelocity.y > 0x1800) {
			this->minVelocity.y = 0x1800;
		}
		if (this->minVelV < -0x1000) {
			this->minVelV = -0x1000;
		} else if (this->minVelV > 0x1800) {
			this->minVelV = 0x1800;
		}
		if (this->velocity.y < -0x1000) {
			this->velocity.y = -0x1000;
		} else if (this->velocity.y > 0x1800) {
			this->velocity.y = 0x1800;
		}
		return true;
	}
	this->accelV = defaultAccelY;
	this->minVelocity.y = -0x4000;
	this->minVelV = -0x4000;
	return false;
}

u32 StageEntity::checkLiquidCollision(
	const Vec3_32 &position, const Vec3_32 &lastPosition, fx32 waveHeight, bool playSFX)
{
	fx32 lastSurface = data_ov000_020cadac[data_02085a7c];
	fx32 surface = data_ov000_020cae0c[data_02085a7c];
	if ((lastPosition.y <= lastSurface && surface < position.y) ||
	    (position.y < surface && lastSurface <= lastPosition.y)) {
		func_ov054_021646e0(position.x, waveHeight);
		Vec3_32 effectPosition;
		effectPosition.set(position.x, surface, position.z);
		u8 type = data_ov000_020cace0[data_02085a7c];
		if (type == 4) {
			effectPosition.y = surface + 0x8000;
			func_020221b4(&effectPosition);
			if (playSFX) {
				func_02012398(0x173, const_cast<Vec3_32 *>(&position));
			}
			return 4;
		}
		if (type == 2) {
			func_020221d8(const_cast<Vec3_32 *>(&position));
			return 2;
		}
		func_020221fc(&effectPosition);
		if (playSFX) {
			func_02012398(0x173, const_cast<Vec3_32 *>(&position));
		}
		return 1;
	}
	return 0;
}

void StageEntity::_16()
{
	PlayerBase *player;

	if (this->linked_player == ~0) {
		return;
	}
	player = static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	player->func_ov011_0212bde0(this);
	this->activeCollider.detectGroups &= ~0x100;
	this->activeCollider.attack = 0x0;
	this->activeCollider.callback = (void *)damagePlayerCallback;
	this->linked_player = -1;
	func_0201d954(&this->platformMgr, 0);
	this->collisionMgr.flags = 0x0;
	this->properties = this->properties & 0xfffe;
	return;
}

void StageEntity::grabbed()
{
	PlayerActor *player =
		static_cast<PlayerActor *>(Game::getPlayer(this->linked_player));
	BOOL frontLayer = BOOL(player->zLayer == 0x8000);
	if (frontLayer != FALSE) {
		this->backLayer = FALSE;
	} else {
		this->backLayer = TRUE;
	}
	this->activeCollider._a4 = data_ov000_020c4ec0[this->backLayer];
	this->collisionMgr._b7 = data_ov000_020c4ec0[this->backLayer];
	this->activeCollider.detectGroups |= 1 << AC_GRP_Bullet;
	this->activeCollider.attack = AC_ATK_EntityAsWeapon;
	this->activeCollider.callback = (void *)damageEntityCallback;
}

void StageEntity::_37()
{
}

void StageEntity::_36()

{
	this->velocity.y = 0x2000;
	return;
}

void StageEntity::_35()
{
	s32 playerID;
	Vec3_32 effectPosition(this->position);
	Vec3_32 &center = this->centerOffset;
	this->activeCollider.unlink();
	this->permanentDestroy = true;

	playerID = 0;
	if (func_020202a0() > 0) {
		do {
			PlayerBase *player =
				static_cast<PlayerBase *>(Game::getPlayer(playerID));
			if (player != 0 && player->linkedActor == this) {
				player->func_ov011_0212bde0(this);
			}
			++playerID;
		} while (playerID < func_020202a0());
	}

	effectPosition.add2(center);
	func_02022220(&effectPosition);
	func_02012398(0x70, &effectPosition);
	this->destroy(true);
}

void StageEntity::_32()
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	this->activeCollider.unlink();
	this->direction = this->collisionDirection;
	if (player->scoreComboFenceSlam < 10) {
		++player->scoreComboFenceSlam;
	}
	if (player->scoreComboFenceSlam > 8) {
		player->scoreComboFenceSlam = 8;
	}

	u32 scoreCombo = player->scoreComboFenceSlam;
	if (this->scoreType == 0) {
		this->getScorePointsRegular(
			scoreCombo, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsEnhanced(
			scoreCombo, 0, 0x18000, this->linked_player);
	}
	if (scoreCombo < 8) {
		func_02012398(scoreCombo + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->defeat(
		data_ov000_020c4ed4[this->direction] >> 1,
		0x6000, -0x600, 0);
}

void StageEntity::_31()
{
	Game::getPlayer(this->linked_player);
	this->activeCollider.unlink();
	this->direction = this->collisionDirection;
	if (this->scoreType == 0) {
		this->getScorePointsRegular(1, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsRegular(4, 0, 0x18000, this->linked_player);
	}
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::onGroundPound()
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	Vec3_32 soundPosition =
		func_02045bdc(this->position, this->centerOffset);
	this->permanentDestroy = true;
	this->activeCollider.unlink();

	s32 playerID = 0;
	if (func_020202a0() > 0) {
		do {
			PlayerBase *linkedPlayer =
				static_cast<PlayerBase *>(Game::getPlayer(playerID));
			if (linkedPlayer != 0 && linkedPlayer->linkedActor == this) {
				linkedPlayer->func_ov011_0212bde0(this);
			}
			++playerID;
		} while (playerID < func_020202a0());
	}

	if (player->scoreComboStandard < 10) {
		++player->scoreComboStandard;
	}
	++player->scoreJumpVariation;
	player->scoreJumpVariation %= 4;
	if (player->scoreComboStandard > 8) {
		player->scoreComboStandard = 8;
	}
	if (this->scoreType == 0) {
		this->getScorePointsRegular(
			player->scoreComboStandard, 0, 0x18000,
			this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsEnhanced(
			player->scoreComboStandard, 0, 0x18000,
			this->linked_player);
	}

	{
		Vec3_32 effectPosition;
		effectPosition.set(
			(this->collisionSelfPos.x + this->collisionActorPos.x) >> 1,
			(this->collisionSelfPos.y + this->collisionActorPos.y) >> 1,
			0x200000);
		func_02022b64(0xba, &effectPosition);
		func_02022b64(0xbb, &effectPosition);
		func_02022b64(0xbc, &effectPosition);
	}
	func_02012398(0x70, &soundPosition);
	this->destroy(true);
}

void StageEntity::shellStarted(PlayerActor &player)
{
	this->linked_player = player.linked_player;
	this->getScorePointsRegular(
		player.cycleStandardScoreCombo(), 0, 0x18000,
		this->linked_player);

	{
		Vec3_32 effectPosition;
		effectPosition.set(
			(this->collisionSelfPos.x + this->collisionActorPos.x) >> 1,
			(this->collisionSelfPos.y + this->collisionActorPos.y) >> 1,
			0x200000);
		func_02022b64(0xd2, &effectPosition);
		func_02022b64(0xd3, &effectPosition);
	}

	this->direction = this->isBehindTarget(&player);
	fx32 playerVelocity = player.velocity.x;
	fx32 shellVelocity = data_ov000_020c1f40[this->direction];
	u8 playerVelocityDirection =
		((u32)playerVelocity & 0x80000000) >> 31;
	if (this->direction == playerVelocityDirection) {
		shellVelocity += playerVelocity >> 1;
	}
	this->velocity.x = shellVelocity;
	func_02012398(0x70, &this->position);
	this->shellKicked();
	this->updateStateID = 9;
}

void StageEntity::onSpinDrillHit()
{
	Game::getPlayer(this->linked_player);
	if (this->scoreType == 0) {
		this->getScorePointsRegular(1, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsRegular(4, 0, 0x18000, this->linked_player);
	}
	this->activeCollider.unlink();
	this->direction = this->collisionDirection;
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

bool StageEntity::setSpinDrillCollision(const PlayerActor &player)
{
	if ((this->properties & ObjectInfo::EP_SpinDrill) == 0) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_SpinDrill;
	return true;
}

void StageEntity::_27()
{
	Game::getPlayer(this->linked_player);
	if (this->scoreType == 0) {
		this->getScorePointsRegular(1, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsRegular(4, 0, 0x18000, this->linked_player);
	}
	this->activeCollider.unlink();
	this->direction = this->collisionDirection;

	{
		Vec3_32 effectPosition(
			this->collisionSelfPos.x, this->collisionSelfPos.y, 0x200000);
		func_02022b64(0x86, &effectPosition);
	}
	this->_43(data_ov000_020c1f68[this->direction], 0x4000, 0);
}

bool StageEntity::setBlueShellCollision(const PlayerActor &player)
{
	if (this->properties & ObjectInfo::EP_NoBlueShell) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_BlueShell;
	return true;
}

void StageEntity::func_ov000_0209da00()
{
	StageEntity::func_ov000_0209da0c();
}

void StageEntity::func_ov000_0209da0c()
{
	for (u16 i = 0; i < 32; ++i) {
		data_ov000_020ca4cc[i].unk0 = 0;
		data_ov000_020ca4cc[i].unk4 = 0;
		data_ov000_020ca4cc[i].unk8 = 0;
	}
}

void func_ov000_0209e5a8(u32 x, u32 y, s32 playerId)
{
	x &= data_02085aa4;
	if (playerId == -1) {
		playerId = 3;
	}
	u32 alignedX = x & ~0xfff;
	i32 alignedY = y & ~0xfff;

	Stage::stageLayout->changeTile(
		(u16)(alignedX >> 12),
		(u16)-(alignedY >> 12),
		0,
		0
	);

	Vec3_32 position;
	position.x = alignedX;
	position.y = alignedY;
	position.z = 0;
	Actor::spawnActor(0x42, (((u8)playerId & 0xf) << 12) | 9, &position, 0, 0, 0);
}

i8 data_ov000_020c1f50[2];
void StageEntity::func_ov000_0209e264(u32 x, u32 y, u32 param_3)
{
	Vec3_32 vec;
	vec.x = 0;
	vec.y = 0;
	vec.z = 0;

	vec.x = x + this->position.x;
	vec.y = y + this->position.y;
	func_ov010_020e657c(data_ov000_020c1f50[param_3], &vec, ~0);
	return;
}

u8 data_ov000_020c1f38[2];
i32 data_ov000_020c1f58[2];
void StageEntity::func_ov000_020a01b4()

{
	this->updateStateID = 0;
	this->backLayer = this->backLayer ^ 1;
	this->activeCollider._a4 = data_ov000_020c1f38[this->backLayer];
	this->position.z = data_ov000_020c1f58[this->backLayer];
	this->_45();
	return;
}

void StageEntity::func_ov000_020a020c()

{
	if (this->updateStateID == 0) {
		this->updateStateID = 4;
		this->_44();
		return;
	}
	return;
}

void StageEntity::defeat(
	i32 velocityX, i32 velocityY, i32 accelerationY, u8 defeatArgument)
{
	s32 playerID = 0;
	if (func_020202a0() > 0) {
		do {
			PlayerBase *player =
				static_cast<PlayerBase *>(Game::getPlayer(playerID));
			if (player != 0 && player->linkedActor == this) {
				player->func_ov011_0212bde0(this);
			}
			++playerID;
		} while (playerID < func_020202a0());
	}

	if (this->backLayer) {
		this->rotation.y = 0;
		this->position.z = -0x180000;
	} else {
		this->rotation.y =
			StageEntity::directionalRotationY[this->direction] << 1;
		this->position.z = 0x180000;
	}
	this->defeatedArg = defeatArgument;
	this->quicksandFlag = false;
	this->permanentDestroy = true;
	this->accelV = accelerationY;
	this->defeatedInLiquid = this->liquidFlag;
	this->velocity.x = velocityX;
	this->velocity.y = velocityY;
	this->velocity.z = 0;
	this->minVelocity.y = -0x4000;
	this->collisionMgr.flags = 0;
	this->updateStateID = 2;
}

void StageEntity::_43(u32 param_1, u32 param_2, u32 param_3)
{
	this->defeat(param_1, param_2, param_3, 0);
	this->updateStateID = 3;
	func_02012398(0x178, &this->position);
	return;
}

i16 data_ov000_020c1f44[2];
void StageEntity::shellKicked()
{
	PlayerBase *player = static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	this->activeCollider._a4 = player->activeCollider._a4;
	this->collisionMgr._b7 = player->activeCollider._a4;
	if ((player->collisionFlag & PlayerBase::CF_Ground) == 0 && player->velocity.y < 0) {
		Vec2_32 pos;
		u8 side = ((u32)this->velocity.x & 0x80000000) >> 31;
		fx32 baseX = this->position.x + this->centerOffset.x;
		fx32 baseY = this->position.y + this->centerOffset.y;
		pos.x = baseX + StageEntity::unitDirection[side] * 0x10000;
		pos.y = baseY;
		if (CollisionMgr::getSolidTileType(pos.x, pos.y)) {
			u32 wrappedX = (this->position.x + this->centerOffset.x) & 0xffff;
			if (wrappedX > 0x400 && wrappedX <= 0x8000) {
				i32 speed = this->velocity.x;
				if (speed < 0) {
					speed = -speed;
				}
				if (speed < 0x2c00) {
					this->kickedInWall = true;
				}
			}
		}
	}
	if (this->kickedInWall) {
		this->kickedInWallDistance = 0;
		this->velocity.x = (i16)data_ov000_020c1f44[this->direction];
		this->playerCollisionCooldown[this->linked_player] = 5;
	} else {
		this->playerCollisionCooldown[this->linked_player] = 0x10;
	}
	this->activeCollider.detectGroups |= 0x140;
	this->activeCollider.attack = 0xa;
	this->activeCollider.callback = (void *)shellActiveCallback;
	this->accelH = 0x100;
	this->accelV = -0x300;
	this->minVelocity.x = this->velocity.x;
	this->minVelocity.y = -0x4000;
	this->minVelocity.z = 0;
}

void StageEntity::_45()
{
	this->direction ^= 1;
	this->velocity.x = -(this->velocity).x;
	this->activeCollider.callback = (void *)damagePlayerCallback;
}

void StageEntity::_44()
{
	this->activeCollider.callback = (void *)0x0;
}

i16 data_ov000_020c4ed4[2];
void StageEntity::_21()
{
	this->activeCollider.unlink();
	(this->minVelocity).y = -0x4000;
	func_02012398(0x70, &this->position);
	this->direction = this->blockHitDirection;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, 0xfffffd00, 0);
}

void StageEntity::_22()
{
	this->direction = this->collisionDirection;
	this->activeCollider.unlink();
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, 0xfffffd00, 0);
}

void StageEntity::postUpdate(u32 a)
{
	if ((u8)(Stage::actorFreezeFlag & 0xa6) == 0) {
		this->_2bf = 0x0;
	}
	StageActor::postUpdate(a);
}

bool StageEntity::preRender()
{
	bool result = Actor::preRender();
	if (result == 0) {
		return false;
	}
	result = this->_01();
	return result == 0;
}

bool StageEntity::onUpdate_1()
{
	return true;
}
bool StageEntity::onUpdate_defeated()
{
	if (this->relativeDefeatSpin != 0x0) {
		if (this->direction != '\0') {
			this->rotation.x += -0x300;
		} else {
			this->rotation.x += 0x300;
		}
	} else {
		this->rotation.x += 0x300;
	}
	this->updateVerticalVelocity();
	this->applyMovement();
	this->updateLiquids(0xfffffd00);
	this->_11();
	this->destroyInactive(((u32)(this->properties & 2) << 0xf) >> 0x10);
	return true;
}
bool StageEntity::onUpdate_3()
{
	if (this->relativeDefeatSpin != 0x0) {
		u16 rotation = this->rotation.x;
		if (this->direction != '\0') {
			rotation -= 0xc00;
		} else {
			rotation += 0xc00;
		}
		this->rotation.x = rotation;
	} else {
		this->rotation.x += 0xc00;
	}
	this->applyVelocity();
	this->updateVerticalVelocity();
	this->_11();
	this->destroyInactive(((u32)(this->properties & 2) << 0xf) >> 0x10);
	return true;
}
bool StageEntity::onUpdate_4()
{
	return true;
}

bool StageEntity::updateCarriedCollision() {

	fx32 dummy = StageEntity::unitDirection[direction];
	func_01ffe778(&collisionMgr, &dummy, 0);

	if (properties & 0x8000) {

		// Vec3_32 pos;
		// pos.x = position.x;
		// pos.y = position.y;
		// pos.z = position.z;
		// pos.add(centerOffset);

		// Not allowed to be inlined!!
		//Vec3_32 pos = position.add(centerOffset);

		Vec3_32 pos;
		pos = position;
		pos.add2(centerOffset);
		//Vec3_32s* r = &pos;
		//r->x = position.x;
		//r->y = position.y;
		//r->z = position.z;
		//NDS::Math::addVector32(&pos, &centerOffset, r);

		if (collisionMgr.getSolidTileType(pos.x, pos.y))
			return true;

	}

	return false;

}

bool StageEntity::tryGrab(PlayerActor &player)
{
	if (!player.carry(*this)) {
		return false;
	}
	this->linked_player = player.linked_player;
	this->updateStateID = 5;
	this->grabbed();
	return true;
}

bool StageEntity::updateCarried()
{
	if (linked_player == -1) {
		return true;
	}
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(linked_player));
	tryAttachToPlayerHands(0x4000, -0x2000, 0);

	if (carriedAction & 1) {
			_16();
			Vec3_32 *playerVelocity = &player->velocity;
			if (carriedAction & 2) {
				fx32 throwX;
				direction = playerDirection;
				rotation.y = directionalRotationY[direction];
				fx32 halfPlayerVelocity =
					playerVelocity->x >> 1;
				if (object_id == 0x23 || object_id == 0xed) {
					throwX = data_ov000_020c1f44[direction];
				} else {
				throwX = data_ov000_020c1f40[direction];
			}

			u8 playerVelocityDirection =
					((u32)player->velocity.x &
					 0x80000000) >> 31;
				if (direction == playerVelocityDirection) {
					throwX += halfPlayerVelocity;
				}

			if (throwX < minVelocity.x) {
				throwX = Math::min(throwX, minVelocity.x);
			} else if (throwX > minVelocity.x) {
				throwX = Math::max(throwX, minVelocity.x);
			}

			velocity.set(throwX, releaseForceY, 0);
			if (updateCarriedCollision()) {
				activeCollider.unlink();
				func_02012398(0x70, &position);
				getScorePointsRegular(
					1, 0, 0x18000,
					player->linked_player);
				defeat(0, 0x3000, -0x300, 0);
				_11();
				return true;
			}
			if ((collisionMgr.flags &
			     (0x15 << direction)) == 0) {
				position.x +=
					unitDirection[direction] * 0x6000;
			}
			accelV = -0x300;
			thrownFlag = 1;
		} else {
			direction = playerDirection;
			rotation.y = directionalRotationY[direction];
			fx32 releaseVelocity;
			if (object_id == 0x23) {
				releaseVelocity =
					unitDirection[direction] * 0x600;
			} else {
				releaseVelocity =
					unitDirection[direction] *
					data_ov000_020c1f9c[releaseMode];
			}
			velocity.x = releaseVelocity;
			velocity.y = 0;
			velocity.z = 0;
			if (updateCarriedCollision()) {
				activeCollider.unlink();
				func_02012398(0x70, &position);
				getScorePointsRegular(
					1, 0, 0x18000,
					player->linked_player);
				defeat(0, 0x3000, -0x300, 0);
				_11();
				return true;
			}
			if ((collisionMgr.flags &
			     (0x15 << direction)) == 0) {
				position.x +=
					unitDirection[direction] * 0x6000;
			}
			position.y += 0x2000;
			accelV = -0x300;
			thrownFlag = 0;
		}

		if (checkSquished()) {
			getScorePointsRegular(
				1, 0, 0x18000, player->linked_player);
			_35();
			return true;
		}

		minVelocity.x = unitDirection[direction] * 0x6000;
		minVelocity.y = -0x4000;
		minVelocity.z = 0;
		carriedAction &= ~2;
		carriedAction &= ~1;
		if (releaseMode == 0) {
			updateStateID = 6;
		} else if (releaseMode == 1) {
			updateStateID = 7;
		} else {
			updateStateID = 8;
		}
		linked_player = player->linked_player;
		_12();
	}

	updateLiquids(-0x300);
	_11();
	return true;
}
bool StageEntity::onUpdate_6()
{
	this->_11();
	return true;
}
bool StageEntity::onUpdate_7()
{
	if (BOOL(data_02085a84 != 0) != FALSE) {
		Vec3_32 collisionPosition =
			func_02045bdc(position, centerOffset);
		if (CollisionMgr::getSolidTileType(
			    collisionPosition.x, collisionPosition.y)) {
			_35();
			return true;
		}
	}

	updateVerticalVelocity();
	applyMovement();
	updateBottomSensors();
	collisionMgr.func_ov000_020aa990(collisionMgr.flags);
	updateSideSensors();

	if (checkSquished()) {
		getScorePointsRegular(1, 0, 0x18000, linked_player);
		_35();
		return true;
	}

	if (collisionMgr.flags & 0x1f40) {
		if (thrownFlag == 1 && (properties & 0x8000)) {
			updateStateID = 9;
			_11();
			_13();
			shellKicked();
			return true;
		}

		updateBounce(0x300, 0x800, 0x800);
		if (velocity.y == 0) {
			updateStateID = 0;
			velocity.x = 0;
			_13();
			linked_player = -1;
			_11();
			return true;
		}
	} else if (collisionMgr.flags & 0xe000) {
		velocity.y = -0xd00;
	}

	u8 side = direction;
	if (collisionMgr.flags & (0x15 << side)) {
		direction = side ^ 1;
		velocity.x = -velocity.x;
		minVelocity.x = -minVelocity.x;
		func_02012398(0x16f, &position);
	}

	updateLiquids(-0x300);
	_11();
	destroyInactive(((u32)(properties & 2) << 0xf) >> 0x10);
	return true;
}
bool StageEntity::updateDroppedHeavy()
{
	updateVerticalVelocity();
	applyMovement();
	updateBottomSensors();
	collisionMgr.func_ov000_020aa990(collisionMgr.flags);
	updateSideSensors();

	if (checkSquished()) {
		getScorePointsRegular(1, 0, 0x18000, linked_player);
		_35();
		return true;
	}

	if (collisionMgr.flags & 0x1f40) {
		updateBounce(0x300, 0x800, 0x800);
		if (velocity.y == 0) {
			updateStateID = 0;
			velocity.x = 0;
			_13();
			linked_player = -1;
		}
	} else if (collisionMgr.flags & 0xe000) {
		velocity.y = -0xd00;
	}

	if (collisionMgr.flags & (0x15 << direction)) {
		fx32 speed;
		if (velocity.x < 0) {
			speed = -velocity.x;
		} else {
			speed = velocity.x;
		}
		velocity.x = -velocity.x;
		speed >>= 1;
		if (speed < 0x1000) {
			speed = 0x1000;
		}
		if (velocity.x < 0) {
			velocity.x = -speed;
		} else {
			velocity.x = speed;
		}
	}

	updateLiquids(-0x300);
	_11();
	return true;
}
bool StageEntity::updateRolling()
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(linked_player));
	platformMgr.unk32 &= ~8;

	if (BOOL(data_02085a84 != 0) != FALSE) {
		Vec3_32 collisionPosition =
			func_02045bdc(position, centerOffset);
		if (CollisionMgr::getSolidTileType(
			    collisionPosition.x, collisionPosition.y)) {
			_35();
			return true;
		}
	}

	applyMovement();
	updateSideSensors();
	updateBottomSensors();
	collisionMgr.func_ov000_020aa990(collisionMgr.flags);

	if (checkSquished()) {
		getScorePointsRegular(1, 0, 0x18000, linked_player);
		_35();
		return true;
	}

	if (kickedInWall) {
		kickedInWallDistance += velocity.x;
		fx32 distance = kickedInWallDistance;
		if (distance < 0) {
			distance = -distance;
		}
		if (distance > 0xc000) {
			kickedInWall = false;
		} else if (player->collisionFlag & PlayerBase::CF_Ground) {
			kickedInWall = false;
			playerCollisionCooldown[linked_player] = 5;
		}
	}

	if (collisionMgr.flags & 0x1f40) {
		velocity.y = -0xa00;
	} else if (collisionMgr.flags & 0xe000) {
		velocity.y = -0xa00;
	}

	if (collisionMgr.flags & (0x15 << direction)) {
		direction ^= 1;
		velocity.x = -velocity.x;
		minVelocity.x = -minVelocity.x;
		velocity.y -= 0xd00;
		func_02012398(0x16f, &position);
	}

	updateLiquids(-0x300);
	if (collisionMgr.flags & 0x1f40) {
		updateHorizontalVelocity();
	}
	updateVerticalVelocity();
	rotation.y += data_ov000_020c4ed0[direction];
	_11();
	destroyInactive(((u32)(properties & 2) << 0xf) >> 0x10);
	return true;
}
void StageEntity::_11()
{
}



















































u16 data_ov000_020c22b8[2];



























void StageEntity::onStomped()
{
}



void StageEntity::setStompCollision(const PlayerActor &player)
{
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_Stomp;
}

bool StageEntity::setMegaKickCollision(const PlayerActor &player)
{
	if (this->properties & ObjectInfo::EP_NoMegaKick) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	return true;
}

void StageEntity::_26()
{
	PlayerActor *player =
		static_cast<PlayerActor *>(Game::getPlayer(this->linked_player));
	if (this->scoreType == 0) {
		this->getScorePointsRegular(1, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsRegular(4, 0, 0x18000, this->linked_player);
	}
	Game::addMegaDestructionScore(this->linked_player, 10);
	this->activeCollider.unlink();
	this->direction = this->collisionDirection;

	fx32 knockback = player->velocity.x - this->velocity.x +
			  ((fx32)StageEntity::unitDirection[this->direction] << 12);
	if (knockback > 0x6000) {
		knockback = 0x6000;
	} else if (knockback < -0x6000) {
		knockback = -0x6000;
	}

	{
		Vec3_32 effectPosition(
			this->collisionSelfPos.x, this->collisionSelfPos.y, 0x200000);
		func_02022b64(0x86, &effectPosition);
	}
	this->_43(knockback, 0x3000, -0x300);
}

void StageEntity::_25()
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	if (player->scoreComboSliding < 10) {
		++player->scoreComboSliding;
	}
	if (player->scoreComboSliding > 8) {
		player->scoreComboSliding = 8;
	}

	s8 scoreCombo = player->scoreComboSliding;
	if (this->scoreType == 0) {
		this->getScorePointsRegular(
			scoreCombo, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsEnhanced(
			scoreCombo, 0, 0x18000, this->linked_player);
	}

	this->direction = this->collisionDirection;
	this->activeCollider.unlink();
	if (player->scoreComboSliding < 8) {
		func_02012398(scoreCombo + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_24()
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(this->linked_player));
	if (player->scoreComboStarman < 10) {
		++player->scoreComboStarman;
	}
	if (player->scoreComboStarman > 8) {
		player->scoreComboStarman = 8;
	}

	s8 scoreCombo = player->scoreComboStarman;
	if (this->scoreType == 0) {
		this->getScorePointsRegular(
			scoreCombo, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsEnhanced(
			scoreCombo, 0, 0x18000, this->linked_player);
	}

	this->direction = this->collisionDirection;
	this->activeCollider.unlink();
	if (player->scoreComboStarman < 8) {
		func_02012398(scoreCombo + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_23()
{
	this->direction = this->collisionDirection;
	this->activeCollider.unlink();
	this->spawnCoin();
	if (this->scoreType == 0) {
		this->getScorePointsRegular(1, 0, 0x18000, this->linked_player);
	} else if (this->scoreType == 1) {
		this->getScorePointsRegular(4, 0, 0x18000, this->linked_player);
	}
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->defeat(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

bool StageEntity::setMegaCollision(const PlayerActor &player)
{
	if (this->properties & ObjectInfo::EP_NoMega) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_Mega;
	return true;
}

void StageEntity::spawnCoin()
{
	Vec3_32 coinPosition = func_02045bdc(position, centerOffset);
	coinPosition.x &= data_02085aa4;
	Actor *coin = Actor::spawnActor(0x42, 5, &coinPosition, 0, 0, 0);
	if (coin != 0) {
		coin->position.x -= 0x8000;
	}
}

bool StageEntity::setFenceSlamCollision(const PlayerActor &player)
{
	if ((this->properties & ObjectInfo::EP_FenceSlam) == 0) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_FenceSlam;
	return true;
}

bool StageEntity::setSlidingCollision(const PlayerActor &player)
{
	if (this->properties & ObjectInfo::EP_NoSliding) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_Sliding;
	return true;
}

bool StageEntity::setStarmanCollision(const PlayerActor &player)
{
	if (this->properties & ObjectInfo::EP_NoStarman) {
		return false;
	}
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_Starman;
	return true;
}

void func_ov000_0209c350()
{
	NDS::Graphics::setClearImageOffset(0x001f001f);
	NDS::Graphics::setFogTable(data_ov000_020c1ff0);
	NDS::Graphics::configureFog(TRUE, 0, 6, 0);

	NDS::Memory::clearFast(0, (u32)data_ov000_020ca3cc, 0x100);
	NDS::Memory::clearFast(0, (u32)data_ov000_020ca64c, 0x100);

	u8 entryIndex = 0;
	do {
		data_ov000_020ca32c[entryIndex].value = 0;
		++entryIndex;
	} while (entryIndex < 10);

	u8 timerIndex = 0;
	do {
		data_ov000_020ca2fc[timerIndex] = 0;
		++timerIndex;
	} while (timerIndex < 24);

	u8 flagIndex = 0;
	do {
		data_ov000_020ca2d4[flagIndex] = 0;
		++flagIndex;
	} while (flagIndex < 8);

	bool spawnForBothPlayers = false;
	data_ov000_020ca2ec[0] = 0;
	data_ov000_020ca2ec[1] = 0;
	data_ov000_020ca2e4[0] = 0;
	data_ov000_020ca2b4 = 0;
	data_ov000_020ca2e4[1] = 0;
	data_ov000_020ca2f4[0] = 0;
	data_ov000_020ca2f4[1] = 0;
	data_ov000_020ca2dc[0] = 0;
	data_ov000_020ca2dc[1] = 0;
	data_ov000_020ca2a8 = 0;
	data_ov000_020ca2b8 = 0;
	data_ov000_020ca2a0 = 0;
	data_ov000_020ca280 = 0;
	data_ov000_020ca290 = 0;
	data_ov000_020ca2b0 = 0;
	data_ov000_020ca294 = 0;
	data_ov000_020ca288 = 0;
	data_ov000_020ca29c = 0;
	data_ov000_020ca298 = -1;

	if (data_02085abc & 1) {
		return;
	}

	if (data_02085a84 != 0) {
		spawnForBothPlayers = true;
	}
	if (spawnForBothPlayers) {
		Vec3_32 position(0);
		Actor::spawnActor(0x21, 0, &position, 0, 0, 0);
		func_ov000_0209aff8(0, false);
		func_ov000_0209aff8(1, false);
		return;
	}
	func_ov000_0209aff8(data_020887f0, false);
}

void func_ov000_0209c2f8(u8 playerID)
{
	if (data_02085abc & 1) {
		return;
	}
	data_ov000_020ca2ec[playerID] = 0;
	data_ov000_020ca2e4[playerID] = 0;
	data_ov000_020ca2f4[playerID] = 0;
	data_ov000_020ca2dc[playerID] = 0;
	func_ov000_0209aff8(playerID, true);
}

void func_ov000_0209c288()
{
	u8 *flags = data_ov000_020ca3cc;
	u16 *timers = data_ov000_020ca64c;
	StageRuntimeEntry *entry = data_0208b168.entries;

	if (entry->id == 0xffff) {
		return;
	}
	do {
		if (*timers != 0) {
			--*timers;
			if (*timers == 1) {
				*flags &= ~1;
			}
		}
		++entry;
		++flags;
		++timers;
	} while (entry->id != 0xffff);
}

StageEntity *func_ov000_0209c178(
	u32 spriteID, u32 settings, Vec3_32 *position)
{
	u16 actorID = data_ov000_020c22b8[spriteID];
	if (actorID == 0x145) {
		return 0;
	}

	ObjectInfo &objectInfo = data_ov000_020c529c[spriteID];
	StageEntity *entity = static_cast<StageEntity *>(
		Actor::spawnActor(actorID, settings, position, 0, 0, 0));
	if (entity == 0) {
		return entity;
	}
	if (spriteID < 10) {
		return entity;
	}

	entity->properties = objectInfo.properties;
	entity->spawnSettings = objectInfo.spawnSettings;
	entity->unused3E0 = false;

	if (entity->activeSize.x == 0 &&
	    entity->activeSize.y == 0) {
		entity->activeSize.x = (u16)objectInfo.size.x << 4;
		entity->activeSize.y = (u16)objectInfo.size.y << 4;
	}
	if (entity->viewOffset.x == 0 &&
	    entity->viewOffset.y == 0) {
		entity->viewOffset.x = objectInfo.viewOffset.x;
		entity->viewOffset.y = -objectInfo.viewOffset.y;
	}
	if (entity->renderSize.x == 0 &&
	    entity->renderSize.y == 0) {
		entity->renderSize.x = entity->activeSize.x;
		entity->renderSize.y = entity->activeSize.y;
	}
	return entity;
}

StageEntity *func_ov000_0209bf10(
	StageRuntimeEntry *entry, const ObjectInfo *objectInfo,
	u8 *spawnFlags, u16 *spawnTimer, u8 viewID, u32 playerID)
{
	if (data_ov000_020c22b8[entry->id] == 0x145) {
		return 0;
	}

	Vec3_32 position(
		((entry->x << 4) + objectInfo->position.x) << 12,
		-(((entry->y << 4) + objectInfo->position.y) << 12),
		0x80000);

	data_ov000_020ca2ac = spawnFlags;
	data_ov000_020ca2a4.value = entry->eventIDs;
	data_ov000_020ca2cc = 0;
	if (data_ov000_020ca2a4.ids[0] != 0) {
		data_ov000_020ca2cc |=
			1ULL <<
			(data_ov000_020ca2a4.ids[0] - 1);
	}
	if (data_ov000_020ca2a4.ids[1] != 0) {
		data_ov000_020ca2cc |=
			1ULL <<
			(data_ov000_020ca2a4.ids[1] - 1);
	}

	StageEntity *entity = static_cast<StageEntity *>(
		Actor::spawnActor(
			data_ov000_020c22b8[entry->id],
			entry->settings, &position,
			0, 0, 0));
	if (entity != 0) {
		if (entry->id >= 10) {
			entity->_2be = viewID;
			entity->objectSpawnFlags = spawnFlags;
			entity->objectRespawnTimer = spawnTimer;
			entity->eventIDs =
				data_ov000_020ca2a4.value;
			entity->eventMask =
				data_ov000_020ca2cc;
			entity->properties =
				objectInfo->properties;
			entity->spawnSettings =
				objectInfo->spawnSettings;
			entity->unused3E0 = false;

			if (entity->activeSize.x == 0 &&
			    entity->activeSize.y == 0) {
				entity->activeSize.x =
					(u16)objectInfo->size.x
					<< 4;
				entity->activeSize.y =
					(u16)objectInfo->size.y
					<< 4;
			}
			if (entity->viewOffset.x == 0 &&
			    entity->viewOffset.y == 0) {
				entity->viewOffset.x =
					objectInfo->viewOffset.x;
				entity->viewOffset.y =
					-objectInfo->viewOffset.y;
			}
			if (entity->renderSize.x == 0 &&
			    entity->renderSize.y == 0) {
				entity->renderSize.x =
					entity->activeSize.x;
				entity->renderSize.y =
					entity->activeSize.y;
			}
			entity->updateStateID = 0;
			entity->spawnPlayerID = playerID;
		}
		*spawnFlags |= 1;
	}
	return entity;
}

bool func_ov000_0209bddc(
	const StageRuntimeEntry *entry, const ObjectInfo *objectInfo,
	u32 playerID)
{
	u8 wrapEnabled =
		data_0208b168.info->value02 & 0x20;
	i32 cameraHalfWidth =
		data_ov000_020cada4[playerID] >> 13;
	i32 cameraCenterX =
		cameraHalfWidth +
		(data_ov000_020cae1c[playerID] >> 12);
	i32 cameraHalfHeight =
		Game::cameraZoomY[playerID] >> 13;
	i32 cameraCenterY =
		cameraHalfHeight +
		(Game::cameraY[playerID] >> 12);

	i32 objectWidth = (u16)objectInfo->size.x << 4;
	i32 objectHeight = (u16)objectInfo->size.y << 4;
	i32 objectX =
		(entry->x + objectInfo->spawnOffset.x) << 4;
	i32 objectY =
		(entry->y + objectInfo->spawnOffset.y) << 4;
	i32 objectHalfWidth = objectWidth >> 1;
	i32 objectCenterX = objectX + objectHalfWidth;
	i32 objectHalfHeight = objectHeight >> 1;
	i32 objectCenterY = objectY + objectHalfHeight;

	if (wrapEnabled != 0 &&
	    data_02085a98 != 1) {
		i32 wrappedDistance = cameraCenterX - objectCenterX;
		wrappedDistance = wrappedDistance < 0
					  ? -wrappedDistance
					  : wrappedDistance;
		i32 wrapWidth = (data_02085aa4 + 1) >> 12;
		i32 wrapHalfWidth = wrapWidth >> 1;
		if (wrappedDistance >= wrapHalfWidth) {
			if (cameraCenterX > wrapHalfWidth) {
				if (objectCenterX < wrapHalfWidth) {
					objectCenterX += wrapWidth;
				}
			} else if (objectCenterX > wrapHalfWidth) {
				objectCenterX -= wrapWidth;
			}
		}
	}

	i32 distanceX = cameraCenterX - objectCenterX;
	distanceX = distanceX < 0 ? -distanceX : distanceX;
	i32 maxDistanceX = cameraHalfWidth + objectHalfWidth;
	maxDistanceX =
		maxDistanceX < 0 ? -maxDistanceX : maxDistanceX;
	if (distanceX <= maxDistanceX) {
		i32 distanceY = cameraCenterY - objectCenterY;
		distanceY =
			distanceY < 0 ? -distanceY : distanceY;
		i32 maxDistanceY =
			cameraHalfHeight + objectHalfHeight;
		maxDistanceY = maxDistanceY < 0
				       ? -maxDistanceY
				       : maxDistanceY;
		if (distanceY <= maxDistanceY) {
			return true;
		}
	}
	return false;
}

void func_ov000_0209ba94(
	StageEntityTileSweep *sweep, u32 playerID, bool moving)
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(playerID));
	u8 viewID = player->_2be;
	u32 entryCount = data_0208b220[viewID];
	if (entryCount == 0) {
		return;
	}

	u16 *spawnTimer;
	i32 entryIndex;
	i32 checkX;
	i32 checkY;
	i32 horizontalDirection;
	i32 verticalDirection;
	u32 otherPlayerID;
	i32 left;
	i32 right;
	i32 top;
	i32 bottom;
	const ObjectInfo *objectInfo;
	StageRuntimeEntry *entry;
	u16 collisionCount;
	i32 objectCheckX;
	i32 objectCheckY;
	i32 objectLeft;
	i32 objectRight;
	i32 objectBottom;
	i32 objectTop;
	u8 *spawnFlags;

	entry = data_0208b1a0[viewID];
	u32 entryOffset = data_0208b2a0[viewID];
	spawnFlags = &data_ov000_020ca3cc[entryOffset];
	spawnTimer = &data_ov000_020ca64c[entryOffset];

	checkX = sweep->checkX;
	checkY = sweep->checkY;
	left = sweep->left;
	entryIndex = 0;
	horizontalDirection = sweep->horizontalDirection;
	right = sweep->right;
	verticalDirection = sweep->verticalDirection;
	top = sweep->top;
	bottom = sweep->bottom;

	if (entryCount == 0) {
		return;
	}

	otherPlayerID = playerID ^ 1;
	do {
		if ((*spawnFlags & 1) == 0) {
			objectInfo =
				&data_ov000_020c529c[entry->id];
			objectLeft =
				entry->x +
				objectInfo->spawnOffset.x;
			objectTop =
				entry->y +
				objectInfo->spawnOffset.y;
			objectRight =
				objectLeft +
				(u16)objectInfo->size.x;
			collisionCount = 0;
			objectBottom =
				objectTop +
				(u16)objectInfo->size.y;

			u8 wrapEnabled =
				data_0208b168.info->value02 &
				0x20;
			if (wrapEnabled != 0 &&
			    data_02085aa4 != 0xfffff) {
				i32 wrapMask =
					data_02085aa4 >> 16;
				objectLeft &= wrapMask;
				objectRight &= wrapMask;
			}

			objectCheckX =
				horizontalDirection != 0
					? objectLeft
					: objectRight;
			objectCheckY =
				verticalDirection != 0
					? objectTop
					: objectBottom;

			if (moving == true) {
				if (objectCheckX == checkX) {
					if (horizontalDirection != 1) {
						if (horizontalDirection < 0) {
							if (right == objectLeft &&
							    bottom >= objectTop &&
							    top <= objectBottom) {
								++collisionCount;
							}
						} else {
							if (left == objectRight &&
							    bottom >= objectTop &&
							    top <= objectBottom) {
								++collisionCount;
							}
						}
					}
				} else if (objectCheckY == checkY) {
					if (verticalDirection != 1) {
						if (verticalDirection < 0) {
							if (bottom == objectTop &&
							    right >= objectLeft &&
							    left <= objectRight) {
								++collisionCount;
							}
						} else {
							if (top == objectBottom &&
							    right >= objectLeft &&
							    left <= objectRight) {
								++collisionCount;
							}
						}
					}
				}
			} else {
				if (objectCheckX == checkX &&
				    bottom >= objectTop &&
				    top <= objectBottom) {
					++collisionCount;
				}
				if (objectCheckY == checkY &&
				    right >= objectLeft &&
				    left <= objectRight) {
					++collisionCount;
				}
			}

			if (collisionCount != 0 &&
			    func_020202a0() == 2 &&
			    func_ov000_0209bddc(
				    entry, objectInfo,
				    otherPlayerID)) {
				collisionCount = 0;
			}
			if (collisionCount != 0) {
				func_ov000_0209bf10(
					entry, objectInfo,
					spawnFlags, spawnTimer,
					viewID, playerID);
			}
		}

		++entry;
		++spawnFlags;
		++spawnTimer;
		++entryIndex;
	} while (entryIndex != entryCount);
}

void func_ov000_0209b7e8(u32 playerID)
{
	i32 checkX;
	i32 checkY;
	i32 bottom;
	Vec3_32 position;
	i32 cameraZoomY = Game::cameraZoomY[playerID] >> 12;
	i32 cameraExtent = data_ov000_020cada4[playerID] >> 12;
	i32 currentX = data_ov000_020cae1c[playerID] >> 12;
	i32 currentY = Game::cameraY[playerID] >> 12;

	i32 left = (currentX - 0x20) >> 4;
	i32 right = (cameraExtent + 0x30 + currentX) >> 4;
	i32 top = (currentY - 0x10) >> 4;
	bottom = (cameraZoomY + 0x20 + currentY) >> 4;

	i32 horizontalDirection = 0;
	i32 verticalDirection = 0;
	u8 wrapEnabled =
		data_0208b168.info->value02 & 0x20;
	if (wrapEnabled != 0 &&
	    data_02085aa4 != 0xfffff) {
		i32 wrapMask = data_02085aa4 >> 16;
		right &= wrapMask;
		left &= wrapMask;
	}

	StageEntityTileSweep sweep;
	if (data_ov000_020cadb4[playerID] !=
	    data_ov010_0212ae6c[playerID]) {
		sweep.checkX = left;
		sweep.checkY = bottom;
		sweep.left = left;
		sweep.right = right;
		sweep.top = top;
		sweep.bottom = bottom;

		sweep.horizontalDirection = 0;
		sweep.verticalDirection = -1;
		func_ov000_0209ba94(&sweep, playerID, false);

		sweep.checkX = right;
		sweep.checkY = bottom;
		sweep.left = left;
		sweep.right = right;
		sweep.top = top;
		sweep.bottom = bottom;
		sweep.horizontalDirection = -1;
		sweep.verticalDirection = -1;
		func_ov000_0209ba94(&sweep, playerID, false);

		data_ov000_020ca2ec[playerID] = currentX;
		data_ov000_020ca2e4[playerID] = currentY;

		checkX = right;
		checkY = top;
		sweep.checkX = checkX;
		sweep.checkY = checkY;
		sweep.horizontalDirection = -1;
		sweep.verticalDirection = 0;
		func_ov000_0209ba94(&sweep, playerID, false);
	} else {
		i32 deltaX =
			currentX - data_ov000_020ca2ec[playerID];
		i32 deltaY =
			currentY - data_ov000_020ca2e4[playerID];
		if (deltaX != 0) {
			if (deltaX > 0) {
				checkX = right;
				horizontalDirection = -1;
			} else {
				checkX = left;
			}
		} else {
			horizontalDirection = 1;
		}

		if (deltaY != 0) {
			if (deltaY > 0) {
				checkY = bottom;
				verticalDirection = -1;
			} else {
				checkY = top;
			}
		} else {
			verticalDirection = 1;
		}

		if (checkX ==
			    (i32)data_ov000_020ca2f4[playerID] &&
		    checkY ==
			    (i32)data_ov000_020ca2dc[playerID]) {
			data_ov000_020ca2ec[playerID] = currentX;
			data_ov000_020ca2e4[playerID] = currentY;
			data_ov000_020ca2f4[playerID] = checkX;
			data_ov000_020ca2dc[playerID] = checkY;
			return;
		}

		sweep.checkX = checkX;
		sweep.checkY = checkY;
		sweep.left = left;
		sweep.right = right;
		sweep.top = top;
		sweep.bottom = bottom;
		sweep.horizontalDirection = horizontalDirection;
		sweep.verticalDirection = verticalDirection;
		func_ov000_0209ba94(&sweep, playerID, true);
	}

	data_ov000_020ca2ec[playerID] = currentX;
	data_ov000_020ca2e4[playerID] = currentY;
	data_ov000_020ca2f4[playerID] = checkX;
	data_ov000_020ca2dc[playerID] = checkY;
}

void func_ov000_0209b764()
{
	if (data_ov000_020ca288 != 0) {
		return;
	}
	if (data_02085abc & 1) {
		return;
	}
	if (data_02085abc & 2) {
		return;
	}

	if (func_020202a0() == 1) {
		func_ov000_0209b7e8(data_020887f0);
		return;
	}

	func_ov000_0209c288();
	func_ov000_0209b7e8(0);
	func_ov000_0209b7e8(1);
}

void func_ov000_0209b688(u8 playerID)
{
	const ObjectInfo *objectInfo;
	StageRuntimeEntry *entry = data_0208b168.entries;
	u8 *spawnFlags = data_ov000_020ca3cc;
	u16 *spawnTimer = data_ov000_020ca64c;
	if (entry->id == 0xffff) {
		return;
	}

	do {
		if ((*spawnFlags & 1) == 0) {
			objectInfo =
				&data_ov000_020c529c[entry->id];
			Unk0201ef94Input input;
			input.x =
				(entry->x +
				 objectInfo->spawnOffset.x) << 4;
			input.y =
				(entry->y +
				 objectInfo->spawnOffset.y) << 4;
			input.width =
				(u16)objectInfo->size.x << 4;
			input.height =
				(u16)objectInfo->size.y << 4;
			u8 viewID = func_0201ef94(&input);
			func_ov000_0209bf10(
				entry, objectInfo, spawnFlags,
				spawnTimer, viewID, playerID);
		}

		++entry;
		++spawnFlags;
		++spawnTimer;
	} while (entry->id != 0xffff);
}

void func_ov000_0209b320(u8 playerID)
{
	const ObjectInfo *objectInfo;
	StageRuntimeEntry *entry = data_0208b168.entries;
	u16 *spawnTimer = data_ov000_020ca64c;
	u8 *spawnFlags = data_ov000_020ca3cc;
	u16 collisionCount;
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(playerID));
	u8 playerViewID = player->_2be;
	u8 viewID;

	i32 cameraZoomY =
		Game::cameraZoomY[playerID] >> 12;
	i32 cameraExtent =
		data_ov000_020cada4[playerID] >> 12;
	i32 cameraX =
		data_ov000_020cae1c[playerID] >> 12;
	i32 cameraY =
		Game::cameraY[playerID] >> 12;
	i32 top = cameraY - 0x10;
	i32 cameraHalfHeight =
		(cameraZoomY + 0x20 + cameraY - top) >> 1;
	i32 cameraCenterY = top + cameraHalfHeight;
	i32 left = cameraX - 0x20;
	i32 cameraHalfWidth =
		(cameraExtent + 0x30 + cameraX - left) >> 1;
	i32 wrapWidth = (data_02085aa4 + 1) >> 12;
	i32 cameraCenterX = left + cameraHalfWidth;
	i32 wrapHalfWidth = wrapWidth >> 1;

	if (entry->id == 0xffff) {
		return;
	}

	do {
		if ((*spawnFlags & 1) == 0) {
			objectInfo =
				&data_ov000_020c529c[entry->id];
			collisionCount = 0;
			u16 listIndex = 0;
			while (data_ov000_020c4ee0[listIndex] !=
			       0xffff) {
				if (entry->id ==
				    data_ov000_020c4ee0[listIndex]) {
					break;
				}
				++listIndex;
			}

			if (data_ov000_020c4ee0[listIndex] !=
			    0xffff) {
				++collisionCount;
			} else {
				Unk0201ef94Input input;
				input.x =
					(entry->x +
					 objectInfo->spawnOffset.x)
					<< 4;
				input.y =
					(entry->y +
					 objectInfo->spawnOffset.y)
					<< 4;
				input.width =
					(u16)objectInfo->size.x
					<< 4;
				input.height =
					(u16)objectInfo->size.y
					<< 4;
				viewID = func_0201ef94(&input);

				if (viewID == playerViewID) {
					if (entry->id == 0x12a &&
					    (u8)(data_0208b168
							 .info
							 ->value02 &
						 0x20) != 0 &&
					    data_02085aa4 != 0xfffff) {
						++collisionCount;
					}

					if (objectInfo->spawnSettings &
					    ObjectInfo::SS_AlwaysLoad) {
						++collisionCount;
					} else {
						i32 objectWidth =
							(u16)objectInfo
								->size.x
							<< 4;
						i32 objectHeight =
							(u16)objectInfo
								->size.y
							<< 4;
						i32 objectX =
							(entry->x +
							 objectInfo
								 ->spawnOffset
								 .x)
							<< 4;
						i32 objectY =
							(entry->y +
							 objectInfo
								 ->spawnOffset
								 .y)
							<< 4;
						i32 objectCenterX =
							objectX +
							(objectWidth >>
							 1);
						i32 objectCenterY =
							objectY +
							(objectHeight >>
							 1);

						if ((u8)(data_0208b168
								 .info
								 ->value02 &
							 0x20) != 0 &&
						    data_02085a98 != 1) {
							i32 wrappedDistance =
								cameraCenterX -
								objectCenterX;
							wrappedDistance =
								wrappedDistance <
										0
									? -wrappedDistance
									: wrappedDistance;
							if (wrappedDistance >=
							    wrapHalfWidth) {
								if (cameraCenterX >
								    wrapHalfWidth) {
									if (objectCenterX <
									    wrapHalfWidth) {
										objectCenterX +=
											wrapWidth;
									}
								} else if (
									objectCenterX >
									wrapHalfWidth) {
									objectCenterX -=
										wrapWidth;
								}
							}
						}

						i32 distanceX =
							cameraCenterX -
							objectCenterX;
						distanceX =
							distanceX < 0
								? -distanceX
								: distanceX;
						i32 maxDistanceX =
							cameraHalfWidth +
							(objectWidth >>
							 1);
						maxDistanceX =
							maxDistanceX < 0
								? -maxDistanceX
								: maxDistanceX;
						if (distanceX <=
						    maxDistanceX) {
							i32 distanceY =
								cameraCenterY -
								objectCenterY;
							distanceY =
								distanceY < 0
									? -distanceY
									: distanceY;
							i32 maxDistanceY =
								cameraHalfHeight +
								(objectHeight >>
								 1);
							maxDistanceY =
								maxDistanceY < 0
									? -maxDistanceY
									: maxDistanceY;
							if (distanceY <=
							    maxDistanceY) {
								++collisionCount;
							}
						}
					}
				}
			}

			if (collisionCount != 0) {
				func_ov000_0209bf10(
					entry, objectInfo,
					spawnFlags, spawnTimer,
					viewID, playerID);
			}
		}

		++entry;
		++spawnFlags;
		++spawnTimer;
	} while (entry->id != 0xffff);
}

void func_ov000_0209b040(u8 playerID)
{
	PlayerBase *player =
		static_cast<PlayerBase *>(Game::getPlayer(playerID));
	u8 viewID = player->_2be;
	u32 entryCount = data_0208b220[viewID];
	if (entryCount == 0) {
		return;
	}

	i32 entryIndex;
	const ObjectInfo *objectInfo;
	StageRuntimeEntry *entry;
	u8 *spawnFlags;
	u16 *spawnTimer;
	StageRuntimeEntry **entryTable = data_0208b1a0;
	u32 *entryOffsetTable = data_0208b2a0;
	i32 cameraExtent;
	i32 cameraZoomY;
	i32 cameraX;
	i32 cameraY;
	i32 left;
	i32 top;
	i32 cameraHalfWidth;
	i32 cameraCenterX;
	i32 cameraHalfHeight;
	i32 cameraCenterY;

	cameraExtent =
		data_ov000_020cada4[playerID] >> 12;
	cameraZoomY =
		Game::cameraZoomY[playerID] >> 12;
	cameraX = data_ov000_020cae1c[playerID];
	cameraY = Game::cameraY[playerID];
	top = (cameraY >> 12) - 0x10;
	left = (cameraX >> 12) - 0x20;
	cameraHalfWidth =
		(cameraExtent + 0x30 + (cameraX >> 12) -
		 left) >>
		1;
	cameraCenterX = left + cameraHalfWidth;
	cameraHalfHeight =
		(cameraZoomY + 0x20 + (cameraY >> 12) -
		 top) >>
		1;

	entry = entryTable[viewID];
	u32 entryOffset = entryOffsetTable[viewID];
	spawnFlags = &data_ov000_020ca3cc[entryOffset];
	spawnTimer = &data_ov000_020ca64c[entryOffset];
	cameraCenterY = top + cameraHalfHeight;
	entryIndex = 0;
	if (entryCount == 0) {
		return;
	}

	u32 otherPlayerID = playerID ^ 1;
	do {
		if ((*spawnFlags & 1) == 0) {
			objectInfo =
				&data_ov000_020c529c[entry->id];
			u16 collisionCount = 0;
			if (entry->id == 0x12a &&
			    (u8)(data_0208b168.info->value02 &
				 0x20) != 0 &&
			    data_02085aa4 != 0xfffff) {
				++collisionCount;
			}

			if (objectInfo->spawnSettings &
			    ObjectInfo::SS_AlwaysLoad) {
				++collisionCount;
			} else {
				i32 objectWidth =
					(u16)objectInfo->size.x
					<< 4;
				i32 objectHeight =
					(u16)objectInfo->size.y
					<< 4;
				i32 objectX =
					(entry->x +
					 objectInfo->spawnOffset.x)
					<< 4;
				i32 objectY =
					(entry->y +
					 objectInfo->spawnOffset.y)
					<< 4;
				i32 objectHalfWidth =
					objectWidth >> 1;
				i32 objectCenterX =
					objectX + objectHalfWidth;
				i32 objectHalfHeight =
					objectHeight >> 1;
				i32 objectCenterY =
					objectY + objectHalfHeight;

				i32 distanceX =
					cameraCenterX -
					objectCenterX;
				distanceX = distanceX < 0
						    ? -distanceX
						    : distanceX;
				i32 maxDistanceX =
					cameraHalfWidth +
					objectHalfWidth;
				maxDistanceX =
					maxDistanceX < 0
						? -maxDistanceX
						: maxDistanceX;
				if (distanceX <= maxDistanceX) {
					i32 distanceY =
						cameraCenterY -
						objectCenterY;
					distanceY =
						distanceY < 0
							? -distanceY
							: distanceY;
					i32 maxDistanceY =
						cameraHalfHeight +
						objectHalfHeight;
					maxDistanceY =
						maxDistanceY < 0
							? -maxDistanceY
							: maxDistanceY;
					if (distanceY <=
					    maxDistanceY) {
						++collisionCount;
					}
				}

				if (collisionCount != 0 &&
				    func_020202a0() == 2 &&
				    (u8)(GlobalFader.fadingState
						 [otherPlayerID] &
					 0x49) == 0 &&
				    func_ov000_0209bddc(
					    entry, objectInfo,
					    otherPlayerID)) {
					collisionCount = 0;
				}
			}

			if (collisionCount != 0) {
				func_ov000_0209bf10(
					entry, objectInfo,
					spawnFlags, spawnTimer,
					viewID, playerID);
			}
		}

		++entry;
		++spawnFlags;
		++spawnTimer;
		++entryIndex;
	} while (entryIndex != entryCount);
}

void func_ov000_0209aff8(u8 playerID, bool mode)
{
	if (data_02085abc & 2) {
		func_ov000_0209b688(playerID);
		return;
	}
	if (!mode) {
		func_ov000_0209b320(playerID);
		return;
	}
	func_ov000_0209b040(playerID);
}

bool StageEntity::isOutOfView(
	const Vec3_32 &position, const FxRect &boundingBox, u8 viewID)
{
	FxRect view;
	Vec2_32 relativeStart;
	Vec2_32 expandedStart;
	Vec2_32 expandedSize;

	if (func_0201f184(viewID, &view) == 0) {
		return true;
	}

	expandedSize.x = boundingBox.halfWidth + 0x80000;
	expandedSize.y = boundingBox.halfHeight + 0x80000;
	expandedStart.x = position.x + boundingBox.x - expandedSize.x;
	i32 verticalStart = position.y + boundingBox.y;
	expandedStart.y = -(verticalStart + expandedSize.y);
	relativeStart.x = expandedStart.x - view.x;
	relativeStart.y = expandedStart.y + view.y;
	expandedSize.x *= 2;
	expandedSize.y *= 2;

	if ((data_ov000_020ca8d0 & 0x1000) == 0 &&
	    (u8)(data_0208b168.info->value02 & 0x20) == 0 &&
	    (u32)(relativeStart.x + expandedSize.x) >
		    (u32)(view.halfWidth + expandedSize.x)) {
		return true;
	}
	if ((u32)(relativeStart.y + expandedSize.y) >
	    (u32)(view.halfHeight + expandedSize.y)) {
		return true;
	}
	return false;
}

bool StageEntity::destroyInactive(u32 flags)
{
	if (data_02085abc & 2) {
		return false;
	}
	if (func_ov000_020a6c9c(&this->collisionMgr)) {
		return false;
	}

	FxRect range;
	range.x = this->viewOffset.x << 12;
	range.y = this->viewOffset.y << 12;
	range.halfWidth = this->activeSize.x << 11;
	range.halfHeight = this->activeSize.y << 11;

	if ((((flags & 2) == 0 &&
	      func_0200aed8(&this->position, &range, this->_2be)) ||
	     isOutOfView(this->position, range, this->_2be)) &&
	    (flags & 1) == 0) {
		this->destroy(this->permanentDestroy);
		return true;
	}
	return false;
}

bool StageEntity::_01()
{
	if (this->forceRender != 0) {
		return false;
	}
	if (this->updateStateID == 5) {
		return false;
	}

	FxRect view;
	view.x = this->viewOffset.x << 12;
	view.y = this->viewOffset.y << 12;
	view.halfWidth = this->renderSize.x << 11;
	view.halfHeight = this->renderSize.y << 11;
	return func_0200ae9c(&this->position, &view, (s8)data_02085a7c) != 0;
}

u8 StageEntity::getHorizontalDirectionToPlayer(const Vec3_32 &position) const
{
	i32 distanceX;
	data_ov000_020ca858(position.x >> 12, position.y >> 12, &distanceX, 0);
	return ((u32)distanceX & 0x80000000) >> 31;
}

u8 StageEntity::getVerticalDirectionToPlayer(const Vec3_32 &position) const
{
	i32 distanceY;
	data_ov000_020ca858(position.x >> 12, position.y >> 12, 0, &distanceY);
	return ((u32)distanceY & 0x80000000) >> 31;
}

void StageEntity::getScorePointsRegular(const Vec3_32 &position, u32 type, s32 playerID)
{
	if (func_020202a0() == 2 || playerID == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f84[type], const_cast<Vec3_32 *>(&position), (i8)playerID);
	if (type != 8) {
		func_02020300(playerID, data_ov000_020c2078[type]);
	} else {
		func_02012398(0x17b, const_cast<Vec3_32 *>(&position));
		func_02020544(playerID);
	}
}

void StageEntity::getScorePointsRegular(u32 type, fx32 x, fx32 y, s32 playerID) const
{
	if (func_020202a0() == 2) {
		return;
	}
	Vec3_32 position;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	position.x = x + this->position.x;
	position.y = y + this->position.y;
	getScorePointsRegular(position, type, playerID);
}

void StageEntity::getCollectablePoints(u32 type, s32 playerID)
{
	PlayerBase *player = static_cast<PlayerBase *>(Game::getPlayer(playerID));
	Vec3_32 result = player->func_ov011_0212bbdc();
	const i32 &height = data_ov000_020c1fd8[player->runtimePowerup];
	result.y = height + player->position.y;
	Vec3_32 position(result.x, result.y, 0);
	getScorePointsRegular(position, type, playerID);
}

void StageEntity::spawnRedCoinNumber(const Vec3_32 &position, u32 coins, s32 playerID)
{
	func_ov010_020e653c(0x18, &position, 0, 0, (i8)playerID, coins);
}

void StageEntity::getScorePointsEnhanced(const Vec3_32 &position, u32 type, s32 playerID)
{
	if (playerID == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f90[type], const_cast<Vec3_32 *>(&position), (i8)playerID);
	if (type < 5) {
		func_02020300(playerID, data_ov000_020c20c8[type]);
	} else {
		func_02012398(0x17b, const_cast<Vec3_32 *>(&position));
		func_02020544(playerID);
	}
}

void StageEntity::getScorePointsEnhanced(
	u32 type, fx32 x, fx32 y, s32 playerID) const
{
	Vec3_32 position(0);
	position.x = x + this->position.x;
	position.y = y + this->position.y;
	getScorePointsEnhanced(position, type, playerID);
}

void StageEntity::getScorePointsStageBeaten(const Vec3_32 &position, u32 type, s32 playerID)
{
	if (playerID == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f78[type], const_cast<Vec3_32 *>(&position), (i8)playerID);
	if (type < 5) {
		func_02020300(playerID, data_ov000_020c2050[type]);
	} else {
		func_02012398(0x17b, const_cast<Vec3_32 *>(&position));
		func_02020544(playerID);
	}
}

void StageEntity::getScorePointsStageBeaten(u32 type, fx32 x, fx32 y, s32 playerID) const
{
	Vec3_32 position;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	position.x = x + this->position.x;
	position.y = y + this->position.y;
	getScorePointsStageBeaten(position, type, playerID);
}

PlayerStompType StageEntity::updatePlayerStomp(
	ActiveCollider &collider, fx32 jumpVelocity, bool allowClippedJump, bool noPoints)
{
	if ((u16)(collider.collidedGroups & 1) == 0) {
		return PlayerStomp_None;
	}

	PlayerBase *player = func_ov000_020a3d68(&collider);
	if (player->powerup == PlayerPowerup_Mega) {
		if (player->_778 & 0x800000) {
			if (jumpVelocity != 0) {
				onPlayerStomp(*player, jumpVelocity, noPoints);
				if (this->defeatSFX != -1) {
					func_02012398(this->defeatSFX, &this->position);
				}
			}
			return PlayerStomp_Stomp;
		}
		if (canPlayerStomp(collider, *player, allowClippedJump)) {
			if (jumpVelocity != 0) {
				doPlayerJump(*player, jumpVelocity);
				if (this->defeatSFX != -1) {
					func_02012398(this->defeatSFX, &this->position);
				}
			}
			return PlayerStomp_MiniStomp;
		}
	} else if (canPlayerStomp(collider, *player, allowClippedJump)) {
		onPlayerStomp(*player, jumpVelocity, noPoints);
		return PlayerStomp_Stomp;
	}
	return PlayerStomp_None;
}

void StageEntity::doPlayerJump(PlayerBase &player, fx32 jumpVelocity)
{
	fx32 force = jumpVelocity + player.constants->jumpVelocity;
	if (player.powerup == PlayerPowerup_Mega) {
		force = ((i64)force * 0xd00 + 0x800) >> 12;
	} else if (player.func_ov011_0212bb90()) {
		force = ((i64)force * 0xd80 + 0x800) >> 12;
	}

	if (player._778 & 0x80000000) {
		Vec3_32 position(player.position.x, player.position.y, 0x200000);
		func_02022b64(0xf5, &position);
		func_02022b64(0xf6, &position);
		func_02022b64(0xf7, &position);
	}

	player.doJump(force, 0, false, true, player.scoreJumpVariation);
	data_ov000_020ca290 = 4;
}

void StageEntity::onPlayerStomp(PlayerBase &player, fx32 jumpVelocity, bool noPoints)
{
	if (jumpVelocity != 0) {
		this->doPlayerJump(player, jumpVelocity);
	}
	if (this->kickedInWall && player.velocity.y > 0) {
		return;
	}

	if (!noPoints) {
		if (player.scoreComboStandard < 10) {
			++player.scoreComboStandard;
		}
		++player.scoreJumpVariation;
		player.scoreJumpVariation %= 4;
		if (player.scoreComboStandard > 8) {
			player.scoreComboStandard = 8;
		}

		if (this->scoreType == 0) {
			this->getScorePointsRegular(
				player.scoreComboStandard, 0, 0x18000, this->activeCollider.collidedPlayerID);
		} else if (this->scoreType == 1) {
			this->getScorePointsEnhanced(
				player.scoreComboStandard, 0, 0x18000, this->activeCollider.collidedPlayerID);
		}
	}

	if (this->defeatSFX != -1) {
		func_02012398(this->defeatSFX, &this->position);
	}
}

bool StageEntity::canPlayerStomp(
	ActiveCollider &collider, PlayerBase &player, bool allowClippedJump)
{
	fx32 velocityY = player.velocity.y;
	fx32 collisionY = collider.intersectionDistY[AC_GRP_Player];
	s32 downward = velocityY <= 0;

	if (this->kickedInWall) {
		if ((player.collisionFlag & PlayerBase::CF_Ground) == 0 &&
		    this->position.y < player.position.y + 0xa000) {
			return true;
		}
		return false;
	}

	if (!allowClippedJump && downward == 0) {
		return false;
	}
	if (data_ov000_020ca290 != 0) {
		downward = 1;
	}
	if (collisionY < 0 &&
	    (-collisionY << 1) < data_ov000_020c20a0[downward][this->stompTriggerHeight]) {
		return true;
	}
	return false;
}

u32 StageEntity::updateSolidActiveCollider(bool push, u32 flags, u8 playerID)
{
	PlayerActor *player =
		simplePlayerCollision[playerID].player;
	u32 result;
	u8 vertical;
	u8 horizontal;
	horizontal = 0;
	vertical = 0;
	result = 0;
	if (player == NULL) {
		return 0;
	}

	fx32 entityPositionY = position.y;
	fx32 entityRectY = activeCollider.rect.y;
	fx32 entityCenterY = entityPositionY + entityRectY;
	fx32 entityHalfHeight = activeCollider.rect.halfHeight;
	fx32 entityLowerY = entityCenterY - entityHalfHeight;

	Vec3_32 &playerPosition = player->position;
	fx32 playerPositionX = playerPosition.x;
	fx32 playerPositionYCenter = playerPosition.y;
	fx32 playerRectY = player->activeCollider.rect.y;
	fx32 playerCenterY = playerPositionYCenter + playerRectY;
	fx32 playerHalfHeight =
		player->activeCollider.rect.halfHeight;

	fx32 playerRectX = player->activeCollider.rect.x;
	fx32 dx = simplePlayerCollision[playerID].dx;
	fx32 entityHalfWidth = activeCollider.rect.halfWidth;
	fx32 dy = simplePlayerCollision[playerID].dy;

	Vec3_32 &playerVelocity = player->velocity;
	fx32 playerCenterX = playerPositionX + playerRectX;
	fx32 entityCenterX = position.x + activeCollider.rect.x;

	if (playerCenterY > entityLowerY &&
	    playerCenterY < entityCenterY + entityHalfHeight) {
		++horizontal;
	}
	if (playerCenterX > entityCenterX - entityHalfWidth &&
	    playerCenterX < entityCenterX + entityHalfWidth) {
		++vertical;
	}

	if ((horizontal | vertical) == 0) {
		fx32 absDx = dx < 0 ? -dx : dx;
		fx32 absDy = dy < 0 ? -dy : dy;
		if (absDx < absDy) {
			++horizontal;
		} else {
			++vertical;
		}

		fx32 playerBottom = playerCenterY - playerHalfHeight;
		if (playerBottom > entityLowerY &&
		    playerBottom < entityCenterY + entityHalfHeight &&
		    playerVelocity.y > 0) {
			++horizontal;
			vertical = 0;
		}
	}

	if (vertical && dy != 0) {
		if (dy > 0) {
			if (playerVelocity.y > 0) {
				if ((flags & 4) == 0) {
					playerPosition.y -= dy * 2;
				}
				horizontal = 0;
				playerVelocity.y = -0x2000;
			}
			result |= 4;
		} else {
			if (playerVelocity.y < 0) {
				if ((flags & 8) == 0) {
					fx32 amount = dy * 2;
					if (amount < 0) {
						amount = -amount;
					}
					playerPosition.y += amount;
				}
				horizontal = 0;
				playerVelocity.y = 0;
			}
			result |= 8;
		}
	}

	if (horizontal) {
		if ((flags & 1) == 0) {
			if (push == 0) {
				player->limitedHorizontalWarp(-dx * 2);
			} else {
				player->pushingHorizontalWarp(-dx * 2);
			}

			bool movingInto = false;
			if (dx < 0 && playerVelocity.x < 0) {
				movingInto = true;
			}
			if (dx > 0 && playerVelocity.x > 0) {
				movingInto = true;
			}
			if (movingInto) {
				player->velH = 0;
				playerVelocity.x = 0;
			}
		}
		if (dx > 0) {
			result |= 1;
		} else {
			result |= 2;
		}
	}

	fx32 playerVelocityZ = playerVelocity.z;
	fx32 playerVelocityY = playerVelocity.y;
	fx32 playerVelocityX = playerVelocity.x;
	player->velocity.x = playerVelocityX;
	player->velocity.y = playerVelocityY;
	player->velocity.z = playerVelocityZ;

	fx32 playerPositionZ = playerPosition.z;
	fx32 playerPositionY = playerPosition.y;
	fx32 playerPositionXFinal = playerPosition.x;
	player->position.x = playerPositionXFinal;
	player->position.y = playerPositionY;
	player->position.z = playerPositionZ;
	return result;
}

void StageEntity::attachToPlayerHands(fx32 z, fx32 y, fx32 x)
{
	if (linked_player == -1) {
		return;
	}

	PlayerBase *player = static_cast<PlayerBase *>(Game::getPlayer(linked_player));
	Vec3_32 handPosition = player->getHandsPosition();
	handPosition.x &= data_02085aa4;

	Game_modelMatrix = player->unk68C;
	MTX::translate(Game_modelMatrix, x, y, z);

	position.x = handPosition.x + Game_modelMatrix.s.m30;
	position.y = handPosition.y + Game_modelMatrix.s.m31;
	position.z = handPosition.z + Game_modelMatrix.s.m32;
	rotation.y = player->rotation.y;
}

i32 StageEntity::tryAttachToPlayerHands(i32 z, i32 y, i32 x)
{
	if (this->updateStateID == 5 && this->linked_player != -1 && (this->carriedAction & 1) == 0) {
		this->attachToPlayerHands(z, y, x);
		return 2;
	}

	return 0;
}

u32 StageEntity::random()
{
	return Wifi::random();
}

bool StageEntity::spawnBrokenPipe(i32 a, i32 b, u32 c, u32 d, u8 e, u8 f, i8 g)
{
	Vec3_32 vec;
	vec.z = 0;
	vec.x = a;
	vec.y = b;
	Actor *actor = Actor::spawnActor(0xd3, d | e << 8 | c << 0x10 | f << 0x1c | g << 0x1f, &vec, 0, 0, 0);

	if (actor == NULL) {
		return false;
	} else {
		return true;
	}
}

void StageEntity::simpleCallback(ActiveCollider *collider, ActiveCollider *other)
{
	if (other->owner->actorType != 1) {
		return;
	}

	u8 group = other->group;
	StageEntity *entity = static_cast<StageEntity *>(collider->owner);
	PlayerActor *player = static_cast<PlayerActor *>(other->owner);
	u8 playerID = player->linked_player;
	if (group == AC_GRP_Player) {
		entity->simplePlayerCollision[playerID].player = player;
		entity->simplePlayerCollision[playerID].dx =
			collider->intersectionDistX[AC_GRP_Player];
		entity->simplePlayerCollision[playerID].dy =
			collider->intersectionDistY[AC_GRP_Player];
		entity->simplePlayerCollisionResult |= data_ov000_020c1f48[playerID];
	} else {
		entity->simplePlayerSpecialCollision[playerID].player = player;
		entity->simplePlayerSpecialCollision[playerID].dx =
			collider->intersectionDistX[AC_GRP_PlayerSpecial];
		entity->simplePlayerSpecialCollision[playerID].dy =
			collider->intersectionDistY[AC_GRP_PlayerSpecial];
		entity->simplePlayerSpecialCollision[playerID].flags =
			collider->flags & 0xfffe;
		entity->simplePlayerCollisionResult |= data_ov000_020c1f4c[playerID];
	}
}

void StageEntity::shellActiveCallback(
	ActiveCollider &collider, ActiveCollider &other)
{
	StageEntity *entity = static_cast<StageEntity *>(collider.owner);
	StageActor *otherActor = static_cast<StageActor *>(other.owner);
	u32 direction = entity->isBehindTarget(otherActor);

	Vec2_32 *selfPosition = &collider.position;
	entity->collisionSelfPos = *selfPosition;
	Vec2_32 *otherPosition = &other.position;
	entity->collisionActorPos = *otherPosition;

	if (otherActor->actorType == 2) {
		StageEntity *otherEntity =
			static_cast<StageEntity *>(otherActor);
		if ((other.detectAttacks &
		     (1 << AC_ATK_EntityAsWeapon)) == 0) {
			if ((u32)((collider.flags & 0xfffe) << 16) >> 16) {
				return;
			}
			if ((u8)(collider._a5 & 1) == 0) {
				return;
			}
			if ((u32)((other.options &
				   AcConfig::BypassDamage) << 16) >> 16) {
				return;
			}
			if (other.attack != AC_ATK_None) {
				return;
			}

			s8 playerID = entity->linked_player;
			fx32 dy = collider.intersectionDistY[playerID];
			fx32 dx = collider.intersectionDistX[playerID];
			if (dy < 0) {
				dy = -dy;
			}
			if (dx < 0) {
				dx = -dx;
			}
			if (dy <= dx) {
				return;
			}

			entity->direction = direction;
			if (direction ^
			    (((u32)entity->velocity.x &
			      0x80000000) >> 31)) {
				entity->velocity.x = -entity->velocity.x;
				entity->minVelocity.x =
					-entity->minVelocity.x;
				func_02012398(0x16f, &entity->position);
			}
			return;
		}

		if (entity->scoreCombo < otherEntity->scoreCombo) {
			return;
		}
		if ((u32)((collider.flags & 0xfffe) << 16) >> 16) {
			entity->collisionDirection = direction;
			entity->collisionType |= CT_Entity;
		}
		otherEntity->collisionDirection = direction ^ 1;
		otherEntity->linkPlayer(entity->linked_player);
		otherEntity->collisionType |= CT_Entity;
		collider.collisionState |= ActiveCollider::CS_Collided;

		if (otherEntity->scoreType == 2) {
			return;
		}
		u8 combo = entity->scoreCombo;
		if (combo < 8) {
			++combo;
		}
		entity->scoreCombo = combo;
		if (otherEntity->scoreType == 0) {
			entity->getScorePointsRegular(
				combo, 0, 0x18000,
				entity->linked_player);
		} else if (otherEntity->scoreType == 1) {
			entity->getScorePointsEnhanced(
				combo, 0, 0x18000,
				entity->linked_player);
		}
		if (combo < 8) {
			func_02012398(combo + 0x70, &entity->position);
		} else {
			func_02012398(0x77, &entity->position);
		}
		return;
	}

	if (otherActor->actorType != 1) {
		return;
	}
	PlayerActor *player = static_cast<PlayerActor *>(otherActor);
	s32 playerID = player->linked_player;
	if (isBelowCamera(
		    entity->position.y, collider, playerID)) {
		return;
	}
	if (entity->playerCollisionCooldown[player->linked_player] != 0) {
		return;
	}
	if (entity->kickedInWall) {
		entity->playerCollisionCooldown[player->linked_player] = 0xf;
	} else {
		entity->playerCollisionCooldown[player->linked_player] = 5;
	}

	if (entity->playerCollision(collider, other)) {
		entity->collisionData = collider.collisionData;
		collider.collisionState |= ActiveCollider::CS_Collided;
		return;
	}
	if ((u32)((other.collidedGroups &
		   (1 << AC_GRP_PlayerSpecial)) << 16) >> 16) {
		return;
	}

	if (player->_778 & 0x400000) {
		if (entity->setBlueShellCollision(*player)) {
			return;
		}
		return;
	}

	PlayerStompType stomp = entity->updatePlayerStomp(
		collider, 0x480, true, entity->kickedInWall != 0);
	if (stomp != PlayerStomp_None) {
		if (stomp == PlayerStomp_Stomp) {
			entity->_19();
		}
		return;
	}

	if (!entity->kickedFaster && direction == entity->direction) {
		Vec3_32 *entityVelocity = &entity->velocity;
		fx32 playerSpeed = player->velocity.x < 0
			? -player->velocity.x : player->velocity.x;
		fx32 entitySpeed = entityVelocity->x < 0
			? -entityVelocity->x : entityVelocity->x;
		if (playerSpeed > entitySpeed) {
			entity->kickedFaster = true;
			Vec3_32 *minimumVelocity = &entity->minVelocity;
			i16 shellSpeed =
				data_ov000_020c1f44[direction];
			fx32 playerVelocity = player->velocity.x;
			minimumVelocity->x =
				shellSpeed + (playerVelocity >> 1);
			entity->velocity.x = minimumVelocity->x;
			entity->getScorePointsRegular(
				0, 0, 0x18000, entity->linked_player);
			func_02012398(0x70, &entity->position);
			return;
		}
	}
	player->virt_25(entity, 0, 0x4000, 0);
}

void StageEntity::damageEntityCallback(ActiveCollider *collider, ActiveCollider *other)
{
	StageEntity *entity = static_cast<StageEntity *>(collider->owner);
	u32 direction;
	Actor *otherActor = other->owner;
	direction = entity->isBehindTarget(otherActor);

	if ((other->detectAttacks & (1 << AC_ATK_EntityAsWeapon)) == 0) {
		return;
	}

	Vec2_32 *selfPosition = &collider->position;
	Vec2_32 *otherPosition = &other->position;
	entity->collisionSelfPos = *selfPosition;
	entity->collisionActorPos = *otherPosition;

	if (otherActor->actorType == 2) {
		StageEntity *otherEntity = static_cast<StageEntity *>(otherActor);
		if (otherEntity->object_id == 0xf1) {
			return;
		}

		if (entity->linked_player != -1) {
			PlayerBase *player =
				static_cast<PlayerBase *>(Game::getPlayer(entity->linked_player));
			player->func_ov011_0212bde0(entity);
		}

		if (entity->scoreType == 0) {
			entity->getScorePointsRegular(1, 0, 0x18000, entity->linked_player);
		} else if (entity->scoreType == 1) {
			entity->getScorePointsRegular(4, 0, 0x18000, entity->linked_player);
		}

		func_02012398(0x70, &entity->position);
		entity->collisionDirection = direction;
		entity->collisionType |= CT_Entity;
		otherEntity->collisionDirection = direction ^ 1;
		otherEntity->linkPlayer(entity->linked_player);
		otherEntity->collisionType |= CT_Entity;
		collider->collisionState |= ActiveCollider::CS_Collided;
		return;
	}

	if (otherActor->actorType != 1) {
		return;
	}

	PlayerBase *player = static_cast<PlayerBase *>(otherActor);
	if (isBelowCamera(
		    entity->position.y, *collider, player->linked_player)) {
		return;
	}
	if (entity->playerCollisionCooldown[player->linked_player] != 0) {
		return;
	}
	entity->playerCollisionCooldown[player->linked_player] = 5;

	if (entity->playerCollision(*collider, *other)) {
		entity->collisionData = collider->collisionData;
		collider->collisionState |= ActiveCollider::CS_Collided;
		return;
	}

	if ((u32)((other->collidedGroups & (1 << AC_GRP_PlayerSpecial)) << 16) >> 16) {
		return;
	}
}

void StageEntity::updateBounce(i32 a, i32 b, i32 c)
{
	if ((this->collisionMgr.flags & 0x1f40) == 0) {
		return;
	}

	if (b < 0x1000) {
		this->velocity.x = _FixedMul(this->velocity.x, b);
		i32 absVelocityX = this->velocity.x;
		if (absVelocityX < 0) {
			absVelocityX = -absVelocityX;
		}
		if (absVelocityX < 0x100) {
			this->velocity.x = 0;
		}
	}

	if (this->velocity.y < 0) {
		this->velocity.y = -this->velocity.y;
		this->velocity.y = _FixedMul(this->velocity.y, c);
		if (this->velocity.y < a) {
			this->velocity.y = 0;
		}
	}
}

void StageEntity::destroy(bool permanent)
{
	Base::destroy();
	u8 *objectSpawnFlags = this->objectSpawnFlags;
	u16 *objectRespawnTimer = this->objectRespawnTimer;
	if (!permanent) {
		if (objectSpawnFlags != 0) {
			*objectSpawnFlags &= ~1;
		}
	} else {
		if (objectSpawnFlags != 0) {
			*objectSpawnFlags |= 8;
		}
		if (objectRespawnTimer != 0) {
			*objectRespawnTimer = 300;
		}
		return;
	}
}

void StageEntity::setTimedEvent(u32 event_id, i32 time, bool enable, bool switch_event, bool play_sfx)
{
	if (!enable) {
		if (time != 0) {
			if (!switch_event) {
				data_0208af3c &= ~((u64)1 << event_id);
				data_0208af84[event_id] = time * 10;
				data_0208af44[event_id] |= 1;
				if (play_sfx) {
					data_0208af44[event_id] |= 2;
				} else {
					data_0208af44[event_id] &= ~2;
				}
			} else {
				data_0208af3c |= (u64)1 << event_id;
				data_0208af84[event_id] = time * 10;
				data_0208af44[event_id] &= ~1;
				if (play_sfx) {
					data_0208af44[event_id] |= 2;
				} else {
					data_0208af44[event_id] &= ~2;
				}
			}
		} else {
			data_0208af3c &= ~((u64)1 << event_id);
		}
	} else {
		if (time != 0) {
			if (!switch_event) {
				data_0208af3c |= (u64)1 << event_id;
				data_0208af84[event_id] = time * 10;
				data_0208af44[event_id] &= ~1;
				if (play_sfx) {
					data_0208af44[event_id] |= 2;
				} else {
					data_0208af44[event_id] &= ~2;
				}
			} else {
				data_0208af3c &= ~((u64)1 << event_id);
				data_0208af84[event_id] = time * 10;
				data_0208af44[event_id] |= 1;
				if (play_sfx) {
					data_0208af44[event_id] |= 2;
				} else {
					data_0208af44[event_id] &= ~2;
				}
			}
		} else {
			data_0208af3c |= (u64)1 << event_id;
		}
	}
}

u16 getActorID(u8 sprite_id)
{
	return data_ov000_020c22b8[sprite_id];
}

void StageEntity::onUpdate_xx()
{
	if ((this->properties & 0x4000) != 0) {
		return;
	}

	if ((u32)((this->activeCollider.collidedGroups & 0x80) << 0x10) >> 0x10) {
		this->wiggleTimer = 0x18;
		this->wiggleFactor = 0x1000;
	}

	if (this->wiggleTimer == 0) {
		this->wiggleScale.x = this->scale.x;
		this->wiggleScale.y = this->scale.y;
		this->wiggleScale.z = this->scale.z;
		this->wiggleFactor = 0x1000;
		return;
	}
	this->wiggleTimer -= 1;
	if (this->wiggleTimer & 0x4) {
		this->wiggleFactor += 0x100;
	} else {
		this->wiggleFactor -= 0x100;
	}
}

void StageEntity::applyFireballWiggle()
{
	if (this->properties & 0x4000) {
		this->wiggleScale.x = this->scale.x;
		this->wiggleScale.y = this->scale.y;
		this->wiggleScale.z = this->scale.z;
	} else if (this->wiggleFactor == 0x1000) {
		this->wiggleScale.x = this->scale.x;
		this->wiggleScale.y = this->scale.y;
		this->wiggleScale.z = this->scale.z;
	} else {
		this->wiggleScale.x = ((i64)(i32)this->wiggleFactor * (i64)this->scale.x + 0x800) >> 12;
		this->wiggleScale.y = ((i64)(i32)this->wiggleFactor * (i64)this->scale.y + 0x800) >> 12;
		this->wiggleScale.z = ((i64)(i32)this->wiggleFactor * (i64)this->scale.z + 0x800) >> 12;
	}
}

bool StageEntity::rotateToTarget(i16 a[2], i16 b[2])
{
	this->rotation.y += b[this->direction];
	if (a[0] <= this->rotation.y || this->rotation.y <= a[1]) {
		this->rotation.y = a[this->direction];
		return true;
	}
	return false;
}

bool StageEntity::checkPlayersInRange(fx32 x) const
{
	if (func_020202a0() == 2) {
		PlayerActor *first = static_cast<PlayerActor *>(Game::getPlayer(0));
		PlayerActor *second = static_cast<PlayerActor *>(Game::getPlayer(1));

		Vec3_32 firstPosition = first->position;
		Vec3_32 secondPosition = second->position;
		i32 firstX = firstPosition.x - this->position.x;
		if (firstX < 0) {
			firstX = -firstX;
		}
		if (firstX < x) {
			return true;
		}
		i32 secondX = secondPosition.x - this->position.x;
		if (secondX < 0) {
			secondX = -secondX;
		}
		return secondX < x;
	}

	PlayerActor *player = func_020205ec();
	Vec3_32 playerPosition = player->position;
	i32 distanceX = playerPosition.x - this->position.x;
	if (distanceX < 0) {
		distanceX = -distanceX;
	}
	return distanceX < x;
}

bool StageEntity::checkPlayersInRange(fx32 x, fx32 y) const
{
	if (func_020202a0() == 2) {
		PlayerActor *first = static_cast<PlayerActor *>(Game::getPlayer(0));
		PlayerActor *second = static_cast<PlayerActor *>(Game::getPlayer(1));

		const Vec3_32 &firstSource = first->position;
		const Vec3_32 &secondSource = second->position;
		Vec3_32 firstPosition = firstSource;
		Vec3_32 secondPosition = secondSource;
		i32 firstX = firstPosition.x - this->position.x;
		if (firstX < 0) {
			firstX = -firstX;
		}
		i32 firstY = firstPosition.y - this->position.y;
		if (firstY < 0) {
			firstY = -firstY;
		}
		i32 secondX = secondPosition.x - this->position.x;
		if (secondX < 0) {
			secondX = -secondX;
		}
		i32 secondY = secondPosition.y - this->position.y;
		if (firstX < x && firstY < y) {
			return true;
		}

		if (secondX < x) {
			if (secondY < 0) {
				secondY = -secondY;
			}
			if (secondY < y) {
				return true;
			}
		}
		return false;
	}

	PlayerActor *player = func_020205ec();
	const Vec3_32 &playerSource = player->position;
	Vec3_32 playerPosition = playerSource;
	i32 distanceX = playerPosition.x - this->position.x;
	i32 selfY;
	if ((selfY = this->position.y, distanceX) < 0) {
		distanceX = -distanceX;
	}
	i32 distanceY = playerPosition.y - selfY;
	if (distanceX < x) {
		if (distanceY < 0) {
			distanceY = -distanceY;
		}
		if (distanceY < y) {
			return true;
		}
	}
	return false;
}

u32 StageEntity::updateCollisionSensors()
{
	u32 flags = 0;
	u32 bottom = this->updateBottomSensors();
	if (this->collisionMgr.flags & 0x1f40) {
		this->velocity.y = 0;
		flags |= 1;
	}
	if (this->collisionMgr.func_ov000_020aa990(bottom)) {
		flags |= 2;
	}
	if (this->updateSideSensors()) {
		flags |= 4;
	}
	return flags;
}

bool StageEntity::checkLavaCollision(Vec3_32 *pos)
{
	bool hit = false;
	if (func_ov000_020a6d18(pos->x, pos->y) == 0x10000004) {
		hit = true;
	} else if (data_ov000_020cace0[data_02085a7c] == 2 &&
		   data_ov000_020cae0c[data_02085a7c] >= pos->y) {
		hit = true;
	}
	if (hit) {
		func_020221d8(pos);
	}
	return hit;
}

void StageEntity::_38() {
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->accelV = 0;
}

u32 StageEntity::updateBottomSensors()
{
	this->quicksandFlag = 0;
	this->slipperyFlag = 0;
	u32 result = this->collisionMgr.func_ov000_020a917c();
	if (this->collisionMgr.flags & 0x1f40) {
		if (this->collisionMgr.func_ov000_020a8140() == 0x3000) {
			this->quicksandFlag = 1;
		}
		if (this->collisionMgr.func_ov000_020a8140() == 0x1000) {
			this->slipperyFlag = 1;
		}
		const Vec3_32 &surfaceVector = this->collisionMgr.surfaceVector;
		this->externalForce = surfaceVector;
	} else {
		this->externalForce.set(0);
	}
	return result;
}

u32 StageEntity::updateSideSensors()
{
	u8 side = ((this->position.x - this->collisionMgr.sideSensorPosition) & 0x80000000) >> 31;
	i32 sensor = StageEntity::unitDirection[side];
	u32 result = this->collisionMgr.func_ov000_020a915c(&sensor, 0);
	sensor = StageEntity::unitDirection[(u8)(side ^ 1)];
	this->collisionMgr.func_ov000_020a915c(&sensor, 0x40000000);
	if (this->_2bf & 3) {
		this->collisionMgr.func_ov000_020a915c(&sensor, 0);
	}
	return result;
}

bool StageEntity::checkSquished()
{
	u8 mask = this->_2bf;
	if (mask != 0) {
		if ((u8)(mask & 1) && (this->collisionMgr.flags & 0x15)) {
			return true;
		}
		if ((u8)(mask & 2) && (this->collisionMgr.flags & 0x2a)) {
			return true;
		}
		if ((u8)(mask & 8) && (this->collisionMgr.flags & 0x1f40)) {
			return true;
		}
		if ((u8)(mask & 4) && (this->collisionMgr.flags & 0xe000)) {
			return true;
		}
	}
	return false;
}

void StageEntity::onMegaGroundPound()
{
	this->activeCollider.unlink();
	this->defeat(0, 0x2000, 0xfffffd00, 0);
}

void StageEntity::onStageBeaten(PlayerActor &player)
{
	Vec3_32 position(this->position);
	Vec3_32 &center = this->centerOffset;
	if ((this->properties & ObjectInfo::EP_NoLevelBeaten) == 0) {
		if (player.scoreComboStandard < 10) {
			++player.scoreComboStandard;
		}
		++player.scoreJumpVariation;
		player.scoreJumpVariation %= 4;
		if (player.scoreComboStandard > 8) {
			player.scoreComboStandard = 8;
		}
		this->getScorePointsStageBeaten(
			player.scoreComboStandard, 0, 0x18000, player.linked_player);
		position.add2(center);
		position.y += 0x4000;
		func_02022220(&position);
		func_02012398(0x70, &position);
		this->destroy(true);
	}
}

bool StageEntity::setGroundPoundCollision(const PlayerActor &player)
{
	i32 delta = (this->position.x + this->centerOffset.x) -
		    (player.position.x + player.centerOffset.x);
	if (this->properties & ObjectInfo::EP_NoGroundPound) {
		return false;
	}
	if (player.powerup == PlayerPowerup_Mega) {
		return false;
	}
	this->linked_player = player.linked_player;
	this->collisionDirection = ((u32)delta & 0x80000000) >> 31;
	this->collisionType |= CT_GroundPound;
	return true;
}

bool StageEntity::isBelowCamera(
	fx32 posY, ActiveCollider &collider, s8 playerID)
{
	return -((posY + collider.rect.y) - collider.rect.halfHeight) <
	       (int)Game::cameraY[playerID];
}

void StageEntity::damagePlayerCallback(ActiveCollider &collider, ActiveCollider &other)
{
	StageEntity *entity = static_cast<StageEntity *>(collider.owner);
	Actor *otherActor = other.owner;
	Vec2_32 *selfPosition = &collider.position;
	Vec2_32 *otherPosition = &other.position;
	entity->collisionSelfPos = *selfPosition;
	entity->collisionActorPos = *otherPosition;

	if (otherActor->actorType == 2) {
		if ((u32)((collider.flags & 0xfffe) << 16) >> 16) {
			collider.collisionState |= ActiveCollider::CS_Collided;
			return;
		}
		entity->entityCollision(collider, *static_cast<StageActor *>(otherActor));
		return;
	}
	if (otherActor->actorType != 1) {
		return;
	}

	PlayerBase *player = static_cast<PlayerBase *>(otherActor);
	if (isBelowCamera(
		    entity->position.y, collider, player->linked_player)) {
		return;
	}
	if (entity->playerCollisionCooldown[player->linked_player] != 0) {
		return;
	}
	entity->playerCollisionCooldown[player->linked_player] = 5;
	if (entity->playerCollision(collider, other)) {
		entity->collisionData = collider.collisionData;
		collider.collisionState |= ActiveCollider::CS_Collided;
		return;
	}
	if ((u32)((other.collidedGroups & (1 << AC_GRP_PlayerSpecial)) << 16) >> 16) {
		return;
	}
	entity->damagePlayer(collider, *player);
}

bool StageEntity::playerCollision(ActiveCollider &collider, ActiveCollider &other)
{
	PlayerActor *player = static_cast<PlayerActor *>(other.owner);

	isBehindTarget(player);
	if (player->actorType != 1) {
		return false;
	}

	if (BOOL(player->powerup == 3) != FALSE &&
	    setMegaCollision(*player)) {
		return true;
	}

	if (data_0208b350[player->linked_player] > 1 &&
	    setStarmanCollision(*player)) {
		return true;
	}

	if ((player->_778 & 0x800000) &&
	    setGroundPoundCollision(*player)) {
		return true;
	}

	if (player->getShellState() == 2 &&
	    setBlueShellCollision(*player)) {
		return true;
	}

	if ((player->st1 & 0x10) &&
	    (u32)((collider.detectAttacks & (1 << AC_ATK_Sliding)) << 16) >> 16 &&
	    setSlidingCollision(*player)) {
		return true;
	}

	bool spinDrill;
	if ((player->_778 & 0x80000000) &&
	    (player->st1 & 0x2000)) {
		spinDrill = true;
	} else {
		spinDrill = false;
	}
	if (spinDrill && setSpinDrillCollision(*player)) {
		return true;
	}

	if (other.group == AC_GRP_PlayerSpecial) {
		if (other.attack == AC_ATK_SlamFence) {
			if (setFenceSlamCollision(*player)) {
				return true;
			}
		} else if (other.attack != AC_ATK_Sliding &&
			   setStarmanCollision(*player)) {
			return true;
		}
	}

	return false;
}

void StageEntity::entityCollision(ActiveCollider &collider, StageActor &other)
{
}

void StageEntity::damagePlayer(ActiveCollider &collider, PlayerBase &player)
{
	bool check;
	if ((player._79c != 0) || (player._7c1 != 0)) {
		check = 1;
	} else {
		check = 0;
	}

	if (!check) {
		u32 shell_status = player.getShellState();
		if (shell_status != 1) {
			player.virt_25(this, 0, 0x4000, 0);
		}
	}
}

u32 StageEntity::stopPlayerInShell(ActiveCollider *collider, PlayerActor *player)
{
	if (player->getShellState() == 1) {
		if ((collider->intersectionDistX[AC_GRP_Player] > 0 && player->velH > 0) ||
		    (collider->intersectionDistX[AC_GRP_Player] < 0 && player->velH < 0)) {
			player->velH = 0;
			return 2;
		}
		return 1;
	}
	return 0;
}

bool StageEntity::isPlayerInZone(PlayerActor *player, u32 id)
{
	FxRect rect;

	func_0201eef8(id, &rect);
	fx32 maxX = rect.x + rect.halfWidth;
	fx32 minY = rect.y - rect.halfHeight;
	Vec3_32 &position = player->position;
	position.x &= data_02085aa4;
	fx32 posX = position.x;
	if (rect.x <= posX && posX <= maxX &&
	    rect.y >= position.y && position.y >= minY) {
		return true;
	}
	return false;
}

void StageEntity::assignView(Vec3_32 *position)
{

  	this->_2be = func_0201f000(position);
}

void StageEntity::func_ov000_020988d0(u32 bit)
{
	data_ov000_020ca2b8 |= 1 << (bit & 0x1f);
}

void StageEntity::func_ov000_020988ac(u32 bit)
{
	data_ov000_020ca2b8 &= ~(1 << (0x1f & bit));
}

Vec3_32 StageEntity::tryNormalizeVec3(Vec3_32 *input)
{
	if (input->x == 0 && input->y == 0 && input->z == 0) {
		return *input;
	}
	input->normalize();
	return *input;
}

u32 StageEntity::getSpritePriority(u32 a)
{
	u16 index;
	if (a != 0) {
		index = (u16)(a << 2);
	} else {
		index = (u16)(data_0208b168.info->value1C << 2);
	}

	u8 state = 0;
	if (this->liquidFlag != 0 || this->backLayer != 0) {
		state = 1;
	} else if (this->quicksandFlag != 0) {
		state = 2;
	}

	u8 result = data_ov000_020c1fb8[index + state];
	if (this->manualTimerA != 0) {
		result += 0x10;
	}
	return result;
}

u16 *StageEntity::getObjectBank(u32 sprite_id)
{
	return &Stage::objectBankTable[sprite_id];
}
