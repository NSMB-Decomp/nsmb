#include "Object216.hpp"

Unk_ov120_0218d860 data_ov120_0218e058[3];

void *Object216::create()
{
	return new Object216();
}

void *Object217::create()
{
	return new Object217();
}

void *Object218::create()
{
	return new Object218();
}

void *Object219::create()
{
	return new Object219();
}

void *Object220::create()
{
	return new Object220();
}

void *Object221::create()
{
	return new Object221();
}

void *Object222::create()
{
	return new Object222();
}

void *Object223::create()
{
	return new Object223();
}

Unk_ov120_0218d860::Unk_ov120_0218d860()
{
	_1 = 0;
	_4 = 0;
	_0 = 0;
	for (int i = 0; i < 12; i++) {
		_8[i] = 0;
	}
}

Unk_ov120_0218d860::~Unk_ov120_0218d860() {}

// 0x0218de74
ActorProfile Object222_Profile = { Object222::create, 222, 270, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218de80
ActorProfile Object223_Profile = { Object223::create, 223, 271, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218de8c
ActorProfile Object221_Profile = { Object221::create, 221, 269, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218de98
ActorProfile Object220_Profile = { Object220::create, 220, 268, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218dea4
ActorProfile Object217_Profile = { Object217::create, 217, 265, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218deb0
ActorProfile Object218_Profile = { Object218::create, 218, 266, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218debc
ActorProfile Object219_Profile = { Object219::create, 219, 267, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218dec8
ActorProfile Object216_Profile = { Object216::create, 216, 264, NULL /* TODO: 0x0218d0a8 */ };
