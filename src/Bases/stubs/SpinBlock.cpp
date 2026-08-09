#include "SpinBlock.hpp"

void *SpinBlock::create()
{
	return new SpinBlock();
}

void *Object255::create()
{
	return new Object255();
}

void *Object256::create()
{
	return new Object256();
}

// 0x02125348
ActorProfile Object254_Profile = { SpinBlock::create, 254, 91, NULL /* TODO: 0x020da9a8 */ };

// 0x0212533c
ActorProfile Object255_Profile = { Object255::create, 255, 92, NULL };

// 0x02125354
ActorProfile Object256_Profile = { Object256::create, 256, 93, NULL };
