#include "Coin.hpp"
#include "../ProcessManager.hpp"

bool (Coin::*data_ov010_021293e4)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_021293ec)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_021293f4)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_021293fc)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_02129404)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_0212940c)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_02129414)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_0212941c)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_02129424)() = Coin::func_ov010_020d923c;
bool (Coin::*data_ov010_0212942c)() = Coin::func_ov010_020d923c;

void *Coin::create()
{
	return new Coin();
}

bool Coin::func_ov010_020d9dcc(bool (Coin::**param_1)())
{
	if (this->_430 != param_1) {
		if (this->_430 != NULL) {
			this->_4e4 = 0xff;
			(this->**_430)();
		}
		this->_430 = param_1;
		this->_4e4 = 0;
		(this->**_430)();
	}
	return true;
}

void Coin::func_ov010_020d9d84()
{
	if (this->_430 == NULL) {
		this->func_ov010_020d9dcc(&data_ov010_0212941c);
	}
	(this->**_430)();
}

StageEntity *func_020205ec();
void Coin::func_ov010_020d9cf0(StageEntity *param_1)
{
	if (BOOL(param_1->actorType == 2) == FALSE) {
		return;
	}
	u16 object_id = param_1->object_id;
	if (((object_id != 0xf0) && (object_id != 0xf1)) && (object_id != 0xbc)) {
		return;
	}
	if (this->_4ec != 0) {
		return;
	}
	i8 linked_player = param_1->linked_player;
	if (2 <= linked_player) {
		linked_player = func_020205ec()->linked_player;
	}
	this->_4e3 = linked_player;
	this->func_ov010_020d9dcc(&data_ov010_02129404);
	func_02012398(0x16c, &this->position);
	this->_4ae |= 4;
}

u32 data_ov000_020cad40;
void func_ov000_020af844(i32, u16, u16);
bool Coin::func_ov010_020d9c78()
{
	if ((this->_4a8 & 0x400000) != 0) {
		if (this->_4c0 == 0) {
			func_ov000_020af844(data_ov000_020cad40, this->_408.x >> 0xc, -(this->_408.y>>0xc));
		}
		Base::destroy();
		return true;
	}
	this->_444.link();
	return false;
}

void func_02020300(u32, u32);
void Coin::_21()
{

	i8 linked_player = this->linked_player;
	if (2 <= linked_player) {
		StageEntity *stage_entity = func_020205ec();
		linked_player = stage_entity->linked_player;
	}
	func_02020354(linked_player);
	if (func_020202a0() == true) {
		func_02020300(linked_player, 100);
	} else {
		i32 iVar2 = func_0202040c(linked_player);
		iVar2 -= 1;
		if (iVar2 < 0) {
			iVar2 = 7;
		}
		StageEntity::func_ov000_0209aad0(&this->position, iVar2, linked_player);
	}
	func_02012398(0x16c, &this->position);
	Base::destroy();
}

void Coin::func_ov010_020d9b84()
{
	if (this->_4d0 != 0) {
		this->_4d0 -= 1;
	}
	if (this->_4d0 < 0x78) {
		if (this->_4d0 == 0) {
			Base::destroy();
			return;
		}
		if (this->_4d8 != 0) {
			this->_4d8 -= 1;
		} else {
			this->_4d8 = 4;
			this->_4da ^= 1;
		}
		return;
	}
	return;
}

void Coin::func_ov010_020d9b40()
{
	if (this->_4f1 != 0) {
		this->_4f1 -= 1;
	}
	if (this->_4f1 == 0) {
		this->_4f0 = this->_4f0 + 1 & 3;
		this->_4f1 = 8;
	}
	this->_4e9 ^= 1;
}

void Coin::func_ov010_020d9acc()
{
	if (this->_4ed == 0) {
		this->_418.x -= 0x80;
		if (this->_418.x <= 0xc00) {
			this->_418.x = 0xc00;
			this->_4ed = this->_4ed ^ 1;
		}
		this->_418.y = this->_418.x;

	} else {
		this->_418.x += 0x80;
		if (0x1000 <= this->_418.x) {
			this->_418.x = 0x1000;
			this->_4ed = this->_4ed ^ 1;
		}
		this->_418.y = this->_418.x;
	}
}

void Coin::func_ov010_020d99a8()
{
	if (this->_4e8 == '\0') {
		return;
	}
	this->_4b0 = this->_4b0 + 0x10;
	if (0x40 <= (int)this->_4b0) {
		this->_4b0 = 0x40;
	}
	u8 uVar1 = this->_4ee;
	if (uVar1 == '\0') {
		this->_424.y = this->_424.y + this->_4b0;
		if (0x1200 <= this->_424.y) {
			this->_4ee = this->_4ee + 1 & 3;
			this->_4b0 = 0;
			return;
		}
		return;
	}
	if (uVar1 == '\x01') {
		this->_424.y = this->_424.y - this->_4b0;
		if (this->_424.y <= 0x1000) {
			this->_4ee = this->_4ee + 1 & 3;
			this->_4b0 = 0;
			return;
		}
		return;
	}
	if (uVar1 == '\x02') {
		this->_424.x = this->_424.x + this->_4b0;
		if (0x1200 <= this->_424.x) {
			this->_4ee = this->_4ee + 1 & 3;
			this->_4b0 = 0;
			return;
		}
		return;
	}
	this->_424.x = this->_424.x - this->_4b0;
	if (this->_424.x <= 0x1000) {
		this->_4ee = this->_4ee + 1 & 3;
		this->_4b0 = 0;
		return;
	}
	return;
}

bool Coin::func_ov010_020d9890()
{
}

bool Coin::func_ov010_020d9634()
{
}

bool Coin::func_ov010_020d93b4()
{
}

bool Coin::func_ov010_020d923c()
{
}

bool Coin::func_ov010_020d91f4()
{
	if (this->_4e4 == 0) {
		this->_4e4 += 1;
	} else if (this->_4e4 != ~0) {
		func_ov010_020d9c78();
		this->applyVelocity();
		this->func_ov010_020d9acc();
	}
	return true;
}

bool Coin::func_ov010_020d9004()
{
	// uint uVar1;
	// undefined4 *local_18;
	// int local_14;
	// int local_10;
	// i32 local_c;
	//
	// if (this->_4e4 == '\0') {
	//	this->_4e4 = '\x01';
	//	uVar1 = (uint) * (short *)(&data_02080304 + (((int)*(short *)(&data_ov010_02121634 + (uint)this->_4eb * 2) >> 4) * 2 + 1) * 2);
	//	(this->velocity).x = uVar1 * 0x800 + 0x800 >> 0xc | ((((int)uVar1 >> 0x1f) << 0xb | uVar1 >> 0x15) + (uint)(0xfffff7ff < uVar1 * 0x800)) * 0x100000;
	//	uVar1 = (uint) * (short *)(&data_02080304 + ((int)*(short *)(&data_ov010_02121634 + (uint)this->_4eb * 2) >> 4) * 4);
	//	(this->velocity).y = -(uVar1 * 0x800 + 0x800 >> 0xc | ((((int)uVar1 >> 0x1f) << 0xb | uVar1 >> 0x15) + (uint)(0xfffff7ff < uVar1 * 0x800)) * 0x100000);
	//	if (this->direction != '\0') {
	//		(this->velocity).x = -(this->velocity).x;
	//	}
	//	(this->_3f8).x = (this->position).x;
	//	(this->_3f8).y = (this->position).y;
	//	(this->_3f8).z = (this->position).z;
	//	(this->_3f8).x = (this->_3f8).x + -0x8000;
	//	(this->_3f8).y = (this->_3f8).y + 0x10000;
	//} else if (this->_4e4 != 0xff) {
	//	func_ov010_020d9c78();
	//	Actor::applyVelocity((Actor *)this);
	//	func_ov010_020d9acc(this);
	//	if (this->_4ea != '\0') {
	//		local_18 = &{vtable(Vec3_32)};
	//		local_c = (this->_3f8).z;
	//		if (this->direction == '\0') {
	//			local_14 = -*(int *)(&data_ov010_0212166c + (uint)this->_4ea * 4);
	//		} else {
	//			local_14 = *(int *)(&data_ov010_0212166c + (uint)this->_4ea * 4);
	//		}
	//		local_14 = (this->_3f8).x + local_14;
	//		local_10 = (this->_3f8).y + *(int *)(&data_ov010_02121678 + (uint)this->_4ea * 4);
	//		Actor::spawnActor(0x42, (this->_4ea - 1) * 0x100 | 1, &local_18, 0, 0, 0);
	//		this->_4ea = this->_4ea + 0xff;
	//	}
	//}
	// return true;
}

bool (Coin::*data_ov010_021293dc)();
bool Coin::func_ov010_020d8fb0()
{
	Base *pBVar1;

	if (this->_4e4 == 0) {
		this->_4e4 += 1;
	} else if ((this->_4e4 != ~0) && (pBVar1 = ProcessManager::getObjectByID(this->_3f4), pBVar1 == (Base *)0x0)) {
		this->func_ov010_020d9dcc(&data_ov010_021293dc);
	}
	return true;
}

bool Coin::func_ov010_020d8eec()
{
	if (this->_4e4 == 0) {
		this->_4e4 += 1;
		this->visible = true;
		this->_4ce = 0x20;
	} else if (this->_4e4 != ~0) {
		if (((this->_4a8) & 0x400000) != 0) {
			Base::destroy();
			return true;
		}
		this->applyVelocity();
		if (this->_4ce == 0) {
			this->_444.link();
			this->func_ov000_0209c820(0xfffffd00);
		} else {
			this->_4ce = this->_4ce - 1;
		}
		if (this->_4ce == 1) {
			this->_3be = 0x1;
			this->_3ea = 0;
		}
		this->func_ov010_020d9acc();
	}
	return true;
}

bool Coin::func_ov010_020d8d9c()
{
	if (this->_4e4 == 0) {
		this->_4e4 += 1;
		this->_4de = 0x1c;
		this->minVelocity.x = 0x1000;
		this->minVelocity.y = -0x8000;
		this->minVelocity.z = 0;
		this->accelV = -0x300;
		this->velocity.y = 0x3000;
		this->_4c0 = 9;
	} else if (this->_4e4 != ~0) {
		this->updateVerticalVelocity();
		this->func_ov000_0209c85c();
		if (this->_4f1 != 0) {
			this->_4f1 -= 1;
		}
		if (this->_4f1 == 0) {
			this->_4f0 = this->_4f0 + 1 & 3;
			this->_4f1 = 3;
		}
		if (this->_4de != 0) {
			this->_4de = this->_4de - 1;

		} else {
			func_02020354(this->_4e3);
			bool iVar1 = func_020202a0();
			if (iVar1 == 1) {
				this->func_ov000_0209ab90(0, 0, 0, this->_4e3);
			} else {
				i32 iVar1 = func_0202040c(this->_4e3);
				iVar1 = iVar1 + -1;
				if (iVar1 < 0) {
					iVar1 = 7;
				}
				StageEntity::func_ov000_0209aad0(&this->position, iVar1, this->_4e3);
			}
			this->func_ov000_0209e264(0, 0, 2);
			Base::destroy();
		}
	}
	return true;
}

i32 data_ov010_02121644[2];
i32 data_ov010_021216b4[2];
u32 data_ov010_02121684;
u32 data_ov010_02121690;
u32 data_ov010_0212169c;
bool Coin::func_ov010_020d8b9c()
{
	int iVar1;

	if (this->_4e4 == 0) {
		this->_4e4 += 1;
		this->minVelocity.x = 0x4000;
		this->minVelocity.y = -0x8000;
		this->minVelocity.z = 0;
		this->accelV = -0x280;
		this->velocity.x = data_ov010_02121644[this->direction];
		this->velocity.y = 0x3400;
		this->velocity.z = 0;
		this->collision_manager.func_ov000_020ab010(this, &data_ov010_02121684, &data_ov010_02121690, &data_ov010_0212169c, 0);
		this->_4dc = 0;
		this->_4e2 = 0;
		this->_4e0 = 6;
		this->_2c6 = this->_2c6 | 4;
	} else if (this->_4e4 != ~0) {
		iVar1 = this->func_ov010_020d9c78();
		if (iVar1 != 0) {
			return true;
		}
		this->updateVerticalVelocity();
		this->func_ov000_0209c85c();
		if (this->_4e2 == 0) {
			if (this->_4e0 != 0) {
				this->_4e0 = this->_4e0 - 1;
			}
			if (this->_4e0 == 0) {
				this->_4e2 = 1;
			}
		}
		if (this->_4e2 != 0) {
			iVar1 = this->updateBottomSensors();
			if (iVar1 != 0) {
				this->velocity.y = 0;
				if (this->_4dc < 3) {
					this->_4dc = this->_4dc + 1;
					if (this->_4dc == 1) {
						func_02012398(0x170, &this->position);
					}
					(this->velocity).y = data_ov010_021216b4[this->_4dc];
				} else {
					(this->velocity).x = 0;
				}
			}
			bool iVar1 = this->collision_manager.func_ov000_020aa990(0);
			if (iVar1 != 0) {
				this->velocity.y = -0x2000;
			}
			bool iVar2 = this->collision_manager.func_01ffe778(0, 0);
			if (iVar2 != 0) {
				this->velocity.x = -(this->velocity).x;
			}
			this->func_ov000_0209c820(0xfffffd80);
		}
		this->func_ov010_020d9b84();
	}
	return true;
}

void Coin::func_ov010_020d8b40()
{
	this->_4e8 = 1;
	this->_4ef = 1;
	this->_4ec = 1;
	this->_4ed = 0;
	this->_4b0 = 0;
	this->_418.x = 0x1000;
	this->_418.y = 0x1000;
	this->_424.x = 0x1000;
	this->_424.y = 0x1000;
	u32 uVar1 = WiFi::random();
	// TODO: Is this a typecast? Can we make the syntax better?
	this->_4ee = ((((uVar1 & 0x7fff) << 1) >> 0xf) << 1);
}

u8 data_ov000_020c4ec0[2];
u32 data_ov010_021216a8[3];
u32 data_ov010_02121660[3];
u32 data_ov010_02121654[3];
u32 data_ov010_021216ec[3];
i32 data_ov010_021216c4[3];
i32 data_ov010_0212164c[2];
u8 *data_ov000_020ca2ac;
Collider* data_ov010_02125204;
bool func_ov000_020af790(u32, u16, u16);
bool Coin::onCreate()
{
	this->_408 = this->position;
	this->position.x += 0x8000;
	this->position.y -= 0x10000;
	u32 settings = this->settings;
	this->_4c0 = settings & 0xf;
	this->direction = (settings >> 0x1c) & 0xf;
	this->_4c4 = 0;
	if (this->_4c0 == 0) {
		this->_4c4 = (settings >> 8) & 0xf;
	}
	this->_4eb = (settings >> 8) & 0xf;
	this->_4d0 = 0x1c2;
	this->_4d8 = 4;
	this->_4da = 0;
	this->_3ea = 0;
	this->_4ef = 0;
	this->_4e8 = 0;
	this->_4ea = 0;
	this->_4e3 = 0;
	this->_4ec = 0;
	this->_4e9 = 0;
	this->scale.x = 0x1200;
	this->scale.y = 0x1200;
	this->scale.z = 0x1200;
	this->_3b4 &= ~6;
	this->_444.init(this, &data_ov010_02125204, 0x20000, 0, 0);
	if (this->_4c4 != 0) {
		this->_4ad = data_ov000_020c4ec0[this->_4c4];
	} else {
		this->_4ad = 0;

	}
	this->func_ov000_0209c820(0xfffffd80);

	u32 _4c0 = this->_4c0;
	if (_4c0 == 0) {
		if ((settings >> 0x14 & 0xf) != 0) {
			this->position.y -= 0x8000;
		}
		if ((settings >> 0x18 & 0xf) != 0) {
			this->position.x += 0x8000;
		}
		if (this->_3be != 0) {
			this->_4ef = 1;
			this->_4ed = 0;
			this->_418.x = 0x1000;
			this->_418.y = 0x1000;
		}
		bool iVar2 = func_ov000_020af790(data_ov000_020cad40, this->_408.x >> 0xc, -(this->_408.y>>0xc));
		if (iVar2 != 0) {
			*data_ov000_020ca2ac |= 1;
			return false;
		} else {
			this->func_ov010_020d9dcc(&data_ov010_0212941c);
			return true;
		}
	} else {
		if (_4c0 == 8) {
			this->func_ov010_020d9dcc(&data_ov010_0212941c);
			this->func_ov010_020d8b40();
			this->_4e8 = 0;
		} else if (_4c0 == 1) {
			this->func_ov010_020d8b40();
			this->direction = this->func_ov000_0209acd4(&this->position);
			this->func_ov010_020d9dcc(&data_ov010_021293e4);
		} else if (_4c0 == 2) {
			this->func_ov010_020d8b40();
			this->direction = this->func_ov000_0209acd4(&this->position);
			this->_4eb = 2;
			this->_4ea = 2;
			this->func_ov010_020d9dcc(&data_ov010_021293e4);
		} else if (_4c0 == 4) {
			this->_4b4 = data_ov010_021216a8[settings >> 4 & 0xf];
			this->_4bc = data_ov010_02121660[settings >> 4 & 0xf];
			this->_4b8 = data_ov010_02121654[settings >> 4 & 0xf];
			this->func_ov010_020d9dcc(&data_ov010_0212940c);
		} else if (_4c0 == 6) {
			this->func_ov010_020d8b40();
			this->_4e8 = 0;
			this->velocity.x = data_ov010_0212164c[this->direction];
			this->velocity.y = 0;
			this->velocity.z = 0;
			this->func_ov010_020d9dcc(&data_ov010_021293fc);
		} else if (_4c0 == 7) {
			this->func_ov010_020d8b40();
			this->_4e8 = 0;
			this->velocity.x = data_ov010_021216ec[settings >> 4 & 0xf];
			this->velocity.y = data_ov010_021216c4[settings >> 4 & 0xf];
			this->visible = false;
			this->_3be = 0;
			this->_3ea = 1;
			this->func_ov010_020d9dcc(&data_ov010_021293ec);
		} else if (_4c0 == 9) {
			this->_4e3 = (settings >> 0xc) & 0xf;
			if (2 <= this->_4e3) {
				this->_4e3 = func_020205ec()->linked_player;
			}
			this->func_ov010_020d9dcc(&data_ov010_02129404);
			func_02012398(0x16c, &this->position);
			Coin::onRender();
		} else if (_4c0 == 10) {
			this->func_ov010_020d9dcc(&data_ov010_02129424);
			Coin::onRender();
		} else if (_4c0 == 0xb) {
			(this->position).y = (this->position).y + 0x11000;
			this->_4b4 = 0xFFF;
			this->_4bc = 0x1000;
			this->_4b8 = 0;
			this->func_ov010_020d9dcc(&data_ov010_02129414);
		} else {
			if (_4c0 == 5) {
				(this->position).y = (this->position).y + 0x11000;
			}
			this->_4b4 = 0x0FFF;
			this->_4bc = 0x1000;
			this->_4b8 = 0x0000;
			this->func_ov010_020d9dcc(&data_ov010_02129414);
		}
		if (this->_4c0 == 6) {
			this->_36c.x = 0xc0;
			this->_36c.y = 0x40;
			this->_378.x = 0xc0;
			this->_378.y = 0x40;
		} else if (this->_4c0 == 8) {
			this->_36c.x = 0x140;
			this->_36c.y = 0x40;
			this->_378.x = 0x140;
			this->_378.y = 0x40;
		} else {
			this->_36c.x = 0x80;
			this->_36c.y = 0x40;
			this->_378.x = 0x80;
			this->_378.y = 0x40;
		}
		this->_384.x = 0;
		this->_384.y = 8;
		return true;
	}
}

bool Coin::onDestroy()
{
	this->_444.unlink();
	return true;
}

void Coin::onStageComplete(PlayerActor *player)
{
	Vec3_32 vec;
	vec.x = this->position.x;
	vec.y = this->position.y;
	vec.z = this->position.z;
	player->func_ov000_0209ab90(0, 0, 0x18000, player->linked_player);
	func_02020354(player->linked_player);
	Nitro::Math_AddVec3_32s(&vec, &this->centerOffset, &vec);
	func_02012398(0x70, &vec);
	this->destroy(true);
}

void(func_ov000_020ab350)(Collider *);
void(func_ov010_020d9b40)(Coin *);
void(func_ov000_020ab2cc)(Collider *);
bool Coin::onUpdate_0()
{
	func_ov000_020ab350(&this->_444);
	this->func_ov010_020d9d84();
	if ((this->_4c0 - 1 <= 1) && (this->_01() == false)) {
		this->_3e4 = 1;
	}
	this->func_ov010_020d9b40();
	this->func_ov010_020d99a8();
	this->func_ov000_0209adb0(0);
	func_ov000_020ab2cc(&this->_444);
	return true;
}

void Coin::func_ov010_020d8488()
{
	drawSprite(data_ov011_0212f180[this->_4e9 + 0x15], this->position.x, this->position.y + 0x8000, 0, 0, 3, &this->_424, 0, 0, 0);
}

bool Coin::onRender()
{
	if (this->_4da != 0) {
		return true;
	}

	if (this->_4ef != 0) {
		if (this->_4e8 == 0) {
			u32 sprite_priority = this->getSpritePriority(0);
			drawSprite(data_ov011_0212f180[this->_4f0 + 0xf], this->position.x, this->position.y + 0x8000, sprite_priority, 0, 3, &this->_418, 0, 0, 0);
		} else {
			if (this->_4e9 != 0) {
				this->func_ov010_020d8488();
			}
			drawSprite(data_ov011_0212f180[this->_4f0 + 0xf], this->position.x, this->position.y + 0x8000, 0, 0, 3, (Vec2_32 *)NULL, 0, 0, 0);
			// drawSprite(*(int *)((this->_4f0 + 0xf) * 4 +
			// 0x212f180),(this->position).x,
			//(this->position).y + 0x8000,0,0,3,0,0,(undefined2
			//*)0x0,0);
			if (this->_4e9 == 0) {
				this->func_ov010_020d8488();
			}
		}
	} else {
		u8 b;
		if (this->_4c0 == 0) {
			b = data_ov010_02129438;
		} else {
			b = this->_4f0;
		}

		u32 sprite_priority = this->getSpritePriority(0);
		if ((this->_4c0 == 0) && (this->_4c4 != 0)) {
			sprite_priority = 0x20;
		}

		drawSprite(data_ov011_0212f180[b + 0xf], this->position.x, this->position.y + 0x8000, sprite_priority, 0, 3, (Vec2_32 *)NULL, 0, 0, 0);

		if (data_02085a98 == 1) {
			bool a = false;
			Vec3_32 d;
			d.x = this->position.x;
			d.y = this->position.y;
			d.z = this->position.z;
			if (d.x < 0x8000) {
				d.x += 0x100000;
				a = true;
			} else if (0xf8000 < d.x) {
				d.x -= 0x100000;
				a = true;
			}
			if (a) {
				drawSprite(data_ov011_0212f180[b + 0xf], d.x, d.y + 0x8000, sprite_priority, 0, 3, (Vec2_32 *)NULL, 0, 0, 2);
			}
		}
	}
	return true;
}
void Coin::_11()
{
}

void Coin::func_ov010_020d823c(u32 a)
{
	this->_3f4 = a;
}

u32 data_ov010_0212163c[2];
void Coin::func_ov010_020d81dc(u32 a)
{
	if ((BOOL)(this->_430 == &data_ov010_021293f4) == FALSE) {
		this->func_ov010_020d9dcc(&data_ov010_021293f4);
		this->velocity.x = data_ov010_0212163c[a];
		this->velocity.y = 0;
	}
}
