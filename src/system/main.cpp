#include "app.hpp"

inline u32 getResetParam() {
	return *rcast<u32*>(0x027FFC20);
}

extern "C" void NitroMain() {

	u32 bootTarget;
	u32 bootScene;

	if (Nitro::Wifi_isMultiBootCart()) {
		if ((func_020109c8() != 0)) {
			bootTarget = 0;
		} else {
			bootTarget = 1;
		}
		bootScene = 0;
	} else {
		bootTarget = getResetParam() & 0xf;
		bootScene = (getResetParam() & 0xf00) >> 0x8;
	};

	u32 bootParam = (getResetParam() & 0xF0000) >> 16;

	App::setBootTarget(bootTarget);
	App::setBootScene(bootScene);
	App::setBootParam(bootParam);

	while (true) {
		App::branchToMain();
	}

}
