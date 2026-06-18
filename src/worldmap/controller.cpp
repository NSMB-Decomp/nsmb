#include "controller.hpp"

s32 WmController::getEntityMoveIndex(u32 entityIndex, u32 moveCount, u32 moveStep) {
	return (entityIndex * 12 + moveCount) * 2 + moveStep;
}

bool WmController::canEntityTransitLink(WM::NodeLink* link) {

	if (link->flag & LF_Pipe)
		return false;

	u8 ps = save.game.pathStates[save.game.currentWorld][link->path];
	if (u8(ps & PS_Unk40) == 0 && u8(wxPaths[link->path].flag & PF_Unk1))
		return false;

	return true;

}

