#include "StageLayout.hpp"

void *StageLayout::create()
{
	return new StageLayout();
}

// 0x020c9388
ActorProfile StageLayout_Profile = { StageLayout::create, 303, 291, NULL };
