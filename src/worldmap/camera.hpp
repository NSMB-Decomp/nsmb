#pragma once
#include "../graphics/util/perspview.hpp"

struct ObjectProfile;

class WorldMapCamera : public PerspView {
public:

	typedef void(WorldMapCamera::* TaskFunc)();

	static ObjectProfile profile;

	virtual ~WorldMapCamera() override;
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
NTR_OFFSET_GUARD(WorldMapCamera, taskFunc, 0x108);
NTR_OFFSET_GUARD(WorldMapCamera, taskID, 0x110);
NTR_OFFSET_GUARD(WorldMapCamera, startTask, 0x114);
NTR_OFFSET_GUARD(WorldMapCamera, unk114, 0x118);
NTR_OFFSET_GUARD(WorldMapCamera, lightPos, 0x128);
NTR_OFFSET_GUARD(WorldMapCamera, unk138, 0x138);
NTR_OFFSET_GUARD(WorldMapCamera, fovSetting, 0x148);
NTR_OFFSET_GUARD(WorldMapCamera, fovy, 0x14C);
NTR_OFFSET_GUARD(WorldMapCamera, leftBound, 0x150);
NTR_OFFSET_GUARD(WorldMapCamera, rightBound, 0x154);
NTR_OFFSET_GUARD(WorldMapCamera, unk164, 0x164);

struct WmCameraTaskRaw {
	void (*function)(WorldMapCamera*);
	s32 adjustment;
};
NTR_SIZE_GUARD(WmCameraTaskRaw, 0x8);

union WmCameraTaskEntry {
	WmCameraTaskRaw raw;
	WorldMapCamera::TaskFunc member;
};
NTR_SIZE_GUARD(WmCameraTaskEntry, 0x8);

struct WmCameraMemberTaskEntry {
	WorldMapCamera::TaskFunc member;
};
NTR_SIZE_GUARD(WmCameraMemberTaskEntry, 0x8);

extern WorldMapCamera::TaskFunc data_ov008_020ee604[2];
extern WorldMapCamera::TaskFunc data_ov008_020ee614[2];
extern Vec3_32 data_ov008_020ee48c;
extern WmCameraTaskEntry data_ov008_020e8bd4;
extern WmCameraMemberTaskEntry data_ov008_020e8bdc;
extern WmCameraTaskEntry data_ov008_020e8be4;
extern WmCameraTaskEntry data_ov008_020e8bf4;

extern "C" void func_ov008_020d1808(WorldMapCamera* camera);
extern "C" void func_ov008_020d1850(WorldMapCamera* camera);
extern "C" void func_ov008_020d1880(WorldMapCamera* camera);
extern "C" void* func_ov008_020d1f98();
