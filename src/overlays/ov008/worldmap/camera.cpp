#include "../../../worldmap/camera.hpp"
#include "../../../AAA.hpp"
#include <nds/graphics.hpp>
#include <nds/graphics_state.hpp>
#include <nsmb/overlays/ov000/symbols.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>

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
