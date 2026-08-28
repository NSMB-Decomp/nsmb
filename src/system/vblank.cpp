#include "vblank.hpp"

namespace System {

#pragma section autobss_3 begin
	IrqFunction userVBlankFunction;
	s32 minigamesVBlankCounter;
	ThreadQueue systemThreadQueue;
	ThreadQueue gameThreadQueue;
	VBlankBGInfo subBGInfo;
#pragma section autobss_3 end

	void setUserVBlankHandler(IrqFunction handler) {
		userVBlankFunction = handler;
	}

	void subEngineVBlankHandler() {
		uploadSubBGState(subBGInfo);
	}

	void uploadSubBGState(VBlankBGInfo& info) {
		if (info.dirty[0]) {
			REG_BG0OFS_SUB = (info.x[0] & 0x1ff) | ((info.y[0] << 0x10) & 0x1ff0000);
			info.dirty[0] = 0;
		}
		if (info.dirty[1]) {
			REG_BG1OFS_SUB = (info.x[1] & 0x1ff) | ((info.y[1] << 0x10) & 0x1ff0000);
			info.dirty[1] = 0;
		}
		if (info.dirty[2]) {
			REG_BG2OFS_SUB = (info.x[2] & 0x1ff) | ((info.y[2] << 0x10) & 0x1ff0000);
			info.dirty[2] = 0;
		}
		if (info.dirty[3]) {
			REG_BG3OFS_SUB = (info.x[3] & 0x1ff) | ((info.y[3] << 0x10) & 0x1ff0000);
			info.dirty[3] = 0;
		}
	}

	void removeUserVBlankHandler() {
		userVBlankFunction = NULL;
	}

	void setMinigamesVBlankCounter(s32 value) {
		minigamesVBlankCounter = value;
	}

	void sleepSystemThread() {
		Nitro::_MultiThread::Sleep(&systemThreadQueue);
	}

	void sleepGameThread() {
		Nitro::_MultiThread::Sleep(&gameThreadQueue);
	}

}