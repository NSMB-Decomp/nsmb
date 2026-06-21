#include "controller.hpp"

using namespace WM;

struct __Work {
	NodeLink* link;
	u32 world;
	u32 n;
	u32 a;
};

WmController::WmController() {}

WmController::~WmController() {}


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
	u32 buf4[2];
	u32 buf3[2];
	u8 moveTbl[2*12*2];
	u8 nodeTbl[2*12];
	//int g;

	NodeLink* nextLink; // 1
	int moveCount3 = 0;
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

	u8* pm = moveTbl;
	u8* pn;

	for (pn = nodeTbl, e = 0; e < 2; pn += 12, e++) {

		for (moveCount3 = 0; moveCount3 < 12; moveCount3++) {

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
			pn[moveCount3] = 0xff;
			//p1 += 2;
			//nodeTbl[(a*12) + b] = 0xff;

		}

		for (moveCount3 = 0; moveCount3 < 2; moveCount3++) {
			entityStates[e][moveCount3] = 0xff;
		}

		buf3[e] = 0;
		//pn += 12;

	}

	//w_n = 1; // Does not need to exist!
	//pn = nodeTbl;
	//pm = moveTbl;

	for (pn = nodeTbl, e = 0; e < 2; pn += 12, e++) {
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

		moveCount3 = 0;
		w_link = WM::wxNodes[w_a].links;
		//int linkA = 0;
		/* iterate through all 4 possible links of the current node */
		for (f = 0; f < 4; w_link++, f++) {
			if (w_link->node == 0xff)
				break;

			if (canEntityTransitLink(w_link) != 0) {
				/* entity cannot stop at this node, analyze next node's links */
				if (canEntityStopAtNode(w_link) != 0) {
					/* entity can stop at first node */
					moveTbl[getEntityMoveIndex(e, moveCount3, 0)] = f;
					pn[moveCount3] = w_link->node;
					moveCount3++;
				} else {

					nextLink = WM::wxNodes[w_link->node].links;
					for (mi = 0; mi < 4; nextLink++, mi++) {
						if (nextLink->node == 0xff)
							break;

						/* can transit link, can stop at node and target node isn't source node */
						if (canEntityTransitLink(nextLink) && canEntityStopAtNode(nextLink) && (nextLink->node != w_a)) {
							moveTbl[getEntityMoveIndex(e, moveCount3, 0)] = f;
							moveTbl[getEntityMoveIndex(e, moveCount3, 1)] = mi;
							pn[moveCount3] = nextLink->node;
							moveCount3++;
						}
					};
				}
			}
		}

		buf3[e] = moveCount3;
	}

	// q can be anything really, even a newly defined int
	#define q f
	//int q;

	if ((buf3[0] == 0) || (buf3[1] == 0)) {
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
		moveEntitiesLoop(entityStates[q], q, moveTbl, nodeTbl+(q*12)/* [q] *//* nodeTbl + q * 0xc */, buf4, 1);
		return;
	}

	if ((buf3[0] == 1) && (buf3[1] == 1)) {
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
		u8* pn = nodeTbl;
		for (e = 0; e < 2; e++) {
			moveEntitiesOnce(entityStates[e], e, 0, moveTbl, pn/* [e] */, buf4, (u32)(e != 0));
			//pm += 2;
			pn += 12;
		}
	} else {
		if ((buf3[0] == 1) || (buf3[1] == 1)) {
			q = -1;
			for (e = 0; e < 2; e++) {
				if (buf3[e] == 1) {
					q = e;
					break;
				}
			}
			moveEntitiesOnce(entityStates[q], q, 0, moveTbl, nodeTbl+(q*12)/* [q] *//* nodeTbl + q * 0xc */, buf4, 0);
			int r = q == 0 ? 1 : 0;
			moveEntitiesLoop(entityStates[r], r, moveTbl, nodeTbl+(r*12)/* [r] *//* nodeTbl + r * 0xc */, buf4, 1);
			return;
		}
		u8* pn = nodeTbl;
		for (e = 0; e < 2; e++) {
			moveEntitiesLoop(entityStates[e], e, moveTbl, pn/* [e] */, buf4, (u32)(e != 0));
			pn += 12;
		}
	}

}

void WmController::moveEntitiesLoop(u8* entityMoves, u32 entityIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order) {

	if (order) {

		for (int m = 0; m < 12; m++) {

			// Entity is already at this node, cancel this movement
			if (nodeTbl[m] != 0xFF && isEntityAtNode(nodeTbl[m], entityIdx, entityNodes))
				nodeTbl[m] = 0xFF;

		}

	}

	// Count number of moves
	int moveNum = 0;

	for (int m = 0; m < 12; m++) {

		if (nodeTbl[m] != 0xFF)
			moveNum++;

	}

	if (moveNum == 0)
		return;

	u32 random = WiFi::random();
	s32 randMove = (moveNum * (random & 0x7FFF)) >> 15;

	for (int m = 0; m < 12; m++) {

		if (nodeTbl[m] == 0xFF)
			continue;

		if (randMove > 0) {
			randMove--;
			continue;
		}

		moveEntitiesOnce(entityMoves, entityIdx, m, moveTbl, nodeTbl, entityNodes, false);
		return;

	}

}

void WmController::moveEntitiesOnce(u8* entityMoves, u32 entityIdx, u32 moveIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order) {

	u8 node = nodeTbl[moveIdx];
	if (node == 0xFF)
		return;

	if (order && isEntityAtNode(node, entityIdx, entityNodes))
		return;

	for (int s = 0; s < 2; s++) {
		entityMoves[s] = moveTbl[getEntityMoveIndex(entityIdx, moveIdx, s)];
	}

	entityNodes[entityIdx] = node;

}

s32 WmController::getEntityMoveIndex(u32 entityIdx, u32 moveIdx, u32 moveStep) {
	return (entityIdx * 12 + moveIdx) * 2 + moveStep;
}

bool WmController::isEntityAtNode(u8 node, u32 entityIdx, u32* entityNodes) {

	for (int e = 0; e < 2; e++) {

		if (e == entityIdx)
			continue;

		if (entityNodes[e] == node)
			return true;

	}

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


void* WmController::create() {
	return new WmController();
}
