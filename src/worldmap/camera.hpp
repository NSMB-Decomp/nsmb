#pragma once
#include "../graphics/util/perspview.hpp"

class WmCamera : public PerspView {
public:

	typedef void(WmCamera::* TaskFunc)();

	TaskFunc taskFunc;
	u32 taskID;
	u32 startTask;
	Vec3_32 unk114;
	Vec3_32 lightPos;
	Vec3_32 unk138;
	u32 fovSetting;
	fx32 fovy;
	fx32 leftBound;
	fx32 rightBound;
	u32 unk158;
	u32 unk15C;
	u32 unk160;
	u32 unk164;

};
NTR_SIZE_GUARD(WmCamera, 0x168);

extern WmCamera::TaskFunc data_ov008_020ee604[2];
extern WmCamera::TaskFunc data_ov008_020ee614[2];
extern Vec3_32 data_ov008_020ee48c;

extern "C" void func_ov008_020d162c(WmCamera* camera);
extern "C" void func_ov008_020d16a0(WmCamera* camera, u32 task);
extern "C" void func_ov008_020d1808(WmCamera* camera);
extern "C" void func_ov008_020d1850(WmCamera* camera);
extern "C" void func_ov008_020d1880(WmCamera* camera);
extern "C" void* func_ov008_020d1f98();
