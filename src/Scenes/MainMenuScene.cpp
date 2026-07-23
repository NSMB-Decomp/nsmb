#include "MainMenuScene.hpp"
#include <nsmb/arm9/functions.hpp>
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov009/dependencies.hpp>
#include <nsmb/overlays/ov009/symbols.hpp>
#include "../system/app.hpp"

void (MainMenuScene::*data_ov009_020dbbb4[5])();

void *MainMenuScene::create()
{
	return new MainMenuScene();
}

MainMenuScene::MainMenuScene()
{
}

s32 MainMenuScene::onCreate()
{
}

// void (Object229::*data_ov099_02186614[4])() = {
//     Object229::func_ov099_021860f0,
//     Object229::func_ov099_02186080,
//     Object229::func_ov099_02186028,
//     Object229::func_ov099_02185fb4,
// };
u32 data_ov009_020dbb94;
s32 MainMenuScene::onRender()
{
	if ((data_ov009_020dbb94 & 1) == 0) {
		data_ov009_020dbbb4[0] = MainMenuScene::onRender_0;
		data_ov009_020dbbb4[1] = MainMenuScene::onRender_1;
		data_ov009_020dbbb4[2] = MainMenuScene::onRender_2;
		data_ov009_020dbbb4[3] = MainMenuScene::onRender_3;
		data_ov009_020dbbb4[4] = MainMenuScene::onRender_4;
		data_ov009_020dbb94 |= 1;
	}
	(this->*(data_ov009_020dbbb4[this->menuID]))();
	this->cutscene.func_ov009_020cd994();
	return true;
}

u32 data_ov009_020db914;
u32 data_ov009_020db854;
void MainMenuScene::onRender_1()
{
	if (this->stateID != 0x0) {
		this->label.func_02018060();
		i32 i = 0;
		do {
			i32 v = this->func_ov009_020ce944(i);
			this->func_ov009_020ceaec(i, v);
			i += 1;
		} while (i <= 2);

		u8 temp1 = this->func_ov009_020ce8d8();
		Game::drawBNCLSpriteSub(0x15, &data_ov009_020db914, 0, temp1, 0, 0, 0, 0, 0, this->button1Offset, this->buttonHitTimer + this->button1Offset);

		u8 temp2 = this->func_ov009_020ce86c();
		Game::drawBNCLSpriteSub(0x16, &data_ov009_020db854, 0, temp2, 0, 0, 0, 0, 0, this->button2Offset, this->buttonHitTimer + this->button2Offset);
		this->func_ov009_020cea8c();
		this->func_ov009_020cea44(0);
	}
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
			palette = (u8)(stateID + 0xfd) <= 1;
			position = menuOffset + mainMenuButtons[buttonID].posX - buttonHitTimer * 2;
		} else {
			palette = 2;
			position = mainMenuButtons[buttonID].posX + 24 + menuOffset;
		}

		func_0200419c(data_ov009_020daa24[buttonID], data_ov009_020daa34[buttonID],
			0, palette, 0, 0, 0, 0, 0, position, -4);
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

extern "C" void func_ov009_020d2fec(MainMenuScene *scene)
{
	if (scene->buttonAnimTimer > 0)
		scene->buttonAnimTimer--;
	else
		scene->stateID = 6;
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

extern "C" void func_ov009_020d352c(MainMenuScene *scene)
{
	func_ov009_020cd9ac(&scene->cutscene);
}

extern "C" s32 func_ov009_020d353c(MainMenuScene *scene)
{
	if (scene->settings == 0)
		func_020180a4(&scene->label);

	func_ov009_020cd9bc(&scene->cutscene);
	return true;
}

extern "C" void func_ov009_020d0674(MainMenuScene *scene)
{
	scene->fileConfirmOperationButton = 1;
	scene->stateID = 3;
	scene->buttonAnimTimer = 3;
	scene->fileEraseCurrentButton = 5;
	func_02012398(0xea, 0);
}

extern "C" void func_ov009_020d08e0(MainMenuScene *scene)
{
	scene->stateID = 3;
	scene->fileEraseCurrentButton = 3;
	scene->buttonAnimTimer = 3;
	scene->backButtonSelected = true;
	scene->backButtonHighlighted = true;
}

extern "C" void func_ov009_020d0900(MainMenuScene *scene)
{
	scene->fileEraseSelected = 1;
	scene->stateID = 3;
	scene->buttonAnimTimer = 3;
	scene->fileEraseCurrentButton = scene->fileEraseFile;
	scene->fileConfirmOperationButton = 1;
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

extern "C" void func_ov009_020d1f0c(MainMenuScene *scene)
{
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 6;
	scene->unk66 = 16;
	scene->buttonAnimTimer = 3;
	scene->backButtonSelected = true;
	scene->backButtonHighlighted = true;
}

extern "C" void func_ov009_020d1f3c(MainMenuScene *scene)
{
	scene->stateID = 13;
	scene->fileCopyCurrentButton = scene->fileCopySourceFile;
	scene->buttonAnimTimer = 3;
	scene->unk7c = 1;
	scene->fileCopyDestinationFile = 3;
}

extern "C" void func_ov009_020d3264(MainMenuScene *scene)
{
	func_ov009_020d34a0(scene);
	func_ov009_020ce7a4(scene);
	scene->stateID = 1;
	scene->stateTimer = 12;
	scene->buttonHitTimer = 0;
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

extern "C" void func_ov009_020d1830(MainMenuScene *scene)
{
	scene->fileConfirmOperationButton = 1;
	scene->stateID = 13;
	scene->fileCopyCurrentButton = 8;
	scene->buttonAnimTimer = 3;
	func_02012398(0xea, 0);
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
