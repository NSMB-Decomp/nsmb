#pragma once
#include "../graphics/util/perspview.hpp"

struct ObjectProfile;

class WorldMapCamera : public PerspView {
public:

	typedef void(WorldMapCamera::* TaskFunc)();

	static ObjectProfile profile;

	virtual s32 onCreate() override;
	virtual s32 onUpdate() override;
	virtual s32 onRender() override;

	void updateState();
	void setState(u32 task);
	void func_ov008_020d16cc();

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
NTR_SIZE_GUARD(WorldMapCamera, 0x168);

extern WorldMapCamera::TaskFunc data_ov008_020ee604[2];
extern WorldMapCamera::TaskFunc data_ov008_020ee614[2];
extern Vec3_32 data_ov008_020ee48c;

extern "C" void func_ov008_020d1808(WorldMapCamera* camera);
extern "C" void func_ov008_020d1850(WorldMapCamera* camera);
extern "C" void func_ov008_020d1880(WorldMapCamera* camera);
extern "C" void* func_ov008_020d1f98();
