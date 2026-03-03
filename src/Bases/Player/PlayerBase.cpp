#include "PlayerBase.hpp"
#include "../StageEntity.hpp"

struct UNKNOWN {
	u16 _0;
	u8 _pad[18];
	u16 _1;
	u8 _pad1[2];
};

UNKNOWN data_020876b2[2];
u8 data_02085a0c;
u16 data_02087660[2];
u16 data_02087664[2];

void PlayerBase::func_ov011_0212c950()
{
	this->_7a0 = data_02087660[this->linked_player];
	this->_7a2 = data_02087664[this->linked_player];
}

void PlayerBase::func_ov011_0212c93c()
{
	this->_7a0 = 0;
	this->_7a2 = 0;
}

void PlayerBase::func_ov011_0212c91c()
{
	this->_7a0 &= ~0x30;
	this->_7a2 &= ~0x30;
}

u32 PlayerBase::func_ov011_0212c90c()
{
	return this->_7a0 & 0xf0;
}
u32 PlayerBase::func_ov011_0212c8fc()
{
	return this->_7a2 & 0xf0;
}

u32 PlayerBase::func_ov011_0212c8ec()
{
	return this->_7a0 & 0x40;
}

u32 PlayerBase::func_ov011_0212c8dc()
{
	return this->_7a0 & 0x80;
}

u32 PlayerBase::func_ov011_0212c8cc()
{
	return this->_7a0 & 0x20;
}

u32 PlayerBase::func_ov011_0212c8bc()
{
	return this->_7a0 & 0x10;
}

u32 PlayerBase::func_ov011_0212c8ac()
{
	return this->_7a2 & 0x80;
}

u32 PlayerBase::func_ov011_0212c880()
{
	return this->_7a2 & data_020876b2[this->linked_player]._1;
}

u32 PlayerBase::func_ov011_0212c854()
{
	return this->_7a0 & data_020876b2[this->linked_player]._1;
}

u32 PlayerBase::func_ov011_0212c828()
{
	return this->_7a2 & data_020876b2[this->linked_player]._0;
}

u32 PlayerBase::func_ov011_0212c7fc()
{
	return this->_7a0 & data_020876b2[this->linked_player]._0;
}

u32 PlayerBase::func_ov011_0212c7d0()
{
	return this->_7a2 & data_020876b2[this->linked_player]._1;
}

u32 PlayerBase::func_ov011_0212c7a4()
{
	return this->_7a0 & data_020876b2[this->linked_player]._1;
}

u32 PlayerBase::func_ov011_0212c78c()
{
	if ((this->_7a0 & 0xb0) != 0) {
		return 0;
	} else {
		return this->_7a0 & 0x40;
	}
}

u32 PlayerBase::func_ov011_0212c774()
{
	if ((this->_7a0 & 0x70) != 0) {
		return 0;
	} else {
		return this->_7a0 & 0x80;
	}
}

u32 PlayerBase::func_ov011_0212c768()
{
	return this->func_ov011_0212c7a4();
}

u32 PlayerBase::func_ov011_0212c75c()
{
	return this->func_ov011_0212c7d0();
}

u32 PlayerBase::func_ov011_0212c720()
{
	if ((u32)1 >= (data_02085a0c + 0xff & 0xff)) {
		return this->func_ov011_0212c854();
	}
	return this->func_ov011_0212c7a4();
}

u32 PlayerBase::func_ov011_0212c6e4()
{
	if ((u32)1 >= (data_02085a0c + 0xff & 0xff)) {
		return this->func_ov011_0212c880();
	}
	return this->func_ov011_0212c7d0();
}

u32 PlayerBase::func_ov011_0212c6b0()
{
	if (data_02085a0c == 0x2) {
		return this->func_ov011_0212c854();
	}
	return this->func_ov011_0212c7a4();
}

u32 PlayerBase::func_ov011_0212c67c()
{
	if (data_02085a0c == 0x2) {
		return this->func_ov011_0212c880();
	}
	return this->func_ov011_0212c7d0();
}

u32 PlayerBase::func_ov011_0212c648()
{
	if (data_02085a0c == 0x2) {
		return this->func_ov011_0212c880();
	}
	return this->func_ov011_0212c7d0();
}

u32 PlayerBase::func_ov011_0212c63c()
{
	return this->func_ov011_0212c828();
}

u32 PlayerBase::func_ov011_0212c630()
{
	return this->func_ov011_0212c7fc();
}

u32 PlayerBase::func_ov011_0212c61c()
{
	return (this->_7a0 & 0x30) >> 4;
}

u32 PlayerBase::func_ov011_0212c610()
{
	return this->func_ov011_0212c8dc();
}

u32 PlayerBase::func_ov011_0212c5ec()
{
	if ((this->func_ov011_0212c90c() & 0x70)) {
		return false;
	}
	return this->func_ov011_0212c8dc();
}

u32 PlayerBase::func_ov011_0212c5c8()
{
	if ((this->func_ov011_0212c90c() & 0x70)) {
		return false;
	}
	return this->func_ov011_0212c8dc();
}

u32 PlayerBase::func_ov011_0212c5bc()
{
	return this->func_ov011_0212c8cc();
}

u32 PlayerBase::func_ov011_0212c5b0()
{
	return this->func_ov011_0212c8cc();
}

u32 PlayerBase::func_ov011_0212c5a4()
{
	return this->func_ov011_0212c8cc();
}

u32 PlayerBase::func_ov011_0212c598()
{
	return this->func_ov011_0212c8cc();
}

void PlayerBase::func_ov011_0212c56c()
{
}

u32 PlayerBase::func_ov011_0212c52c()
{
}

bool PlayerBase::func_ov011_0212c4ec()
{
}

PlayerBase::PlayerBase()
{
	this->actorType = 1;
	this->actorCategory = (1 << this->actorType) | 0x80;
	this->_7aa = (this->settings & 0xf0) >> 4;
	this->_7b0 = 0;
	i8 a = this->settings & 0xf;
	this->linkPlayer(a);
	this->_7b4 = a;
	this->collision_manager._25e = a;
	this->_7a8 = 0;
}

PlayerBase::~PlayerBase()
{
}

u32 PlayerBase::func_ov011_0212c27c(u32)
{
}
void PlayerBase::func_ov011_0212c200()
{
}
void PlayerBase::func_ov011_0212c1b8()
{
}
void PlayerBase::func_ov011_0212c170(u32 a)
{
}
void PlayerBase::func_ov011_0212c130()
{
}
void PlayerBase::func_ov011_0212c110(u32 a)
{
}
bool PlayerBase::virt_20()
{
	return false;
}
bool PlayerBase::virt_21()
{
	return false;
}
bool PlayerBase::virt_22()
{
	return false;
}
bool PlayerBase::virt_23()
{
	return false;
}
bool PlayerBase::virt_24()
{
	return false;
}
bool PlayerBase::virt_25(void *a, u32 b, u32 c, u32 d)
{
	return false;
}
bool PlayerBase::virt_26()
{
	return false;
}
bool PlayerBase::virt_27()
{
	return false;
}
bool PlayerBase::virt_28()
{
	return false;
}
bool PlayerBase::virt_29()
{
	return false;
}
bool PlayerBase::virt_30()
{
	return false;
}
bool PlayerBase::virt_31()
{
	return false;
}
bool PlayerBase::virt_32()
{
	return false;
}
bool PlayerBase::virt_33()
{
	return false;
}
bool PlayerBase::virt_34()
{
	return false;
}
bool PlayerBase::virt_35()
{
	return false;
}
bool PlayerBase::virt_36()
{
	return false;
}
bool PlayerBase::virt_37()
{
	return false;
}
bool PlayerBase::virt_38()
{
	return false;
}
bool PlayerBase::virt_39()
{
	return false;
}
bool PlayerBase::virt_40()
{
	return false;
}
bool PlayerBase::virt_41()
{
	return false;
}
bool PlayerBase::virt_42()
{
}
bool PlayerBase::virt_43()
{
}
bool PlayerBase::virt_44()
{
	return false;
}
bool PlayerBase::virt_45()
{
	return false;
}
bool PlayerBase::virt_46()
{
	return true;
}
bool PlayerBase::virt_47()
{
}
u32 PlayerBase::virt_48()
{
	return ~0;
}
u32 PlayerBase::virt_49()
{
	return ~0;
}
bool PlayerBase::virt_50()
{
}
bool PlayerBase::virt_51()
{
}

Vec3_32 PlayerBase::func_ov011_0212bff0()
{
	Vec3_32 result;

	return result;
}

void PlayerBase::func_ov011_0212bfec()
{
}

void PlayerBase::func_ov011_0212bfe8()
{
}

void PlayerBase::func_ov011_0212bfe4()
{
}

bool PlayerBase::func_ov011_0212bfdc()
{
	return false;
}

bool PlayerBase::func_ov011_0212bfd4()
{
	return false;
}

bool PlayerBase::func_ov011_0212bfcc()
{
	return false;
}

bool PlayerBase::func_ov011_0212bfc4()
{
	return false;
}

void PlayerBase::func_ov011_0212bfc0()
{
}

void PlayerBase::func_ov011_0212bfbc()
{
}

void PlayerBase::func_ov011_0212bfb8()
{
}

bool PlayerBase::func_ov011_0212bfb0()
{
	return false;
}

bool PlayerBase::func_ov011_0212bf6c()
{
	// TODO: Is this possible without goto?
	switch (this->_7a9) {
	case 0:
	case 1:
	case 2:
		break;
	case 3:
	case 4:
	case 5:
		goto LAB_arm9_ov011__0212bfa8;
	case 6:
		break;
	default:
		goto LAB_arm9_ov011__0212bfa8;
	}
	if (this->_7b0 == 0) {
		return true;
	}
LAB_arm9_ov011__0212bfa8:
	return false;
}

bool PlayerBase::func_ov011_0212bf64()
{
	return false;
}

void PlayerBase::func_ov011_0212bf60()
{
}

bool PlayerBase::func_ov011_0212bf58()
{
	return false;
}

bool PlayerBase::func_ov011_0212bf50()
{
	return false;
}

Vec3_32 PlayerBase::func_ov011_0212bf28()
{
	Vec3_32 result;
	result = this->position;
	return result;
}

void PlayerBase::func_ov011_0212bf24()
{
}

void func_02022b64(u32, Vec3_32 *);
void PlayerBase::func_ov011_0212bf00()
{
	func_02022b64(0xaa, &this->position);
	func_02022b64(0xab, &this->position);
}

bool PlayerBase::func_ov011_0212beb8()
{
	u32 iVar1 = this->virt_20();
	if (iVar1 != 0) {
		this->_77c |= 0x40000;
	}
	return iVar1 != 0;
}

bool PlayerBase::func_ov011_0212be70()
{
	u32 iVar1 = this->virt_20();
	if (iVar1 != 0) {
		this->_77c |= 0x40000;
	}
	return iVar1 != 0;
}

bool PlayerBase::func_ov011_0212be28()
{
	bool iVar1 = this->virt_20();
	if (iVar1) {
		this->_778 |= 0x80000;
	}
	return iVar1;
}

bool PlayerBase::func_ov011_0212bde0(Actor *a)
{
	this->_77c = this->_77c & ~0x1;
	if ((BOOL)(this->linkedActor == a) == FALSE) {
		return false;
	}
	this->func_ov011_0212b26c(0);
	return true;
}

u32 PlayerBase::func_ov011_0212bdb8(u32 a)
{
}

bool PlayerBase::func_ov011_0212bd68(i32 x, i32 y, i32 z)
{
	Vec3_32s uStack_c;
	if (x < 0) {
		z = this->_778 | 0x40000;
		y = 0xffff1000;
		this->_778 = z;
		if (x < -0xf000) {
			x = y;
		}
	} else if (0 < x) {
		y = this->_778 | 0x20000;
		this->_778 = y;
		if (0xf000 < x) {
			x = 0xf000;
		}
	}
	uStack_c.x = x;
	uStack_c.y = x;
	uStack_c.z = x;
	return this->func_ov011_0212bca4(uStack_c);
}

bool PlayerBase::func_ov011_0212bca4(Vec3_32s a)
{
	if ((BOOL)(this->_7a9 == 2) == FALSE) {
		if (a.x < 0) {
			if ((this->_788 & 0x400) == 0) {
				this->position.x += a.x;
				this->collision_manager.func_01ffe778(&a, 0);
				return true;
			}
		} else if ((0 < a.x) && ((this->_788 & 0x800) == 0)) {
			this->position.x += a.x;
			this->collision_manager.func_01ffe778(&a, 0);
			return true;
		}
	}
	return false;
}

bool PlayerBase::func_ov011_0212bc50(i32 a)
{
	if ((a < 0)) {
		if ((this->_788 & 1) == 0) {
			this->position.y += a;
			return true;
		}
	} else if (0 < a) {
		if ((this->_788 & 2) == 0) {
			this->position.y += a;
			return true;
		}
	}
	return false;
}

Vec3_32 PlayerBase::func_ov011_0212bbdc()
{
	Vec3_32 result;
	Vec3_32s *_574 = &this->_574;
	result.x = _574->x;
	result.y = _574->y;
	result.z = _574->z;

	i32 uVar1 = this->_758 >> 0x1f;
	result.y += (uVar1 + 0x800) >> 0xc | ((this->_758 >> 0x11) + (0x800 < uVar1)) * 0x100000;
	return result;
}

void PlayerBase::func_ov011_0212bbcc()
{
	this->_780 &= ~0x200;
}

u32 PlayerBase::getShellStatus()
{
	u32 result;

	if ((this->_778 & 0x400000) != 0) {
		if (this->minVelH != 0) {
			return 2;
		} else {
			return 1;
		}
	}
	return 0;
}

bool PlayerBase::func_ov011_0212bb90()
{
	return this->_7bf == TRUE;
}

#define POWERUP_SMALL 0
#define POWERUP_SUPER 1
#define POWERUP_FIRE 2
#define POWERUP_MEGA 3
#define POWERUP_MINI 4
#define POWERUP_SHELL 5
#define POWERUP_6 6
#define POWERUP_7 7
u16 data_0208b344[2];
void func_02020150(u32, u32);
void func_02020128(u32);
void PlayerBase::func_ov011_0212bac8()
{
	i32 powerup = this->powerup;
	if (powerup != POWERUP_MEGA) {
		if (powerup != POWERUP_MINI) {
			func_02020150(this->linked_player, 0x348);
			data_0208b344[this->linked_player] = 0;
			func_02020128(this->linked_player);
		} else {
			func_02020150(this->linked_player, 0);
			data_0208b344[this->linked_player] = 0x168;
			this->func_ov011_0212b838(0x167, &this->position);
		}
	} else {
		func_02020150(this->linked_player, 0);
		data_0208b344[this->linked_player] = 0;
	}
}

bool PlayerBase::checkAndApplyPowerup(u8 new_powerup)
{
	bool bVar2;

	i8 current_powerup = this->powerup;
	if (current_powerup == POWERUP_MEGA) {
		return false;
	}
	switch (new_powerup) {
	case 3:
		return this->applyPowerup(new_powerup);
	case 2:
		if (((current_powerup == 0) || (current_powerup == 1)) || (current_powerup == 4)) {
			return this->applyPowerup(new_powerup);
		}
		break;
	case 5:
		if (current_powerup != 5) {
			return this->applyPowerup(new_powerup);
		}
		break;
	case 4:
		if (current_powerup != 4) {
			return this->applyPowerup(new_powerup);
		}
		break;
	case 1:
		if ((current_powerup == 0) || (current_powerup == 4)) {
			return this->applyPowerup(new_powerup);
		}
		break;
	case 0:
	default:
		return this->applyPowerup(new_powerup);
	}
	return false;
}

bool PlayerBase::applyPowerup(u8 new_powerup)
{
	if (BOOL(this->_7a9 == 0x5) != FALSE) {
		return false;
	}
	if (this->runtimePowerup == new_powerup) {
		return false;
	}
	this->runtimePowerup = new_powerup;
	return this->powerup != this->runtimePowerup;
}

void PlayerBase::func_ov011_0212b9a8()
{
}

void PlayerBase::func_ov011_0212b998()
{
	this->_780 |= 0x20;
}

void PlayerBase::func_ov011_0212b984()
{
	if ((this->_780 & 0x20) != 0) {
		this->_780 &= 0xffffffdf;
	}
}

void func_ov011_0212cfe4(void *);
void PlayerBase::func_ov011_0212b954()
{
	if ((this->_780 & 0x40) != 0) {
		this->_780 &= 0xffffffbf;
		func_ov011_0212cfe4(&this->_000._2c4);
	}
}

u8 data_ov000_020ca880;
u8 data_ov000_020ca898;
void PlayerBase::func_ov011_0212b908()
{
	data_ov000_020ca880 |= 0x10;
	data_ov000_020ca898 |= 0x40;
	this->_7b0 = 1;
	this->active_collider._1c6 |= 1;
}

void PlayerBase::func_ov011_0212b8bc()
{
	data_ov000_020ca880 &= ~0x10;
	data_ov000_020ca898 &= ~0x40;
	this->_7b0 = 0;
	this->active_collider._1c6 &= ~1;
}

u16 data_0208b350[2];
void PlayerBase::func_ov011_0212b878(u16 a)
{
	if (this->powerup == 3) {
		return;
	}
	data_0208b350[this->linked_player] = a;
	this->func_ov011_0212b740(2);
	this->func_ov011_0212b998();
}

void func_02012314(u32, u32);
void PlayerBase::func_ov011_0212b864(u32 a, u32 b)
{
	func_02012314(a, b);
}

void func_020122d0(u32, u32, u32);
void PlayerBase::func_ov011_0212b84c(u32 a, u32 b, u32 c)
{
	func_020122d0(a, b, c);
}

void func_02012290(u32, Vec3_32 *);
void PlayerBase::func_ov011_0212b838(u32 a, Vec3_32 *b)
{
	func_02012290(a, b);
}

void func_0201224c(u32, u32, u32);
void PlayerBase::func_ov011_0212b820(u32 a, u32 b, u32 c)
{
	func_0201224c(a, b, c);
}

void func_020121e4(u32);
void PlayerBase::func_ov011_0212b810(u32 a)
{
	func_020121e4(a);
}

void func_0204e87c(u32, u32);
void func_02011e3c(u32);
void PlayerBase::func_ov011_0212b7f0(u32 a)
{
	func_0204e87c(a, 0x1e);
	func_02011e3c(a);
}

u32 data_02085a7c;
void PlayerBase::func_ov011_0212b7bc(u32 a)
{
	if (this->linked_player == data_02085a7c) {
		this->func_ov011_0212b7f0(a);
	}
}

u32 data_02085a84;
void func_02011dc4(u32);
void PlayerBase::func_ov011_0212b740(u32 a)
{
	if (this->linked_player != data_02085a7c) {
		return;
	}
	if (BOOL(data_02085a84 != 0) != FALSE && (a == 3)) {
		return;
	}
	this->_77c = this->_77c | 0x800000;
	func_02011dc4(a);
	this->_798 = a;
}

void func_02011d94(u32);
void PlayerBase::func_ov011_0212b710()
{
	if ((this->_77c & 0x800000) != 0) {
		this->_77c &= 0xff7fffff;
		func_02011d94(this->_798);
	}
}

void PlayerBase::func_ov011_0212b384(i16)
{
	Vec3_16 rotation = this->rotation;
	Vec3_32 position = this->position;
	// switch (this->_7b2) {
	//	case 0:
	//		break;
	//	case 1:
	//
	// }
}

u8 func_020204e0(i8);
void func_0202048c(i8);
u8 data_02089508[2];
void func_ov000_020a189c(u32);
void func_ov000_020a183c(u32, u32);
void func_02012d6c(u32);

bool PlayerBase::func_ov011_0212b2bc()
{
	if (this->_7b3 == 0) {
		i8 linked_player = this->linked_player;
		u8 b = func_020204e0(linked_player);
		this->_7b3 = 1;
		func_0202048c(linked_player);
		if (data_02088f34 == 0) {
			data_02089508[this->linked_player] = 2;
		}

		if (BOOL(data_02085a84 != 0) != FALSE) {
			if (b != 0) {
				return true;
			}
		} else {
			if (b != 0) {
				func_ov000_020a189c(0);
			} else {
				func_02012d6c(*(u32 *)((u32)&data_02088bdc + 0x34c));
				func_ov000_020a183c(0xe, 0);
			}
		}
	}
	return false;
}

void PlayerBase::func_ov011_0212b26c(Actor *a)
{
	this->linkedActor = a;
	Actor *linkedActor = this->linkedActor;
	if (linkedActor == NULL) {
		return;
	}
	if ((BOOL)(linkedActor->actorType == 1) == FALSE) {
		linkedActor->linkPlayer(this->linked_player);
	}
}

void PlayerBase::setPosition(Vec3_32 *newPos)
{
	this->position.x = newPos->x;
	this->position.y = newPos->y;
}

i32 PlayerBase::func_ov011_0212b210(i32 gravity)
{
	if (this->powerup == POWERUP_MINI) {
		return ((i64)gravity * 0xD00 + 0x800) >> 12;
	}
	return gravity;
}

u8 PlayerBase::func_ov011_0212b1d4()

{
	int scale = this->scale.y;
	if (scale < 0xacc) {
		i32 a = 0;
		return a;
	}

	if (0x1599 > scale) {
		return 1;
	}

	if (scale < 0x2000) {
		return 2;
	}
	return 3;
}
