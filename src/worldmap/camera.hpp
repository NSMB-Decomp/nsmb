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
