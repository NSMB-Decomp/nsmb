#include "camera.hpp"
#include "../AAA.hpp"

extern "C" void func_ov008_020d162c(WmCamera* camera) {
	if (camera->startTask) {
		(camera->*data_ov008_020ee604[camera->taskID])();
		camera->startTask = 0;
	}

	(camera->*camera->taskFunc)();
}

extern "C" void func_ov008_020d16a0(WmCamera* camera, u32 task) {
	camera->taskID = task;
	camera->taskFunc = data_ov008_020ee614[task];
	camera->startTask = 1;
}

extern "C" void func_ov008_020d1808(WmCamera* camera) {
	camera->fovSetting ^= 1;

	if (camera->fovSetting) {
		func_02012398(0x2e, 0);
	} else {
		func_02012398(0x2f, 0);
	}

	camera->unk164 = 0;
}

extern "C" void func_ov008_020d1850(WmCamera* camera) {
	if (camera->fovSetting)
		return;

	camera->unk138 = data_ov008_020ee48c;
}

extern "C" void func_ov008_020d1880(WmCamera*) {}

extern "C" void* func_ov008_020d1f98() {
	return new WmCamera();
}
