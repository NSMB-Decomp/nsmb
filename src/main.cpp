#include "system/app.hpp"
#include "Vec.hpp"
#include "ProcessManager.hpp"
#include "Collision/platform.hpp"

// main.o comes right after crt0 in the link, so the linker keeps its copies of
// every inline/implicit function and vtable it shares with later objects. The
// ROM's copies were generated without inlining (e.g. UnkVec2Entry's ctor calls
// Vec2_32's instead of inlining it).
#pragma dont_inline on

extern "C" void NitroMain() {
	u32 bootTarget;
	u32 bootScene;

	if (MB_IsMultiBootChild() != 0) {
		if ((Wifi_isMinigames() != 0)) {
			bootTarget = 0;
		} else {
			bootTarget = 1;
		}
		bootScene = 0;
	} else {
		bootTarget = REG_RESET & 0xf;
		bootScene = (REG_RESET & 0xf00) >> 0x8;
	};

	u32 bootParam = (REG_RESET & 0xF0000) >> 16;

	App::setBootTarget(bootTarget);
	App::setBootScene(bootScene);
	App::setBootParam(bootParam);

	while (true) {
		App::branchToMain();
	}

	// This appears to be from stubbed out code in release.
	if (false) {
		new Vec3_32;
		new Vec3_16;
		{
			Fader fader;
			SegmentPlatform segment;
			RotatingPlatform rotating;
			UnkVec2Entry entry;
			UnkListEntry list;
		}
		{
			Vec3_32 v;
		}
		{
			Vec3_16 v;
		}
	}
}
