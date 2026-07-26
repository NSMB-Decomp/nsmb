#include "ConnectScene.hpp"
#include "../system/app.hpp"
#include <nds/graphics_controls.hpp>
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/core/net/state.hpp>

ObjectProfile ConnectScene::profile = {
	ConnectScene::create,
	1,
	8,
};

ConnectScene::ConnectScene()
{

}
void *ConnectScene::create()
{
	return new ConnectScene();
}

void ConnectScene::func_020037e4(u32) {
	FS::Archive::mountFront(9, 0);
	FS::Archive::mountFront(5, 0);
	FS::Overlay::load(OVERLAY_11);
	FS::Overlay::load(OVERLAY_LEVEL);
	FS::Overlay::load(OVERLAY_52);
	func_ov052_021535a0();
	func_020125c4();
	func_02011c64();
	FS::Archive::unmount(5);
}

void ConnectScene::func_020037b4() {
	rcast<void (*)(u32)>(&App::initBoot)(0);
	ConnectScene::func_020037e4(0x0);
	data_0208ae58 = 0x1;
}

void ConnectScene::func_0200379c(u32 a, u32 b) {
	rcast<ConnectScene *>(b)->func_02003250(a, a);
}

void ConnectScene::func_02003580()
{
	func_0201325c();
	NDS::Graphics::assignMainObjectBank(1);
	NDS::Graphics::assignSubBackgroundBank(0x80);
	NDS::Graphics::assignSubObjectBank(0x100);
	NDS::Graphics::setMainDisplayMode(1, 5, 1);

	NDS::Graphics::setMainObjectTileMapping1D128K();
	NDS::Graphics::setMainObjectCharacterBase(0);
	NDS::Graphics::setMainObjectScreenBase(1);
	*(vu16 *)0x04000304 |= 0x8000;

	NDS::Graphics::configureMainTextBackground(0, 0, 0, 4, 6, 0);
	NDS::Graphics::configureMainTextBackground(1, 1, 0, 2, 2, 0);
	NDS::Graphics::configureMainTextBackground(2, 0, 0, 1, 2, 0);
	NDS::Graphics::configureMainTextBackground(3, 0, 0, 0, 2, 0);
	NDS::Graphics::setMainBackgroundPriority(1, 0);
	NDS::Graphics::setMainBackgroundPriority(1, 1);
	NDS::Graphics::setMainBackgroundPriority(2, 2);
	NDS::Graphics::setMainBackgroundPriority(3, 3);

	NDS::Graphics::setMainBackgroundHorizontalOffset(0, 0);
	NDS::Graphics::setMainBackgroundHorizontalOffset(1, 0);
	NDS::Graphics::setMainBackgroundHorizontalOffset(2, 0);
	NDS::Graphics::setMainBackgroundHorizontalOffset(3, 0);
	NDS::Graphics::setMainVisiblePlanes(0);
	data_02085a88 = 0x10;
	REG_POWER_CNT = (REG_POWER_CNT & 0xfffffdf1) | 0x20e;
	NDS::Graphics::enableDisplays();
	REG_DISPCNT_SUB |= 0x10000;
	wifiIconOBJIndex = 0x3de;

	if (data_0208884c[1] == 1) {
		data_0208ae54[0] = 1;
		data_0208ae54[1] = 0;
	} else {
		data_0208ae54[0] = 0;
		data_0208ae54[1] = 1;
	}
	func_02003f3c(&connectionStatus);
}

s32 ConnectScene::onCreate()
{
	u16 palette = 0;

	GlobalFader.setupSceneFading(Fader::FadeOnly, true, false);
	NDS::Graphics::uploadMainBackgroundPalette(&palette, 0, 2);
	data_02088f30 = 0;
	func_02003580();
	func_02010a84();
	func_02010a3c();
	connectionSubstate = 0;
	func_02006674(1);
	connectionTimer = 0;
	GlobalFader.brightnessFactor[0] = 0x1000;
	GlobalFader.brightnessFactor[1] = 0x1000;
	data_02085a84 = 2;
	func_02010bb0(
		&packetBuffer, 2, rcast<void *>(func_0200379c), this
	);
	syncedAidMask = 0;
	FS::setReadModeSafe();
	return true;
}

s32 ConnectScene::onUpdate()
{
	u8 syncSettings[2];

	if (data_02039678 != 0)
		func_02003ed8(&connectionStatus);

	switch (connectionSubstate) {
	case 0:
		if (BOOL(data_02088800 == 2) != FALSE) {
			func_0200ee9c(
				rcast<void *>(func_020037b4), 0, 0x5a, 2
			);
			connectionSubstate = 1;
			connectionTimer = 0;
		} else {
			connectionTimer++;
			if (connectionTimer >= 900)
				Net::errorState |= 0x8000;
		}
		break;

	case 1:
		if (!func_0200ee40(-1))
			break;
		connectionSubstate = 2;
	case 2:
		if (func_02010b34(&packetBuffer, syncSettings) != 0)
			connectionSubstate = 3;
		break;

	case 3: {
		bool synced = true;
		for (s32 aid = 0; aid < 2; aid++) {
			if ((syncedAidMask & (1 << aid)) == 0) {
				synced = false;
				break;
			}
		}
		if (synced) {
			func_0200e7c4(0);
			connectionSubstate = 4;
		}
		break;
	}

	case 4:
		if (func_0200e7ac(0) != 0) {
			func_0200e7b8(0);
			func_0200e748();
			func_0201e00c();

			NicknameInfo *nickname = data_02088850;
			if (!nickname->valid)
				nickname = 0;
			func_02016438(
				data_0208adcc, &nickname->data[2], nickname->data[1]
			);

			GlobalFader.reserved_5c4 = 0;
			GlobalFader.targetBrightness = -16;
			func_020131fc(5, 0);
			connectionSubstate = 5;
		}
		break;
	}

	if (connectionSubstate >= 1 && connectionSubstate < 5) {
		connectionTimer++;
		if (connectionTimer >= 0x1518)
			Net::errorState |= 0x8000;
	}
	return true;
}

s32 ConnectScene::onRender()
{
	func_02003e20(&connectionStatus);
	return true;
}

s32 ConnectScene::onDestroy()
{
	return true;
}

void ConnectScene::func_02003250(u32 aid, u32)
{
	if (aid == 0) {
		u8 *entry = packetBuffer.buffers[aid];
		data_02085ad4[0] = entry[0];
		data_02085ad4[1] = entry[0];
		func_02006444(entry[1]);
	}
	syncedAidMask |= 1 << aid;
}

ConnectScene::~ConnectScene()
{

}
