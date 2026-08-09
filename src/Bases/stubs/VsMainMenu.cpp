#include "VsMainMenu.hpp"

void *VsMainMenu::create()
{
	return new VsMainMenu();
}

// 0x0215bdec
ActorProfile Object6_Profile = { VsMainMenu::create, 6, 14, NULL /* TODO: 0x021589e0 */ };
