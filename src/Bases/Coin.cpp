#include "Coin.hpp"

void (Coin::*data_ov010_021293e4)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_021293ec)() = Coin::func_ov010_020d9890;
i32 (Coin::*data_ov010_021293f4)() = Coin::func_ov010_020d923c;
void (Coin::*data_ov010_021293fc)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_02129404)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_0212940c)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_02129414)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_0212941c)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_02129424)() = Coin::func_ov010_020d9890;
void (Coin::*data_ov010_0212942c)() = Coin::func_ov010_020d9890;

Coin::Coin()
{
}

void *Coin::create()
{
	return new Coin();
}

void Coin::_21()
{
}

void(func_ov000_020ab350)(Collider *);
void(func_ov010_020d9d84)(Coin *);
void(func_ov010_020d9b40)(Coin *);
void(func_ov000_020ab2cc)(Collider *);
bool Coin::onUpdate_0()
{
	func_ov000_020ab350(&this->_444);
	func_ov010_020d9d84(this);
	if ((this->_4c0 - 1 <= 1) && (this->_01() == false)) {
		this->_3e4 = 1;
	}
	func_ov010_020d9b40(this);
	this->func_ov010_020d99a8();
	this->func_ov000_0209adb0(0);
	func_ov000_020ab2cc(&this->_444);
	return true;
}

void Coin::_11()
{
}

void Coin::onStageComplete(PlayerActor *player)
{
	Vec3_32 vec = this->position;
	// StageEntity::func_ov000_0209ab90((StageEntity
	// *)this,0,0,0x18000,(int)player->linked_player);
	func_02020354(player->linked_player);
	// Nitro::Math_AddVec3_32s((Vec3_32 *)&vec.x,(Vec3_32
	// *)&(this->centerOffset).x,(Vec3_32 *)&vec.x);
	// func_02012398(0x70,&vec);
	this->destroy(1);
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

void Coin::func_ov010_020d8488()
{
	drawSprite(data_ov011_0212f180[this->_4e9 + 0x15], this->position.x, this->position.y + 0x8000, 0, 0, 3, &this->_424, 0, 0, 0);
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

u8 data_ov000_020c4ec0[2];
void *data_ov010_02125204;
bool Coin::onCreate()
{
	this->_408 = this->position;
	this->position.x += 0x8000;
	this->position.y -= 0x10000;
	this->_4c0 = this->settings & 0xf;
	this->direction = this->settings >> 0x1c;
	this->_4c4 = 0;
	if (this->_4c0 == 0) {
		this->_4c0 = this->settings >> 8 & 0xf;
	}
	this->_4eb = (this->settings >> 8) & 0xf;
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
	this->_3b4 &= 0xfffffff9;
	Collider *c = &this->_444;
	c->init((Base *)this, data_ov010_02125204, 0x20000, 0, 0);
	if (this->_4c4 == 0) {
		this->_4ad = 0;
	} else {
		this->_4ad = data_ov000_020c4ec0[this->_4c4];
	}
	this->func_ov000_0209c820(0xfffffd80);

	u32 _4c0 = this->_4c0;
	if (_4c0 != 0) {}
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

void Coin::func_ov010_020d823c(u32 a)
{
	this->_3f4 = a;
}

bool Coin::onDestroy()
{
	this->_444.unlink();
	return true;
}

Coin::~Coin()
{
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
		(this->minVelocity).x = 0x4000;
		(this->minVelocity).y = -0x8000;
		(this->minVelocity).z = 0;
		this->accelV = -0x280;
		(this->velocity).x = data_ov010_02121644[this->direction];
		(this->velocity).y = 0x3400;
		(this->velocity).z = 0;
		this->collision_manager.func_ov000_020ab010(this, &data_ov010_02121684, &data_ov010_02121690, &data_ov010_0212169c, 0);
		// func_ov000_020ab010(&this->collision_manager, this, &data_ov010_02121684, &data_ov010_02121690, &data_ov010_0212169c, 0);
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
				(this->velocity).y = 0;
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
				(this->velocity).y = -0x2000;
			}
			bool iVar2 = this->collision_manager.func_01ffe778(0, 0);
			if (iVar2 != 0) {
				(this->velocity).x = -(this->velocity).x;
			}
			this->func_ov000_0209c820(0xfffffd80);
		}
		this->func_ov010_020d9b84();
	}
	return true;
}