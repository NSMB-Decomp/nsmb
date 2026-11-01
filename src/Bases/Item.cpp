#include "Item.hpp"
#include "Player/PlayerBase.hpp"

extern const AcConfig data_ov010_02121564;
extern u8 data_ov010_021214fc[];
extern u8 data_ov010_02121508[];
extern u8 data_ov010_02121514[];
extern u8 data_ov010_02121520[];
extern u8 data_ov010_0212152c[];
extern u8 data_ov010_0212153c[];
extern const s32 data_ov010_021214c4[];
extern const s32 data_ov010_021214cc[];
extern const u8 data_ov010_02124020[];
extern u8 data_02085a08;
u8 func_ov000_020baa2c(u8);

s32 Item::onCreate()
{
	this->activeCollider.init(this, data_ov010_02121564, 0xff);
	this->_5c7 = 0;
	this->_5c6 = 0;
	this->_5c5 = 0;
	this->_5c4 = 0;
	this->_5c2 = 0;
	this->_5c9 = 0x20;
	this->_5c8 = 0;
	this->_5aa = 0;
	this->_5ac = 0;
	this->_5bc = 0;
	this->_59c = 0;
	this->_5b2 = 0;
	this->centerOffset.x = 0;
	this->centerOffset.y = 0x8000;
	this->centerOffset.z = 0;
	this->scale.x = 0x1000;
	this->scale.y = 0x1000;
	this->scale.z = 0x1000;
	this->_548.x = 0x1000;
	this->_548.y = 0x1000;
	this->_548.z = 0x1000;
	this->activeSize.x = 0x1a0;
	this->activeSize.y = 0x10;
	this->viewOffset.x = 0;
	this->viewOffset.y = 0x10;
	this->renderSize.x = 0x20;
	this->renderSize.y = 0x20;

	u32 settings = this->settings;
	if (this->object_id == 0x20) {
		if (READ_NIBBLE(settings, 1) >= 3) {
			this->func_ov010_020d1fd8();
		} else {
			this->func_ov010_020d2090();
		}
		return true;
	}

	u32 unk5a4 = (settings >> 5) & 3;
	this->_574 = this->settings & 0x1f;
	this->direction = this->settings >> 31;
	this->_584 = settings & 0x200;
	this->_588 = settings & 0x400;
	this->_58c = settings & 0x800;
	this->_57c = (settings >> 28) & 7;
	this->_594 = READ_NIBBLE(settings, 6);
	this->player_id = (settings >> 16) & 3;
	this->_5a4 = unk5a4;
	this->_580 = (settings >> 18) & 3;
	this->_590 = (settings >> 12) & 1;
	if (this->_590 != 0) {
		this->_5c9 = 0x10;
	}
	this->_5a0 = 0;
	this->_544 = 0;
	this->_5cc = -1;
	this->_5bf = 0;
	this->_5b0 = 0;
	this->_2c6 = 4;
	this->_59a = 0;
	this->_598 = 100;
	this->_5b8 = 0;
	this->_5c0 = 1;
	this->_5ca = 0;
	this->collisionType &= ~6;
	u32 flag80 = settings & 0x80;

	if (this->_574 == 10 || this->_574 == 0x12) {
		this->collisionMgr.func_ov000_020ab010(this, data_ov010_021214fc, data_ov010_02121508, data_ov010_0212152c, 0);
	} else {
		this->collisionMgr.func_ov000_020ab010(this, data_ov010_021214fc, data_ov010_02121514, data_ov010_0212152c, 0);
	}
	this->collisionMgr._64.x = this->position.x;

	u32 type = this->_574;
	if (type == 0) {
		s8 powerup = ((PlayerBase *)Game::getPlayer(this->player_id))->powerup;
		if (powerup == 1 || powerup == 5 || powerup == 2) {
			this->_5a0 = 1;
		}
	} else if (type == 1) {
		this->_5a0 = 2;
	} else if (type == 5) {
		this->_5a0 = 4;
	} else if (type == 0xb) {
		this->_5a0 = 8;
	} else if (type == 7) {
		this->_5a0 = 6;
	} else if (type == 10 || type == 0x12) {
		this->_5a0 = 7;
	} else if (type == 9) {
		this->_5a0 = 1;
	} else if (type == 0x19) {
		this->_5a0 = 0xd;
		this->centerOffset.x = 0x1000;
		this->centerOffset.y = 0x5000;
		this->centerOffset.z = 0;
		this->activeCollider.rect.x = 0x1000;
		this->activeCollider.rect.y = 0x5000;
		this->activeCollider.rect.halfWidth = 0x6000;
		this->activeCollider.rect.halfHeight = 0x5000;
	} else if (type == 2 || type == 4 || type == 0x13 || type == 0x14) {
		this->_5a0 = 3;
		this->position.y += 0x10000;
		this->_568 = this->position.y + 0x10000;
		this->func_ov010_020d4eb8(&Item::func_ov010_020d31ac);
		return true;
	}

	if (this->_5a0 == 0 || this->_5a0 == 6 || this->_5a0 == 0xd) {
		this->_5c3 = 0;
	}
	this->_5cb = func_ov000_020baa2c(this->_2be);

	type = this->_574;
	if (type == 0x12) {
		this->scale.x = 0x1000;
		this->scale.y = 0x1000;
		this->scale.z = 0x1000;
		this->_558.x = this->position.x;
		this->_558.y = this->position.y + 0x80000;
		this->_5b8 = 1;
		this->_580 = 2;
		this->func_ov010_020d4eb8(&Item::func_ov010_020d2e00);
		this->_5c9 = 0x20;
		this->_5cf = 0;
		this->actorCategory &= ~4;
		return true;
	}

	if (type == 10) {
		if (!this->prepareResourcesSafe(0x40, Memory_gameHeap)) {
			return false;
		}
		Ns_3dModelUseModelAmbient(this->model.model);
		Ns_3dModelUseModelEmission(this->model.model);
		this->scale.x = 0x1000;
		this->scale.y = 0x1000;
		this->scale.z = 0x1000;
		this->_558.x = this->position.x;
		this->_558.y = this->position.y + 0x8000;
		this->_5c8 = 1;
		this->func_ov010_020d4eb8(&Item::func_ov010_020d2e00);
		this->_5c9 = 0x20;
		if (flag80 != 0) {
			this->_5cd = 2;
			if (func_020202a0() == 1) {
				this->_5cf = 0;
			} else {
				this->_5cf = (settings & 0x100) >> 8;
			}
		}
		return true;
	}

	if (type == 5) {
		if (!this->prepareResourcesSafe(0x80, Memory_gameHeap)) {
			return false;
		}
		Ns_3dModelUseModelAmbient(this->model.model);
		Ns_3dModelUseModelEmission(this->model.model);
		data_02085a08 = 1;
		this->centerOffset.x = 0;
		this->centerOffset.y = 0xc000;
		this->centerOffset.z = 0;
		this->_5c8 = 1;
		this->_558.x = this->position.x;
		this->_558.y = this->position.y + 0x8000;
		this->position.y += 0x10000;
		this->position.z = 0xc0000;
		this->scale.x = 0x700;
		this->scale.y = 0x700;
		this->scale.z = 0x700;
		this->activeCollider.rect.x = 0;
		this->activeCollider.rect.y = 0x10000;
		this->activeCollider.rect.halfWidth = 0xe000;
		this->activeCollider.rect.halfHeight = 0x10000;
		this->activeSize.x = 0x1a0;
		this->activeSize.y = 0x10;
		this->viewOffset.x = 0;
		this->viewOffset.y = 0x20;
		this->renderSize.x = 0x40;
		this->renderSize.y = 0x40;
		this->collisionMgr.func_ov000_020ab010(this, data_ov010_021214fc, data_ov010_02121520, data_ov010_0212153c, 0);
		this->collisionMgr._64.x = this->position.x;
		if (unk5a4 == 3) {
			this->_5c2 = 1;
		}
		if (flag80 != 0) {
			this->modelAnm.init(1, 0, 0x1000, 0);
			this->position.y = -0x20000 - Game::cameraY[this->player_id];
			this->func_ov010_020d4eb8(&Item::func_ov010_020d3e88);
			this->_5c8 = 0;
		} else if (this->_594 == 1) {
			this->_57c = 3;
			this->func_ov010_020d43f4();
			this->_5c8 = 0;
			this->velocity.y = 0x4000;
			this->velocity.x = 0;
			return true;
		} else if (this->_57c == 3) {
			this->func_ov010_020d43f4();
			this->_5c8 = 0;
			this->velocity.y = 0x4000;
			this->velocity.x = data_ov010_021214c4[this->direction];
			return true;
		} else if (this->_57c == 5) {
			this->func_ov010_020d4eb8(&Item::func_ov010_020d3574);
			this->_5c8 = 0;
			this->velocity.y = 0x4000;
			this->velocity.x = data_ov010_021214c4[this->direction];
		} else if (this->_57c == 6) {
			this->func_ov010_020d4eb8(&Item::func_ov010_020d34cc);
			this->_5c8 = 0;
			this->velocity.y = -0x4000;
			this->velocity.x = data_ov010_021214c4[this->direction];
		} else {
			if (this->_590 != 0) {
				this->position.z = 0x40000;
				this->_5c8 = 0;
			}
			this->func_ov010_020d4eb8(&Item::func_ov010_020d361c);
		}
		return true;
	}

	if (this->_58c != 0) {
		this->_570 = this->position.x - data_ov000_020cae1c[this->player_id];
		this->func_ov010_020d4eb8(&Item::func_ov010_020d3e88);
		this->_5c9 = 0;
		return true;
	}
	if (this->_588 != 0) {
		this->func_ov010_020d4eb8(&Item::func_ov010_020d33c8);
		this->_5c9 = 0;
		this->collisionType = 1;
		this->_3e6 = 1;
		return true;
	}
	if (flag80 != 0) {
		this->position.y = -0x20000 - Game::cameraY[this->player_id];
		this->func_ov010_020d4eb8(&Item::func_ov010_020d3e88);
		this->_5c9 = 0;
		return true;
	}
	if (this->_594 == 1) {
		this->_57c = 3;
		this->func_ov010_020d43f4();
		if (this->_584 == 0) {
			this->velocity.y = 0x4000;
			this->velocity.x = 0;
		} else {
			this->velocity.y = 0;
			this->velocity.x = 0;
			this->_5a2 = 9;
		}
		return true;
	}

	u32 mode = this->_57c;
	if (mode == 1) {
		this->func_ov010_020d43f4();
		this->activeCollider.link();
		this->velocity.y = 0x3000;
		this->velocity.x = data_ov010_021214c4[this->direction];
		return true;
	}
	if (mode == 2) {
		this->_5c9 = 0x20;
		if (this->_5a0 == 0xd) {
			this->position.y += 0x4000;
		}
		if (unk5a4 == 3) {
			this->_5c2 = 1;
		}
		this->func_ov010_020d4eb8(&Item::func_ov010_020d2dc0);
		return true;
	}
	if (mode == 3) {
		this->func_ov010_020d43f4();
		if (this->_584 != 0) {
			this->velocity.y = 0;
			this->velocity.x = 0;
			this->_5a2 = 9;
		} else {
			this->velocity.y = 0x4000;
			this->velocity.x = data_ov010_021214c4[this->direction];
		}
		return true;
	}
	if (mode == 4) {
		this->func_ov010_020d43f4();
		this->activeCollider.link();
		this->velocity.y = 0x3a00;
		this->velocity.x = data_ov010_021214cc[this->direction];
		this->_5aa = 6;
		this->_5ac = 1;
		return true;
	}
	if (mode == 5) {
		this->func_ov010_020d4eb8(&Item::func_ov010_020d3574);
		this->velocity.y = 0x4000;
		this->velocity.x = data_ov010_021214c4[this->direction];
		return true;
	}
	if (mode == 6) {
		this->func_ov010_020d4eb8(&Item::func_ov010_020d34cc);
		this->velocity.y = -0x4000;
		this->velocity.x = data_ov010_021214c4[this->direction];
		return true;
	}

	if (data_ov010_02124020[type] != 0 && this->_580 == 3) {
		unk5a4 = 3;
	}
	if (unk5a4 == 3) {
		this->_568 = this->position.y - 0x10000;
		this->velocity.y = -0x500;
		this->_5c2 = 1;
		if (this->_5a0 == 0xd) {
			this->_568 = this->position.y - 0xc000;
		}
		this->func_ov010_020d4eb8(&Item::func_ov010_020d4340);
		return true;
	}
	this->_568 = this->position.y + 0x10000;
	this->velocity.y = 0x500;
	if (this->_5a0 == 0xd) {
		this->position.y += 0x4000;
	}
	this->func_ov010_020d4eb8(&Item::func_ov010_020d438c);
	return true;
}
s32 Item::onDestroy() {
}

Item *Item::create()
{
	return new Item();
}

ToadItem *ToadItem::create()
{
	return new ToadItem();
}
