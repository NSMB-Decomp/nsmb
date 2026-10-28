#include "StageEntity.hpp"
#include "Player/PlayerActor.hpp"

StageEntity::StageEntity()
{
	// this->_40 = 0x2;
	this->actorType = 0x2;
	this->actorCategory = (1 << this->actorType) | 0x80;
	this->actorCategory = this->actorCategory | 0x20;
	this->_2d0 = 0;
	this->_3e7 = ~0;
	this->collisionType = 0x107;
	this->accelV = -0x300;
	this->minVelocity.x = 0;
	this->minVelocity.y = -0x4000;
	this->minVelocity.z = 0;
	this->_3d8 = 0;
	this->_3a8 = 0x1000;
	this->activeSize.x = 0;
	this->activeSize.y = 0;
	this->viewOffset.x = 0;
	this->viewOffset.y = 0;
	this->renderSize.x = 0;
	this->renderSize.y = 0;
	this->_31c.x = 0;
	this->_31c.y = 0;
	this->_31c.z = 0;
	this->_2ca = 0;
	this->_3c6[0] = 0;
	this->_3c6[1] = 0;
	this->_3d2 = 0;
	this->_3e8 = 0;
	this->_3ea = 0;
	this->_3e4 = 0;
	this->_3eb = 0;
	this->_358 = 0;
	this->_3ec = 0;
	this->_2c4 = 0;
	this->_34c = 0x6e;
	this->_2be = func_0201f000(&this->position);
	this->_3ed = 0;
	this->_3ef = 0;
	this->linked_player = ~0;
	this->_3df = 0;
	this->_3d0 = 0;
	this->_3de = 0;
	this->_350 = 1;
	this->_3f1 = 0;
}

bool StageEntity::onUpdate_0()
{
	return true;
}

s32 StageEntity::onUpdate()
{
	this->onUpdate_xx();
	s32 state = this->_340;
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
		return this->onUpdate_5();
	}
	if (state == 6) {
		return this->onUpdate_6();
	}
	if (state == 7) {
		return this->onUpdate_7();
	}
	if (state == 8) {
		return this->onUpdate_8();
	}
	if (state == 9) {
		return this->onUpdate_9();
	}
	this->_340 = 0;
	return this->onUpdate_0();
}

bool StageEntity::_01()
{
	if (this->_3e9 != 0) {
		return false;
	}
	if (this->_340 == 5) {
		return false;
	}
	FxRect rect;
	rect.x = this->viewOffset.x << 0xc;
	rect.y = this->viewOffset.y << 0xc;
	rect.halfWidth = this->renderSize.x << 0xb;
	rect.halfHeight = this->renderSize.y << 0xb;
	return func_0200ae9c(&this->position, &rect, data_02085a7c) != 0;
}

void StageEntity::_12()
{
	this->_3c6[this->linked_player] = 0xc;
	(this->activeCollider)._26 |= 0x140;
	if (this->_3c2 != 0) {
		(this->activeCollider)._25 = 0xa;
		(this->activeCollider)._2c = (void *)shellCallback;
	}
}

void StageEntity::_13()
{
	(this->activeCollider)._26 &= ~0x140;
	(this->activeCollider)._25 = 0x0;
	(this->activeCollider)._2c = (void *)damagePlayerCallback;
	this->accelH = 0;
	(this->minVelocity).x = 0;
	this->_2c6 &= 0xfffe;
}

void StageEntity::_19()
{
	if (this->_3f1 != 0x0) {
		(this->velocity).x = data_ov000_020c1f60[this->direction];
	} else {
		this->_pad4[1] = 0x0;
	}
	this->activeCollider._26 &= ~0x140;
	this->activeCollider._25 = 0x0;
	this->activeCollider._2c = damagePlayerCallback;
	this->_3f1 = 0x0;
	this->accelH = 0;
	this->minVelocity.x = 0;
	this->minVelocity.y = -0x4000;
	this->minVelocity.z = 0;
	this->_2c6 = this->_2c6 & 0xfffe;
	this->_340 = 0;
	return;
}

bool StageEntity::_14()

{
	this->activeCollider._25 = 0xa;
	this->activeCollider._26 = 0x113;
	return 0;
}

void StageEntity::_16()
{
	PlayerBase *player;

	if (this->linked_player == ~0) {
		return;
	}
	player = (PlayerActor *)Game::getPlayer(this->linked_player);
	player->func_ov011_0212bde0(this);
	this->activeCollider._26 &= ~0x100;
	this->activeCollider._25 = 0x0;
	this->activeCollider._2c = damagePlayerCallback;
	this->linked_player = -1;
	func_0201d954(&this->platformMgr, 0);
	this->collisionMgr._rawr = 0x0;
	this->_2c6 = this->_2c6 & 0xfffe;
	return;
}

void StageEntity::_37()
{
}

void StageEntity::_36()

{
	this->velocity.y = 0x2000;
	return;
}

void StageEntity::stopVelocity()
{
	Game::getPlayer(this->linked_player);
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(1, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209ab90(4, 0, 0x18000, this->linked_player);
	}
	this->activeCollider.unlink();
	this->direction = this->_3ee;
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_27()
{
	Game::getPlayer(this->linked_player);
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(1, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209ab90(4, 0, 0x18000, this->linked_player);
	}
	this->activeCollider.unlink();
	this->direction = this->_3ee;
	func_02022b64(0x86, &Vec3_32(this->_390.x, this->_390.y, 0x200000));
	this->_43(data_ov000_020c1f68[this->direction], 0x4000, 0);
}

bool StageEntity::func_ov000_0209ccd0(PlayerBase *player)
{
	if ((this->_2c6 & 0x400) != 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (player->position.x + player->centerOffset.x);
	this->linked_player = player->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x8000;
	return true;
}

void StageEntity::func_ov000_0209da00()
{
	StageEntity::func_ov000_0209da0c();
}

void StageEntity::func_ov000_0209e5a8(u32 x, u32 y, u32 param_3)
{
	x &= data_02085aa4;
	if (param_3 == ~0) {
		param_3 = 3;
	}
	u32 tileY = y & 0xfffff000;
	u32 tileX = x & 0xfffff000;
	func_ov000_020af30c(data_ov000_020cad40, (tileX << 4) >> 0x10, (u16)-((s32)tileY >> 0xc), 0, 0);
	Vec3_32 vec;
	vec.x = tileX;
	vec.y = tileY;
	vec.z = 0;
	Actor::spawnActor(0x42, ((u8)param_3 & 0xf) << 0xc | 9, &vec, 0, 0, 0);
}

Actor *StageEntity::func_ov000_0209e3f8(Vec3_32 *pos, u32 idx, u32 param_4, u32 param_5, u8 param_6)
{
	u32 type = data_ov000_020c2130[idx];
	param_5 = param_5 | type | (param_6 << 31) | (param_4 << 16) | 0x1000;
	Actor *actor = Actor::spawnActor(0x1f, param_5, pos, 0, 0, 0);
	if (type == 2) {
		func_02012398(0x16c, &this->position);
	} else if (type == 5) {
		func_02012398(0x175, pos);
	} else {
		func_02012398(0x176, pos);
	}
	return actor;
}

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

void StageEntity::func_ov000_020a01b4()

{
	this->_340 = 0;
	this->_3f0 = this->_3f0 ^ 1;
	this->activeCollider._a4 = data_ov000_020c1f38[this->_3f0];
	this->position.z = data_ov000_020c1f58[this->_3f0];
	this->_45();
	return;
}

void StageEntity::func_ov000_020a020c()

{
	if (this->_340 == 0) {
		this->_340 = 4;
		this->_44();
		return;
	}
	return;
}

void StageEntity::_43(u32 param_1, u32 param_2, u32 param_3)
{
	this->_42(param_1, param_2, param_3, 0);
	this->_340 = 3;
	func_02012398(0x178, &this->position);
	return;
}

void StageEntity::_18()
{
	PlayerBase *player;
	s32 iVar1;
	u32 uVar1;
	s32 iVar2;

	player = (PlayerActor *)Game::getPlayer((int)this->linked_player);
	(this->activeCollider)._a4 = (player->activeCollider)._a4;
	(this->collisionMgr)._b7 = (player->activeCollider)._a4;
	if (((
		 //((*(uint *)player->_pad2 & 1) == 0) &&
		 ((player->velocity).y < 0)) &&
	     (iVar1 = func_ov000_020a76d4(), iVar1 != 0)) &&
	    ((uVar1 = (this->position).x + (this->centerOffset).x & 0xffff, 0x400 < uVar1 && (uVar1 < 0x8001)))) {
		iVar2 = (this->velocity).x;
		if (iVar2 < 0) {
			iVar2 = -iVar2;
		}
		if (iVar2 < 0x2c00) {
			this->_3f1 = 0x1;
		}
	}
	if (this->_3f1 == 0x0) {
		this->_3c6[this->linked_player] = 0x10;
	} else {
		this->_3b8 = 0;
		(this->velocity).x = (int)(short)data_ov000_020c1f44[this->direction];
		this->_3c6[this->linked_player] = 5;
	}
	(this->activeCollider)._26 = (this->activeCollider)._26 | 0x140;
	(this->activeCollider)._25 = 0xa;
	(this->activeCollider)._2c = shellCallback;
	this->accelH = 0x100;
	this->accelV = -0x300;
	(this->minVelocity).x = (this->velocity).x;
	(this->minVelocity).y = -0x4000;
	(this->minVelocity).z = 0;
}

void StageEntity::_45()
{
	this->direction ^= 1;
	this->velocity.x = -(this->velocity).x;
	this->activeCollider._2c = damagePlayerCallback;
}

void StageEntity::_44()
{
	this->activeCollider._2c = (void *)0x0;
}

void StageEntity::_21()
{
	this->activeCollider.unlink();
	(this->minVelocity).y = -0x4000;
	func_02012398(0x70, &this->position);
	this->direction = this->_3e2;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, 0xfffffd00, 0);
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
	if (this->_3e8 != 0x0) {
		if (this->direction != '\0') {
			this->rotation.x += -0x300;
		} else {
			this->rotation.x += 0x300;
		}
	} else {
		this->rotation.x += 0x300;
	}
	this->updateVerticalVelocity();
	this->func_ov000_0209c85c();
	this->func_ov000_0209c820(0xfffffd00);
	this->_11();
	this->destroyInactive(((u32)(this->_2c6 & 2) << 0xf) >> 0x10);
	return true;
}
bool StageEntity::onUpdate_3()
{
	if (this->_3e8 != 0x0) {
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
	this->destroyInactive(((u32)(this->_2c6 & 2) << 0xf) >> 0x10);
	return true;
}
bool StageEntity::onUpdate_4()
{
	return true;
}
bool StageEntity::onUpdate_5()
{
}
bool StageEntity::onUpdate_6()
{
	this->_11();
	return true;
}
bool StageEntity::onUpdate_7()
{
}
bool StageEntity::onUpdate_8()
{
}
bool StageEntity::onUpdate_9()
{
}
void StageEntity::_11()
{
}

// StageEntity::func_ov000_0209acd4
// StageEntity::func_ov000_0209ac8c
// StageEntity::func_ov000_0209ac0c
// StageEntity::func_ov000_0209ab90

void StageEntity::func_ov000_0209a990(Vec3_32 *pos, s32 type, s32 player_id)
{
	if (player_id == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f78[type], pos, player_id);
	if ((u32)type < 5) {
		func_02020300(player_id, data_ov000_020c2050[type]);
	} else {
		func_02012398(0x17b, pos);
		func_02020544(player_id);
	}
}

void StageEntity::func_ov000_0209aa5c(Vec3_32 *pos, s32 type, s32 player_id)
{
	if (player_id == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f90[type], pos, player_id);
	if ((u32)type < 5) {
		func_02020300(player_id, data_ov000_020c20c8[type]);
	} else {
		func_02012398(0x17b, pos);
		func_02020544(player_id);
	}
}

void StageEntity::func_ov000_0209ab90(u32 type, s32 x, s32 y, s32 player_id)
{
	if (func_020202a0() == 2) {
		return;
	}
	Vec3_32 vec;
	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.x = x + this->position.x;
	vec.y = y + this->position.y;
	func_ov000_0209ac0c(&vec, type, player_id);
}


void StageEntity::func_ov000_0209ac0c(Vec3_32 *pos, s32 type, s32 player_id)
{
	if (func_020202a0() == 2) {
		return;
	}
	if (player_id == -1) {
		return;
	}
	func_ov010_020e657c(data_ov000_020c1f84[type], pos, player_id);
	if (type != 8) {
		func_02020300(player_id, data_ov000_020c2078[type]);
	} else {
		func_02012398(0x17b, pos);
		func_02020544(player_id);
	}
}


void StageEntity::func_ov000_0209ab04(s32 type, s32 player_id)
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(player_id);
	Vec3_32 pos = player->func_ov011_0212bbdc();
	pos.y = data_ov000_020c1fd8[player->runtimePowerup] + player->position.y;
	Vec3_32 vec;
	vec.x = pos.x;
	vec.y = pos.y;
	vec.z = 0;
	func_ov000_0209ac0c(&vec, type, player_id);
}


void StageEntity::func_ov000_0209b764()
{
	if (data_ov000_020ca288 != 0) {
		return;
	}
	if ((data_02085abc & 1) != 0) {
		return;
	}
	if ((data_02085abc & 2) != 0) {
		return;
	}
	if (func_020202a0() == 1) {
		func_ov000_0209b7e8(data_020887f0);
	} else {
		func_ov000_0209c288();
		func_ov000_0209b7e8(0);
		func_ov000_0209b7e8(1);
	}
}

void StageEntity::func_ov000_0209a938(u32 type, s32 x, s32 y, s32 player_id)
{
	Vec3_32 vec;
	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.x = x + this->position.x;
	vec.y = y + this->position.y;
	func_ov000_0209a990(&vec, type, player_id);
}

void StageEntity::func_ov000_0209aa04(u32 type,s32 x,s32 y,s32 player_id)

{
  Vec3_32 local_18;
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = 0;

  local_18.x = x+this->position.x;
  local_18.y = y+this->position.y;

  StageEntity::func_ov000_0209aa5c(&local_18,type,player_id);
  return;
}

// StageEntity::func_ov000_0209a990
// StageEntity::func_ov000_0209a938
// StageEntity::func_ov000_0209a938
// StageEntity::func_ov000_0209a80c
// StageEntity::_46()
// StageEntity::func_ov000_0209a5bc

bool StageEntity::func_ov000_0209a4f0(ActiveCollider *collider, PlayerBase *player, u32 param_3)
{
	s32 speed = collider->_64;
	bool falling = player->velocity.y <= 0;
	if (this->_3f1 != 0) {
		if ((player->_788 & 1) == 0 && this->position.y < player->position.y + 0xa000) {
			return true;
		}
		return false;
	}
	if (param_3 == 0 && !falling) {
		return false;
	}
	if (data_ov000_020ca290 != 0) {
		falling = true;
	}
	if (speed < 0 && -speed * 2 < data_ov000_020c20a0[falling][this->_3ec]) {
		return true;
	}
	return false;
}

s32 StageEntity::func_ov000_0209a23c() {

}

void StageEntity::attachToPlayerHands(s32 z, s32 y, s32 x)
{
	if (this->linked_player == -1) {
		return;
	}
	PlayerBase *player = (PlayerBase *)Game::getPlayer(this->linked_player);
	Vec3_32 pos = player->func_ov011_0212bff0();
	pos.x &= data_02085aa4;
	Game_modelMatrix = player->_68c;
	MTX::translate(Game_modelMatrix, x, y, z);
	this->position.x = pos.x + Game_modelMatrix.v[3][0];
	this->position.y = pos.y + Game_modelMatrix.v[3][1];
	this->position.z = pos.z + Game_modelMatrix.v[3][2];
	this->rotation.y = player->rotation.y;
}

s32 StageEntity::tryAttachToPlayerHands(s32 z, s32 y, s32 x)
{
	if (this->_340 == 5 && this->linked_player != -1 && (this->_354 & 1) == 0) {
		this->attachToPlayerHands(z, y, x);
		return 2;
	}

	return 0;
}

u32 StageEntity::random()
{
	return Wifi::random();
}



void StageEntity::func_ov000_0209da0c()
{
	for (u16 i = 0; i < 32; i++) {
		data_ov000_020ca4cc[i]._0 = 0;
		data_ov000_020ca4cc[i]._4 = 0;
		data_ov000_020ca4cc[i]._8 = 0;
	}
}

void StageEntity::func_ov000_0209cfc4(StageEntity *other)
{
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x2000;
}

void StageEntity::func_ov000_0209c820(u32 param_1)
{
	this->func_ov000_0209c7a0(&this->position, param_1);
	if ((this->_2c6 & 4) != 0) {
		func_ov000_0209c590(&this->position, &this->lastPosition, this->_350, 1);
	}
}

bool StageEntity::func_ov000_0209aff8(u32 id, u32 param_2)
{
	if ((data_02085abc & 2) != 0) {
		return func_ov000_0209b688(id, param_2);
	} else if (param_2 == 0) {
		return func_ov000_0209b320(id, param_2);
	} else {
		return func_ov000_0209b040(id, param_2);
	}
}


void StageEntity::func_ov000_0209c2f8(u32 id)
{
	if ((data_02085abc & 1) != 0) {
		return;
	}
	data_ov000_020ca2ec[id] = 0;
	data_ov000_020ca2e4[id] = 0;
	data_ov000_020ca2f4[id] = 0;
	data_ov000_020ca2dc[id] = 0;
	func_ov000_0209aff8(id, 1);
}

bool StageEntity::func_ov000_020a0048(PlayerBase *player)
{
	if (!player->virt_31(this)) {
		return false;
	}
	this->linked_player = player->linked_player;
	this->_340 = 5;
	this->_15();
	return true;
}

void StageEntity::_22()
{
	this->direction = this->_3ee;
	this->activeCollider.unlink();
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

bool StageEntity::func_ov000_0209d0ec(StageEntity *other)
{
	if ((this->_2c6 & 0x1000) == 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x800;
	return true;
}

bool StageEntity::func_ov000_0209d3d0(StageEntity *other)
{
	if ((this->_2c6 & 0x80) != 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x400;
	return true;
}

bool StageEntity::func_ov000_0209d708(StageEntity *other)
{
	if ((this->_2c6 & 0x800) == 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x10000;
	return true;
}

bool StageEntity::func_ov000_0209d774(StageEntity *other)
{
	if ((this->_2c6 & 0x200) != 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x1000;
	return true;
}

bool StageEntity::func_ov000_0209d7e0(StageEntity *other)
{
	if ((this->_2c6 & 0x100) != 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x200;
	return true;
}


void StageEntity::func_ov000_0209d694()
{
	Vec3_32 pos = func_02045bdc(&this->position, &this->centerOffset);
	pos.x &= data_02085aa4;
	Actor *actor = Actor::spawnActor(0x42, 5, &pos, 0, 0, 0);
	if (actor != NULL) {
		actor->position.x -= 0x8000;
	}
}


void StageEntity::func_ov000_0209c288()
{
	u8 *flag = data_ov000_020ca3cc;
	u16 *timer = data_ov000_020ca64c;
	for (UnkEntry_0208b168 *entry = data_0208b168.entries; entry->id != 0xffff; entry++, flag++, timer++) {
		if (*timer != 0) {
			(*timer)--;
			if (*timer == 1) {
				*flag &= ~1;
			}
		}
	}
}

void StageEntity::func_ov000_0209c7a0(Vec3_32 *pos, u32 param_2)
{
	if (this->checkLavaCollision(pos)) {
		this->_35();
		return;
	}
	if (this->_3d0 != 0) {
		return;
	}
	this->_3be = this->func_ov000_0209c6d4(pos, param_2);
	if (this->_3e4 == 0) {
		return;
	}
	if (this->_3d1 == 0) {
		return;
	}
	if (this->_3be == 0) {
		this->_3d0 = 1;
	}
}


void StageEntity::_15()
{
	PlayerActor *player = (PlayerActor *)Game::getPlayer(this->linked_player);
	bool facing = player->_9b0 == 0x8000;
	if (facing) {
		this->_3f0 = 0;
	} else {
		this->_3f0 = 1;
	}
	this->activeCollider._a4 = data_ov000_020c4ec0[this->_3f0];
	this->collisionMgr._b7 = data_ov000_020c4ec0[this->_3f0];
	this->activeCollider._26 |= 0x100;
	this->activeCollider._25 = 10;
	this->activeCollider._2c = damageEntityCallback;
}

void StageEntity::func_ov000_0209ee64(s32 x, s32 y, u32 param_3, u32 param_4, u8 param_5, s8 player_id, u16 param_7)
{
	Vec3_32 pos;
	pos.x = x;
	pos.y = y;
	pos.z = 0;
	pos.x += 0x8000;
	pos.y -= 0x10000;
	u32 settings = param_3 | (param_7 << 8);
	if (player_id >= 0) {
		func_02020300(player_id, 10);
	}
	if (player_id < 0) {
		player_id = 0;
	}
	func_ov010_020e653c(0x16, &pos, 0, 0, player_id, settings);
	func_02012398(0x177, &pos);
}

void StageEntity::func_ov000_0209eefc(s32 x, s32 y, u32 param_3, u32 param_4, u8 param_5, s8 player_id, u16 param_7)
{
	Vec3_32 pos;
	pos.x = x;
	pos.y = y;
	pos.z = 0;
	u32 settings = (param_3 << 4) | (param_4 << 8) | ((param_5 << 24) & 0x3000000) | ((player_id & 3) << 16) | (param_7 << 20);
	Actor::spawnActor(0xf1, settings, &pos, 0, 0, 0);
	if ((player_id & 3) != 3) {
		func_02020300(player_id, 10);
	}
	func_02012398(0x177, &pos);
}

bool StageEntity::func_ov000_0209ec28(PlayerBase *player, s32 a, s32 b, u32 mode, u8 param_5, u8 param_6)
{
	if (data_02085a98 == 1) {
		b &= data_02085aa4;
		a &= data_02085aa4;
	}
	bool result = false;
	if (param_5 == 2) {
		if (mode == 1) {
			result = true;
		} else if (mode == 3) {
			if (a < b) {
				result = true;
			}
		}
	} else {
		if (param_6 == 0) {
			return result;
		}
		if (player->powerup == 0 && mode == 2) {
			if (a < b + data_ov000_020c1f70[player->direction]) {
				result = true;
			}
		} else if (a < b) {
			result = true;
		}
	}
	return result;
}

u16 StageEntity::func_ov000_0209c6d4(Vec3_32 *pos, u32 accel)
{
	if (func_ov000_020a6e70(pos->x, pos->y, 0, -1)) {
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
		return 1;
	}
	this->accelV = accel;
	this->minVelocity.y = -0x4000;
	this->minVelV = -0x4000;
	return 0;
}

void StageEntity::_35()
{
	Vec3_32 &offset = this->centerOffset;
	Vec3_32 pos = this->position;
	this->activeCollider.unlink();
	this->_3e4 = 1;
	for (s32 i = 0; i < func_020202a0(); i++) {
		PlayerBase *player = (PlayerBase *)Game::getPlayer(i);
		if (player != NULL && player->linkedActor == this) {
			player->func_ov011_0212bde0(this);
		}
	}
	pos.add2(offset);
	func_02022220(&pos);
	func_02012398(0x70, &pos);
	this->destroy(true);
}

void StageEntity::_23()
{
	this->direction = this->_3ee;
	this->activeCollider.unlink();
	this->func_ov000_0209d694();
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(1, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209ab90(4, 0, 0x18000, this->linked_player);
	}
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_31()
{
	Game::getPlayer(this->linked_player);
	this->activeCollider.unlink();
	this->direction = this->_3ee;
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(1, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209ab90(4, 0, 0x18000, this->linked_player);
	}
	func_02012398(0x70, &this->position);
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

bool StageEntity::destroyInactive(u32 flags)
{
	if ((data_02085abc & 2) != 0) {
		return false;
	}
	if (this->collisionMgr.func_ov000_020a6c9c()) {
		return false;
	}
	FxRect rect;
	rect.x = this->viewOffset.x << 0xc;
	rect.y = this->viewOffset.y << 0xc;
	rect.halfWidth = this->activeSize.x << 0xb;
	rect.halfHeight = this->activeSize.y << 0xb;
	if (((flags & 2) == 0 && func_0200aed8(&this->position, &rect, this->_2be)) || func_ov000_0209ae88(&this->position, &rect, this->_2be)) {
		if ((flags & 1) == 0) {
			this->destroy(this->_3e4);
			return true;
		}
	}
	return false;
}

void StageEntity::_42(u32 velX, u32 velY, u32 accel, u8 param_4)
{
	for (s32 i = 0; i < func_020202a0(); i++) {
		PlayerBase *player = (PlayerBase *)Game::getPlayer(i);
		if (player != NULL && player->linkedActor == this) {
			player->func_ov011_0212bde0(this);
		}
	}
	if (this->_3f0 != 0) {
		this->rotation.y = 0;
		this->position.z = -0x180000;
	} else {
		this->rotation.y = data_ov000_020c4ec8[this->direction] * 2;
		this->position.z = 0x180000;
	}
	this->_3e3 = param_4;
	this->_3ea = 0;
	this->_3e4 = 1;
	this->accelV = accel;
	this->_3d1 = this->_3be;
	this->velocity.x = velX;
	this->velocity.y = velY;
	this->velocity.z = 0;
	this->minVelocity.y = -0x4000;
	this->collisionMgr._rawr = 0;
	this->_340 = 2;
}

void StageEntity::func_ov000_0209c85c()
{
	Vec3_32 step;
	s32 velX = this->velocity.x;
	s32 speed = velX < 0 ? -velX : velX;
	u16 angle = this->collisionMgr.func_ov000_020a7ea8((u32)(velX & 0x80000000) >> 31);
	if (this->_3ea != 0) {
		step.x = 0;
		step.y = 0;
		step.z = 0;
	} else {
		step.x = _FixedMul(speed, _FixedCos(angle));
		step.y = this->velocity.y + _FixedMul(speed, _FixedSin(angle));
		step.z = this->velocity.z;
		if (this->_3be != 0) {
			step.x = step.x >> 1;
		}
	}
	step.add2(this->_31c);
	this->position.add3(step);
}

void StageEntity::func_ov000_0209e038()
{
	bool vsMode = data_02085a84 != 0;
	if (vsMode) {
		return;
	}
	u8 variant;
	if (data_0208b168._0->_1e == 0) {
		variant = ((Wifi::random() & 0x7fff) * 3) >> 15;
		if (variant == 2) {
			return;
		}
	} else if (data_0208b168._0->_1e == 1) {
		variant = ((Wifi::random() & 0x7fff) * 2) >> 15;
		if (variant == 1) {
			return;
		}
	} else {
		return;
	}
	StageEntity *player = func_020205ec();
	Vec3_32 *src = &player->position;
	Vec3_32 pos = *src;
	Actor::spawnActor(0x3e, ((variant & 3) << 24) | 0x10000000, &pos, 0, 0, 0);
}

Actor *StageEntity::func_ov000_0209e49c(Vec3_32 *pos, u32 idx, u32 player_id, u32 param_5, u8 param_6, u8 param_7)
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(player_id);
	Vec3_32 *src = &player->position;
	Vec3_32 playerPos = *src;
	s32 diff = playerPos.x - pos->x;
	u32 side;
	if (param_6 != 0 && diff > 0) {
		side = 1;
	} else {
		side = 0;
	}
	u32 type = data_ov000_020c2130[idx];
	param_5 = param_5 | type | (side << 31) | (player_id << 16);
	if (param_7 != 0) {
		param_5 |= 0x1000;
	}
	Actor *actor = Actor::spawnActor(0x1f, param_5, pos, 0, 0, 0);
	if (type == 2) {
		func_02012398(0x16c, &this->position);
	} else if (type == 5) {
		func_02012398(0x175, pos);
	} else {
		func_02012398(0x176, pos);
	}
	return actor;
}

StageEntity *StageEntity::func_ov000_0209c178(u32 idx, u32 settings, Vec3_32 *pos)
{
	if (data_ov000_020c22b8[idx] == 0x145) {
		return NULL;
	}
	UnkSpawnCfg_020c529c *cfg = &data_ov000_020c529c[idx];
	StageEntity *entity = (StageEntity *)Actor::spawnActor(data_ov000_020c22b8[idx], settings, pos, 0, 0, 0);
	if (entity == NULL) {
		return entity;
	}
	if (idx < 10) {
		return entity;
	}
	entity->_2c6 = cfg->_10;
	entity->_2c8 = cfg->_12;
	entity->_3e0 = 0;
	if (entity->activeSize.x == 0 && entity->activeSize.y == 0) {
		entity->activeSize.x = cfg->_4 << 4;
		entity->activeSize.y = cfg->_6 << 4;
	}
	if (entity->viewOffset.x == 0 && entity->viewOffset.y == 0) {
		entity->viewOffset.x = cfg->_c;
		entity->viewOffset.y = -cfg->_e;
	}
	if (entity->renderSize.x == 0 && entity->renderSize.y == 0) {
		entity->renderSize.x = entity->activeSize.x;
		entity->renderSize.y = entity->activeSize.y;
	}
	return entity;
}

void StageEntity::func_ov000_0209a5bc(PlayerBase *player, s32 param_2, u32 param_3)
{
	if (param_2 != 0) {
		this->_46(player, param_2);
	}
	if (this->_3f1 != 0 && player->velocity.y > 0) {
		return;
	}
	if (param_3 == 0) {
		if (player->_7b7 < 10) {
			player->_7b7++;
		}
		player->_7b8++;
		player->_7b8 = player->_7b8 % 4;
		if (player->_7b7 > 8) {
			player->_7b7 = 8;
		}
		if (this->_3de == 0) {
			this->func_ov000_0209ab90(player->_7b7, 0, 0x18000, this->activeCollider._a7);
		} else if (this->_3de == 1) {
			this->func_ov000_0209aa04(player->_7b7, 0, 0x18000, this->activeCollider._a7);
		}
	}
	if (this->_34c != -1) {
		func_02012398(this->_34c, &this->position);
	}
}

bool StageEntity::func_ov000_0209b688(u32 id, u32 param_2)
{
	UnkSpawnCfg_020c529c *cfg;
	u8 *flag = data_ov000_020ca3cc;
	u16 *timer = data_ov000_020ca64c;
	for (UnkEntry_0208b168 *entry = data_0208b168.entries; entry->id != 0xffff; entry++, flag++, timer++) {
		if ((*flag & 1) == 0) {
			cfg = &data_ov000_020c529c[entry->id];
			UnkRect16 rect;
			rect.x = (entry->_2 + cfg->_8) << 4;
			rect.y = (entry->_4 + cfg->_a) << 4;
			rect.w = cfg->_4 << 4;
			rect.h = cfg->_6 << 4;
			u32 area = func_0201ef94(&rect);
			func_ov000_0209bf10(entry, cfg, flag, timer, area, id);
		}
	}
}

void StageEntity::_24()
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(this->linked_player);
	if (player->_7b9 < 10) {
		player->_7b9++;
	}
	if (player->_7b9 > 8) {
		player->_7b9 = 8;
	}
	s8 count = player->_7b9;
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(count, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209aa04(count, 0, 0x18000, this->linked_player);
	}
	this->direction = this->_3ee;
	this->activeCollider.unlink();
	if (player->_7b9 < 8) {
		func_02012398(count + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_25()
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(this->linked_player);
	if (player->_7ba < 10) {
		player->_7ba++;
	}
	if (player->_7ba > 8) {
		player->_7ba = 8;
	}
	s8 count = player->_7ba;
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(count, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209aa04(count, 0, 0x18000, this->linked_player);
	}
	this->direction = this->_3ee;
	this->activeCollider.unlink();
	if (player->_7ba < 8) {
		func_02012398(count + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction], 0x3000, -0x300, 0);
}

void StageEntity::_26()
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(this->linked_player);
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(1, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209ab90(4, 0, 0x18000, this->linked_player);
	}
	func_020200d4(this->linked_player, 10);
	this->activeCollider.unlink();
	this->direction = this->_3ee;
	s32 velX = (player->velocity.x - this->velocity.x) + (data_ov000_020c4ec4[this->direction] << 12);
	if (velX > 0x6000) {
		velX = 0x6000;
	} else if (velX < -0x6000) {
		velX = -0x6000;
	}
	func_02022b64(0x86, &Vec3_32(this->_390.x, this->_390.y, 0x200000));
	this->_43(velX, 0x3000, -0x300);
}

void StageEntity::_32()
{
	PlayerBase *player = (PlayerBase *)Game::getPlayer(this->linked_player);
	this->activeCollider.unlink();
	this->direction = this->_3ee;
	if (player->_7bc < 10) {
		player->_7bc++;
	}
	if (player->_7bc > 8) {
		player->_7bc = 8;
	}
	u32 count = player->_7bc;
	if (this->_3de == 0) {
		this->func_ov000_0209ab90(count, 0, 0x18000, this->linked_player);
	} else if (this->_3de == 1) {
		this->func_ov000_0209aa04(count, 0, 0x18000, this->linked_player);
	}
	if (count < 8) {
		func_02012398(count + 0x70, &this->position);
	} else {
		func_02012398(0x77, &this->position);
	}
	this->minVelocity.y = -0x4000;
	this->_42(data_ov000_020c4ed4[this->direction] >> 1, 0x6000, -0x600, 0);
}

void StageEntity::func_ov000_0209e13c(PlayerBase *player, u32 param_2, u32 param_3)
{
	bool vsMode = data_02085a84 != 0;
	if (!vsMode) {
		return;
	}
	u8 player_id = player->linked_player;
	u32 count = 1;
	s32 stock = func_0202046c(player_id);
	if (stock == 0) {
		return;
	}
	s32 remaining;
	if (param_3 != 0) {
		if (stock >= 3) {
			remaining = stock - 3;
			count = 3;
		} else {
			count = stock;
			remaining = 0;
		}
	} else {
		remaining = stock - 1;
	}
	func_0202047c(player_id, remaining);
	Vec3_32 pos;
	pos.x = player->position.x;
	pos.x &= data_02085aa4;
	pos.y = player->position.y;
	pos.z = 0x80000;
	if (player->powerup == 4 || player->powerup == 0) {
		pos.y -= 0x10000;
	}
	Actor::spawnActor(0x22, (player->direction << 31) | 2 | (param_2 != 0 ? 0x10 : 0) | (player_id << 8) | (count << 12), &pos, 0, 0, 0);
}

u32 StageEntity::func_ov000_0209a80c(ActiveCollider *collider, s32 param_2, u32 param_3, u8 param_4)
{
	if ((u16)(collider->_1c0 & 1) == 0) {
		return 0;
	}
	PlayerBase *player = func_ov000_020a3d68(collider);
	if (player->powerup == 4) {
		if ((player->_778 & 0x800000) != 0) {
			if (param_2 != 0) {
				this->func_ov000_0209a5bc(player, param_2, param_4);
				if (this->_34c != -1) {
					func_02012398(this->_34c, &this->position);
				}
			}
			return 1;
		}
		if (this->func_ov000_0209a4f0(collider, player, param_3)) {
			if (param_2 != 0) {
				this->_46(player, param_2);
				if (this->_34c != -1) {
					func_02012398(this->_34c, &this->position);
				}
			}
			return 2;
		}
	} else if (this->func_ov000_0209a4f0(collider, player, param_3)) {
		this->func_ov000_0209a5bc(player, param_2, param_4);
		return 1;
	}
	return 0;
}

void StageEntity::func_ov000_0209e2c8(s32 x, s32 y, u32 mode)
{
	u32 tileX = x & data_02085aa4;
	Vec3_32 pos;
	pos.x = tileX;
	pos.y = y;
	pos.z = 0;
	if (mode == 0) {
		func_ov000_020af30c(data_ov000_020cad40, (tileX << 4) >> 0x10, (u16)-(y >> 0xc), 0, 0);
		Actor::spawnActor(0x47, 0, &pos, 0, 0, 0);
	} else {
		if (mode == 2) {
			pos.x = tileX - 0x10000;
			pos.y = y;
		}
		func_ov000_020af30c(data_ov000_020cad40, ((u32)pos.x << 4) >> 0x10, (u16)-(pos.y >> 0xc), 0, 0);
		func_ov000_020af30c(data_ov000_020cad40, ((u32)(pos.x + 0x10000) << 4) >> 0x10, (u16)-(pos.y >> 0xc), 0, 0);
		Actor::spawnActor(0x48, 0, &pos, 0, 0, 0);
	}
}

void StageEntity::_46(PlayerBase *player, s32 value)
{
	s32 speed = value + player->_6bc->_20;
	if (player->powerup == 4) {
		speed = (s32)(((s64)speed * 0xd00LL + 0x800) >> 12);
	} else if (player->func_ov011_0212bb90()) {
		speed = (s32)(((s64)speed * 0xd80LL + 0x800) >> 12);
	}
	if ((player->_778 & 0x80000000) != 0) {
		Vec3_32 pos(player->position.x, player->position.y, 0x200000);
		func_02022b64(0xf5, &pos);
		func_02022b64(0xf6, &pos);
		func_02022b64(0xf7, &pos);
	}
	player->virt_20(speed, 0, 0, 1, player->_7b8);
	data_ov000_020ca290 = 4;
}

u32 StageEntity::func_ov000_0209c590(Vec3_32 *pos, Vec3_32 *prev, s32 param_3, u32 playSound)
{
	s32 top = data_ov000_020cadac[data_02085a7c];
	s32 surface = data_ov000_020cae0c[data_02085a7c];
	if ((prev->y <= top && surface < pos->y) || (pos->y < surface && top <= prev->y)) {
		func_ov054_021646e0(pos->x, param_3);
		Vec3_32 splash;
		splash.x = pos->x;
		splash.y = surface;
		splash.z = pos->z;
		u8 type = data_ov000_020cace0[data_02085a7c];
		if (type == 4) {
			splash.y = surface + 0x8000;
			func_020221b4(&splash);
			if (playSound != 0) {
				func_02012398(0x173, pos);
			}
			return 4;
		}
		if (type == 2) {
			func_020221d8(pos);
			return 2;
		}
		func_020221fc(&splash);
		if (playSound != 0) {
			func_02012398(0x173, pos);
		}
		return 1;
	}
	return 0;
}

void StageEntity::_17(PlayerBase *player)
{
	this->linked_player = player->linked_player;
	if (player->_7b7 < 10) {
		player->_7b7++;
	}
	player->_7b8++;
	player->_7b8 = player->_7b8 % 4;
	if (player->_7b7 > 8) {
		player->_7b7 = 8;
	}
	this->func_ov000_0209ab90(player->_7b7, 0, 0x18000, this->linked_player);
	{
		Vec3_32 pos;
		pos.set((this->_390.x + this->_39c.x) >> 1, (this->_390.y + this->_39c.y) >> 1, 0x200000);
		func_02022b64(0xd2, &pos);
		func_02022b64(0xd3, &pos);
	}
	this->direction = this->isBehindTarget(player);
	s32 velX = player->velocity.x;
	s32 speed = data_ov000_020c1f40[this->direction];
	if (this->direction == (u8)((u32)(velX & 0x80000000) >> 31)) {
		speed += velX >> 1;
	}
	this->velocity.x = speed;
	func_02012398(0x70, &this->position);
	this->_18();
	this->_340 = 9;
}

bool StageEntity::func_ov000_0209d240(StageEntity *other)
{
	if ((this->_2c6 & 0x40) != 0) {
		return false;
	}
	s32 diff = (this->position.x + this->centerOffset.x) - (other->position.x + other->centerOffset.x);
	this->linked_player = other->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	return true;
}

bool StageEntity::func_ov000_0209acd4(Vec3_32 *pos)
{
	s32 out;
	data_ov000_020ca858(pos->x >> 0xc, pos->y >> 0xc, (s32)&out, 0);
	return (u32)(out & 0x80000000) >> 31;
}

bool StageEntity::func_ov000_0209ac8c(Vec3_32 *pos)
{
	s32 out;
	data_ov000_020ca858(pos->x >> 0xc, pos->y >> 0xc, 0, (s32)&out);
	return (u32)(out & 0x80000000) >> 31;
}


u8 StageEntity::func_ov000_0209aad0(Vec3_32 *pos, u32 a, u32 b)
{
	return func_ov010_020e653c(0x18, pos, 0, 0, b, a);
}

bool StageEntity::spawnBrokenPipe(s32 a, s32 b, u32 c, u32 d, u8 e, u8 f, s8 g)
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
	Actor *actor = other->owner;
	if (actor->actorType != 1) {
		return;
	}
	StageEntity *self = (StageEntity *)collider->owner;
	u8 player_id = actor->linked_player;
	if (other->_24 == 0) {
		self->_2d4[player_id].actor = actor;
		self->_2d4[player_id]._4 = collider->_3c;
		self->_2d4[player_id]._8 = collider->_64;
		self->_3ca |= data_ov000_020c1f48[player_id];
	} else {
		self->_2ec[player_id].actor = actor;
		self->_2ec[player_id]._4 = collider->_40;
		self->_2ec[player_id]._8 = collider->_68;
		self->_2ec[player_id]._c = collider->_a2 & 0xfffe;
		self->_3ca |= data_ov000_020c1f4c[player_id];
	}
}

void StageEntity::damageEntityCallback(ActiveCollider *collider)
{
}

void StageEntity::updateBounce(s32 a, s32 b, s32 c)
{
	if ((this->collisionMgr._rawr & 0x1f40) == 0) {
		return;
	}
	if (b < 0x1000) {
		this->velocity.x = _FixedMul(this->velocity.x, b);
		s32 speed = this->velocity.x;
		if (speed < 0) {
			speed = -speed;
		}
		if (speed < 0x100) {
			this->velocity.x = 0;
		}
	}
	if (this->velocity.y >= 0) {
		return;
	}
	this->velocity.y = -this->velocity.y;
	this->velocity.y = _FixedMul(this->velocity.y, c);
	if (this->velocity.y < a) {
		this->velocity.y = 0;
	}
}

void StageEntity::destroy(bool permanent)
{
	Base::destroy();
	u8 *_3d8 = this->_3d8;
	u16 *_3cc = this->_3cc;
	if (!permanent) {
		if (_3d8 != 0) {
			*_3d8 &= ~1;
		}
	} else {
		if (_3d8 != 0) {
			*_3d8 |= 8;
		}
		if (_3cc != 0) {
			*_3cc = 300;
		}
		return;
	}
}

void StageEntity::setTimedEvent(u32 event_id, s32 time, bool enable, bool switch_event, bool play_sfx)
{
}

u16 getActorID(u8 sprite_id)
{
	return data_ov000_020c22b8[sprite_id];
}

void StageEntity::onUpdate_xx()
{
	if ((this->_2c6 & 0x4000) != 0) {
		return;
	}

	if ((u32)((this->activeCollider._1c0 & 0x80) << 0x10) >> 0x10) {
		this->_3bc = 0x18;
		this->_3a8 = 0x1000;
	}

	if (this->_3bc == 0) {
		this->_35c.x = this->scale.x;
		this->_35c.y = this->scale.y;
		this->_35c.z = this->scale.z;
		this->_3a8 = 0x1000;
		return;
	}
	this->_3bc -= 1;
	if (this->_3bc & 0x4) {
		this->_3a8 += 0x100;
	} else {
		this->_3a8 -= 0x100;
	}
}

void StageEntity::applyFireballWiggle()
{
	if (this->_2c6 & 0x4000) {
		this->_35c.x = this->scale.x;
		this->_35c.y = this->scale.y;
		this->_35c.z = this->scale.z;
	} else if (this->_3a8 == 0x1000) {
		this->_35c.x = this->scale.x;
		this->_35c.y = this->scale.y;
		this->_35c.z = this->scale.z;
	} else {
		this->_35c.x = ((s64)(s32)this->_3a8 * (s64)this->scale.x + 0x800) >> 12;
		this->_35c.y = ((s64)(s32)this->_3a8 * (s64)this->scale.y + 0x800) >> 12;
		this->_35c.z = ((s64)(s32)this->_3a8 * (s64)this->scale.z + 0x800) >> 12;
	}
}

bool StageEntity::rotateToTarget(s16 a[2], s16 b[2])
{
	this->rotation.y += b[this->direction];
	if (a[0] <= this->rotation.y || this->rotation.y <= a[1]) {
		this->rotation.y = a[this->direction];
		return true;
	}
	return false;
}

bool StageEntity::checkPlayersInOffset(s32 x)
{
	if (func_020202a0() == 2) {
		PlayerActor *player0 = (PlayerActor *)Game::getPlayer(0);
		PlayerActor *player1 = (PlayerActor *)Game::getPlayer(1);
		Vec3_32 pos0 = player0->position;
		Vec3_32 pos1 = player1->position;
		s32 dist0 = pos0.x - this->position.x;
		if (dist0 < 0) {
			dist0 = -dist0;
		}
		if (dist0 < x) {
			return true;
		}
		s32 dist1 = pos1.x - this->position.x;
		if (dist1 < 0) {
			dist1 = -dist1;
		}
		return dist1 < x;
	}
	StageEntity *player = func_020205ec();
	Vec3_32 pos = player->position;
	s32 dist = pos.x - this->position.x;
	if (dist < 0) {
		dist = -dist;
	}
	return dist < x;
}

bool StageEntity::checkPlayersInOffset(s32 x, s32 y)
{
	if (func_020202a0() == 2) {
		PlayerActor *player0 = (PlayerActor *)Game::getPlayer(0);
		PlayerActor *player1 = (PlayerActor *)Game::getPlayer(1);
		Vec3_32 &ref0 = player0->position;
		Vec3_32 pos0 = ref0;
		Vec3_32 &ref1 = player1->position;
		Vec3_32 pos1 = ref1;
		s32 dx0 = pos0.x - this->position.x;
		if (dx0 < 0) {
			dx0 = -dx0;
		}
		s32 dy0 = pos0.y - this->position.y;
		if (dy0 < 0) {
			dy0 = -dy0;
		}
		s32 dx1 = pos1.x - this->position.x;
		if (dx1 < 0) {
			dx1 = -dx1;
		}
		s32 dy1 = pos1.y - this->position.y;
		if (dy1 < 0) {
			dy1 = -dy1;
		}
		if (dx0 < x && dy0 < y) {
			return true;
		}
		if (dx1 < x && dy1 < y) {
			return true;
		}
		return false;
	}
	StageEntity *player = func_020205ec();
	Vec3_32 &ref = player->position;
	Vec3_32 pos = ref;
	s32 dx = pos.x - this->position.x;
	if (dx < 0) {
		dx = -dx;
	}
	s32 dy = pos.y - this->position.y;
	if (dy < 0) {
		dy = -dy;
	}
	if (dx < x && dy < y) {
		return true;
	}
	return false;
}

u32 StageEntity::updateCollisionSensors()
{
	u32 flags = 0;
	u32 bottom = this->updateBottomSensors();
	if ((this->collisionMgr._rawr & 0x1f40) != 0) {
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
	bool lava = false;
	if (func_ov000_020a6d18(pos->x, pos->y) == 0x10000004) {
		lava = true;
	} else if (data_ov000_020cace0[data_02085a7c] == 2 && data_ov000_020cae0c[data_02085a7c] >= pos->y) {
		lava = true;
	}
	if (lava) {
		func_020221d8(pos);
	}
	return lava;
}


void StageEntity::_38() {
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->accelV = 0;
}

u32 StageEntity::updateBottomSensors()
{
	this->_3ea = 0;
	this->_3eb = 0;
	u32 result = this->collisionMgr.func_ov000_020a917c();
	if ((this->collisionMgr._rawr & 0x1f40) != 0) {
		if (this->collisionMgr.func_ov000_020a8140() == 0x3000) {
			this->_3ea = 1;
		}
		if (this->collisionMgr.func_ov000_020a8140() == 0x1000) {
			this->_3eb = 1;
		}
		Vec3_32 *src = &this->collisionMgr._54;
		this->_31c = *src;
	} else {
		this->_31c.x = 0;
		this->_31c.y = 0;
		this->_31c.z = 0;
	}
	return result;
}

u32 StageEntity::updateSideSensors()
{
	u8 side = (u32)((this->position.x - this->collisionMgr._64.x) & 0x80000000) >> 31;
	s32 offset = data_ov000_020c4ec4[side];
	u32 result = this->collisionMgr.func_ov000_020a915c(&offset, 0);
	offset = data_ov000_020c4ec4[(u8)(side ^ 1)];
	this->collisionMgr.func_ov000_020a915c(&offset, 0x40000000);
	if ((this->_2bf & 3) != 0) {
		this->collisionMgr.func_ov000_020a915c(&offset, 0);
	}
	return result;
}

bool StageEntity::checkSquished()
{
	u8 sides = this->_2bf;
	if (sides != 0) {
		if ((u8)(sides & 1) != 0 && (this->collisionMgr._rawr & 0x15) != 0) {
			return true;
		}
		if ((u8)(sides & 2) != 0 && (this->collisionMgr._rawr & 0x2a) != 0) {
			return true;
		}
		if ((u8)(sides & 8) != 0 && (this->collisionMgr._rawr & 0x1f40) != 0) {
			return true;
		}
		if ((u8)(sides & 4) != 0 && (this->collisionMgr._rawr & 0xe000) != 0) {
			return true;
		}
	}
	return false;
}

void StageEntity::onStomped()
{
}

void StageEntity::onMegaGroundPound()
{
	this->activeCollider.unlink();
	this->_42(0, 0x2000, 0xfffffd00, 0);
}

void StageEntity::onStageComplete(PlayerActor *player)
{
	Vec3_32 pos = this->position;
	Vec3_32 &offset = this->centerOffset;
	if ((this->_2c6 & 0x10) == 0) {
		if (player->_7b7 < 10) {
			player->_7b7++;
		}
		player->_7b8++;
		player->_7b8 = player->_7b8 % 4;
		if (player->_7b7 > 8) {
			player->_7b7 = 8;
		}
		this->func_ov000_0209a938(player->_7b7, 0, 0x18000, player->linked_player);
		pos.add2(offset);
		pos.y += 0x4000;
		func_02022220(&pos);
		func_02012398(0x70, &pos);
		this->destroy(true);
	}
}

bool StageEntity::setGroundPoundCollision(PlayerActor *player)
{
	s32 diff = (this->position.x + this->centerOffset.x) - (player->position.x + player->centerOffset.x);
	if ((this->_2c6 & 0x20) != 0) {
		return false;
	}
	if (player->powerup == 4) {
		return false;
	}
	this->linked_player = player->linked_player;
	this->_3ee = (u32)(diff & 0x80000000) >> 31;
	this->collisionType |= 0x4000;
	return true;
}

bool StageEntity::isBelowPlayer(s32 posY, ActiveCollider *collider, u8 player_id)
{
	return -((posY + collider->rect.y) - collider->rect.halfHeight) < (int)Game::cameraY[player_id];
}

void StageEntity::damagePlayerCallback(ActiveCollider *collider, ActiveCollider *other)
{
}

bool StageEntity::playerCollision(ActiveCollider *collider, ActiveCollider *other)
{
}

void StageEntity::entityCollision()
{
}

void StageEntity::damagePlayer(ActiveCollider *collider, PlayerBase *player)
{
	bool check;
	if ((player->_79c != 0) || (player->_7c1 != 0)) {
		check = 1;
	} else {
		check = 0;
	}

	if (!check) {
		u32 shell_status = player->getShellStatus();
		if (shell_status != 1) {
			player->virt_25(this, 0, 0x4000, 0);
		}
	}
}

u32 StageEntity::stopPlayerInShell(ActiveCollider *collider, PlayerActor *player)
{
	if (player->getShellStatus() == 1) {
		if ((collider->_3c > 0 && player->velH > 0) || (collider->_3c < 0 && player->velH < 0)) {
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
	s32 right = rect.x + rect.halfWidth;
	s32 bottom = rect.y - rect.halfHeight;
	Vec3_32 *pos = &player->position;
	pos->x &= data_02085aa4;
	if (rect.x <= pos->x && pos->x <= right && rect.y >= pos->y && pos->y >= bottom) {
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
	func_02045908(input);
	return *input;
}


u32 StageEntity::getSpritePriority(u32 a)
{
	u16 type = 0;
	u16 idx;
	if (a != 0) {
		idx = a * 4;
	} else {
		idx = data_0208b168._0->_1c * 4;
	}
	if (this->_3be != 0 || this->_3f0 != 0) {
		type = 1;
	} else if (this->_3ea != 0) {
		type = 2;
	}
	u8 priority = data_ov000_020c1fb8[idx + type];
	if (this->_3d2 != 0) {
		priority += 0x10;
	}
	return priority;
}

u16 *StageEntity::getObjectBank(u32 sprite_id)
{
	return &Stage::ObjectBankTable[sprite_id];
}



bool StageEntity::func_ov000_0209ff98() {

	fx32 dummy = data_ov000_020c4ec4[direction];
	collisionMgr.func_01ffe778(&dummy, 0);

	if (_2c6 & 0x8000) {

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
		//Nitro::Math_AddVec3_32s(&pos, &centerOffset, r);

		if (collisionMgr.getSolidTileType(pos.x, pos.y))
			return true;

	}

	return false;

}
