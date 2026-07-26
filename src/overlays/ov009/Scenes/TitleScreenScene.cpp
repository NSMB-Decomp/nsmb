#include "../../../Scenes/TitleScreenScene.hpp"
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
#include "../../../system/app.hpp"









// void (Object229::*data_ov099_02186614[4])() = {
//     Object229::func_ov099_021860f0,
//     Object229::func_ov099_02186080,
//     Object229::func_ov099_02186028,
//     Object229::func_ov099_02185fb4,
// };


u32 data_ov009_020db914;
u32 data_ov009_020db854;

void *TitleScreenScene::create()
{
	return new TitleScreenScene;
}

TitleScreenScene::TitleScreenScene()
{
}

TitleScreenScene::~TitleScreenScene()
{
}

s32 TitleScreenScene::onCreate()
{
	func_02010a84();
	func_0200f3d8();
	NDS::Graphics::setMainVisiblePlanes(0);
	cutscene.onCreate(this);

	if (settings == 1) {
		func_02007bd8(&GlobalFader);
		func_02011c84(data_ov009_020d9630, data_ov009_020d9628);
		func_02011e7c(0x6d, 0);
	} else {
		NDS::Graphics::setSubDisplayMode(0);
		NDS::Graphics::assignSubBackgroundBank(0x80);
		NDS::Graphics::assignSubObjectBank(0x100);
		loadMainMenuGraphics();
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
		menuID = TitleScreenPage_Main;
		stateID = TitleScreenState_Initialize;
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

s32 TitleScreenScene::onDestroy()
{
	if (settings == 0)
		func_020180a4(&label);

	cutscene.onDestroy();
	return true;
}

void TitleScreenScene::pendingDestroy()
{
	cutscene.pendingDestroy();
}

void TitleScreenScene::loadMainMenuGraphics()
{
	NDS::Memory::clearFast(0xc0, 0x07000400, 0x400);
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_title_d_bnbl), false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_title_d_bncl), false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping2D();
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_UI_O_menu_title_o_d_ncg_bin),
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_d_2d_UI_O_menu_title_o_d_ncl_bin),
		(void *)0x05000600);
}

s32 TitleScreenScene::onUpdate()
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

	cutscene.onUpdate();
	return true;
}

void TitleScreenScene::updateMainMenu()
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

	(this->*data_ov009_020dbc3c[this->stateID].member)();
}

void TitleScreenScene::initializeMainMenu()
{
	loadMainMenuGraphics();
	reloadSaveData();
	this->stateID = TitleScreenState_WaitForFade;
	this->stateTimer = 12;
	this->buttonHitTimer = 0;
}

void TitleScreenScene::waitForMainMenuFade()
{
	BOOL fading = (u8)(GlobalFader.fadingState[0] & 0x49) != 0 ||
		(u8)(GlobalFader.fadingState[1] & 0x49) != 0;
	if (fading)
		return;

	if (this->stateTimer != 0) {
		this->stateTimer--;
	} else {
		this->stateID = TitleScreenState_SelectButton;
		data_ov009_020dbb80 = 0;
	}
}

void TitleScreenScene::selectMainMenuButton()
{
	u8 previousState = this->stateID;
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
			this->stateID = TitleScreenState_PressButton;
			data_ov009_020dbb80 = 1;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if ((u8)(previousButton + 0xff) <= 1)
				func_02011e3c(30);
			this->stateID = TitleScreenState_PressButton;
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

	updateSelectionFeedback(previousState, this->stateID, previousButton,
		data_ov009_020dbb84, 30);
}

void TitleScreenScene::pressMainMenuButton()
{
	if (this->buttonHitTimer < 4)
		this->buttonHitTimer++;

	if (this->buttonHitTimer >= 4) {
		this->stateTimer = 0;
		this->stateID = TitleScreenState_ReleaseButton;
		this->buttonAnimTimer = 0;
	}
}

void TitleScreenScene::releaseMainMenuButton()
{
	if (this->buttonHitTimer > 0) {
		this->buttonHitTimer--;
	} else {
		this->buttonAnimTimer = 10;
		this->stateID = TitleScreenState_WaitAfterSelection;
	}
}

void TitleScreenScene::waitAfterMainMenuSelection()
{
	if (this->buttonAnimTimer > 0)
		this->buttonAnimTimer--;
	else
		this->stateID = TitleScreenState_ExecuteSelection;
}

void TitleScreenScene::executeMainMenuSelection()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		return;
	}

	switch (data_ov009_020dbb84) {
	case 0:
		this->menuID = TitleScreenPage_FileSelect;
		this->stateID = FileSelectState_Initialize;
		this->fileSelectCurrentButton = 0;
		loadFileSelectGraphics();
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
		this->menuID = TitleScreenPage_Options;
		this->stateID = OptionsState_Initialize;
		break;
	}
}

void TitleScreenScene::updateFileSelect()
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

	(this->*data_ov009_020dbc74[this->stateID].member)();
}

void TitleScreenScene::loadFileSelectGraphics()
{
	NDS::Memory::clearFast(0xc0, 0x07000400, 0x400);
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_select_d_bnbl), false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_select_d_bncl), false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping1D32K();
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_UI_O_menu_select_o_d_ncg_bin),
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_d_2d_UI_O_menu_select_o_d_ncl_bin),
		(void *)0x05000600);
	func_ov000_020bd604();
}

void TitleScreenScene::initializeFileSelect()
{
	if (!this->buttonsVisible) {
		this->buttonsTimer = 64;
		resetFileSelectButtons();
		for (s32 fileID = 0; fileID < 3; fileID++)
			this->fileSelectFileButtons[fileID].posX = 320;
	}

	this->guiTimer = 64;
	this->buttonHitTimer = 64;
	this->button2Offset = 0;
	this->button1Offset = 0;
	u32 value = 0;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->backButtonSelected = false;
	this->backButtonHighlighted = false;
	this->stateID = FileSelectState_Enter;
	this->stateTimer = 16;
}

void TitleScreenScene::enterFileSelect()
{
	if (this->stateTimer == 0) {
		this->stateID = FileSelectState_SelectButton;
		this->guiTimer = 0;
		this->buttonsVisible = false;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	this->buttonHitTimer = this->guiTimer;
	s32 zero = 0;
	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = zero;
	this->label.buttonPositions[0].y = -guiTimer;
	if (this->buttonsVisible)
		return;

	this->buttonsTimer = this->guiTimer;
	for (s32 fileID = 0; fileID < 3; fileID++) {
		this->fileSelectFileButtons[fileID].posX =
			((this->stateTimer - ((2 - fileID) * 2)) * 320) / 12;
		if (this->fileSelectFileButtons[fileID].posX < 0)
			this->fileSelectFileButtons[fileID].posX = zero;
	}
}

void TitleScreenScene::selectFile()
{
	u8 previousState = this->stateID;
	u8 previousButton = this->fileSelectCurrentButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (isBackButtonTouched() == 1) {
			this->stateID = FileSelectState_PressButton;
			this->backButtonSelected = true;
			this->backButtonHighlighted = true;
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 0:
			case 1:
			case 2:
				this->fileSelectCurrentButton = action;
				this->stateID = FileSelectState_PressButton;
				func_02011e3c(30);
				func_02012398(0x111, 0);
				this->buttonAnimTimer = 3;
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
				if (hasSavedFile() == 1) {
					this->fileSelectCurrentButton = 3;
					this->stateID = FileSelectState_PressButton;
				}
				break;
			case 4:
				if (hasSavedFile() == 1) {
					this->fileSelectCurrentButton = 4;
					this->stateID = FileSelectState_PressButton;
				}
				break;
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			this->stateID = FileSelectState_PressButton;
			switch (this->fileSelectCurrentButton) {
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
			this->buttonAnimTimer = 3;
			return;
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			this->stateID = FileSelectState_PressButton;
			this->backButtonSelected = true;
			this->backButtonHighlighted = true;
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousButton <= 2) {
				if (previousButton + 1 == 3 &&
					hasSavedFile() == 0)
					return;
				this->fileSelectCurrentButton++;
			} else if ((heldButtons & NDS_PAD_BUTTON_RIGHT) &&
				previousButton == 3) {
				this->fileSelectCurrentButton = 4;
			} else if ((heldButtons & NDS_PAD_BUTTON_LEFT) &&
				previousButton == 4) {
				this->fileSelectCurrentButton = 3;
			} else if ((heldButtons & NDS_PAD_BUTTON_DOWN) &&
				previousButton < 2) {
				this->fileSelectCurrentButton++;
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) &&
				previousButton != 0) {
				if (previousButton == 4)
					this->fileSelectCurrentButton = 2;
				else
					this->fileSelectCurrentButton--;
			}
		}
	}

	updateSelectionFeedback(previousState, this->stateID, previousButton,
		this->fileSelectCurrentButton, 3);
}

void TitleScreenScene::setFileSelectButtonOffset(s32 offset)
{
	if (this->backButtonSelected == true) {
		this->backButtonOffset = offset;
		return;
	}

	u8 buttonID = this->fileSelectCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		this->fileSelectFileButtons[buttonID].posX = offset;
		this->fileSelectFileButtons[buttonID].posY = offset;
		break;
	case 3:
		this->button1Offset = offset;
		break;
	case 4:
		this->button2Offset = offset;
		break;
	}
}

void TitleScreenScene::pressFileSelectButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileSelectState_ReleaseButton;
		this->buttonAnimTimer = 3;
		return;
	}

	this->buttonAnimTimer--;
	setFileSelectButtonOffset(3 - this->buttonAnimTimer);
}

void TitleScreenScene::releaseFileSelectButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileSelectState_ExecuteSelection;
		if (this->backButtonSelected == true) {
			this->buttonAnimTimer = 10;
		} else {
			u8 buttonID = this->fileSelectCurrentButton;
			switch (buttonID) {
			case 0:
			case 1:
			case 2:
				this->buttonAnimTimer = 68;
				break;
			default:
				this->buttonAnimTimer = 10;
				break;
			}
		}
		this->backButtonHighlighted = false;
		return;
	}

	this->buttonAnimTimer--;
	setFileSelectButtonOffset(this->buttonAnimTimer);
}

void TitleScreenScene::executeFileSelectSelection()
{
	if (this->buttonAnimTimer == 0) {
		if (this->backButtonSelected == true) {
			this->stateID = FileSelectState_ExitToMainMenu;
			this->stateTimer = 0;
			this->backButtonSelected = false;
			this->backButtonHighlighted = false;
			return;
		}

		switch (this->fileSelectCurrentButton) {
		case 0:
		case 1:
		case 2:
			if (func_02012e08(this->fileSelectCurrentButton, 0, &save) == 0)
				return;

			if ((this->saves[this->fileSelectCurrentButton].flags & Saved) == 0)
				func_020131fc(4, 1);
			else
				func_020131fc(func_02012934(), save.game.currentWorld);

			GlobalFader.enableMainScreenFading();
			GlobalFader.func_02007bfc();
			break;
		case 3:
			this->stateID = FileSelectState_ExitToFileOperation;
			this->stateTimer = 0;
			break;
		case 4:
			this->stateID = FileSelectState_ExitToFileOperation;
			this->stateTimer = 0;
			break;
		}
	} else {
		this->buttonAnimTimer--;
	}
}

void TitleScreenScene::exitFileSelectToMainMenu()
{
	if (this->stateTimer < 16) {
		this->stateTimer++;
		s32 fileID = 0;
		s32 delay = 0;
		for (; fileID < 3; fileID++) {
			this->fileSelectFileButtons[fileID].posX =
				((this->stateTimer - delay) * 320) / 12;
			delay += 2;
			if (this->fileSelectFileButtons[fileID].posX < 0)
				this->fileSelectFileButtons[fileID].posX = 0;
		}

		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonsTimer = this->guiTimer;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->menuID = TitleScreenPage_Main;
	this->stateID = TitleScreenState_Initialize;
}

void TitleScreenScene::exitFileSelectToOperation()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	switch (this->fileSelectCurrentButton) {
	case 3:
		this->menuID = TitleScreenPage_FileCopy;
		this->stateID = FileCopyState_Initialize;
		initializeFileCopy();
		return;
	case 4:
		this->menuID = TitleScreenPage_FileErase;
		this->stateID = FileEraseState_Initialize;
		initializeFileErase();
		return;
	default:
		this->menuID = TitleScreenPage_FileCopy;
		this->stateID = FileCopyState_Initialize;
		initializeFileCopy();
		return;
	}
}

void TitleScreenScene::updateFileCopy()
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

	(this->*data_ov009_020dbda4[this->stateID].member)();
}

void TitleScreenScene::initializeFileCopy()
{
	this->guiTimer = 64;
	this->buttonHitTimer = 64;
	this->button2Offset = 0;
	this->button1Offset = 0;
	this->fileSelectionCompleted = false;
	this->unk7c = 0;
	this->fileConfirmRequest = false;
	this->stateTimer = 12;
	this->copyingFile = false;

	u32 value = 1;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);

	s32 fileID = 0;
	for (; fileID < 3; fileID++) {
		if ((this->saves[fileID].flags & Saved) != 0)
			break;
	}

	if (fileID == 3)
		this->fileCopySourceFile = 0;
	else
		this->fileCopySourceFile = fileID;

	for (fileID = 0; fileID < 3; fileID++)
		this->fileButtonsTargetY[fileID] = 0;

	this->stateID = FileCopyState_Enter;
	this->stateTimer = 12;
}

void TitleScreenScene::enterFileCopy()
{
	if (this->stateTimer == 0) {
		this->stateID = FileCopyState_SelectSource;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::selectFileCopySource()
{
	u8 previousState = this->stateID;
	u8 previousFile = this->fileCopySourceFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (isBackButtonTouched() == 1) {
			cancelFileCopySource();
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 0:
			case 1:
			case 2:
				if ((this->saves[action].flags & Saved) != 0) {
					this->fileCopySourceFile = action;
					confirmFileCopySource();
				}
				break;
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			confirmFileCopySource();
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			cancelFileCopySource();
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousFile < 2) {
				s32 nextFile = previousFile + 1;
				if ((this->saves[nextFile].flags & Saved) != 0) {
					this->fileCopySourceFile++;
				} else if (nextFile < 2 &&
					(this->saves[previousFile + 2].flags & Saved) != 0) {
					this->fileCopySourceFile += 2;
				}
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) && previousFile != 0) {
				s32 previousFileID = previousFile - 1;
				if ((this->saves[previousFileID].flags & Saved) != 0) {
					this->fileCopySourceFile--;
				} else if (previousFileID > 0 &&
					(this->saves[previousFile - 2].flags & Saved) != 0) {
					this->fileCopySourceFile -= 2;
				}
			}
		}
	}

	updateSelectionFeedback(previousState, this->stateID, previousFile,
		this->fileCopySourceFile, 3);
}

void TitleScreenScene::confirmFileCopySource()
{
	this->stateID = FileCopyState_PressButton;
	this->fileCopyCurrentButton = this->fileCopySourceFile;
	this->buttonAnimTimer = 3;
	this->unk7c = 1;
	this->fileCopyDestinationFile = 3;
}

void TitleScreenScene::cancelFileCopySource()
{
	this->stateID = FileCopyState_PressButton;
	this->fileCopyCurrentButton = 6;
	this->fileCopyReturnState = FileCopyState_ExitToFileSelect;
	this->buttonAnimTimer = 3;
	this->backButtonSelected = true;
	this->backButtonHighlighted = true;
}

void TitleScreenScene::hideFileCopySourcePrompt()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->stateID = FileCopyState_ShowDestinationPrompt;
	u32 value = 2;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->stateTimer = 12;
}

void TitleScreenScene::showFileCopyDestinationPrompt()
{
	if (this->stateTimer == 0) {
		this->stateID = FileCopyState_SelectDestination;
		this->guiTimer = 0;
		for (s32 fileID = 0; fileID < 3; fileID++) {
			if (fileID != this->fileCopySourceFile) {
				this->fileCopyDestinationFile = fileID;
				break;
			}
		}
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::selectFileCopyDestination()
{
	u8 previousState = this->stateID;
	u8 previousFile = this->fileCopyDestinationFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (isBackButtonTouched() == 1) {
			cancelFileCopyDestination();
		} else {
			s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (action) {
			case 1:
			case 2: {
				u32 destinationFiles =
					(u32)data_ov009_020d9620 + this->fileCopySourceFile * 2;
				s32 destinationIndex = action - 1;
				this->fileCopyDestinationFile =
					*(const u8 *)(destinationFiles + destinationIndex);
				confirmFileCopyDestination();
				break;
			}
			}
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			confirmFileCopyDestination();
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			cancelFileCopyDestination();
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) &&
				previousFile == data_ov009_020d9620[this->fileCopySourceFile][0]) {
				this->fileCopyDestinationFile =
					data_ov009_020d9621[this->fileCopySourceFile * 2];
			} else if ((heldButtons & NDS_PAD_BUTTON_UP) &&
				previousFile == data_ov009_020d9621[this->fileCopySourceFile * 2]) {
				this->fileCopyDestinationFile =
					data_ov009_020d9620[this->fileCopySourceFile][0];
			}
		}
	}

	updateSelectionFeedback(previousState, this->stateID, previousFile,
		this->fileCopyDestinationFile, 3);
}

void TitleScreenScene::restoreFileCopyDestinationSelection()
{
	if (this->stateTimer == 0) {
		this->stateID = FileCopyState_SelectDestination;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
	this->fileSelectFileButtons[this->fileCopyIgnoredFile].posX =
		(this->stateTimer * 320) / 12;
	this->buttonsTimer = this->guiTimer;
}

void TitleScreenScene::confirmFileCopyDestination()
{
	for (s32 fileID = 0; fileID < 3; fileID++) {
		if (fileID != this->fileCopySourceFile && fileID != this->fileCopyDestinationFile)
			this->fileCopyIgnoredFile = fileID;
	}

	if ((this->saves[this->fileCopyDestinationFile].flags & Saved) == 0) {
		data_02088f30 = 0;
		App::startWritingSave();
	}

	this->fileCopyCurrentButton = this->fileCopyDestinationFile + 3;
	this->buttonAnimTimer = 3;
	this->stateID = FileCopyState_PressButton;
}

void TitleScreenScene::cancelFileCopyDestination()
{
	this->stateID = FileCopyState_PressButton;
	this->fileCopyCurrentButton = 6;
	this->fileCopyReturnState = FileCopyState_ReturnToSourceSelect;
	this->buttonAnimTimer = 3;
	this->backButtonSelected = true;
	this->backButtonHighlighted = true;
}

void TitleScreenScene::showFileCopyOverwriteConfirmation()
{
	if (this->stateTimer == 0) {
		this->stateID = FileCopyState_ConfirmOverwrite;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
	this->buttonHitTimer = this->guiTimer;
}

void TitleScreenScene::selectFileCopyOverwriteResponse()
{
	u8 previousState = this->stateID;
	u8 previousButton = this->fileConfirmOperationButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 3:
			if (data_0208b4e8 >= 40)
				selectFileCopyOverwriteYes();
			break;
		case 4:
			if (data_0208b4e8 <= 120)
				selectFileCopyOverwriteYes();
			else if (data_0208b4e8 >= 136)
				selectFileCopyOverwriteNo();
			break;
		case 5:
			selectFileCopyOverwriteYes();
			break;
		case 6:
			selectFileCopyOverwriteNo();
			break;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if (previousButton == 0)
				selectFileCopyOverwriteYes();
			else
				selectFileCopyOverwriteNo();
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			selectFileCopyOverwriteNo();
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_RIGHT) && previousButton == 0)
				this->fileConfirmOperationButton++;
			else if ((heldButtons & NDS_PAD_BUTTON_LEFT) && previousButton == 1)
				this->fileConfirmOperationButton--;
		}
	}

	this->buttonAnimTimer = 3;
	if (previousState != this->stateID)
		return;

	updateSelectionFeedback(previousState, previousState, previousButton,
		this->fileConfirmOperationButton, 3);
}

void TitleScreenScene::selectFileCopyOverwriteYes()
{
	data_02088f30 = 0;
	App::startWritingSave();
	this->fileConfirmOperationButton = 0;
	this->stateID = FileCopyState_PressButton;
	this->fileCopyCurrentButton = 7;
	this->buttonAnimTimer = 3;
	func_02012398(0xe9, 0);
}

void TitleScreenScene::selectFileCopyOverwriteNo()
{
	this->fileConfirmOperationButton = 1;
	this->stateID = FileCopyState_PressButton;
	this->fileCopyCurrentButton = 8;
	this->buttonAnimTimer = 3;
	func_02012398(0xea, 0);
}

void TitleScreenScene::showFileCopyingPrompt()
{
	if (this->stateTimer == 0) {
		this->stateID = FileCopyState_CopyFile;
		this->guiTimer = 0;
		this->buttonAnimTimer = 120;
		this->copyingFile = true;
		this->copyingFileAnimStopping = false;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::copyFile()
{
	if (this->buttonAnimTimer == 0) {
		if (func_02012e08(this->fileCopySourceFile, 0, &save) == 0) {
			Scene::switchToCorruptedSave(17);
			this->fileOperationFailed = true;
		}

		if (func_02012d98(this->fileCopyDestinationFile, &save) != 1) {
			Scene::switchToCorruptedSave(17);
			this->fileOperationFailed = true;
		}

		if (data_0203bd30 != 11) {
			this->stateID = FileCopyState_CopyComplete;
			reloadSaveData();
			if (data_0203bd30 == 11) {
				Scene::switchToCorruptedSave(17);
				this->fileOperationFailed = true;
			}
		}

		this->fileCopiedTimer = 24;
		App::finishWritingSave();
		data_02088f30 = 1;
		func_02012398(0x113, 0);
		return;
	}

	func_02012314(0x112, 0);
	this->buttonAnimTimer--;
}

void TitleScreenScene::waitForFileCopyAcknowledgement()
{
	if (this->fileCopiedTimer != 0) {
		this->fileCopiedTimer--;
		if (this->fileCopiedTimer > 12)
			this->guiTimer = ((24 - this->fileCopiedTimer) << 6) / 12;
		else
			this->guiTimer = (this->fileCopiedTimer << 6) / 12;

		if (this->fileCopiedTimer == 12) {
			u32 value = 5;
			func_02017bc4(&this->label, &value, 0, 0);
			this->copyingFileAnimStopping = true;
		}

		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	if ((Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_A) == 0) {
		BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (!touchActive)
			return;
	}

	this->stateID = FileCopyState_ExitAfterCopy;
	this->copyingFile = false;
	this->stateTimer = 0;
	func_02012398(0xe9, 0);
}

void TitleScreenScene::exitFileCopyAfterCopy()
{
	if (this->stateTimer < 14) {
		this->stateTimer++;
		this->fileSelectFileButtons[this->fileCopySourceFile].posX =
			(this->stateTimer * 320) / 12;
		if (this->stateTimer > 2) {
			this->fileSelectFileButtons[this->fileCopyDestinationFile].posX =
				((this->stateTimer - 2) * 320) / 12;
		}

		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->fileConfirmRequest = false;
	this->menuID = TitleScreenPage_FileSelect;
	this->stateID = FileSelectState_Initialize;
	this->fileSelectCurrentButton = 0;
	initializeFileSelect();
}

void TitleScreenScene::setFileCopyButtonOffset(s32 offset)
{
	s32 buttonID = this->fileCopyCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		this->fileSelectFileButtons[buttonID].posX = offset;
		this->fileSelectFileButtons[buttonID].posY = offset + this->fileButtonsTargetY[buttonID];
		break;
	case 3:
	case 4:
	case 5: {
		s32 fileID = buttonID - 3;
		this->fileSelectFileButtons[fileID].posX = offset;
		this->fileSelectFileButtons[fileID].posY = offset + this->fileButtonsTargetY[fileID];
		break;
	}
	case 6:
		this->backButtonOffset = offset;
		break;
	case 7:
		this->button1Offset = offset;
		break;
	case 8:
		this->button2Offset = offset;
		break;
	}
}

void TitleScreenScene::pressFileCopyButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileCopyState_ReleaseButton;
		this->buttonAnimTimer = 3;
		return;
	}

	this->buttonAnimTimer--;
	setFileCopyButtonOffset(3 - this->buttonAnimTimer);
}

void TitleScreenScene::releaseFileCopyButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileCopyState_ExecuteSelection;
		this->buttonAnimTimer = 10;
		this->backButtonHighlighted = false;
		return;
	}

	this->buttonAnimTimer--;
	setFileCopyButtonOffset(this->buttonAnimTimer);
}

void TitleScreenScene::executeFileCopySelection()
{
	if (this->buttonAnimTimer == 0) {
		switch (this->fileCopyCurrentButton) {
		case 6:
			this->backButtonSelected = false;
			this->backButtonHighlighted = false;
			this->stateID = this->fileCopyReturnState;
			this->stateTimer = 0;
			if (this->stateID == FileCopyState_ReturnToSourceSelect) {
				this->unk7c = 0;
				for (s32 fileID = 0; fileID < 3; fileID++) {
					if (this->fileButtonsTargetY[fileID] != 0) {
						this->fileSelectFileButtons[fileID].velY =
							this->fileButtonsTargetY[fileID] / 12;
						this->fileButtonsTargetY[fileID] = 0;
						if (this->fileSelectFileButtons[fileID].velY < 0)
							this->fileSelectFileButtons[fileID].velY =
								-this->fileSelectFileButtons[fileID].velY;
					}
				}
			}
			break;
		case 0:
		case 1:
		case 2:
			this->stateID = FileCopyState_HideSourcePrompt;
			this->stateTimer = 0;
			switch (this->fileCopyCurrentButton) {
			case 1:
				this->fileButtonsTargetY[0] = 40;
				this->fileSelectFileButtons[0].velY = 3;
				this->fileButtonsTargetY[1] = -40;
				this->fileSelectFileButtons[1].velY = 3;
				break;
			case 2:
				this->fileButtonsTargetY[0] = 40;
				this->fileSelectFileButtons[0].velY = 3;
				this->fileButtonsTargetY[1] = 40;
				this->fileSelectFileButtons[1].velY = 3;
				this->fileButtonsTargetY[2] = -80;
				this->fileSelectFileButtons[2].velY = 6;
				break;
			}
			break;
		case 3:
		case 4:
		case 5:
			this->stateID = FileCopyState_FinalizeDestinationSelection;
			this->stateTimer = 0;
			break;
		case 7:
			this->stateID = FileCopyState_AcceptOverwrite;
			this->stateTimer = 0;
			break;
		case 8:
			this->stateID = FileCopyState_DeclineOverwrite;
			this->stateTimer = 0;
			if (this->fileCopyIgnoredFile > this->fileCopyDestinationFile) {
				this->fileButtonsTargetY[this->fileCopyDestinationFile] -= 40;
				this->fileSelectFileButtons[this->fileCopyDestinationFile].velY = 3;
			}
			break;
		}
	} else {
		this->buttonAnimTimer--;
	}
}

void TitleScreenScene::exitFileCopyToFileSelect()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->menuID = TitleScreenPage_FileSelect;
	this->stateID = FileSelectState_Initialize;
	this->buttonsVisible = true;
	initializeFileSelect();
}

void TitleScreenScene::returnFileCopyToSourceSelect()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->stateID = FileCopyState_Initialize;
	initializeFileCopy();
}

void TitleScreenScene::finalizeFileCopyDestination()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonsTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		this->fileSelectFileButtons[this->fileCopyIgnoredFile].posX =
			(this->stateTimer * 320) / 12;
		return;
	}

	this->fileSelectionCompleted = true;
	this->stateTimer = 12;
	this->guiTimer = 64;
	if (this->fileCopyIgnoredFile > this->fileCopyDestinationFile) {
		this->fileButtonsTargetY[this->fileCopyDestinationFile] += 40;
		this->fileSelectFileButtons[this->fileCopyDestinationFile].velY = 3;
	}

	if ((this->saves[this->fileCopyDestinationFile].flags & Saved) != 0) {
		u32 value = 3;
		func_02017bc4(&this->label, &value, 0, -this->guiTimer);
		this->stateID = FileCopyState_ShowOverwriteConfirmation;
		this->fileConfirmOperationButton = 1;
		this->fileConfirmRequest = true;
		this->buttonHitTimer = this->guiTimer;
		return;
	}

	u32 value = 4;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->stateID = FileCopyState_ShowCopyingPrompt;
}

void TitleScreenScene::acceptFileCopyOverwrite()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->fileConfirmRequest = false;
	u32 value = 4;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->stateID = FileCopyState_ShowCopyingPrompt;
}

void TitleScreenScene::declineFileCopyOverwrite()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->fileConfirmRequest = false;
	this->guiTimer = 64;
	u32 value = 2;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->stateID = FileCopyState_RestoreDestinationSelection;
	this->fileSelectionCompleted = false;
	this->buttonsTimer = this->guiTimer;
}

void TitleScreenScene::updateFileErase()
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

	(this->*data_ov009_020dbcb4[this->stateID].member)();
}

void TitleScreenScene::initializeFileErase()
{
	this->guiTimer = 64;
	this->buttonHitTimer = 64;
	this->button2Offset = 0;
	this->button1Offset = 0;
	this->fileSelectionCompleted = false;
	this->fileEraseSelected = 0;
	this->fileConfirmRequest = false;
	u32 value = 6;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);

	s32 fileID = 0;
	for (; fileID < 3; fileID++) {
		if ((this->saves[fileID].flags & Saved) != 0)
			break;
	}

	if (fileID == 3)
		this->fileEraseFile = 0;
	else
		this->fileEraseFile = fileID;

	this->stateID = FileEraseState_Enter;
	this->stateTimer = 12;
}

void TitleScreenScene::enterFileErase()
{
	if (this->stateTimer == 0) {
		this->stateID = FileEraseState_SelectFile;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::selectFileToErase()
{
	u8 previousState = this->stateID;
	u8 previousFile = this->fileEraseFile;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		if (isBackButtonTouched() == 1) {
			cancelFileEraseSelection();
		} else {
			s32 fileID =
				Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
			switch (fileID) {
			case 0:
			case 1:
			case 2:
				if (this->saves[fileID].flags & Saved) {
					this->fileEraseFile = fileID;
					confirmFileEraseSelection();
				}
				break;
			}
		}
	} else if (data_02087650[0][1] & NDS_PAD_BUTTON_A) {
		confirmFileEraseSelection();
	} else if (data_02087650[0][1] & NDS_PAD_BUTTON_B) {
		cancelFileEraseSelection();
	} else {
		u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
		if ((heldButtons & NDS_PAD_BUTTON_DOWN) && previousFile < 2) {
			s32 nextFile = previousFile + 1;
			if (this->saves[nextFile].flags & Saved) {
				this->fileEraseFile++;
			} else if (nextFile < 2 &&
				(this->saves[previousFile + 2].flags & Saved)) {
				this->fileEraseFile += 2;
			}
		} else if ((heldButtons & NDS_PAD_BUTTON_UP) && previousFile != 0) {
			s32 nextFile = previousFile - 1;
			if (this->saves[nextFile].flags & Saved) {
				this->fileEraseFile--;
			} else if (nextFile > 0 &&
				(this->saves[previousFile - 2].flags & Saved)) {
				this->fileEraseFile -= 2;
			}
		}
	}

	updateSelectionFeedback(previousState, this->stateID, previousFile,
		this->fileEraseFile, 3);
}

void TitleScreenScene::confirmFileEraseSelection()
{
	this->fileEraseSelected = 1;
	this->stateID = FileEraseState_PressButton;
	this->buttonAnimTimer = 3;
	this->fileEraseCurrentButton = this->fileEraseFile;
	this->fileConfirmOperationButton = 1;
}

void TitleScreenScene::cancelFileEraseSelection()
{
	this->stateID = FileEraseState_PressButton;
	this->fileEraseCurrentButton = 3;
	this->buttonAnimTimer = 3;
	this->backButtonSelected = true;
	this->backButtonHighlighted = true;
}

void TitleScreenScene::selectFileEraseConfirmation()
{
	u8 previousState = this->stateID;
	u8 previousButton = this->fileConfirmOperationButton;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 3:
			if (data_0208b4e8 >= 40)
				confirmFileErase();
			break;

		case 4:
			if (data_0208b4e8 <= 120)
				confirmFileErase();
			else if (data_0208b4e8 >= 136)
				declineFileErase();
			break;

		case 5:
			confirmFileErase();
			break;

		case 6:
			declineFileErase();
			break;
		}
	} else {
		u16 pressedButtons = data_02087650[0][1];
		if (pressedButtons & NDS_PAD_BUTTON_A) {
			if (previousButton == 0)
				confirmFileErase();
			else
				declineFileErase();
		} else if (pressedButtons & NDS_PAD_BUTTON_B) {
			this->fileConfirmOperationButton = 1;
			declineFileErase();
			return;
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_RIGHT) && previousButton == 0)
				this->fileConfirmOperationButton++;
			else if ((heldButtons & NDS_PAD_BUTTON_LEFT) && previousButton == 1)
				this->fileConfirmOperationButton--;
		}
	}

	if (previousState != this->stateID)
		return;

	updateSelectionFeedback(previousState, previousState, previousButton,
		this->fileConfirmOperationButton, 120);
}

void TitleScreenScene::confirmFileErase()
{
	this->fileConfirmOperationButton = 0;
	data_02088f30 = 0;
	App::startWritingSave();
	this->stateID = FileEraseState_PressButton;
	this->buttonAnimTimer = 3;
	this->fileEraseCurrentButton = 4;
	this->fileCopiedTimer = 24;
	func_02012398(0xe9, 0);
}

void TitleScreenScene::declineFileErase()
{
	this->fileConfirmOperationButton = 1;
	this->stateID = FileEraseState_PressButton;
	this->buttonAnimTimer = 3;
	this->fileEraseCurrentButton = 5;
	func_02012398(0xea, 0);
}

void TitleScreenScene::setFileEraseButtonOffset(s32 offset)
{
	u8 buttonID = this->fileEraseCurrentButton;
	switch (buttonID) {
	case 0:
	case 1:
	case 2:
		this->fileSelectFileButtons[buttonID].posX = offset;
		this->fileSelectFileButtons[buttonID].posY = offset;
		break;
	case 3:
		this->backButtonOffset = offset;
		break;
	case 4:
		this->button1Offset = offset;
		break;
	case 5:
		this->button2Offset = offset;
		break;
	}
}

void TitleScreenScene::updateFileEraseProgress()
{
	if (this->fileCopiedTimer != 0) {
		this->fileCopiedTimer--;
		if (this->fileCopiedTimer > 12) {
			this->guiTimer = ((24 - this->fileCopiedTimer) << 6) / 12;
			this->buttonHitTimer = this->guiTimer;
		} else {
			this->guiTimer = (this->fileCopiedTimer << 6) / 12;
		}

		if (this->fileCopiedTimer == 12) {
			u32 value = 8;
			func_02017bc4(&this->label, &value, 0, 0);
			this->fileConfirmRequest = false;
		}

		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
	}

	func_02012314(0x114, 0);
}

void TitleScreenScene::eraseFile()
{
	if (this->buttonAnimTimer == 0) {
		if (func_02012ee0(this->fileEraseFile, &save) == 0) {
			Scene::switchToCorruptedSave(16);
			this->fileOperationFailed = true;
		}

		if (data_0203bd30 != 11) {
			this->stateID = FileEraseState_EraseComplete;
			reloadSaveData();
			if (data_0203bd30 == 11) {
				Scene::switchToCorruptedSave(16);
				this->fileOperationFailed = true;
			}
		}

		this->fileCopiedTimer = 24;
		App::finishWritingSave();
		data_02088f30 = 1;
		func_02012398(0x115, 0);
	} else {
		updateFileEraseProgress();
		this->buttonAnimTimer--;
	}
}

void TitleScreenScene::waitForFileEraseAcknowledgement()
{
	if (this->fileCopiedTimer != 0) {
		this->fileCopiedTimer--;
		if (this->fileCopiedTimer > 12)
			this->guiTimer = ((24 - this->fileCopiedTimer) << 6) / 12;
		else
			this->guiTimer = (this->fileCopiedTimer << 6) / 12;

		if (this->fileCopiedTimer == 12) {
			u32 value = 9;
			func_02017bc4(&this->label, &value, 0, 0);
		}

		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	if ((Input::consoleKeys[Input::localConsoleID][0] & NDS_PAD_BUTTON_A) == 0) {
		BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (!touchActive)
			return;
	}

	this->stateID = FileEraseState_ExitToFileSelect;
	this->stateTimer = 0;
	this->fileSelectCurrentButton = 0;
	func_02012398(0xe9, 0);
}

void TitleScreenScene::pressFileEraseButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileEraseState_ReleaseButton;
		this->buttonAnimTimer = 3;
		return;
	}

	this->buttonAnimTimer--;
	setFileEraseButtonOffset(3 - this->buttonAnimTimer);
}

void TitleScreenScene::releaseFileEraseButton()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = FileEraseState_ExecuteSelection;
		this->buttonAnimTimer = 10;
		this->backButtonHighlighted = false;
		return;
	}

	this->buttonAnimTimer--;
	setFileEraseButtonOffset(this->buttonAnimTimer);
}

void TitleScreenScene::executeFileEraseSelection()
{
	if (this->buttonAnimTimer == 0) {
		switch (this->fileEraseCurrentButton) {
		case 3:
			this->backButtonSelected = false;
			this->backButtonHighlighted = false;
			this->stateID = FileEraseState_ExitToFileSelect;
			this->stateTimer = 0;
			break;
		case 0:
		case 1:
		case 2:
			this->stateID = FileEraseState_HideFileSelection;
			this->stateTimer = 0;
			break;
		case 4:
			this->stateID = FileEraseState_EraseFile;
			this->buttonAnimTimer = 120;
			break;
		case 5:
			this->stateID = FileEraseState_HideConfirmation;
			this->stateTimer = 0;
			break;
		}
	} else {
		this->buttonAnimTimer--;
	}
}

void TitleScreenScene::exitFileEraseToFileSelect()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->menuID = TitleScreenPage_FileSelect;
	this->stateID = FileSelectState_Initialize;
	this->buttonsVisible = true;
	initializeFileSelect();
}

void TitleScreenScene::hideFileEraseSelection()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonsTimer = this->guiTimer;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->fileSelectionCompleted = true;
	this->stateID = FileEraseState_ShowConfirmation;
	u32 value = 7;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
	this->stateTimer = 12;
	this->fileConfirmRequest = true;
}

void TitleScreenScene::showFileEraseConfirmation()
{
	if (this->stateTimer == 0) {
		this->stateID = FileEraseState_ConfirmErase;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	this->buttonHitTimer = this->guiTimer;
	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::hideFileEraseConfirmation()
{
	if (this->stateTimer < 12) {
		this->stateTimer++;
		this->guiTimer = (this->stateTimer << 6) / 12;
		this->buttonHitTimer = this->guiTimer;
		s32 guiTimer = this->guiTimer;
		this->label.buttonPositions[0].x = 0;
		this->label.buttonPositions[0].y = -guiTimer;
		return;
	}

	this->fileSelectionCompleted = false;
	this->stateID = FileEraseState_ShowFileSelection;
	this->fileEraseSelected = 0;
	this->fileConfirmRequest = false;
	this->buttonHitTimer = this->guiTimer;
	u32 value = 6;
	func_02017bc4(&this->label, &value, 0, -this->guiTimer);
}

void TitleScreenScene::showFileEraseSelection()
{
	if (this->stateTimer == 0) {
		this->stateID = FileEraseState_SelectFile;
		this->guiTimer = 0;
	} else {
		this->stateTimer--;
		this->guiTimer = (this->stateTimer << 6) / 12;
	}

	this->buttonsTimer = this->guiTimer;
	s32 guiTimer = this->guiTimer;
	this->label.buttonPositions[0].x = 0;
	this->label.buttonPositions[0].y = -guiTimer;
}

void TitleScreenScene::updateOptions()
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

	(this->*data_ov009_020dbc04[this->stateID].member)();
}

void TitleScreenScene::initializeOptions()
{
	void *buttonHitboxes = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_option_d_bnbl), false);
	void *buttonCells = FS::Cache::loadFile(
		NSMB_FID(uiStudio_UI_O_menu_option_d_bncl), false);
	Layout::initSub(0, buttonCells, buttonHitboxes);

	NDS::Graphics::setSubObjectTileMapping1D32K();
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_UI_O_menu_option_o_d_ncg_bin),
		(void *)0x06600000);
	FS::loadFileLZ77(
		NSMB_FID(uiStudio_d_2d_UI_O_menu_option_o_d_ncl_bin),
		(void *)0x05000600);

	this->stateID = OptionsState_Enter;
	this->optionsCurrentButton = 0;
	this->stateTimer = 15;
	this->button2Offset = 80;
	this->button1Offset = 320;
	this->optionsOKButtonOffset = 80;
	this->optionsOKButtonPosX = 0;
}

void TitleScreenScene::enterOptions()
{
	if (this->stateTimer != 0) {
		this->stateTimer--;
	} else {
		this->stateID = OptionsState_SelectOption;
		this->button2Offset = 0;
	}

	if (this->stateTimer < 3) {
		this->button1Offset = 0;
		this->button2Offset = (this->stateTimer * 80) / 3;
	} else {
		this->button1Offset = ((this->stateTimer - 3) * 320) / 12;
	}

	this->optionsOKButtonOffset = (this->button1Offset + this->button2Offset) >> 2;
}

void TitleScreenScene::selectOption()
{
	s32 previousControlMode;
	s32 previousSoundMode = this->soundMode;
	previousControlMode = this->controlMode;
	BOOL touchActive = data_0208b4f0 != 0 && data_0208b4ec != 0;

	if (touchActive) {
		s32 action = Layout::bnbl[1]->getBox(data_0208b4e8, data_0208b4f4);
		switch (action) {
		case 0:
		case 3:
			this->optionsCurrentButton = 0;
			if (this->soundMode == 2)
				this->soundMode = 0;
			else
				this->soundMode++;
			func_02012398(0xe5, 0);
			break;

		case 2:
			this->optionsCurrentButton = 0;
			if (this->soundMode == 0)
				this->soundMode = 2;
			else
				this->soundMode--;
			func_02012398(0xe5, 0);
			break;

		case 1:
		case 4:
		case 5:
			this->optionsCurrentButton = 1;
			this->controlMode ^= 1;
			func_02012398(0xe5, 0);
			break;

		case 6:
			this->optionsCurrentButton = 2;
			this->stateID = OptionsState_PressOK;
			this->buttonAnimTimer = 3;
			func_02012398(0xe9, 0);
			break;
		}
	} else {
		if (((data_02087650[0][1] & NDS_PAD_BUTTON_A) && this->optionsCurrentButton == 2) ||
			(data_02087650[0][1] & NDS_PAD_BUTTON_B)) {
			this->optionsCurrentButton = 2;
			this->stateID = OptionsState_PressOK;
			this->buttonAnimTimer = 3;
			if (data_02087650[0][1] & NDS_PAD_BUTTON_B)
				func_02012398(0xea, 0);
			else
				func_02012398(0xe9, 0);
		} else {
			u16 heldButtons = Input::consoleKeys[Input::localConsoleID][0];
			if ((heldButtons & NDS_PAD_BUTTON_DOWN) || (heldButtons & NDS_PAD_BUTTON_A)) {
				if (this->optionsCurrentButton < 2) {
					this->optionsCurrentButton++;
					func_02012398(0xe5, 0);
				}
			} else if (heldButtons & NDS_PAD_BUTTON_UP) {
				if (this->optionsCurrentButton != 0) {
					this->optionsCurrentButton--;
					func_02012398(0xe5, 0);
				}
			} else if (heldButtons & NDS_PAD_BUTTON_LEFT) {
				if (this->optionsCurrentButton == 0) {
					if (previousSoundMode == 0)
						this->soundMode = 2;
					else
						this->soundMode--;
				} else if (this->optionsCurrentButton == 1) {
					this->controlMode ^= 1;
				}
				if (this->optionsCurrentButton != 2)
					func_02012398(0xe5, 0);
			} else if (heldButtons & NDS_PAD_BUTTON_RIGHT) {
				if (this->optionsCurrentButton == 0) {
					if (previousSoundMode == 2)
						this->soundMode = 0;
					else
						this->soundMode++;
				} else if (this->optionsCurrentButton == 1) {
					this->controlMode ^= 1;
				}
				if (this->optionsCurrentButton != 2)
					func_02012398(0xe5, 0);
			}
		}
	}

	if (this->soundMode != previousSoundMode)
		func_02006444(this->soundMode);

	if (this->controlMode != previousControlMode) {
		data_02085ad4[0] = this->controlMode;
		save.options.controlOptions = this->controlMode;
	}
}

void TitleScreenScene::pressOptionsOK()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = OptionsState_ReleaseOK;
		this->buttonAnimTimer = 3;
	} else {
		this->buttonAnimTimer--;
		this->optionsOKButtonPosX = 3 - this->buttonAnimTimer;
	}
}

void TitleScreenScene::releaseOptionsOK()
{
	if (this->buttonAnimTimer == 0) {
		this->stateID = OptionsState_WaitAfterSelection;
		this->buttonAnimTimer = 10;
	} else {
		this->buttonAnimTimer--;
		this->optionsOKButtonPosX = this->buttonAnimTimer;
	}
}

void TitleScreenScene::waitAfterOptionsSelection()
{
	if (this->buttonAnimTimer != 0) {
		this->buttonAnimTimer--;
		return;
	}

	this->stateID = OptionsState_Exit;
	this->stateTimer = 0;
	this->button2Offset = 0;
	this->button1Offset = 0;
	this->optionsOKButtonOffset = 0;
}

void TitleScreenScene::exitOptions()
{
	if (this->stateTimer < 15) {
		this->stateTimer++;
		this->button1Offset = (this->stateTimer * 320) / 12;
		if (this->stateTimer < 3)
			this->button2Offset = -this->button1Offset;
		else
			this->button2Offset = -80;

		this->optionsOKButtonOffset = (this->button1Offset + this->button2Offset) >> 2;
		return;
	}

	this->menuID = TitleScreenPage_Main;
	this->stateID = TitleScreenState_Initialize;
	if (func_0201301c(&save.options) == 0) {
		Scene::switchToCorruptedSave(15);
		this->fileOperationFailed = true;
	}
}

s32 TitleScreenScene::onRender()
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
	cutscene.onRender();
	return true;
}

void TitleScreenScene::onRender_0()
{
	if (stateID == TitleScreenState_Initialize)
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
			palette = (u8)(currentState + (0x100 - TitleScreenState_PressButton)) <=
				TitleScreenState_ReleaseButton - TitleScreenState_PressButton;
		} else {
			palette = 2;
			position = mainMenuButtons[buttonID].posX + 24 + menuOffset;
		}

		func_0200419c(data_ov009_020daa24[buttonID], data_ov009_020daa34[buttonID],
			0, palette, 0, 0, 0, 0, 0, position, -4);
	}
}

void TitleScreenScene::onRender_1()
{
	if (stateID != FileSelectState_Initialize) {
		func_02018060(&label);
		i32 i = 0;
		do {
			i32 value = getSaveFilePalette(i);
			renderSaveFile(i, value);
			i += 1;
		} while (i <= 2);

		u8 palette = getCopyButtonPalette();
		func_0200419c(0x15, (u32)&data_ov009_020db914, 0, palette, 0, 0,
			0, 0, 0, button1Offset, buttonHitTimer + button1Offset);

		palette = getEraseButtonPalette();
		func_0200419c(0x16, (u32)&data_ov009_020db854, 0, palette, 0, 0,
			0, 0, 0, button2Offset, buttonHitTimer + button2Offset);
		renderBackButton();
		renderFileMenuHeader(0);
	}
}

void TitleScreenScene::onRender_2()
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

		s32 value = getSaveFilePalette(fileID);
		renderSaveFile(fileID, value);
	}

	if (fileConfirmRequest) {
		u8 palette = getConfirmButtonPalette(0);
		func_0200419c(0x17, (u32)&data_ov009_020db7f4, 0, palette, 0, 0, 0, 0, 0,
			button1Offset, buttonHitTimer + button1Offset);

		palette = getConfirmButtonPalette(1);
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

	if (stateID == FileCopyState_CopyComplete && fileCopiedTimer == 0)
		func_0200419c(1, (u32)&data_ov009_020db644, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (!fileSelectionCompleted)
		renderBackButton();

	renderFileMenuHeader(8);
}

void TitleScreenScene::onRender_3()
{
	func_02018060(&label);
	for (s32 fileID = 0; fileID <= 2; fileID++) {
		s32 value = getSaveFilePalette(fileID);
		renderSaveFile(fileID, value);
	}

	if (fileConfirmRequest) {
		u8 palette = getConfirmButtonPalette(0);
		func_0200419c(0x17, (u32)&data_ov009_020db7f4, 0, palette, 0, 0, 0, 0, 0,
			button1Offset, buttonHitTimer + button1Offset);

		palette = getConfirmButtonPalette(1);
		func_0200419c(0x18, (u32)&data_ov009_020db8b4, 0, palette, 0, 0, 0, 0, 0,
			button2Offset, buttonHitTimer + button2Offset);
	}

	if (stateID == FileEraseState_EraseComplete && fileCopiedTimer == 0)
		func_0200419c(1, (u32)&data_ov009_020db644, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (!fileSelectionCompleted)
		renderBackButton();

	renderFileMenuHeader(4);
}

void TitleScreenScene::onRender_4()
{
	if (stateID == OptionsState_Initialize)
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
		palette = (u8)(stateID + (0x100 - OptionsState_PressOK)) <=
				OptionsState_ReleaseOK - OptionsState_PressOK
			? 2
			: 0;
	else
		palette = 1;

	func_0200419c(0x12, (u32)&data_ov053_0216e4cc,
		0, palette, 0, 0, 0, 0, 0,
		okButtonPosX, optionsOKButtonOffset + okButtonPosX);
}
