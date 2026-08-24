#include "vblank.hpp"

namespace System {

#pragma section autobss_3 begin
	IrqFunction userVBlankFunction;
	s32 minigamesVBlankCounter;
#pragma section autobss_3 end

	void setUserVBlankHandler(IrqFunction handler) {
		userVBlankFunction = handler;
	}

	void removeUserVBlankHandler() {
		userVBlankFunction = NULL;
	}

	void setMinigamesVBlankCounter(s32 value) {
		minigamesVBlankCounter = value;
	}

}