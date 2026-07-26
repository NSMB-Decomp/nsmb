#include "../../../worldmap/camera.hpp"
#include "../../../worldmap/scene.hpp"
#include "../../../AAA.hpp"
#include <nds/graphics.hpp>
#include <nds/graphics_state.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>

WmCameraTaskEntry data_ov008_020e8bd4 = {
	{ func_ov008_020d1880, 0 },
};

WmCameraMemberTaskEntry data_ov008_020e8bdc = {
	&WorldMapCamera::func_ov008_020d16cc,
};

WmCameraTaskEntry data_ov008_020e8be4 = {
	{ func_ov008_020d1850, 0 },
};

ObjectProfile WorldMapCamera::profile = {
	func_ov008_020d1f98,
	0x142,
	2,
};

WmCameraTaskEntry data_ov008_020e8bf4 = {
	{ func_ov008_020d1808, 0 },
};

s32 data_ov008_020e8bfc[8][2] = {
	{  0,  1 },
	{  1,  1 },
	{  1,  0 },
	{  1, -1 },
	{  0, -1 },
	{ -1, -1 },
	{ -1,  0 },
	{ -1,  1 },
};

WorldMapCamera::TaskFunc data_ov008_020ee604[2] = {
	data_ov008_020e8bd4.member,
	data_ov008_020e8bdc.member,
};

WorldMapCamera::TaskFunc data_ov008_020ee614[2] = {
	data_ov008_020e8be4.member,
	data_ov008_020e8bf4.member,
};

WorldMapCamera::~WorldMapCamera() {}

void WorldMapCamera::func_ov008_020d16cc()
{
	Vec3_32 targetValue;
	u32 world = save.game.currentWorld;

	targetValue.y = func_ov008_020ce200(world, fovSetting);
	targetValue.z = func_ov008_020ce1ec(world, fovSetting);
	targetValue.x = func_ov008_020ce1d8(world, fovSetting);

	s32 positionSettled = func_02044120(
		&unk114,
		&targetValue,
		0x200,
		0x100000,
		0x200);

	s32 fovSettled = Math::expLerp(
		&fovy,
		func_ov008_020ce1c4(world, fovSetting),
		0x200,
		0x1000,
		0x1000);

	if (fovSetting == 0) {
		targetValue = data_ov008_020ee48c;
	} else {
		targetValue.set(0);
	}

	s32 targetSettled = func_02044120(
		&unk138,
		&targetValue,
		0x200,
		0x100000,
		0x200);

	unk164++;
	if (positionSettled == 0 && fovSettled == 0 && targetSettled == 0) {
		data_ov008_020ee3d0 = 1;
		setState(0);
	}
}

void WorldMapCamera::setState(u32 task) {
	WorldMapCamera* camera = this;

	camera->taskID = task;
	camera->taskFunc = data_ov008_020ee614[task];
	camera->startTask = 1;
}

void WorldMapCamera::updateState() {
	WorldMapCamera* camera = this;

	if (camera->startTask) {
		(camera->*data_ov008_020ee604[camera->taskID])();
		camera->startTask = 0;
	}

	(camera->*camera->taskFunc)();
}

extern "C" void func_ov008_020d1808(WorldMapCamera* camera) {
	camera->fovSetting ^= 1;

	if (camera->fovSetting) {
		func_02012398(0x2e, 0);
	} else {
		func_02012398(0x2f, 0);
	}

	camera->unk164 = 0;
}

extern "C" void func_ov008_020d1850(WorldMapCamera* camera) {
	if (camera->fovSetting)
		return;

	camera->unk138 = data_ov008_020ee48c;
}

extern "C" void func_ov008_020d1880(WorldMapCamera*) {}

extern "C" void* func_ov008_020d1f98() {
	return new WorldMapCamera();
}

s32 WorldMapCamera::onUpdate()
{
	Vec3_32 cameraTarget;
	Vec3_32 cameraPosition;

	NDS::Graphics::flushGeometry();
	updateState();

	fx32 targetX = unk138.x;
	u8 playMovementSound = data_ov008_020ee394;

	if (targetX <= leftBound) {
		targetX = leftBound;
		playMovementSound = false;
	} else if (targetX >= rightBound) {
		targetX = rightBound;
		playMovementSound = false;
	}

	if (playMovementSound) {
		func_02012314(0xec, 0);
	}

	data_ov008_020ee3c4 = targetX;
	rotation.x = unk114.x >> 4;

	fx32 cameraDistance = _FixedMul(unk114.z, data_ov008_020ee3dc);
	cameraPosition.x = targetX;
	cameraPosition.y = unk138.y;
	cameraPosition.z = unk138.z + cameraDistance;
	MTX::setRotationX(Game_modelMatrix, rotation.x);
	NDS::Math::transformVector43(
		&cameraPosition, &Game_modelMatrix, &cameraPosition);

	if ((WM::wxFlags & WM::WF_Bit2) == 0) {
		if (cameraPosition.z < 0) {
			up.set(0, -0x1000, 0);
		} else {
			up.set(0, 0x1000, 0);
		}
	}

	cameraTarget.x = targetX;
	cameraTarget.y = unk138.y + unk114.y;
	cameraTarget.z = unk138.z;
	cameraPosition.x = 0;
	cameraPosition.y = 0;
	cameraPosition.z = cameraDistance;

	MTX::setRotationY(Game_modelMatrix, rotation.y);
	MTX::rotateX(Game_modelMatrix, rotation.x);
	NDS::Math::transformVector43(
		&cameraPosition, &Game_modelMatrix, &cameraPosition);

	data_ov000_020caa54 = Game_modelMatrix;
	cameraPosition.add2(cameraTarget);

	Vec3_32 shake;
	fx32 shakeAmount = data_ov008_020ee3ec;
	if (shakeAmount != 0) {
		u32 direction =
			((Wifi::random() & 0x7fff) << 3) >> 15;

		shake.x = shakeAmount * data_ov008_020e8bfc[direction][0];
		shake.y = shakeAmount * data_ov008_020e8c00[direction][0];
		shake.z = 0;
		NDS::Math::transformVector43(&shake, &Game_modelMatrix, &shake);
		cameraTarget.add2(shake);
		cameraPosition.add2(shake);
	}

	fx32 targetZ = cameraTarget.z;
	fx32 targetY = cameraTarget.y;
	fx32 targetXValue = cameraTarget.x;
	target.x = targetXValue;
	target.y = targetY;
	target.z = targetZ;

	fx32 positionZ = cameraPosition.z;
	fx32 positionY = cameraPosition.y;
	fx32 positionX = cameraPosition.x;
	position.x = positionX;
	position.y = positionY;
	position.z = positionZ;

	s32 complement;
	s32 angle = fovy >> 12;
	complement = (angle + 90) % 360;

	NDS::Graphics3D::buildPerspectiveMatrix(
		data_ov008_020e8c8c[angle],
		data_ov008_020e8c8c[complement],
		0x1555, 0x1000, 0x800000, 0x1000, TRUE, nullptr);
	NDS::Graphics3D::buildPerspectiveMatrix(
		data_ov008_020e8c8c[angle],
		data_ov008_020e8c8c[complement],
		0x1555, 0x1000, 0x800000, 0x1000, FALSE,
		&NDS::Graphics3D::runtimeState.projectionMatrix);

	NDS::Graphics3D::runtimeState.flags &=
		~NDS::Graphics3D::GeometryStateFlagBits4_6;
	return 1;
}

s32 WorldMapCamera::onCreate()
{
	data_ov000_020caa3c = 0x1000;
	NDS::Math::identityMatrix43(&data_ov000_020caa54);

	up.x = 0;
	up.y = 0x1000;
	up.z = 0;

	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;

	target.set(0);
	position.x = 0;
	position.y = 0;
	position.z = 0x200000;

	fovSetting = 0;
	u32 world = save.game.currentWorld;

	unk114.y = func_ov008_020ce200(world, fovSetting);
	unk114.z = func_ov008_020ce1ec(world, fovSetting);
	unk114.x = func_ov008_020ce1d8(world, fovSetting);
	fovy = func_ov008_020ce1c4(world, fovSetting);
	leftBound = func_ov008_020ce1b4(world);
	rightBound = func_ov008_020ce184(world);

	lightPos.x = func_ov008_020ce16c(world);
	lightPos.y = func_ov008_020ce154(world);
	lightPos.z = func_ov008_020ce13c(world);

	for (s32 lightID = 0; lightID < 4; lightID++) {
		{
			Vec3_32 lightVector;
			lightVector.x = lightPos.x;
			lightVector.y = lightPos.y;
			lightVector.z = lightPos.z;
			func_ov000_020a3c40(lightID, &lightVector);
		}
		data_ov000_020caa40[lightID] = 0x7FFF;
	}

	NDS::Graphics3D::setLightVector(
		0, static_cast<s16>(lightPos.x),
		static_cast<s16>(lightPos.y), static_cast<s16>(lightPos.z));
	NDS::Graphics3D::setLightVector(
		1, static_cast<s16>(lightPos.x),
		static_cast<s16>(lightPos.y), static_cast<s16>(lightPos.z));
	NDS::Graphics3D::setLightVector(
		2, static_cast<s16>(lightPos.x),
		static_cast<s16>(lightPos.y), static_cast<s16>(lightPos.z));
	NDS::Graphics3D::setLightVector(
		3, static_cast<s16>(lightPos.x),
		static_cast<s16>(lightPos.y), static_cast<s16>(lightPos.z));

	NDS::Graphics3D::setLightColor(0, 0x7FFF);
	NDS::Graphics3D::setLightColor(1, 0x7FFF);
	NDS::Graphics3D::setLightColor(2, 0x7FFF);
	NDS::Graphics3D::setLightColor(3, 0x7FFF);
	NDS::Graphics3D::setMaterialDiffuseAmbient(0x2954, 0x18C6, false);
	NDS::Graphics3D::setMaterialSpecularEmission(0x20A, 0x38C6, false);
	NDS::Graphics3D::setPolygonAttributes(0, 0, 2, 0, 0x1C, 0x800);

	data_02085a74 = 1;
	data_02085a78 = 1;
	setState(0);
	onUpdate();
	return 1;
}

s32 WorldMapCamera::onRender()
{
	NDS::Graphics::flushGeometry();

	NDS::Graphics3D::buildLookAtMatrix(
		position,
		up,
		target,
		true,
		&viewMatrix);

	Vec3_32s* targetVector = target;
	Vec3_32s* upVector = up;
	Vec3_32s* positionVector = position;
	NDS::Graphics3D::RuntimeState* state = &NDS::Graphics3D::runtimeState;
	Mat4x3* cameraMatrix = &NDS::Graphics3D::runtimeState.cameraMatrix;

	state->cameraPosition = *positionVector;
	state->cameraUp = *upVector;
	state->cameraTarget = *targetVector;

	NDS::Graphics3D::buildLookAtMatrix(
		positionVector,
		upVector,
		targetVector,
		false,
		cameraMatrix);

	NDS::Graphics3D::runtimeState.flags &=
		~NDS::Graphics3D::GeometryStateFlagBits3_5_6_7;
	return View::onRender();
}

fx32 data_ov008_020e8c8c[450] = {
	0, 71, 143, 214, 286, 357, 428, 499,
	570, 641, 711, 782, 852, 921, 991, 1060,
	1129, 1198, 1266, 1334, 1401, 1468, 1534, 1600,
	1666, 1731, 1796, 1860, 1923, 1986, 2048, 2110,
	2171, 2231, 2290, 2349, 2408, 2465, 2522, 2578,
	2633, 2687, 2741, 2793, 2845, 2896, 2946, 2996,
	3044, 3091, 3138, 3183, 3228, 3271, 3314, 3355,
	3396, 3435, 3474, 3511, 3547, 3582, 3617, 3650,
	3681, 3712, 3742, 3770, 3798, 3824, 3849, 3873,
	3896, 3917, 3937, 3956, 3974, 3991, 4006, 4021,
	4034, 4046, 4056, 4065, 4074, 4080, 4086, 4090,
	4094, 4095, 4096, 4095, 4094, 4090, 4086, 4080,
	4074, 4065, 4056, 4046, 4034, 4021, 4006, 3991,
	3974, 3956, 3937, 3917, 3896, 3873, 3849, 3824,
	3798, 3770, 3742, 3712, 3681, 3650, 3617, 3582,
	3547, 3511, 3474, 3435, 3396, 3355, 3314, 3271,
	3228, 3183, 3138, 3091, 3044, 2996, 2946, 2896,
	2845, 2793, 2741, 2687, 2633, 2578, 2522, 2465,
	2408, 2349, 2290, 2231, 2171, 2110, 2048, 1986,
	1923, 1860, 1796, 1731, 1666, 1600, 1534, 1468,
	1401, 1334, 1266, 1198, 1129, 1060, 991, 921,
	852, 782, 711, 641, 570, 499, 428, 357,
	286, 214, 143, 71, 0, -71, -143, -214,
	-286, -357, -428, -499, -570, -641, -711, -782,
	-852, -921, -991, -1060, -1129, -1198, -1266, -1334,
	-1401, -1468, -1534, -1600, -1666, -1731, -1796, -1860,
	-1923, -1986, -2048, -2110, -2171, -2231, -2290, -2349,
	-2408, -2465, -2522, -2578, -2633, -2687, -2741, -2793,
	-2845, -2896, -2946, -2996, -3044, -3091, -3138, -3183,
	-3228, -3271, -3314, -3355, -3396, -3435, -3474, -3511,
	-3547, -3582, -3617, -3650, -3681, -3712, -3742, -3770,
	-3798, -3824, -3849, -3873, -3896, -3917, -3937, -3956,
	-3974, -3991, -4006, -4021, -4034, -4046, -4056, -4065,
	-4074, -4080, -4086, -4090, -4094, -4095, -4096, -4095,
	-4094, -4090, -4086, -4080, -4074, -4065, -4056, -4046,
	-4034, -4021, -4006, -3991, -3974, -3956, -3937, -3917,
	-3896, -3873, -3849, -3824, -3798, -3770, -3742, -3712,
	-3681, -3650, -3617, -3582, -3547, -3511, -3474, -3435,
	-3396, -3355, -3314, -3271, -3228, -3183, -3138, -3091,
	-3044, -2996, -2946, -2896, -2845, -2793, -2741, -2687,
	-2633, -2578, -2522, -2465, -2408, -2349, -2290, -2231,
	-2171, -2110, -2048, -1986, -1923, -1860, -1796, -1731,
	-1666, -1600, -1534, -1468, -1401, -1334, -1266, -1198,
	-1129, -1060, -991, -921, -852, -782, -711, -641,
	-570, -499, -428, -357, -286, -214, -143, -71,
	0, 71, 143, 214, 286, 357, 428, 499,
	570, 641, 711, 782, 852, 921, 991, 1060,
	1129, 1198, 1266, 1334, 1401, 1468, 1534, 1600,
	1666, 1731, 1796, 1860, 1923, 1986, 2048, 2110,
	2171, 2231, 2290, 2349, 2408, 2465, 2522, 2578,
	2633, 2687, 2741, 2793, 2845, 2896, 2946, 2996,
	3044, 3091, 3138, 3183, 3228, 3271, 3314, 3355,
	3396, 3435, 3474, 3511, 3547, 3582, 3617, 3650,
	3681, 3712, 3742, 3770, 3798, 3824, 3849, 3873,
	3896, 3917, 3937, 3956, 3974, 3991, 4006, 4021,
	4034, 4046, 4056, 4065, 4074, 4080, 4086, 4090,
	4094, 4095,
};
