#include "MainMenuScene.hpp"
#include <nsmb/arm9/functions.hpp>
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov009/dependencies.hpp>
#include <nsmb/overlays/ov009/symbols.hpp>
#include <nsmb/overlays/ov053/symbols.hpp>
#include <nsmb/file_ids.hpp>
#include <nds/graphics.hpp>
#include <nds/graphics_controls.hpp>
#include <nds/input_buttons.hpp>
#include <nds/memory.hpp>
#include <nds/system_boot.hpp>
#include "../system/app.hpp"









// void (Object229::*data_ov099_02186614[4])() = {
//     Object229::func_ov099_021860f0,
//     Object229::func_ov099_02186080,
//     Object229::func_ov099_02186028,
//     Object229::func_ov099_02185fb4,
// };


u32 data_ov009_020db914;
u32 data_ov009_020db854;

void *MainMenuScene::create()
{
	MainMenuScene *scene =
		(MainMenuScene *)MainMenuScene::operator new(sizeof(MainMenuScene));
	if (scene == 0)
		return scene;
	return _ZN13MainMenuSceneC2Ev(scene);
}

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

s32 MainMenuScene::onCreate()
{
	func_02010a84();
	func_0200f3d8();
	NDS::Graphics::setMainVisiblePlanes(0);
	func_ov009_020ce35c(&cutscene, this);

	if (settings == 1) {
		func_02007bd8(&GlobalFader);
		func_02011c84(data_ov009_020d9630, data_ov009_020d9628);
		func_02011e7c(0x6d, 0);
	} else {
		NDS::Graphics::setSubDisplayMode(0);
		NDS::Graphics::assignSubBackgroundBank(0x80);
		NDS::Graphics::assignSubObjectBank(0x100);
		func_ov009_020d34a0(this);
		func_ov000_020bd63c();
		func_ov000_020bd604();

		u16 palette = 0;
		NDS::Graphics::uploadSubBackgroundPalette((u32)&palette, 0, 2);

		NDS::Graphics::setSubBackgroundPriority(1, 1);
		NDS::Graphics::setSubBackgroundPriority(2, 2);
		NDS::Graphics::setSubBackgroundHorizontalOffset(1, 0);
		NDS::Graphics::setSubBackgroundHorizontalOffset(2, 0);
		NDS::Graphics::setSubBackgroundMosaicEnabled(1, false);
		NDS::Graphics::setSubBackgroundMosaicEnabled(2, false);
		NDS::Graphics::setSubVisiblePlanes(
			NDS_VISIBLE_PLANE_BACKGROUND2 | NDS_VISIBLE_PLANE_OBJECTS);

		fileOperationFailed = false;
		menuID = 0;
		stateID = 0;
		buttonsVisible = false;
		buttonAnimTimer = 0;
		fileSelectCurrentButton = 0;
		controlMode = data_02085ad4[0];
		soundMode = save.options.soundMode;
		backButtonSelected = false;
		backButtonHighlighted = false;
		copyingFile = false;
		copyingFileFrame = 0;
		data_ov009_020dbb80 = 0;
		guiTimer = 0;
		buttonsTimer = 0;
		backButtonOffset = 0;

		for (s32 button = 0; button < 4; button++) {
			mainMenuButtons[button].posX = 0;
			mainMenuButtons[button].posY = 0;
			mainMenuButtons[button].velX = 0;
			mainMenuButtons[button].velY = 0;
		}

		if (data_0203bd2c == 6 || data_0203bd2c == 10) {
			data_ov009_020dbb84 = 1;
		} else if (NDS::System::readBootSource() == 2 &&
			data_0203bd2c == 0x181) {
			data_ov009_020dbb84 = 2;
		} else {
			data_ov009_020dbb84 = 0;
		}

		if ((s32)data_02085a84 >= 2)
			data_02085a84 = 1;

		func_020180c0(&label, 1);
		Game::character = 0;
		func_0204dad8(Game::character);
		func_02011ce4(0x1b, 0x2e);
		func_02011e7c(0x1b, 0);
	}

	return true;
}

s32 MainMenuScene::onDestroy()
{
	if (settings == 0)
		func_020180a4(&label);

	func_ov009_020cd9bc(&cutscene);
	return true;
}

void MainMenuScene::pendingDestroy()
{
	func_ov009_020cd9ac(&cutscene);
}

extern "C" void func_ov009_020d34a0(MainMenuScene *)
{
	NDS::Memory::clearFast(0xc0, 0x07000400, 0x400);
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_title_d_bnbl, false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_title_d_bncl, false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping2D();
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_UI_O_menu_title_o_d_ncg_bin,
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_d_2d_UI_O_menu_title_o_d_ncl_bin,
		(void *)0x05000600);
}

s32 MainMenuScene::onUpdate()
{
	if ((data_ov009_020dbba0 & 1) == 0) {
		data_ov009_020dbbdc[0] = data_ov009_020da7a4;
		data_ov009_020dbbdc[1] = data_ov009_020da8ec;
		data_ov009_020dbbdc[2] = data_ov009_020da6c4;
		data_ov009_020dbbdc[3] = data_ov009_020da63c;
		data_ov009_020dbbdc[4] = data_ov009_020da6ac;
		data_ov009_020dbba0 |= 1;
	}

	if (settings == 0) {
		func_02021808();
		if (!fileOperationFailed)
			(this->*data_ov009_020dbbdc[menuID].member)();
	}

	func_ov009_020cd884(&cutscene);
	return true;
}

extern "C" void func_ov009_020d3294(MainMenuScene *scene)
{
	if ((data_ov009_020dbba4 & 1) == 0) {
		data_ov009_020dbc3c[0] = data_ov009_020da994;
		data_ov009_020dbc3c[1] = data_ov009_020da6cc;
		data_ov009_020dbc3c[2] = data_ov009_020da79c;
		data_ov009_020dbc3c[3] = data_ov009_020da654;
		data_ov009_020dbc3c[4] = data_ov009_020da7ac;
		data_ov009_020dbc3c[5] = data_ov009_020da7b4;
		data_ov009_020dbc3c[6] = data_ov009_020da7c4;
		data_ov009_020dbba4 |= 1;
	}

	(scene->*data_ov009_020dbc3c[scene->stateID].member)();
}

extern "C" void func_ov009_020d3264(MainMenuScene *scene)
{
	func_ov009_020d34a0(scene);
	func_ov009_020ce7a4(scene);
	scene->stateID = 1;
	scene->stateTimer = 12;
	scene->buttonHitTimer = 0;
}

extern "C" void func_ov009_020d31fc(MainMenuScene *scene)
{
	BOOL fading = (u8)(GlobalFader.fadingState[0] & 0x49) != 0 ||
		(u8)(GlobalFader.fadingState[1] & 0x49) != 0;
	if (fading)
		return;

	if (scene->stateTimer != 0) {
		scene->stateTimer--;
	} else {
		scene->stateID = 2;
		data_ov009_020dbb80 = 0;
	}
}

extern "C" void func_ov009_020d305c(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousButton = data_ov009_020dbb84;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		if (action >= 0 && action <= 3) {
			switch (action) {
			case 0:
				break;
			case 1:
			case 2:
				func_02011e3c(30);
				break;
			case 3:
				break;
			}
			data_ov009_020dbb84 = action;
			scene->stateID = 3;
			data_ov009_020dbb80 = 1;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if ((u8)(previousButton + 0xff) <= 1)
				func_02011e3c(30);
			scene->stateID = 3;
			data_ov009_020dbb80 = 1;
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if (heldButtons & NDS_PAD_BUTTON_DOWN) {
				if (previousButton != 3)
					data_ov009_020dbb84++;
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) && previousButton != 0) {
				data_ov009_020dbb84--;
			}
		}
	}

	func_ov009_020ce7b4(scene, previousState, scene->stateID, previousButton,
		data_ov009_020dbb84, 30);
}

extern "C" void func_ov009_020d302c(MainMenuScene *scene)
{
	if (scene->buttonHitTimer < 4)
		scene->buttonHitTimer++;

	if (scene->buttonHitTimer >= 4) {
		scene->stateTimer = 0;
		scene->stateID = 4;
		scene->buttonAnimTimer = 0;
	}
}

extern "C" void func_ov009_020d3008(MainMenuScene *scene)
{
	if (scene->buttonHitTimer > 0) {
		scene->buttonHitTimer--;
	} else {
		scene->buttonAnimTimer = 10;
		scene->stateID = 5;
	}
}

extern "C" void func_ov009_020d2fec(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer > 0)
		scene->buttonAnimTimer--;
	else
		scene->stateID = 6;
}

extern "C" void func_ov009_020d2f2c(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		return;
	}

	switch (data_ov009_020dbb84) {
	case 0:
		scene->menuID = 1;
		scene->stateID = 0;
		scene->fileSelectCurrentButton = 0;
		func_ov009_020d2d74(scene);
		break;
	case 1:
		func_020131fc(6, 0);
		GlobalFader.func_02007bfc();
		break;
	case 2:
		func_020131fc(0x146, 0);
		GlobalFader.func_02007bfc();
		break;
	case 3:
		scene->menuID = 4;
		scene->stateID = 0;
		break;
	}
}

extern "C" void func_ov009_020d2e0c(MainMenuScene *scene)
{
	if ((data_ov009_020dbb98 & 1) == 0) {
		data_ov009_020dbc74[0] = data_ov009_020da634;
		data_ov009_020dbc74[1] = data_ov009_020da694;
		data_ov009_020dbc74[2] = data_ov009_020da9dc;
		data_ov009_020dbc74[3] = data_ov009_020da9d4;
		data_ov009_020dbc74[4] = data_ov009_020da9cc;
		data_ov009_020dbc74[5] = data_ov009_020da9c4;
		data_ov009_020dbc74[6] = data_ov009_020da9bc;
		data_ov009_020dbc74[7] = data_ov009_020da9b4;
		data_ov009_020dbb98 |= 1;
	}

	(scene->*data_ov009_020dbc74[scene->stateID].member)();
}

extern "C" void func_ov009_020d2d74(MainMenuScene *)
{
	NDS::Memory::clearFast(0xc0, 0x07000400, 0x400);
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_select_d_bnbl, false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_select_d_bncl, false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping1D32K();
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_UI_O_menu_select_o_d_ncg_bin,
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_d_2d_UI_O_menu_select_o_d_ncl_bin,
		(void *)0x05000600);
	func_ov000_020bd604();
}

extern "C" void func_ov009_020d2cd8(MainMenuScene *scene)
{
	if (!scene->buttonsVisible) {
		scene->buttonsTimer = 64;
		func_ov009_020ce744(scene);
		for (s32 fileID = 0; fileID < 3; fileID++)
			scene->fileSelectFileButtons[fileID].posX = 320;
	}

	scene->guiTimer = 64;
	scene->buttonHitTimer = 64;
	scene->button2Offset = 0;
	scene->button1Offset = 0;
	u32 value = 0;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->backButtonSelected = false;
	scene->backButtonHighlighted = false;
	scene->stateID = 1;
	scene->stateTimer = 16;
}

extern "C" void func_ov009_020d2c04(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 2;
		scene->guiTimer = 0;
		scene->buttonsVisible = false;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	scene->buttonHitTimer = scene->guiTimer;
	s32 zero = 0;
	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = zero;
	scene->label.buttonPositions[0].y = -guiTimer;
	if (scene->buttonsVisible)
		return;

	scene->buttonsTimer = scene->guiTimer;
	for (s32 fileID = 0; fileID < 3; fileID++) {
		scene->fileSelectFileButtons[fileID].posX =
			((scene->stateTimer - ((2 - fileID) * 2)) * 320) / 12;
		if (scene->fileSelectFileButtons[fileID].posX < 0)
			scene->fileSelectFileButtons[fileID].posX = zero;
	}
}

extern "C" void func_ov009_020d28ac(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousButton = scene->fileSelectCurrentButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (func_ov009_020ce6f0(scene) == 1) {
			scene->stateID = 3;
			scene->backButtonSelected = true;
			scene->backButtonHighlighted = true;
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 0:
			case 1:
			case 2:
				scene->fileSelectCurrentButton = action;
				scene->stateID = 3;
				func_02011e3c(30);
				func_02012398(0x111, 0);
				scene->buttonAnimTimer = 3;
				if ((data_02087650[Input::localConsoleID][0] &
						(NDS_PAD_BUTTON_L | NDS_PAD_BUTTON_R)) ==
					(NDS_PAD_BUTTON_L | NDS_PAD_BUTTON_R)) {
					Game::character = 1;
					func_02012398(0x100, 0);
				} else {
					Game::character = 0;
				}
				func_0204dad8(Game::character);
				return;
			case 3:
				if (func_ov009_020ce6c4(scene) == 1) {
					scene->fileSelectCurrentButton = 3;
					scene->stateID = 3;
				}
				break;
			case 4:
				if (func_ov009_020ce6c4(scene) == 1) {
					scene->fileSelectCurrentButton = 4;
					scene->stateID = 3;
				}
				break;
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			scene->stateID = 3;
			switch (scene->fileSelectCurrentButton) {
			case 0:
			case 1:
			case 2:
				func_02012398(0x111, 0);
				func_02011e3c(30);
				if ((data_02087650[Input::localConsoleID][0] &
						(NDS_PAD_BUTTON_L | NDS_PAD_BUTTON_R)) ==
					(NDS_PAD_BUTTON_L | NDS_PAD_BUTTON_R)) {
					Game::character = 1;
					func_02012398(0x100, 0);
				} else {
					Game::character = 0;
				}
				func_0204dad8(Game::character);
				break;
			default:
				func_02012398(0xe9, 0);
				break;
			}
			scene->buttonAnimTimer = 3;
			return;
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			scene->stateID = 3;
			scene->backButtonSelected = true;
			scene->backButtonHighlighted = true;
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousButton <= 2) {
				if (previousButton + 1 == 3 &&
					func_ov009_020ce6c4(scene) == 0)
					return;
				scene->fileSelectCurrentButton++;
			} else if ((heldButtons & NDS_PAD_BUTTON_RIGHT) &&
				previousButton == 3) {
				scene->fileSelectCurrentButton = 4;
			} else if ((heldButtons & NDS_PAD_BUTTON_LEFT) &&
				previousButton == 4) {
				scene->fileSelectCurrentButton = 3;
			} else if ((heldButtons & NDS_PAD_BUTTON_DOWN) &&
				previousButton < 2) {
				scene->fileSelectCurrentButton++;
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) &&
				previousButton != 0) {
				if (previousButton == 4)
					scene->fileSelectCurrentButton = 2;
				else
					scene->fileSelectCurrentButton--;
			}
		}
	}

	func_ov009_020ce7b4(scene, previousState, scene->stateID, previousButton,
		scene->fileSelectCurrentButton, 3);
}

extern "C" void func_ov009_020d2858(MainMenuScene *scene, s32 offset)
{
	if (scene->backButtonSelected == true) {
		scene->backButtonOffset = offset;
		return;
	}

	u8 buttonID = scene->fileSelectCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		scene->fileSelectFileButtons[buttonID].posX = offset;
		scene->fileSelectFileButtons[buttonID].posY = offset;
		break;
	case 3:
		scene->button1Offset = offset;
		break;
	case 4:
		scene->button2Offset = offset;
		break;
	}
}

extern "C" void func_ov009_020d2814(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 4;
		scene->buttonAnimTimer = 3;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d2858(scene, 3 - scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d278c(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 5;
		if (scene->backButtonSelected == true) {
			scene->buttonAnimTimer = 10;
		} else {
			u8 buttonID = scene->fileSelectCurrentButton;
			switch (buttonID) {
			case 0:
			case 1:
			case 2:
				scene->buttonAnimTimer = 68;
				break;
			default:
				scene->buttonAnimTimer = 10;
				break;
			}
		}
		scene->backButtonHighlighted = false;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d2858(scene, scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d2690(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		if (scene->backButtonSelected == true) {
			scene->stateID = 6;
			scene->stateTimer = 0;
			scene->backButtonSelected = false;
			scene->backButtonHighlighted = false;
			return;
		}

		switch (scene->fileSelectCurrentButton) {
		case 0:
		case 1:
		case 2:
			if (func_02012e08(scene->fileSelectCurrentButton, 0, &save) == 0)
				return;

			if ((scene->saves[scene->fileSelectCurrentButton].flags & Saved) == 0)
				func_020131fc(4, 1);
			else
				func_020131fc(func_02012934(), save.game.currentWorld);

			GlobalFader.enableMainScreenFading();
			GlobalFader.func_02007bfc();
			break;
		case 3:
			scene->stateID = 7;
			scene->stateTimer = 0;
			break;
		case 4:
			scene->stateID = 7;
			scene->stateTimer = 0;
			break;
		}
	} else {
		scene->buttonAnimTimer--;
	}
}

extern "C" void func_ov009_020d25bc(MainMenuScene *scene)
{
	if (scene->stateTimer < 16) {
		scene->stateTimer++;
		s32 fileID = 0;
		s32 delay = 0;
		for (; fileID < 3; fileID++) {
			scene->fileSelectFileButtons[fileID].posX =
				((scene->stateTimer - delay) * 320) / 12;
			delay += 2;
			if (scene->fileSelectFileButtons[fileID].posX < 0)
				scene->fileSelectFileButtons[fileID].posX = 0;
		}

		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonsTimer = scene->guiTimer;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->menuID = 0;
	scene->stateID = 0;
}

extern "C" void func_ov009_020d24ec(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	switch (scene->fileSelectCurrentButton) {
	case 3:
		scene->menuID = 2;
		scene->stateID = 0;
		func_ov009_020d21c0(scene);
		return;
	case 4:
		scene->menuID = 3;
		scene->stateID = 0;
		func_ov009_020d0b80(scene);
		return;
	default:
		scene->menuID = 2;
		scene->stateID = 0;
		func_ov009_020d21c0(scene);
		return;
	}
}

extern "C" void func_ov009_020d2288(MainMenuScene *scene)
{
	if ((data_ov009_020dbb8c & 1) == 0) {
		data_ov009_020dbda4[0] = data_ov009_020da99c;
		data_ov009_020dbda4[1] = data_ov009_020da93c;
		data_ov009_020dbda4[2] = data_ov009_020da94c;
		data_ov009_020dbda4[3] = data_ov009_020da984;
		data_ov009_020dbda4[4] = data_ov009_020da97c;
		data_ov009_020dbda4[5] = data_ov009_020da974;
		data_ov009_020dbda4[6] = data_ov009_020da77c;
		data_ov009_020dbda4[7] = data_ov009_020da964;
		data_ov009_020dbda4[8] = data_ov009_020da95c;
		data_ov009_020dbda4[9] = data_ov009_020da76c;
		data_ov009_020dbda4[10] = data_ov009_020da684;
		data_ov009_020dbda4[11] = data_ov009_020da944;
		data_ov009_020dbda4[12] = data_ov009_020da764;
		data_ov009_020dbda4[13] = data_ov009_020da934;
		data_ov009_020dbda4[14] = data_ov009_020da75c;
		data_ov009_020dbda4[15] = data_ov009_020da924;
		data_ov009_020dbda4[16] = data_ov009_020da754;
		data_ov009_020dbda4[17] = data_ov009_020da914;
		data_ov009_020dbda4[18] = data_ov009_020da74c;
		data_ov009_020dbda4[19] = data_ov009_020da904;
		data_ov009_020dbda4[20] = data_ov009_020da744;
		data_ov009_020dbb8c |= 1;
	}

	(scene->*data_ov009_020dbda4[scene->stateID].member)();
}

extern "C" void func_ov009_020d21c0(MainMenuScene *scene)
{
	scene->guiTimer = 64;
	scene->buttonHitTimer = 64;
	scene->button2Offset = 0;
	scene->button1Offset = 0;
	scene->fileSelectionCompleted = false;
	scene->unk7c = 0;
	scene->fileConfirmRequest = false;
	scene->stateTimer = 12;
	scene->copyingFile = false;

	u32 value = 1;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);

	s32 fileID = 0;
	for (; fileID < 3; fileID++) {
		if ((scene->saves[fileID].flags & Saved) != 0)
			break;
	}

	if (fileID == 3)
		scene->fileCopySourceFile = 0;
	else
		scene->fileCopySourceFile = fileID;

	for (fileID = 0; fileID < 3; fileID++)
		scene->fileButtonsTargetY[fileID] = 0;

	scene->stateID = 1;
	scene->stateTimer = 12;
}

extern "C" void func_ov009_020d2160(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 2;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020d1f64(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousFile = scene->fileCopySourceFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (func_ov009_020ce6f0(scene) == 1) {
			func_ov009_020d1f0c(scene);
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 0:
			case 1:
			case 2:
				if ((scene->saves[action].flags & Saved) != 0) {
					scene->fileCopySourceFile = action;
					func_ov009_020d1f3c(scene);
				}
				break;
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			func_ov009_020d1f3c(scene);
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			func_ov009_020d1f0c(scene);
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousFile < 2) {
				s32 nextFile = previousFile + 1;
				if ((scene->saves[nextFile].flags & Saved) != 0) {
					scene->fileCopySourceFile++;
				} else if (nextFile < 2 &&
					(scene->saves[previousFile + 2].flags & Saved) != 0) {
					scene->fileCopySourceFile += 2;
				}
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) && previousFile != 0) {
				s32 previousFileID = previousFile - 1;
				if ((scene->saves[previousFileID].flags & Saved) != 0) {
					scene->fileCopySourceFile--;
				} else if (previousFileID > 0 &&
					(scene->saves[previousFile - 2].flags & Saved) != 0) {
					scene->fileCopySourceFile -= 2;
				}
			}
		}
	}

	func_ov009_020ce7b4(scene, previousState, scene->stateID, previousFile,
		scene->fileCopySourceFile, 3);
}

extern "C" void func_ov009_020d1f3c(MainMenuScene *scene)
{
	scene->stateID = 13;
	scene->fileCopyCurrentButton = scene->fileCopySourceFile;
	scene->buttonAnimTimer = 3;
	scene->unk7c = 1;
	scene->fileCopyDestinationFile = 3;
}

extern "C" void func_ov009_020d1f0c(MainMenuScene *scene)
{
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 6;
	scene->unk66 = 16;
	scene->buttonAnimTimer = 3;
	scene->backButtonSelected = true;
	scene->backButtonHighlighted = true;
}

extern "C" void func_ov009_020d1e6c(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->stateID = 4;
	u32 value = 2;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->stateTimer = 12;
}

extern "C" void func_ov009_020d1dec(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 5;
		scene->guiTimer = 0;
		for (s32 fileID = 0; fileID < 3; fileID++) {
			if (fileID != scene->fileCopySourceFile) {
				scene->fileCopyDestinationFile = fileID;
				break;
			}
		}
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020d1c50(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousFile = scene->fileCopyDestinationFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (func_ov009_020ce6f0(scene) == 1) {
			func_ov009_020d1afc(scene);
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 1:
			case 2: {
				u32 destinationFiles =
					(u32)data_ov009_020d9620 + scene->fileCopySourceFile * 2;
				s32 destinationIndex = action - 1;
				scene->fileCopyDestinationFile =
					*(const u8 *)(destinationFiles + destinationIndex);
				func_ov009_020d1b2c(scene);
				break;
			}
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			func_ov009_020d1b2c(scene);
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			func_ov009_020d1afc(scene);
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) &&
				previousFile == data_ov009_020d9620[scene->fileCopySourceFile][0]) {
				scene->fileCopyDestinationFile =
					data_ov009_020d9621[scene->fileCopySourceFile * 2];
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) &&
				previousFile == data_ov009_020d9621[scene->fileCopySourceFile * 2]) {
				scene->fileCopyDestinationFile =
					data_ov009_020d9620[scene->fileCopySourceFile][0];
			}
		}
	}

	func_ov009_020ce7b4(scene, previousState, scene->stateID, previousFile,
		scene->fileCopyDestinationFile, 3);
}

extern "C" void func_ov009_020d1bb0(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 5;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
	scene->fileSelectFileButtons[scene->fileCopyIgnoredFile].posX =
		(scene->stateTimer * 320) / 12;
	scene->buttonsTimer = scene->guiTimer;
}

extern "C" void func_ov009_020d1b2c(MainMenuScene *scene)
{
	for (s32 fileID = 0; fileID < 3; fileID++) {
		if (fileID != scene->fileCopySourceFile && fileID != scene->fileCopyDestinationFile)
			scene->fileCopyIgnoredFile = fileID;
	}

	if ((scene->saves[scene->fileCopyDestinationFile].flags & Saved) == 0) {
		data_02088f30 = 0;
		App::startWritingSave();
	}

	scene->fileCopyCurrentButton = scene->fileCopyDestinationFile + 3;
	scene->buttonAnimTimer = 3;
	scene->stateID = 13;
}

extern "C" void func_ov009_020d1afc(MainMenuScene *scene)
{
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 6;
	scene->unk66 = 17;
	scene->buttonAnimTimer = 3;
	scene->backButtonSelected = true;
	scene->backButtonHighlighted = true;
}

extern "C" void func_ov009_020d1a94(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 8;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
	scene->buttonHitTimer = scene->guiTimer;
}

extern "C" void func_ov009_020d18bc(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousButton = scene->fileConfirmOperationButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 3:
			if (data_0208b4e8 >= 40)
				func_ov009_020d1864(scene);
			break;
		case 4:
			if (data_0208b4e8 <= 120)
				func_ov009_020d1864(scene);
			else if (data_0208b4e8 >= 136)
				func_ov009_020d1830(scene);
			break;
		case 5:
			func_ov009_020d1864(scene);
			break;
		case 6:
			func_ov009_020d1830(scene);
			break;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if (previousButton == 0)
				func_ov009_020d1864(scene);
			else
				func_ov009_020d1830(scene);
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			func_ov009_020d1830(scene);
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_RIGHT) && previousButton == 0)
				scene->fileConfirmOperationButton++;
			else if ((heldButtons & NDS_PAD_BUTTON_LEFT) && previousButton == 1)
				scene->fileConfirmOperationButton--;
		}
	}

	scene->buttonAnimTimer = 3;
	if (previousState != scene->stateID)
		return;

	func_ov009_020ce7b4(scene, previousState, previousState, previousButton,
		scene->fileConfirmOperationButton, 3);
}

extern "C" void func_ov009_020d1864(MainMenuScene *scene)
{
	data_02088f30 = 0;
	App::startWritingSave();
	scene->fileConfirmOperationButton = 0;
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 7;
	scene->buttonAnimTimer = 3;
	func_02012398(0xe9, 0);
}

extern "C" void func_ov009_020d1830(MainMenuScene *scene)
{
	scene->fileConfirmOperationButton = 1;
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 8;
	scene->buttonAnimTimer = 3;
	func_02012398(0xea, 0);
}

extern "C" void func_ov009_020d17b8(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 10;
		scene->guiTimer = 0;
		scene->buttonAnimTimer = 120;
		scene->copyingFile = true;
		scene->copyingFileAnimStopping = false;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020d16b0(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		if (func_02012e08(scene->fileCopySourceFile, 0, &save) == 0) {
			Scene::switchToCorruptedSave(17);
			scene->fileOperationFailed = true;
		}

		if (func_02012d98(scene->fileCopyDestinationFile, &save) != 1) {
			Scene::switchToCorruptedSave(17);
			scene->fileOperationFailed = true;
		}

		if (data_0203bd30 != 11) {
			scene->stateID = 11;
			func_ov009_020ce7a4(scene);
			if (data_0203bd30 == 11) {
				Scene::switchToCorruptedSave(17);
				scene->fileOperationFailed = true;
			}
		}

		scene->fileCopiedTimer = 24;
		App::finishWritingSave();
		data_02088f30 = 1;
		func_02012398(0x113, 0);
		return;
	}

	func_02012314(0x112, 0);
	scene->buttonAnimTimer--;
}

extern "C" void func_ov009_020d1568(MainMenuScene *scene)
{
	if (scene->fileCopiedTimer != 0) {
		scene->fileCopiedTimer--;
		if (scene->fileCopiedTimer > 12)
			scene->guiTimer = ((24 - scene->fileCopiedTimer) << 6) / 12;
		else
			scene->guiTimer = (scene->fileCopiedTimer << 6) / 12;

		if (scene->fileCopiedTimer == 12) {
			u32 value = 5;
			func_02017bc4(&scene->label, &value, 0, 0);
			scene->copyingFileAnimStopping = true;
		}

		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	if ((Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_A) == 0) {
		BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (!touchActive)
			return;
	}

	scene->stateID = 12;
	scene->copyingFile = false;
	scene->stateTimer = 0;
	func_02012398(0xe9, 0);
}

extern "C" void func_ov009_020d1490(MainMenuScene *scene)
{
	if (scene->stateTimer < 14) {
		scene->stateTimer++;
		scene->fileSelectFileButtons[scene->fileCopySourceFile].posX =
			(scene->stateTimer * 320) / 12;
		if (scene->stateTimer > 2) {
			scene->fileSelectFileButtons[scene->fileCopyDestinationFile].posX =
				((scene->stateTimer - 2) * 320) / 12;
		}

		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->fileConfirmRequest = false;
	scene->menuID = 1;
	scene->stateID = 0;
	scene->fileSelectCurrentButton = 0;
	func_ov009_020d2cd8(scene);
}

extern "C" void func_ov009_020d1408(MainMenuScene *scene, s32 offset)
{
	s32 buttonID = scene->fileCopyCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		scene->fileSelectFileButtons[buttonID].posX = offset;
		scene->fileSelectFileButtons[buttonID].posY = offset + scene->fileButtonsTargetY[buttonID];
		break;
	case 3:
	case 4:
	case 5: {
		s32 fileID = buttonID - 3;
		scene->fileSelectFileButtons[fileID].posX = offset;
		scene->fileSelectFileButtons[fileID].posY = offset + scene->fileButtonsTargetY[fileID];
		break;
	}
	case 6:
		scene->backButtonOffset = offset;
		break;
	case 7:
		scene->button1Offset = offset;
		break;
	case 8:
		scene->button2Offset = offset;
		break;
	}
}

extern "C" void func_ov009_020d13c4(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 14;
		scene->buttonAnimTimer = 3;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d1408(scene, 3 - scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d1378(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 15;
		scene->buttonAnimTimer = 10;
		scene->backButtonHighlighted = false;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d1408(scene, scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d11a4(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		switch (scene->fileCopyCurrentButton) {
		case 6:
			scene->backButtonSelected = false;
			scene->backButtonHighlighted = false;
			scene->stateID = scene->unk66;
			scene->stateTimer = 0;
			if (scene->stateID == 17) {
				scene->unk7c = 0;
				for (s32 fileID = 0; fileID < 3; fileID++) {
					if (scene->fileButtonsTargetY[fileID] != 0) {
						scene->fileSelectFileButtons[fileID].velY =
							scene->fileButtonsTargetY[fileID] / 12;
						scene->fileButtonsTargetY[fileID] = 0;
						if (scene->fileSelectFileButtons[fileID].velY < 0)
							scene->fileSelectFileButtons[fileID].velY =
								-scene->fileSelectFileButtons[fileID].velY;
					}
				}
			}
			break;
		case 0:
		case 1:
		case 2:
			scene->stateID = 3;
			scene->stateTimer = 0;
			switch (scene->fileCopyCurrentButton) {
			case 1:
				scene->fileButtonsTargetY[0] = 40;
				scene->fileSelectFileButtons[0].velY = 3;
				scene->fileButtonsTargetY[1] = -40;
				scene->fileSelectFileButtons[1].velY = 3;
				break;
			case 2:
				scene->fileButtonsTargetY[0] = 40;
				scene->fileSelectFileButtons[0].velY = 3;
				scene->fileButtonsTargetY[1] = 40;
				scene->fileSelectFileButtons[1].velY = 3;
				scene->fileButtonsTargetY[2] = -80;
				scene->fileSelectFileButtons[2].velY = 6;
				break;
			}
			break;
		case 3:
		case 4:
		case 5:
			scene->stateID = 18;
			scene->stateTimer = 0;
			break;
		case 7:
			scene->stateID = 19;
			scene->stateTimer = 0;
			break;
		case 8:
			scene->stateID = 20;
			scene->stateTimer = 0;
			if (scene->fileCopyIgnoredFile > scene->fileCopyDestinationFile) {
				scene->fileButtonsTargetY[scene->fileCopyDestinationFile] -= 40;
				scene->fileSelectFileButtons[scene->fileCopyDestinationFile].velY = 3;
			}
			break;
		}
	} else {
		scene->buttonAnimTimer--;
	}
}

extern "C" void func_ov009_020d1120(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->menuID = 1;
	scene->stateID = 0;
	scene->buttonsVisible = true;
	func_ov009_020d2cd8(scene);
}

extern "C" void func_ov009_020d10a8(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->stateID = 0;
	func_ov009_020d21c0(scene);
}

extern "C" void func_ov009_020d0f38(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonsTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		scene->fileSelectFileButtons[scene->fileCopyIgnoredFile].posX =
			(scene->stateTimer * 320) / 12;
		return;
	}

	scene->fileSelectionCompleted = true;
	scene->stateTimer = 12;
	scene->guiTimer = 64;
	if (scene->fileCopyIgnoredFile > scene->fileCopyDestinationFile) {
		scene->fileButtonsTargetY[scene->fileCopyDestinationFile] += 40;
		scene->fileSelectFileButtons[scene->fileCopyDestinationFile].velY = 3;
	}

	if ((scene->saves[scene->fileCopyDestinationFile].flags & Saved) != 0) {
		u32 value = 3;
		func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
		scene->stateID = 7;
		scene->fileConfirmOperationButton = 1;
		scene->fileConfirmRequest = true;
		scene->buttonHitTimer = scene->guiTimer;
		return;
	}

	u32 value = 4;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->stateID = 9;
}

extern "C" void func_ov009_020d0e94(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->fileConfirmRequest = false;
	u32 value = 4;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->stateID = 9;
}

extern "C" void func_ov009_020d0dd8(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->fileConfirmRequest = false;
	scene->guiTimer = 64;
	u32 value = 2;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->stateID = 6;
	scene->fileSelectionCompleted = false;
	scene->buttonsTimer = scene->guiTimer;
}

extern "C" void func_ov009_020d0c20(MainMenuScene *scene)
{
	if ((data_ov009_020dbb90 & 1) == 0) {
		data_ov009_020dbcb4[0] = data_ov009_020da8dc;
		data_ov009_020dbcb4[1] = data_ov009_020da8d4;
		data_ov009_020dbcb4[2] = data_ov009_020da8cc;
		data_ov009_020dbcb4[3] = data_ov009_020da8c4;
		data_ov009_020dbcb4[4] = data_ov009_020da8bc;
		data_ov009_020dbcb4[5] = data_ov009_020da8b4;
		data_ov009_020dbcb4[6] = data_ov009_020da8ac;
		data_ov009_020dbcb4[7] = data_ov009_020da8a4;
		data_ov009_020dbcb4[8] = data_ov009_020da89c;
		data_ov009_020dbcb4[9] = data_ov009_020da894;
		data_ov009_020dbcb4[10] = data_ov009_020da88c;
		data_ov009_020dbcb4[11] = data_ov009_020da884;
		data_ov009_020dbcb4[12] = data_ov009_020da87c;
		data_ov009_020dbcb4[13] = data_ov009_020da874;
		data_ov009_020dbb90 |= 1;
	}

	(scene->*data_ov009_020dbcb4[scene->stateID].member)();
}

extern "C" void func_ov009_020d0b80(MainMenuScene *scene)
{
	scene->guiTimer = 64;
	scene->buttonHitTimer = 64;
	scene->button2Offset = 0;
	scene->button1Offset = 0;
	scene->fileSelectionCompleted = false;
	scene->fileEraseSelected = 0;
	scene->fileConfirmRequest = false;
	u32 value = 6;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);

	s32 fileID = 0;
	for (; fileID < 3; fileID++) {
		if ((scene->saves[fileID].flags & Saved) != 0)
			break;
	}

	if (fileID == 3)
		scene->fileEraseFile = 0;
	else
		scene->fileEraseFile = fileID;

	scene->stateID = 1;
	scene->stateTimer = 12;
}

extern "C" void func_ov009_020d0b20(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 2;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020d0924(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousFile = scene->fileEraseFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (func_ov009_020ce6f0(scene) == 1) {
			func_ov009_020d08e0(scene);
		} else {
			s32 fileID =
				Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (fileID) {
			case 0:
			case 1:
			case 2:
				if (scene->saves[fileID].flags & Saved) {
					scene->fileEraseFile = fileID;
					func_ov009_020d0900(scene);
				}
				break;
			}
		}
	} else if (data_02087650[0][1] & NDS_PAD_BUTTON_A) {
		func_ov009_020d0900(scene);
	} else if (data_02087650[0][1] & NDS_PAD_BUTTON_B) {
		func_ov009_020d08e0(scene);
	} else {
		u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
		if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousFile < 2) {
			s32 nextFile = previousFile + 1;
			if (scene->saves[nextFile].flags & Saved) {
				scene->fileEraseFile++;
			} else if (nextFile < 2 &&
				(scene->saves[previousFile + 2].flags & Saved)) {
				scene->fileEraseFile += 2;
			}
		} else if ((heldButtons & NDS_PAD_BUTTON_UP) && previousFile != 0) {
			s32 nextFile = previousFile - 1;
			if (scene->saves[nextFile].flags & Saved) {
				scene->fileEraseFile--;
			} else if (nextFile > 0 &&
				(scene->saves[previousFile - 2].flags & Saved)) {
				scene->fileEraseFile -= 2;
			}
		}
	}

	func_ov009_020ce7b4(scene, previousState, scene->stateID, previousFile,
		scene->fileEraseFile, 3);
}

extern "C" void func_ov009_020d0900(MainMenuScene *scene)
{
	scene->fileEraseSelected = 1;
	scene->stateID = 3;
	scene->buttonAnimTimer = 3;
	scene->fileEraseCurrentButton = scene->fileEraseFile;
	scene->fileConfirmOperationButton = 1;
}

extern "C" void func_ov009_020d08e0(MainMenuScene *scene)
{
	scene->stateID = 3;
	scene->fileEraseCurrentButton = 3;
	scene->buttonAnimTimer = 3;
	scene->backButtonSelected = true;
	scene->backButtonHighlighted = true;
}

extern "C" void func_ov009_020d0700(MainMenuScene *scene)
{
	u8 previousState = scene->stateID;
	u8 previousButton = scene->fileConfirmOperationButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 3:
			if (data_0208b4e8 >= 40)
				func_ov009_020d06a4(scene);
			break;

		case 4:
			if (data_0208b4e8 <= 120)
				func_ov009_020d06a4(scene);
			else if (data_0208b4e8 >= 136)
				func_ov009_020d0674(scene);
			break;

		case 5:
			func_ov009_020d06a4(scene);
			break;

		case 6:
			func_ov009_020d0674(scene);
			break;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if (previousButton == 0)
				func_ov009_020d06a4(scene);
			else
				func_ov009_020d0674(scene);
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			scene->fileConfirmOperationButton = 1;
			func_ov009_020d0674(scene);
			return;
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_RIGHT) && previousButton == 0)
				scene->fileConfirmOperationButton++;
			else if ((heldButtons & NDS_PAD_BUTTON_LEFT) && previousButton == 1)
				scene->fileConfirmOperationButton--;
		}
	}

	if (previousState != scene->stateID)
		return;

	func_ov009_020ce7b4(scene, previousState, previousState, previousButton,
		scene->fileConfirmOperationButton, 120);
}

extern "C" void func_ov009_020d06a4(MainMenuScene *scene)
{
	scene->fileConfirmOperationButton = 0;
	data_02088f30 = 0;
	App::startWritingSave();
	scene->stateID = 3;
	scene->buttonAnimTimer = 3;
	scene->fileEraseCurrentButton = 4;
	scene->fileCopiedTimer = 24;
	func_02012398(0xe9, 0);
}

extern "C" void func_ov009_020d0674(MainMenuScene *scene)
{
	scene->fileConfirmOperationButton = 1;
	scene->stateID = 3;
	scene->buttonAnimTimer = 3;
	scene->fileEraseCurrentButton = 5;
	func_02012398(0xea, 0);
}

extern "C" void func_ov009_020d0624(MainMenuScene *scene, s32 offset)
{
	u8 buttonID = scene->fileEraseCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		scene->fileSelectFileButtons[buttonID].posX = offset;
		scene->fileSelectFileButtons[buttonID].posY = offset;
		break;
	case 3:
		scene->backButtonOffset = offset;
		break;
	case 4:
		scene->button1Offset = offset;
		break;
	case 5:
		scene->button2Offset = offset;
		break;
	}
}

extern "C" void func_ov009_020d054c(MainMenuScene *scene)
{
	if (scene->fileCopiedTimer != 0) {
		scene->fileCopiedTimer--;
		if (scene->fileCopiedTimer > 12) {
			scene->guiTimer = ((24 - scene->fileCopiedTimer) << 6) / 12;
			scene->buttonHitTimer = scene->guiTimer;
		} else {
			scene->guiTimer = (scene->fileCopiedTimer << 6) / 12;
		}

		if (scene->fileCopiedTimer == 12) {
			u32 value = 8;
			func_02017bc4(&scene->label, &value, 0, 0);
			scene->fileConfirmRequest = false;
		}

		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
	}

	func_02012314(0x114, 0);
}

extern "C" void func_ov009_020d0478(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		if (func_02012ee0(scene->fileEraseFile, &save) == 0) {
			Scene::switchToCorruptedSave(16);
			scene->fileOperationFailed = true;
		}

		if (data_0203bd30 != 11) {
			scene->stateID = 13;
			func_ov009_020ce7a4(scene);
			if (data_0203bd30 == 11) {
				Scene::switchToCorruptedSave(16);
				scene->fileOperationFailed = true;
			}
		}

		scene->fileCopiedTimer = 24;
		App::finishWritingSave();
		data_02088f30 = 1;
		func_02012398(0x115, 0);
	} else {
		func_ov009_020d054c(scene);
		scene->buttonAnimTimer--;
	}
}

extern "C" void func_ov009_020d0338(MainMenuScene *scene)
{
	if (scene->fileCopiedTimer != 0) {
		scene->fileCopiedTimer--;
		if (scene->fileCopiedTimer > 12)
			scene->guiTimer = ((24 - scene->fileCopiedTimer) << 6) / 12;
		else
			scene->guiTimer = (scene->fileCopiedTimer << 6) / 12;

		if (scene->fileCopiedTimer == 12) {
			u32 value = 9;
			func_02017bc4(&scene->label, &value, 0, 0);
		}

		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	if ((Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_A) == 0) {
		BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (!touchActive)
			return;
	}

	scene->stateID = 6;
	scene->stateTimer = 0;
	scene->fileSelectCurrentButton = 0;
	func_02012398(0xe9, 0);
}

extern "C" void func_ov009_020d02f4(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 4;
		scene->buttonAnimTimer = 3;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d0624(scene, 3 - scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d02a8(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 5;
		scene->buttonAnimTimer = 10;
		scene->backButtonHighlighted = false;
		return;
	}

	scene->buttonAnimTimer--;
	func_ov009_020d0624(scene, scene->buttonAnimTimer);
}

extern "C" void func_ov009_020d0210(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		switch (scene->fileEraseCurrentButton) {
		case 3:
			scene->backButtonSelected = false;
			scene->backButtonHighlighted = false;
			scene->stateID = 6;
			scene->stateTimer = 0;
			break;
		case 0:
		case 1:
		case 2:
			scene->stateID = 7;
			scene->stateTimer = 0;
			break;
		case 4:
			scene->stateID = 12;
			scene->buttonAnimTimer = 120;
			break;
		case 5:
			scene->stateID = 9;
			scene->stateTimer = 0;
			break;
		}
	} else {
		scene->buttonAnimTimer--;
	}
}

extern "C" void func_ov009_020d018c(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->menuID = 1;
	scene->stateID = 0;
	scene->buttonsVisible = true;
	func_ov009_020d2cd8(scene);
}

extern "C" void func_ov009_020d00cc(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonsTimer = scene->guiTimer;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->fileSelectionCompleted = true;
	scene->stateID = 8;
	u32 value = 7;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
	scene->stateTimer = 12;
	scene->fileConfirmRequest = true;
}

extern "C" void func_ov009_020d0064(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 11;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	scene->buttonHitTimer = scene->guiTimer;
	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020cffb4(MainMenuScene *scene)
{
	if (scene->stateTimer < 12) {
		scene->stateTimer++;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
		scene->buttonHitTimer = scene->guiTimer;
		s32 guiTimer = scene->guiTimer;
		scene->label.buttonPositions[0].x = 0;
		scene->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	scene->fileSelectionCompleted = false;
	scene->stateID = 10;
	scene->fileEraseSelected = 0;
	scene->fileConfirmRequest = false;
	scene->buttonHitTimer = scene->guiTimer;
	u32 value = 6;
	func_02017bc4(&scene->label, &value, 0, -scene->guiTimer);
}

extern "C" void func_ov009_020cff4c(MainMenuScene *scene)
{
	if (scene->stateTimer == 0) {
		scene->stateID = 2;
		scene->guiTimer = 0;
	} else {
		scene->stateTimer--;
		scene->guiTimer = (scene->stateTimer << 6) / 12;
	}

	scene->buttonsTimer = scene->guiTimer;
	s32 guiTimer = scene->guiTimer;
	scene->label.buttonPositions[0].x = 0;
	scene->label.buttonPositions[0].y = -guiTimer;
}

extern "C" void func_ov009_020cfe44(MainMenuScene *scene)
{
	if ((data_ov009_020dbb9c & 1) == 0) {
		data_ov009_020dbc04[0] = data_ov009_020da85c;
		data_ov009_020dbc04[1] = data_ov009_020da854;
		data_ov009_020dbc04[2] = data_ov009_020da84c;
		data_ov009_020dbc04[3] = data_ov009_020da844;
		data_ov009_020dbc04[4] = data_ov009_020da83c;
		data_ov009_020dbc04[5] = data_ov009_020da834;
		data_ov009_020dbc04[6] = data_ov009_020da82c;
		data_ov009_020dbb9c |= 1;
	}

	(scene->*data_ov009_020dbc04[scene->stateID].member)();
}

extern "C" void func_ov009_020cfd88(MainMenuScene *scene)
{
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_option_d_bnbl, false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FILE_ID_uiStudio_UI_O_menu_option_d_bncl, false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping1D32K();
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_UI_O_menu_option_o_d_ncg_bin,
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FILE_ID_uiStudio_d_2d_UI_O_menu_option_o_d_ncl_bin,
		(void *)0x05000600);

	scene->stateID = 1;
	scene->optionsCurrentButton = 0;
	scene->stateTimer = 15;
	scene->button2Offset = 80;
	scene->button1Offset = 320;
	scene->optionsOKButtonOffset = 80;
	scene->optionsOKButtonPosX = 0;
}

extern "C" void func_ov009_020cfcf0(MainMenuScene *scene)
{
	if (scene->stateTimer != 0) {
		scene->stateTimer--;
	} else {
		scene->stateID = 2;
		scene->button2Offset = 0;
	}

	if (scene->stateTimer < 3) {
		scene->button1Offset = 0;
		scene->button2Offset = (scene->stateTimer * 80) / 3;
	} else {
		scene->button1Offset = ((scene->stateTimer - 3) * 320) / 12;
	}

	scene->optionsOKButtonOffset = (scene->button1Offset + scene->button2Offset) >> 2;
}

extern "C" void func_ov009_020cf9e0(MainMenuScene *scene)
{
	s32 previousControlMode;
	s32 previousSoundMode = scene->soundMode;
	previousControlMode = scene->controlMode;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 0:
		case 3:
			scene->optionsCurrentButton = 0;
			if (scene->soundMode == 2)
				scene->soundMode = 0;
			else
				scene->soundMode++;
			func_02012398(0xe5, 0);
			break;

		case 2:
			scene->optionsCurrentButton = 0;
			if (scene->soundMode == 0)
				scene->soundMode = 2;
			else
				scene->soundMode--;
			func_02012398(0xe5, 0);
			break;

		case 1:
		case 4:
		case 5:
			scene->optionsCurrentButton = 1;
			scene->controlMode ^= 1;
			func_02012398(0xe5, 0);
			break;

		case 6:
			scene->optionsCurrentButton = 2;
			scene->stateID = 3;
			scene->buttonAnimTimer = 3;
			func_02012398(0xe9, 0);
			break;
		}
	} else {
		if (((data_02087650[0][1] & NDS_PAD_BUTTON_A) && scene->optionsCurrentButton == 2) ||
			(data_02087650[0][1] & NDS_PAD_BUTTON_B)) {
			scene->optionsCurrentButton = 2;
			scene->stateID = 3;
			scene->buttonAnimTimer = 3;
			if (data_02087650[0][1] & NDS_PAD_BUTTON_B)
				func_02012398(0xea, 0);
			else
				func_02012398(0xe9, 0);
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) || (heldButtons & NDS_PAD_BUTTON_A)) {
				if (scene->optionsCurrentButton < 2) {
					scene->optionsCurrentButton++;
					func_02012398(0xe5, 0);
				}
			} else if (heldButtons & NDS_PAD_BUTTON_UP) {
				if (scene->optionsCurrentButton != 0) {
					scene->optionsCurrentButton--;
					func_02012398(0xe5, 0);
				}
			} else if (heldButtons & NDS_PAD_BUTTON_LEFT) {
				if (scene->optionsCurrentButton == 0) {
					if (previousSoundMode == 0)
						scene->soundMode = 2;
					else
						scene->soundMode--;
				} else if (scene->optionsCurrentButton == 1) {
					scene->controlMode ^= 1;
				}
				if (scene->optionsCurrentButton != 2)
					func_02012398(0xe5, 0);
			} else if (heldButtons & NDS_PAD_BUTTON_RIGHT) {
				if (scene->optionsCurrentButton == 0) {
					if (previousSoundMode == 2)
						scene->soundMode = 0;
					else
						scene->soundMode++;
				} else if (scene->optionsCurrentButton == 1) {
					scene->controlMode ^= 1;
				}
				if (scene->optionsCurrentButton != 2)
					func_02012398(0xe5, 0);
			}
		}
	}

	if (scene->soundMode != previousSoundMode)
		func_02006444(scene->soundMode);

	if (scene->controlMode != previousControlMode) {
		data_02085ad4[0] = scene->controlMode;
		save.options.controlOptions = scene->controlMode;
	}
}

extern "C" void func_ov009_020cf9b0(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 4;
		scene->buttonAnimTimer = 3;
	} else {
		scene->buttonAnimTimer--;
		scene->optionsOKButtonPosX = 3 - scene->buttonAnimTimer;
	}
}

extern "C" void func_ov009_020cf984(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer == 0) {
		scene->stateID = 5;
		scene->buttonAnimTimer = 10;
	} else {
		scene->buttonAnimTimer--;
		scene->optionsOKButtonPosX = scene->buttonAnimTimer;
	}
}

extern "C" void func_ov009_020cf950(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer != 0) {
		scene->buttonAnimTimer--;
		return;
	}

	scene->stateID = 6;
	scene->stateTimer = 0;
	scene->button2Offset = 0;
	scene->button1Offset = 0;
	scene->optionsOKButtonOffset = 0;
}

extern "C" void func_ov009_020cf8a4(MainMenuScene *scene)
{
	if (scene->stateTimer < 15) {
		scene->stateTimer++;
		scene->button1Offset = (scene->stateTimer * 320) / 12;
		if (scene->stateTimer < 3)
			scene->button2Offset = -scene->button1Offset;
		else
			scene->button2Offset = -80;

		scene->optionsOKButtonOffset = (scene->button1Offset + scene->button2Offset) >> 2;
		return;
	}

	scene->menuID = 0;
	scene->stateID = 0;
	if (func_0201301c(&save.options) == 0) {
		Scene::switchToCorruptedSave(15);
		scene->fileOperationFailed = true;
	}
}

s32 MainMenuScene::onRender()
{
	if ((data_ov009_020dbb94 & 1) == 0) {
		data_ov009_020dbbb4[0] = data_ov009_020da66c;
		data_ov009_020dbbb4[1] = data_ov009_020da6bc;
		data_ov009_020dbbb4[2] = data_ov009_020da78c;
		data_ov009_020dbbb4[3] = data_ov009_020da7fc;
		data_ov009_020dbbb4[4] = data_ov009_020da7f4;
		data_ov009_020dbb94 |= 1;
	}
	(this->*data_ov009_020dbbb4[this->menuID].member)();
	func_ov009_020cd994(&cutscene);
	return true;
}

void MainMenuScene::onRender_0()
{
	if (stateID == 0)
		return;

	s32 titleOffset = -(stateTimer << 6) / 12;
	func_0200419c(0, (u32)&data_ov009_020db304, 0, 0, 0, 0, 0, 0, 0, 0, titleOffset);

	s32 menuOffset = stateTimer * 250 / 12;
	for (s32 buttonID = 0; buttonID < 4; buttonID++) {
		s32 palette;
		s32 position;
		if (buttonID == data_ov009_020dbb84) {
			u8 currentState = stateID;
			position = menuOffset + mainMenuButtons[buttonID].posX - buttonHitTimer * 2;
			palette = (u8)(currentState + 0xfd) <= 1;
		} else {
			palette = 2;
			position = mainMenuButtons[buttonID].posX + 24 + menuOffset;
		}

		func_0200419c(data_ov009_020daa24[buttonID], data_ov009_020daa34[buttonID],
			0, palette, 0, 0, 0, 0, 0, position, -4);
	}
}

void MainMenuScene::onRender_1()
{
	if (stateID != 0) {
		func_02018060(&label);
		i32 i = 0;
		do {
			i32 value = ::func_ov009_020ce944(this, i);
			::func_ov009_020ceaec(this, i, value);
			i += 1;
		} while (i <= 2);

		u8 palette = ::func_ov009_020ce8d8(this);
		func_0200419c(0x15, (u32)&data_ov009_020db914, 0, palette, 0, 0,
			0, 0, 0, button1Offset, buttonHitTimer + button1Offset);

		palette = ::func_ov009_020ce86c(this);
		func_0200419c(0x16, (u32)&data_ov009_020db854, 0, palette, 0, 0,
			0, 0, 0, button2Offset, buttonHitTimer + button2Offset);
		::func_ov009_020cea8c(this);
		::func_ov009_020cea44(this, 0);
	}
}

void MainMenuScene::onRender_2()
{
	func_02018060(&label);
	s32 zero = 0;
	for (s32 fileID = 2; fileID >= 0; fileID--) {
		if (fileButtonsTargetY[fileID] > fileSelectFileButtons[fileID].posY) {
			fileSelectFileButtons[fileID].posY += fileSelectFileButtons[fileID].velY;
			if (fileButtonsTargetY[fileID] < fileSelectFileButtons[fileID].posY) {
				fileSelectFileButtons[fileID].posY = fileButtonsTargetY[fileID];
				fileSelectFileButtons[fileID].velY = zero;
			}
		} else if (fileButtonsTargetY[fileID] < fileSelectFileButtons[fileID].posY) {
			fileSelectFileButtons[fileID].posY -= fileSelectFileButtons[fileID].velY;
			if (fileButtonsTargetY[fileID] > fileSelectFileButtons[fileID].posY) {
				fileSelectFileButtons[fileID].posY = fileButtonsTargetY[fileID];
				fileSelectFileButtons[fileID].velY = zero;
			}
		}

		s32 value = ::func_ov009_020ce944(this, fileID);
		::func_ov009_020ceaec(this, fileID, value);
	}

	if (fileConfirmRequest) {
		u8 palette = func_ov009_020ce824(this, 0);
		func_0200419c(0x17, (u32)&data_ov009_020db7f4, 0, palette, 0, 0, 0, 0, 0,
			button1Offset, buttonHitTimer + button1Offset);

		palette = func_ov009_020ce824(this, 1);
		func_0200419c(0x18, (u32)&data_ov009_020db8b4, 0, palette, 0, 0, 0, 0, 0,
			button2Offset, buttonHitTimer + button2Offset);
	}

	if (copyingFile) {
		if (copyingFileAnimStopping && copyingFileFrame == 0) {
			copyingFileFrame = 0;
		} else if ((FrameCounter & 3) == 0) {
			if (copyingFileFrame >= 5)
				copyingFileFrame = 0;
			else
				copyingFileFrame++;
		}

		func_0200419c(0x14, (u32)&data_ov009_020db64c, 0, copyingFileFrame,
			0, 0, 0, 0, 0, 0, 0);
	}

	if (stateID == 11 && fileCopiedTimer == 0)
		func_0200419c(1, (u32)&data_ov009_020db644, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (!fileSelectionCompleted)
		::func_ov009_020cea8c(this);

	::func_ov009_020cea44(this, 8);
}

void MainMenuScene::onRender_3()
{
	func_02018060(&label);
	for (s32 fileID = 0; fileID <= 2; fileID++) {
		s32 value = ::func_ov009_020ce944(this, fileID);
		::func_ov009_020ceaec(this, fileID, value);
	}

	if (fileConfirmRequest) {
		u8 palette = func_ov009_020ce824(this, 0);
		func_0200419c(0x17, (u32)&data_ov009_020db7f4, 0, palette, 0, 0, 0, 0, 0,
			button1Offset, buttonHitTimer + button1Offset);

		palette = func_ov009_020ce824(this, 1);
		func_0200419c(0x18, (u32)&data_ov009_020db8b4, 0, palette, 0, 0, 0, 0, 0,
			button2Offset, buttonHitTimer + button2Offset);
	}

	if (stateID == 13 && fileCopiedTimer == 0)
		func_0200419c(1, (u32)&data_ov009_020db644, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (!fileSelectionCompleted)
		::func_ov009_020cea8c(this);

	::func_ov009_020cea44(this, 4);
}

void MainMenuScene::onRender_4()
{
	if (stateID == 0)
		return;

	s32 soundButtonID;
	s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
	s32 soundOffset = button1Offset;
	u32 palette = optionsCurrentButton != 0;

	func_0200419c(2, (u32)&data_ov053_0216e3cc,
		0, palette, 0, 0, 0, 0, 0, soundOffset, 0);
	func_0200419c(data_ov009_020da9fc[soundMode], data_ov009_020daa08[soundMode],
		0, palette, 0, 0, 0, 0, 0, soundOffset, 0);
	func_0200419c(0, (u32)&data_ov053_0216e5c4,
		0, palette, 0, 0, 0, 0, 0, soundOffset, 0);

	for (soundButtonID = 0; soundButtonID < 2; soundButtonID++) {
		if ((soundButtonID == 0 && action == 2) ||
			(soundButtonID == 1 && action == 3) ||
			(optionsCurrentButton == 0 &&
				((soundButtonID == 0 &&
					 (data_02087650[Input::localConsoleID][0] & NDS_PAD_BUTTON_LEFT)) ||
					(soundButtonID == 1 &&
					 (data_02087650[Input::localConsoleID][0] & NDS_PAD_BUTTON_RIGHT))))) {
			palette = 1;
		} else {
			palette = optionsCurrentButton == 0 ? 0 : 2;
		}

		func_0200419c(data_ov009_020da80c[soundButtonID], data_ov009_020da81c[soundButtonID],
			0, palette, 0, 0, 0, 0, 0, soundOffset, 0);
	}

	s32 controlOffset = button1Offset + button2Offset;
	if (controlMode == 1)
		palette = optionsCurrentButton == 1 ? 0xfd : 0xff;
	else
		palette = optionsCurrentButton == 1 ? 0xfe : 0;

	func_0200419c(9, (u32)&data_ov053_0216e40c,
		0, palette, 0, 0, 0, 0, 0, controlOffset, 0);

	palette = optionsCurrentButton != 1;
	func_0200419c(6, (u32)&data_ov053_0216e49c,
		0, palette, 0, 0, 0, 0, 0, controlOffset, 0);

	for (s32 part = 0; part < 2; part++) {
		func_0200419c(data_ov009_020daa44[controlMode][part], data_ov009_020da8fc[part],
			0, palette, 0, 0, 0, 0, 0, controlOffset, 0);
	}

	func_0200419c(data_ov009_020da9ac[controlMode], data_ov009_020da92c[controlMode],
		0, palette, 0, 0, 0, 0, 0, controlOffset, 0);
	func_0200419c(1, (u32)&data_ov053_0216e674,
		0, palette, 0, 0, 0, 0, 0, controlOffset, 0);

	for (s32 buttonID = 0; buttonID < 2; buttonID++) {
		if ((buttonID == 0 && action == 4) ||
			(buttonID == 1 && action == 5) ||
			(optionsCurrentButton == 1 &&
				((buttonID == 0 &&
					 (data_02087650[Input::localConsoleID][0] & NDS_PAD_BUTTON_LEFT)) ||
					(buttonID == 1 &&
					 (data_02087650[Input::localConsoleID][0] & NDS_PAD_BUTTON_RIGHT))))) {
			palette = 1;
		} else {
			palette = optionsCurrentButton == 1 ? 0 : 2;
		}

		func_0200419c(data_ov009_020da954[buttonID], data_ov009_020da81c[buttonID],
			0, palette, 0, 0, 0, 0, 0, controlOffset, 0);
	}

	s32 okButtonPosX = optionsOKButtonPosX;
	if (optionsCurrentButton == 2)
		palette = (u8)(stateID + 0xfd) <= 1 ? 2 : 0;
	else
		palette = 1;

	func_0200419c(0x12, (u32)&data_ov053_0216e4cc,
		0, palette, 0, 0, 0, 0, 0,
		okButtonPosX, optionsOKButtonOffset + okButtonPosX);
}
