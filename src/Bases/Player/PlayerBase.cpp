#include "PlayerBase.hpp"

PlayerBase::PlayerBase() {}

PlayerBase::~PlayerBase() {}

u32 PlayerBase::func_ov011_0212c27c(u32) {}
void PlayerBase::func_ov011_0212c200() {}
void PlayerBase::func_ov011_0212c1b8() {}
void PlayerBase::func_ov011_0212c170(u32 a) {}
void PlayerBase::func_ov011_0212c130() {}
void PlayerBase::func_ov011_0212c110(u32 a) {}
bool PlayerBase::virt_20() { return false; }
bool PlayerBase::virt_21() { return false; }
bool PlayerBase::virt_22() { return false; }
bool PlayerBase::virt_23() { return false; }
bool PlayerBase::virt_24() { return false; }
bool PlayerBase::virt_25() { return false; }
bool PlayerBase::virt_26() { return false; }
bool PlayerBase::virt_27() { return false; }
bool PlayerBase::virt_28() { return false; }
bool PlayerBase::virt_29() { return false; }
bool PlayerBase::virt_30() { return false; }
bool PlayerBase::virt_31() { return false; }
bool PlayerBase::virt_32() { return false; }
bool PlayerBase::virt_33() { return false; }
bool PlayerBase::virt_34() { return false; }
bool PlayerBase::virt_35() { return false; }
bool PlayerBase::virt_36() { return false; }
bool PlayerBase::virt_37() { return false; }
bool PlayerBase::virt_38() { return false; }
bool PlayerBase::virt_39() { return false; }
bool PlayerBase::virt_40() { return false; }
bool PlayerBase::virt_41() { return false; }
bool PlayerBase::virt_42() {}
bool PlayerBase::virt_43() {}
bool PlayerBase::virt_44() { return false; }
bool PlayerBase::virt_45() { return false; }
bool PlayerBase::virt_46() { return true; }
bool PlayerBase::virt_47() {}
u32 PlayerBase::virt_48() { return ~0; }
u32 PlayerBase::virt_49() { return ~0; }
bool PlayerBase::virt_50() {}
bool PlayerBase::virt_51() {}

Vec3_32 PlayerBase::func_ov011_0212bff0()
{
	Vec3_32 result;

	return result;
}

void PlayerBase::func_ov011_0212bfec() {}

void PlayerBase::func_ov011_0212bfe8() {}

void PlayerBase::func_ov011_0212bfe4() {}

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

void PlayerBase::func_ov011_0212bfc0() {}

void PlayerBase::func_ov011_0212bfbc() {}

void PlayerBase::func_ov011_0212bfb8() {}

bool PlayerBase::func_ov011_0212bfb0()
{
	return false;
}

bool PlayerBase::func_ov011_0212bf6c()
{
	switch (this->_7a9)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
	case 4:
	case 5:
		return false;
	case 6:
		break;
	default:
		goto LAB_arm9_ov011__0212bfa8;
	}
	if (this->_7b0 == 0)
	{
		return true;
	}
LAB_arm9_ov011__0212bfa8:
	return false;
}

bool PlayerBase::func_ov011_0212bf64()
{
	return false;
}

void PlayerBase::func_ov011_0212bf60() {}

bool PlayerBase::func_ov011_0212bf58()
{
	return false;
}

bool PlayerBase::func_ov011_0212bf50()
{
	return false;
}

void PlayerBase::func_ov011_0212bf28() {}

void PlayerBase::func_ov011_0212bf24() {}

void func_02022b64(u32, Vec3_32 *);
void PlayerBase::func_ov011_0212bf00()
{
	func_02022b64(0xaa, &this->position);
	func_02022b64(0xab, &this->position);
}

bool PlayerBase::func_ov011_0212beb8()
{
	u32 iVar1 = this->virt_20();
	if (iVar1 != 0)
	{
		this->_77c |= 0x40000;
	}
	return iVar1 != 0;
}

bool PlayerBase::func_ov011_0212be70()
{
	u32 iVar1 = this->virt_20();
	if (iVar1 != 0)
	{
		this->_77c |= 0x40000;
	}
	return iVar1 != 0;
}

bool PlayerBase::func_ov011_0212be28()
{
	bool iVar1 = this->virt_20();
	if (iVar1)
	{
		this->_778 |= 0x80000;
	}
	return iVar1;
}

bool PlayerBase::func_ov011_0212bde0(Actor *a)
{
	this->_77c = this->_77c & ~0x1;
	if ((BOOL)(this->linkedActor == a) == FALSE)
	{
		return false;
	}
	this->func_ov011_0212b26c(0);
	return true;
}

u32 PlayerBase::func_ov011_0212bdb8(u32 a)
{
}

u32 PlayerBase::func_ov011_0212bd68(u32 a, u32 b, u32 c)
{
}

u32 PlayerBase::func_ov011_0212bca4()
{
}

bool PlayerBase::func_ov011_0212bc50(i32 a)
{
	if (a < 0)
	{
		if (this->_788 == 0)
		{
			this->position.y += a;
			return true;
		}
	}
	else if ((0 < a) && (this->_788 <= 0))
	{
		this->position.y += a;
		return true;
	}
	return false;
}

Vec3_32 PlayerBase::func_ov011_0212bbdc()
{
	Vec3_32 result;

	return result;
}

void PlayerBase::func_ov011_0212bbcc()
{
	this->_780 &= ~0x200;
}

u32 PlayerBase::func_ov011_0212bba4()
{
	u32 result;

	if ((this->_778 & 0x400000) != 0)
	{
		if (this->minVelH != 0)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

bool PlayerBase::func_ov011_0212bb90()
{
	return this->_7bf == TRUE;
}

u16 data_0208b344[2];
void func_02020150(u32, u32);
void func_02020128(u32);
void PlayerBase::func_ov011_0212bac8()
{
	i32 _7ac = this->_7ac;
	if (_7ac != 3)
	{
		if (_7ac != 4)
		{
			func_02020150(this->linked_player, 0);
			data_0208b344[this->linked_player] = 0x168;
			this->func_ov011_0212b838(0x167, &this->position);
			return;
		}
		func_02020150(this->linked_player, 0);
		data_0208b344[this->linked_player] = 0;
		return;
	}
	func_02020150(this->linked_player, 0x348);
	data_0208b344[this->linked_player] = 0;
	func_02020128(this->linked_player);
	return;
}

bool PlayerBase::func_ov011_0212b9f8(u8 a)
{
	bool bVar2;

	i8 _7ac = this->_7ac;
	if (_7ac == 3)
	{
		return false;
	}
	switch (a)
	{
	case 3:
		return this->func_ov011_0212b9ac(a);
	case 2:
		if (((_7ac == 0) || (_7ac == 1)) || (_7ac == 4))
		{
			return this->func_ov011_0212b9ac(a);
		}
		break;
	case 5:
		if (_7ac != 5)
		{
			return this->func_ov011_0212b9ac(a);
		}
		break;
	case 4:
		if (_7ac != 4)
		{
			return this->func_ov011_0212b9ac(a);
		}
		break;
	case 1:
		if ((_7ac == 0) || (_7ac == 4))
		{
			return this->func_ov011_0212b9ac(a);
		}
		break;
	case 0:
	default:
		return this->func_ov011_0212b9ac(a);
	}
	return false;
}

bool PlayerBase::func_ov011_0212b9ac(u8 a)
{
	if (BOOL(this->_7a9 == 0x5) != FALSE)
	{
		return false;
	}
	if (this->_7ab == a)
	{
		return false;
	}
	this->_7ab = a;
	return this->_7ac != this->_7ab;
}

void PlayerBase::func_ov011_0212b9a8() {}

void PlayerBase::func_ov011_0212b998()
{
	this->_780 |= 0x20;
}

void PlayerBase::func_ov011_0212b984()
{
	if ((this->_780 & 0x20) != 0)
	{
		this->_780 &= 0xffffffdf;
	}
}

void func_ov011_0212cfe4(void *);
void PlayerBase::func_ov011_0212b954()
{
	if ((this->_780 & 0x40) != 0)
	{
		this->_780 &= 0xffffffbf;
		func_ov011_0212cfe4(&this->_2c4);
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
	if (this->_7ac == 3)
	{
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
	if (this->linked_player == data_02085a7c)
	{
		this->func_ov011_0212b7f0(a);
	}
}

u32 data_02085a84;
void func_02011dc4(u32);
void PlayerBase::func_ov011_0212b740(u32 a)
{
	if (this->linked_player != data_02085a7c)
	{
		return;
	}
	if (
		BOOL(data_02085a84 != 0) != FALSE &&
		(a == 3))
	{
		return;
	}
	this->_77c = this->_77c | 0x800000;
	func_02011dc4(a);
	this->_798 = a;
}

void func_02011d94(u32);
void PlayerBase::func_ov011_0212b710()
{
	if ((this->_77c & 0x800000) != 0)
	{
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

u32 func_020204e0(i8);
void func_0202048c(u8);
u8 data_02088f34;
u8 data_02089508[2];
void func_ov000_020a189c(u32);
void func_ov000_020a183c(u32, u32);
void func_02012d6c(u32, u32 *);
u32 data_02088bdc;
u32 uRam02088f28; // data_02088bdc + 0x34c

bool PlayerBase::func_ov011_0212b2bc()
{
	if (this->_7b3 == 0)
	{
		i8 linked_player = this->linked_player;
		u8 b = func_020204e0(linked_player);
		this->_7b3 = 1;
		func_0202048c(linked_player);
		if (data_02088f34 == 0)
		{
			data_02089508[this->linked_player] = 2;
		}

		if (BOOL(data_02085a84 != 0) != FALSE)
		{
			if (b != 0)
			{
				func_ov000_020a189c(0);
			}
			else
			{
				func_02012d6c(uRam02088f28, &data_02088bdc);
				func_ov000_020a183c(0xe, 0);
			}
		}
		else if (b != 0)
		{
			return true;
		}
	}
	return false;
}

void PlayerBase::func_ov011_0212b26c(Actor *a)
{
	this->linkedActor = a;
	Actor *linkedActor = this->linkedActor;
	if (linkedActor == NULL)
	{
		return;
	}
	if ((BOOL)(linkedActor->actorType == 1) == FALSE)
	{
		linkedActor->linkPlayer(this->linked_player);
	}
}

void PlayerBase::setPosition(Vec3_32 *newPos)
{
	this->position.x = newPos->x;
	this->position.y = newPos->y;
}

u16 PlayerBase::func_ov011_0212b210(u16 r1)
{
	if (this->_7ac == 4)
	{
		// u32 r0 = 0xd00; // mov r0, 0xd00
		// u32 r2 = 0x0; // mov r2, 0x0
		// u64 r3_12 = (r1 * r2); // umull r12, r3, r1, r0
		// u32 r3 = r3_12 >> 0x32;
		// i32 r12 = r3_12;
		// r3 = (r1 * r2) + r3; // mla r3, r1, r2, r3
		// r2 = r1 >> 0x1f; // mov r2, r1, asr #0x1f
		// u32 r1 = 0x800; // // mov r1, #0x800
		// r3 = (r2 * r0) + r3; // mla r3, r2, r0, r3
		// r12 += r1; // adds r12, r12, r1
		//
		// return r1;
		// return (u16)(a * 0xd00 + 0x800 >> 0xc);
	}
	return r1;
}

u8 PlayerBase::func_ov011_0212b1d4()

{
	int scale = this->scale.y;
	if (scale < 0xacc)
	{
		i32 a = 0;
		return a;
	}

	if (0x1599 > scale)
	{
		return 1;
	}

	if (scale < 0x2000)
	{
		return 2;
	}
	return 3;
}