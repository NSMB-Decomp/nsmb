#include "VsResultsScreen.hpp"

void *VsResultsScreen::create()
{
	return new VsResultsScreen();
}

// 0x0215bb9c
ObjectProfile Object10_Profile = { VsResultsScreen::create, 10, 17 };
