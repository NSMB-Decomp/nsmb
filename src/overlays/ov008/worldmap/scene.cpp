#include "../../../worldmap/scene.hpp"
#include "../../../worldmap/playermodel.hpp"
#include "../../../menu/OptionsMenu.hpp"
#include "../../../objectid.hpp"
#include "../../../system/vblank.hpp"
#include <nds/input_buttons.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>

extern "C" u8 func_ov008_020cda24(u32 world, u32 path, u8 mask)
{
	return mask & data_ov008_020e79c8[world].paths[path].flag;
}

extern "C" u16 func_ov008_020cda4c(u32 world, u32 node, u16 mask)
{
	return mask & data_ov008_020e79c4[world].nodes[node].flag;
}

extern "C" u16 func_ov008_020cda7c(u32 world)
{
	return data_ov008_020e79e4[world].nodeCount;
}

extern "C" WM::NodeLink* func_ov008_020cda94(u32 world, u32 node)
{
	return data_ov008_020e79c4[world].nodes[node].links;
}

extern "C" void func_ov008_020cdb44(u32 sceneID, u32 settings)
{
	func_02011e3c(0x1e);
	func_020131fc(sceneID, settings);
}

extern "C" u8 func_ov008_020cdcac(u32 index)
{
	u8* values = &data_ov008_020e5cc8[index * 2];
	return values[data_ov008_020ee380];
}

extern "C" void func_ov008_020ce0a0()
{
	save.game.starCoinsCollected = func_ov008_020cdf9c();
	save.game.starCoinsSpent = func_ov008_020cdec0();
	func_ov008_020cddd8();
	func_ov008_020cdcf8();
}

extern "C" u32 func_ov008_020ce0d4(u32 index)
{
	return data_ov008_020e2d3c[index];
}

extern "C" Vec3_32 func_ov008_020ce0e4(u32 index)
{
	Vec3_32 result;
	result.x = data_ov008_020e2d58[index][0];
	result.y = data_ov008_020e2d5c[index][0];
	result.z = data_ov008_020e2d60[index][0];
	return result;
}

extern "C" u32 func_ov008_020ce12c(u32 index)
{
	return data_ov008_020e650c[index];
}

extern "C" u32 func_ov008_020ce13c(u32 index)
{
	return data_ov008_020e6bf8[index][0];
}

extern "C" u32 func_ov008_020ce154(u32 index)
{
	return data_ov008_020e6bf4[index][0];
}

extern "C" u32 func_ov008_020ce16c(u32 index)
{
	return data_ov008_020e6bf0[index][0];
}

extern "C" u32 func_ov008_020ce184(u32 index)
{
	u32 result = data_ov008_020e6718[index][0];
	if (index != 7) {
		return result;
	}

	u8 nodeState = save.game.nodeStates[7][6] & WM::NS_Completed;
	if (nodeState != 0) {
		result = 0x420000;
	}
	return result;
}

extern "C" u32 func_ov008_020ce1b4(u32 index)
{
	return data_ov008_020e6714[index][0];
}

extern "C" u32 func_ov008_020ce1c4(u32 row, u32 column)
{
	return data_ov008_020e77b0[row][column][0];
}

extern "C" u32 func_ov008_020ce1d8(u32 row, u32 column)
{
	return data_ov008_020e77ac[row][column][0];
}

extern "C" u32 func_ov008_020ce1ec(u32 row, u32 column)
{
	return data_ov008_020e77a8[row][column][0];
}

extern "C" u32 func_ov008_020ce200(u32 row, u32 column)
{
	return data_ov008_020e77a4[row][column][0];
}

extern "C" u32 func_ov008_020ce214(u32 row, u32 column)
{
	return data_ov008_020e8794[row][column];
}

extern "C" void func_ov008_020ce228() {}

extern "C" void func_ov008_020ce22c()
{
	u32 world = save.game.currentWorld;
	data_ov008_020ee3f0 = 4;
	data_ov008_020ee3d0 = 0;
	save.game.worldStates[world] |= WM::WS_Completed;

	if (world != 7) {
		world = func_ov008_020ce298(world);
	}
	func_ov008_020cdb44(9, world | 0x3000);
}

extern "C" u32 func_ov008_020ce298(u32 nodeType)
{
	u8 powerup = Game::getPlayerPowerup(0);
	u32 result;

	switch (nodeType) {
	case 0:
		result = 1;
		break;
	case 1:
		if (powerup != WmPlayerModel::P_Shell) {
			result = 2;
		} else {
			result = 3;
		}
		break;
	case 2:
		result = 4;
		break;
	case 3:
		result = 4;
		break;
	case 4:
		if (powerup != WmPlayerModel::P_Shell) {
			result = 5;
		} else {
			result = 6;
		}
		break;
	case 5:
		result = 7;
		break;
	case 6:
		result = 7;
		break;
	case 7:
		result = 7;
		break;
	}

	return result;
}

extern "C" void func_ov008_020ce5ec()
{
	u32 value = data_ov008_020ee3f4;
	data_ov008_020ee3f0 = 3;
	data_ov008_020ee398 = 2;
	data_ov008_020ee3e0 = 0;
	data_ov008_020ee378 = 1;
	data_ov008_020ee37c = 1;
	data_ov008_020ee3d0 = 0;
	func_ov008_020cdc30(7, 1, value);
	func_02012398(0xe6, 0);
}

extern "C" void func_ov008_020cf790() {}

extern "C" void func_ov008_020cf12c(WorldmapScene* scene, u32 state)
{
	func_ov008_020d12ac(data_ov008_020ee49c);
	scene->Scene::postUpdate(state);
}

extern "C" bool func_ov008_020cf794()
{
	FS::Cache::clear();
	if (data_0203bd30 != SC_Worldmap) {
		func_02011d40();
	}
	System::resetSubBGVBlank();
	return true;
}

extern "C" u32 func_ov008_020d04fc()
{
	if (!(save.game.completion & WM_SAVE_COMPLETION_BIT_5)) {
		return 0;
	}

	return func_ov008_020d0548(&data_ov008_020ee3d4);
}

extern "C" void func_ov008_020d0534()
{
	func_ov008_020d0614(&data_ov008_020ee3d4);
}

extern "C" void func_ov008_020d0614(u32* value)
{
	*value = 0;
}

extern "C" u32 func_ov008_020d0620()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_L;
}

extern "C" u32 func_ov008_020d0644()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_R;
}

extern "C" u32 func_ov008_020d0668()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_X;
}

extern "C" u32 func_ov008_020d068c()
{
	return Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_Y;
}

extern "C" void func_ov008_020d06b0()
{
	OptionsMenu::menuUnloadWorldmap();
}

extern "C" void func_ov008_020d06bc()
{
	OptionsMenu::menuMain();
}

extern "C" void func_ov008_020d06c8()
{
	if (OptionsMenu::taskID == OptionsMenu::T_SlideIn) {
		OptionsMenu::menuSlideIn();
		return;
	}

	OptionsMenu::menuClose();
}

extern "C" void func_ov008_020d06fc()
{
	OptionsMenu::menuLoad();
}

extern "C" void func_ov008_020d0a4c()
{
	OptionsMenu::menuDraw();
}

extern "C" void func_ov008_020d1478(Unk020d1478Config* config, u32 mode)
{
	config->value04 = 0x333;
	config->value00 = 0x1000;
	config->value08 = 0;
	config->value0C = 0x1e;
	config->mode = mode;

	switch (config->mode) {
	case 2:
		config->value0C = 0x32;
		data_ov008_020e5a2c = save.game.currentWorld;
		return;
	case 0:
		data_ov008_020ee414 = 0;
		return;
	default:
		config->value04 = 0x333;
		config->value08 = 0x8000;
		return;
	}
}

extern "C" void func_ov008_020d153c() {}

extern "C" void func_ov008_020d1540() {}
