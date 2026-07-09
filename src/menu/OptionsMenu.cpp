#include "OptionsMenu.hpp"
#include "StageMenu.hpp"
#include "../system/vblank.hpp"  // for System::setSubBGPosition
#include "../Scenes/Scene.hpp"   // for Scene::switchToCorruptedSave
#include "../worldmap/scene.hpp" // for WM::NodeType

extern "C" BOOL func_0201301c(void*);
extern u16 data_0203bd34; // currentSceneID
extern u32 data_02085acc; // levelStates
extern u32 data_02085a9c; // wmNodeType

namespace OptionsMenu {

	u8 slideTimer;
	u8 selection;
	s8 taskDelay;
	u8 taskID;
	s32 restOffset;
	s32 menuOffset;
	s32 decideBtnFrame;
	u32 soundMode;
	u32 controlMode;
	s32 decideBtnOffset;
	s32 controlBtnOffset;


	void menuOpen() {
		slideTimer = 0;
		taskID = T_Open;
	}

	void menuInit() {

		if (slideTimer < 12) {

			slideTimer++;
			restOffset = (slideTimer * 250) / 12;

			s32 y = data_0203bd34 == SC_Worldmap ? 4 : 0;
			System::setSubBGPosition(0, restOffset, y);
			System::setSubBGPosition(1, restOffset, y);
			System::setSubBGPosition(2, restOffset, y);

		} else {

			if (data_0203bd34 == SC_Worldmap) {
				u32 visiblePlane = (REG_DISPCNT_SUB & 0x1F00) >> 8;
				REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | ((visiblePlane & ~0x7) << 8);
			} else {
				u32 visiblePlane = (REG_DISPCNT_SUB & 0x1F00) >> 8;
				REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | ((visiblePlane & ~0x6) << 8);
			}

			slideTimer = 15;
			controlBtnOffset = 80;
			menuOffset = 320;
			decideBtnOffset = 80;
			decideBtnFrame = 0;

			taskID++;

		}

	}

	void menuSlideIn() {

		if (slideTimer == 0) {
			taskID++;
			controlBtnOffset = 0;
		} else {
			slideTimer--;
		}

		if (slideTimer < 3) {
			menuOffset = 0;
			controlBtnOffset = (slideTimer * 80) / 3;
		} else {
			menuOffset = ((slideTimer - 3) * 320) / 12;
		}

		decideBtnOffset = menuOffset + controlBtnOffset >> 2;

	}

	void menuMain() {

	}

	void menuClosePress() {

		if (taskDelay == 0) {
			taskID++;
			taskDelay = 3;
		} else {
			taskDelay--;
			decideBtnFrame = 3 - taskDelay;
		}

	}

	void menuCloseRelease() {

		if (taskDelay == 0) {
			taskID++;
			taskDelay = 10;
		} else {
			taskDelay--;
			decideBtnFrame = taskDelay;
		}

	}

	void menuCloseWait() {

		if (taskDelay == 0) {
			taskID++;

			slideTimer = 0;
			controlBtnOffset = 0;
			menuOffset = 0;
			decideBtnOffset = 0;

		} else {
			taskDelay--;
		}

	}

	void menuSlideOut() {

		if (slideTimer < 15) {
			slideTimer++;

			menuOffset = (slideTimer * 320) / 12;

			if (slideTimer < 3) {
				controlBtnOffset = -menuOffset;
			} else {
				controlBtnOffset = -80;
			}

			decideBtnOffset = menuOffset + controlBtnOffset >> 2;

		} else {

			taskID++;

			if (func_0201301c(&save.options) == 0)
				Scene::switchToCorruptedSave(15);

		}

	}

	void menuClose() {

		if (slideTimer != 0) {
			slideTimer--;

			restOffset = (slideTimer * 250) / 12;

			s32 y = data_0203bd34 == SC_Worldmap ? 4 : 0;
			System::setSubBGPosition(0, restOffset, y);
			System::setSubBGPosition(1, restOffset, y);
			System::setSubBGPosition(2, restOffset, y);

		} else {
			taskID = T_Closed;
		}

	}

	void menuLoad() {

		CommonMenu::transVramOptions();

		selection = S_SoundMode;
		controlMode = data_02085ad4[0];
		soundMode = save.options.soundMode;
		taskID = T_SlideIn;

	}

	void menuUnloadStage() {

		CommonMenu::transVramStage();

		if ((data_02085acc & 0x20) != 0 || data_02085a9c == WM::NT_Cannon) {
			u32 visiblePlane = (REG_DISPCNT_SUB & 0x1F00) >> 8;
			REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | ((visiblePlane | 0x4) << 8);
		} else {
			u32 visiblePlane = (REG_DISPCNT_SUB & 0x1F00) >> 8;
			REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | ((visiblePlane | 0x6) << 8);
		}

		slideTimer = 12;
		taskID = T_Close;

	}

	void menuUnloadWorldmap() {

		CommonMenu::transVramWorldmap();

		u32 visiblePlane = (REG_DISPCNT_SUB & 0x1F00) >> 8;
		REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | ((visiblePlane | 0x7) << 8);

		slideTimer = 12;
		taskID = T_Close;

	}

	void menuDraw() {

		if (taskID == T_Load)
			return;

	}

}
