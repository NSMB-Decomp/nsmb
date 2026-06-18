#include "controller.hpp"

s32 WmController::getEntityMoveIndex(u32 entityIndex, u32 moveCount, u32 moveStep) {
	return (entityIndex * 12 + moveCount) * 2 + moveStep;
}

