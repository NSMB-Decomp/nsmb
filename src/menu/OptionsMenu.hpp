#pragma once
#include "../nsmb_nitro.hpp"

namespace OptionsMenu {

	extern u8 slideTimer;
	extern u8 selection;
	extern s8 taskDelay;
	extern u8 taskID;
	extern s32 restOffset;
	extern s32 menuOffset;
	extern s32 decideBtnFrame;
	extern u32 soundMode;
	extern u32 controlMode;
	extern s32 decideBtnOffset;
	extern s32 controlBtnOffset;

	enum Selection {
		S_SoundMode,
		S_ControlMode,
		S_Decide,
		S_MAX
	};

	enum TaskID {
		T_Closed,
		T_Open,
		T_Load,
		T_SlideIn,
		T_Main,
		T_ClosePress,
		T_CloseRelease,
		T_CloseWait,
		T_SlideOut,
		T_Unload,
		T_Close,
		T_MAX
	};


	void menuOpen();
	void menuInit();
	void menuSlideIn();
	void menuMain();
	void menuClosePress();
	void menuCloseRelease();
	void menuCloseWait();
	void menuSlideOut();
	void menuClose();
	void menuLoad();
	void menuUnloadStage();
	void menuUnloadWorldmap();
	void menuDraw();


	inline bool isOpen() {
		int task = taskID;
		return task >= 2 && task < 10;
	}

}
