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

bool WmController::canEntityStopAtNode(WM::NodeLink* link) {

	u16 flag = wxNodes[link->node].flag;

	if (u16(flag & NF_Course) == 0)
		return false;

	if (u16(flag & NF_StarCoins) == 0)
		return false;

	if (u16(flag & NF_Castle) || u16(flag & NF_FinalCastle))
		return false;

	return true;

}
