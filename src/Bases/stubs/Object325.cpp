#include "Object325.hpp"
#include <nsmb/overlays/ov010/symbols.hpp>
#include <nsmb/arm9/itcm.hpp>

void *Object325::create()
{
	return new Object325();
}

s32 Object325::onRender() {
	func_ov010_020e6524();
	NDS::Graphics::flushGeometry();
	return true;
}

s32 Object325::onUpdate() {
	func_01ffded0();
	return true;
}

// 0x02123d58
ActorProfile Object325_Profile = { Object325::create, 325, 307, NULL };
