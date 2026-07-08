#pragma once
#include "../nsmb_nitro.hpp"

namespace System {

	struct VBlankBGInfo {

		s32 x[4];
		s32 y[4];
		bool dirty[4];

	};


	extern s32 frameLength;

	extern VBlankBGInfo subBGInfo;
	extern ThreadQueue systemThreadQueue;
	extern ThreadQueue gameThreadQueue;
	extern IrqFunction userVBlankFunction;
	extern s32 minigamesVBlankCounter;
	extern bool waitingForVBlank;
	extern bool statesInitialized;


	void gameVBlankHandler();

	void stageVBlankHandler();

	void titleScreenVBlankHandler();

	void setupGameVBlank();

	void programGameVBlank();

	void programStageVBlank();

	void programTitleScreenVBlank();


	void minigamesVBlankHandler();

	void setupMinigamesVBlank();

	void setMinigamesVBlankCounter(s32 value);


	void sleepSystemThread();

	void sleepGameThread();

	void waitForVBlank();

	void setUserVBlankHandler(IrqFunction handler);

	void removeUserVBlankHandler();


	void uploadSubBGState(VBlankBGInfo& info);

	void subEngineVBlankHandler();

	void setupSubBGVBlank();

	void resetSubBGVBlank();

	void setSubBGPosition(u32 bg, s32 x, s32 y);

}
