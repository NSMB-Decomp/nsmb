#include "controller.hpp"

using namespace WM;

struct __Work {
	NodeLink* link;
	u32 world;
	u32 n;
	u32 a;
};

void WmController::moveEntities() {

	// int linkA;
	// u32 uVar2;
	// //u8 *pNodeTbl;
	// //u32 entityNode;
	// int extraout_r1;
	// u8 *puVar3;
	// //u8 *pMoveTbl;
	// int i;
	// u32 moveCount;
	// u8(*pauVar4)[2];
	// int linkB;
	// NodeLink *nextLink;


	//__Work w;
	//NodeLink* w_link;
	//u32 w_world;
	//u32 w_a;
	//u32 w_n;
	u32 entityNodes[2];
	s32 buf4[2];
	s32 buf3[2];
	u8 moveTbl[2*12*2];
	u8 nodeTbl[2][12];
	//int g;

	NodeLink* nextLink; // 1
	int moveCount2 = 0;
	u8* pm = moveTbl;
	u8* pn = nodeTbl[0];
	int mi2; // 2
	int mi; // 2
	//int moveCount; // # doesn't matter
	int e; // 3-4 (must be before 5)
	int f; // 3-4 (must be before 5)
	int g; // 5

	//s32* pb = buf3;

	NodeLink* w_link;
	u32 w_world = save.game.currentWorld;

	WM::nodeState |= 0x40;

	for (/* pn = nodeTbl,  */e = 0; e < 2; e++/* , pn += 12 */) {

		for (moveCount2 = 0; moveCount2 < 12; moveCount2++) {

			for (int w = 0; w < 2; w++) {
				*pm = 0xff;
				pm++;
			}

			// int c = 0;
			// while (++c < 2) {
			// 	*pm = 0xff;
			// 	pm++;
			// };

			// for (u32 c = 0; c < 2;) {
			// 	c++;
			// 	*pm = 0xff;
			// 	pm++;
			// 	//moveTbl[(a*2*12) + (b*12) + c] = 0xff;
			// }

			//nodeTbl[e][f] = 0xff;
			pn[moveCount2] = 0xff;
			//p1 += 2;
			//nodeTbl[(a*12) + b] = 0xff;

		}

		for (moveCount2 = 0; moveCount2 < 2; moveCount2++) {
			entityStates[e][moveCount2] = 0xff;
		}

		buf3[e] = 0;
		pn += 12;

	}

	//w_n = 1; // Does not need to exist!
	//pn = nodeTbl;
	//pm = moveTbl;

	for (pn = nodeTbl[0], e = 0; e < 2; e++, pn += 12) {
		/* u32 node = save.game.mapEntities[w_world][e].node;
		//entityNodes[e] = save.game.mapEntities[w_world][e].node;
		node = entityNodes[e] = node;
		//w_a = entityNodes[e];
		w_a = node;
		buf4[e] = node; */
		//w_a = buf4[e] = entityNodes[e] = save.game.mapEntities[w_world][e].node;
		u32 w_a = entityNodes[e] = save.game.mapEntities[w_world][e].node;
		buf4[e] = w_a;
		//w_a = tmp;
		//entityNodes[e] = w_a;
		//w_a = entityNodes[e];
		// u32 tmp = node;
		// w_a = entityNodes[e];
		/* entity exists (linked to a node) */

		if (w_a == 0xff) continue;

		//moveCount2 = 0;
		//w_link = WM::wxNodes[w_a].links;
		//int linkA = 0;
		/* iterate through all 4 possible links of the current node */
		for (moveCount2 = 0, f = 0, w_link = WM::wxNodes[w_a].links; f < 4; w_link++, f++) {
			if (w_link->node == 0xff)
				break;

			if (canEntityTransitLink(w_link) != 0) {
				/* entity cannot stop at this node, analyze next node's links */
				if (canEntityStopAtNode(w_link) != 0) {
					/* entity can stop at first node */
					mi2 = getEntityMoveIndex(e, moveCount2, 0);
					moveTbl[mi2] = (u8)f;
					pn[moveCount2] = w_link->node;
					moveCount2++;
				} else {

					nextLink = WM::wxNodes[w_link->node].links;
					for (mi = 0; mi < 4; nextLink++, mi++) {
						if (nextLink->node == 0xff)
							break;

						/* can transit link, can stop at node and target node isn't source node */
						if (canEntityTransitLink(nextLink) && canEntityStopAtNode(nextLink) && (nextLink->node != w_a)) {
							mi2 = getEntityMoveIndex(e, moveCount2, 0);
							moveTbl[mi2] = (u8)f;
							mi2 = getEntityMoveIndex(e, moveCount2, 1);
							moveTbl[mi2] = (u8)mi;
							pn[moveCount2] = nextLink->node;
							moveCount2++;
						}
					};
				}
			}
		}

		buf3[e] = moveCount2;
	}

	// q can be anything really, even a newly defined int
	#define q f
	//int q;

	if (!buf3[0] || !buf3[1]) {
		q = -1;
		for (e = 0; e < 2; e++) {
			if ((int)buf3[e] <= 0)
				continue;
			q = e;
			break;
		}
		if (q == -1) {
			return;
		}
		func_ov008_020daf34(entityStates[q], q, moveTbl, nodeTbl[q]/* nodeTbl + q * 0xc */, buf4, 1);
		return;
	}

	if ((buf3[1] != 1) || (buf3[0] == 1)) {
		// linkA = 0;
		// //pMoveTbl = nodeTbl;
		// pauVar4 = this->entityStates;
		// do {
		// 	func_ov008_020db030(*pauVar4, linkA, 0, moveTbl, &moveTbl[linkA*12], buf4, (u32)(linkA != 0));
		// 	linkA += 1;
		// 	//pMoveTbl = pMoveTbl + 0xc;
		// 	pauVar4 = pauVar4 + 1;
		// } while (linkA < 2);
		//u8* pn = nodeTbl;
		//pm = entityStates[0];
		for (e = 0; e < 2; e++) {
			func_ov008_020db030(entityStates[e], e, 0, moveTbl, nodeTbl[e], buf4, (u32)(e != 0));
			//pm += 2;
			//pn += 12;
		}
	} else {
		if ((buf4[2] == 1) || (buf3[0] == 1)) {
			q = -1;
			for (e = 0; e < 2; e++) {
				if (buf3[e] == 1) {
					q = e;
					break;
				}
			}
			func_ov008_020db030(entityStates[q], q, 0, moveTbl, nodeTbl[q]/* nodeTbl + q * 0xc */, buf4, 0);
			int r = q == 0 ? 1 : 0;
			func_ov008_020daf34(entityStates[r], r, moveTbl, nodeTbl[r]/* nodeTbl + r * 0xc */, buf4, 1);
			return;
		}

		//pn = nodeTbl;
		for (e = 0; e < 2; e++) {
			func_ov008_020daf34(entityStates[e], e, moveTbl, nodeTbl[e], buf4, (u32)(e != 0));
			//pn += 12;
		}
	}

}

void WmController::func_ov008_020daf34(u8* state, int linkIndex,u8* buf1,u8* buf2, s32* param_5, int param_6) {

}

void WmController::func_ov008_020db030(u8* state, int i, int i2, u8* buf1, u8* buf2, s32* param_6, int param_7) {

}

s32 WmController::getEntityMoveIndex(u32 entityIndex, u32 moveCount, u32 moveStep) {
	return (entityIndex * 12 + moveCount) * 2 + moveStep;
}

bool WmController::func_ov008_020db0c8(u8 param_1, u32 param_2, s32* param_3) {
	return false;
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
