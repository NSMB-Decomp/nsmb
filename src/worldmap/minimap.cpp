#include "minimap.hpp"
#include "../menu/OptionsMenu.hpp"

using namespace WM;

const u16 WmNodeMarkBlinker::blinkTbl[TypeCount][StateCount] = {
	{ 60, 20 }, // Entity
	{ 60, 60 }, // Shared
	{ 10, 10 }  // Moving
};

WmNodeMark::AnimTask WmNodeMark::taskTbl[AnimCount] = {
	{ &WmNodeMark::initDispOff, nullptr },
	{ &WmNodeMark::initDispOn, nullptr },
	{ &WmNodeMark::initBlinkOff, &WmNodeMark::updateBlinkOff },
	{ &WmNodeMark::initBlinkOn, &WmNodeMark::updateBlinkOn }
};

WmEntityMark::Task WmEntityMark::taskTbl[TaskCount] = {
	{ &WmEntityMark::initIdle, &WmEntityMark::updateIdle },
	{ &WmEntityMark::initMove, &WmEntityMark::updateMove }
};

WmPlayerMark::Task WmPlayerMark::taskTbl[TaskCount] = {
	{ &WmPlayerMark::initIdle, &WmPlayerMark::updateIdle },
	{ &WmPlayerMark::initMove, &WmPlayerMark::updateMove },
	{ &WmPlayerMark::initEntityNode, &WmPlayerMark::updateEntityNode }
};

const u32 WmPlayerMark::playerMarkCellTbl[2] = {
	0x19, 0x1A
};

WmMapPath WmMinimap::w1Paths[7] = {

};

WmMapPath WmMinimap::w2Paths[11] = {

};

WmMapPath WmMinimap::w3Paths[8] = {

};

WmMapPath WmMinimap::w4Paths[7] = {

};

WmMapPath WmMinimap::w5Paths[10] = {

};

WmMapPath WmMinimap::w6Paths[5] = {

};

WmMapPath WmMinimap::w7Paths[13] = {

};

WmMapPath WmMinimap::w8Paths[3] = {

};

WmMapPath WmMinimap::w8Paths2[3] = {

};

WmMapPathInfo WmMinimap::w1PathInfo = {

};

WmMapPathInfo WmMinimap::w2PathInfo = {

};

WmMapPathInfo WmMinimap::w3PathInfo = {

};

WmMapPathInfo WmMinimap::w4PathInfo = {

};

WmMapPathInfo WmMinimap::w5PathInfo = {

};

WmMapPathInfo WmMinimap::w6PathInfo = {

};

WmMapPathInfo WmMinimap::w7PathInfo = {

};

WmMapPathInfo WmMinimap::w8PathInfo = {

};

WmMapPathInfo WmMinimap::w8PathInfo2 = {

};

WmMapPathInfo* WmMinimap::paths[9] = {
	&WmMinimap::w1PathInfo, // W1
	&WmMinimap::w2PathInfo, // W2
	&WmMinimap::w3PathInfo, // W3
	&WmMinimap::w4PathInfo, // W4
	&WmMinimap::w5PathInfo, // W5
	&WmMinimap::w6PathInfo, // W6
	&WmMinimap::w7PathInfo, // W7
	&WmMinimap::w8PathInfo, // W8 (first section)
	&WmMinimap::w8PathInfo2 // W8 (both sections)
};

const WmMapNodeInfo WmMinimap::nodes[9] = {
	{}, // W1
	{}, // W2
	{}, // W3
	{}, // W4
	{}, // W5
	{}, // W6
	{}, // W7
	{}, // W8 (first section)
	{}  // W8 (both sections)
};

const u32 WmMinimap::maskNscTbl[9] = {
	1853,
	1855,
	1857,
	1859,
	1861,
	1863,
	1865,
	1869,
	1867
};

const u32 WmMinimap::mainNscTbl[9] = {
	1854,
	1856,
	1858,
	1860,
	1862,
	1864,
	1866,
	1870,
	1868
};

ObjectProfile WmMinimap::profile = {
	&WmMinimap::create,
	WM_Minimap,
	296
};



WmMinimap::WmMinimap() {}
WmMinimap::~WmMinimap() {}

s32 WmMinimap::onCreate() {

	markBlinker.create();

	playerMark.create(markBlinker);

	for (int i = 0; i < ET_MAX; i++) {
		entityMarks[i].create(i, markBlinker);
	}

	pathMap.create();

	return 1;

}

s32 WmMinimap::onDestroy() {
	return 1;
}

s32 WmMinimap::onUpdate() {

	markBlinker.update();

	for (int i = 0; i < ET_MAX; i++) {
		entityMarks[i].update(markBlinker);
	}

	playerMark.update(entityMarks, markBlinker);

	pathMap.update();

	return 1;

}

s32 WmMinimap::onRender() {

	playerMark.render();

	for (int i = 0; i < ET_MAX; i++) {
		entityMarks[i].render();
	}

	return 1;

}


u32 WmMinimap::getWorldID(u32 world) {

	if (world != 7)
		return world;

	// W8 castle completed
	if (u8(save.game.nodeStates[7][6] & 0x80))
		world = 8;

	return world;

}

void* WmMinimap::create() {
	return new WmMinimap();
}



WmNodeMarkBlinker::WmNodeMarkBlinker() {
	Nitro::func_02066fe8(timers, 0, sizeof(timers));
	Nitro::func_02066fe8(states, 0, sizeof(states));
}

WmNodeMarkBlinker::~WmNodeMarkBlinker() {}

void WmNodeMarkBlinker::create() {

	u16* dst = timers;
	u16* end = timers + TypeCount;

	const u16* src = blinkTbl[0];

	u8* sta = states;

	Nitro::func_02066fe8(states, 0, sizeof(states));

	while (dst != end) {
		*dst = src[*sta];
		dst += 1;
		src += 2;
		sta += 1;
	}

}

void WmNodeMarkBlinker::update() {

	u16* dst = timers;
	u16* end = timers + TypeCount;

	u8* sta = states;

	const u16* src = blinkTbl[0];

	while (dst != end) {

		if (*dst == 0) {
			*sta = (~*sta) & 1;
			*dst = src[*sta];
		} else {
			(*dst)--;
		}

		sta += 1;
		dst += 1;
		src += 2;
	}

}



WmNodeMark::WmNodeMark() {}
WmNodeMark::~WmNodeMark() {}

void WmNodeMark::create(s32 animID, s32 node, u32 cellIdx, u32 blinkType) {

	this->cellIdx = cellIdx;
	pos.x = 0;
	pos.y = 0;

	startAnim(animID, node, blinkType);

}


void WmNodeMark::getNodePos(WmMapNodePos& pos, u32 node) {

	u32 worldID = WmMinimap::getWorldID(save.game.currentWorld);
	const WmMapNodeInfo* info = &WmMinimap::nodes[worldID];
	WmMapNodePos* nodes = info->nodes;
	if (nodes && u8(node) < info->count) {
		WmMapNodePos* src = (nodes + node);
		s16 x = src->x;
		s16 y = src->y;
		pos.x = x;
		pos.y = y;
	}

}

void WmNodeMark::startAnim(s32 animID, s32 node, u32 blinkType) {

	if (animID >= AnimCount)
		return;

	AnimTask& task = taskTbl[animID];

	if (task.init != nullptr) {

		if (!(this->*task.init)(node, blinkType))
			return;

	}

	animFunc = task.main;

}


bool WmNodeMark::initDispOff(s32 node, u32 blinkType) {

	this->blinkType = blinkType;
	visible = false;
	getNodePos(pos, node);

	return true;

}

bool WmNodeMark::initDispOn(s32 node, u32 blinkType) {

	this->blinkType = blinkType;
	visible = true;
	getNodePos(pos, node);

	return true;

}

bool WmNodeMark::initBlinkOff(s32 node, u32 blinkType) {

	this->blinkType = blinkType;
	visible = false;
	getNodePos(pos, node);

	return true;

}

void WmNodeMark::updateBlinkOff(WmNodeMarkBlinker& blinker) {

	if (blinker.timers[blinkType] == 0) {
		startAnim(BlinkOn, -1, blinkType);
	}

}

bool WmNodeMark::initBlinkOn(s32 node, u32 blinkType) {

	this->blinkType = blinkType;
	visible = true;
	getNodePos(pos, node);

	return true;

}

void WmNodeMark::updateBlinkOn(WmNodeMarkBlinker& blinker) {

	if (blinker.timers[blinkType] == 0) {
		startAnim(BlinkOff, -1, blinkType);
	}

}


void WmNodeMark::updateAnim(WmNodeMarkBlinker& blinker) {

	if (animFunc != nullptr) {
		(this->*animFunc)(blinker);
	}

}

void WmNodeMark::render() {

	if (OptionsMenu::isOpen())
		return;

	if (!visible)
		return;

	Layout::drawCellSubEx(
		&Layout::bncl[1]->cells[cellIdx], nullptr,
		true, nullptr, 0,
		pos.x - OptionsMenu::restOffset, pos.y,
		0, 0
	);

}



WmEntityMark::WmEntityMark() {}
WmEntityMark::~WmEntityMark() {}

void WmEntityMark::create(u32 type, WmNodeMarkBlinker& blinker) {

	this->type = type;
	node = save.game.mapEntities[save.game.currentWorld][this->type].node;
	taskID = TaskCount;

	if (node != 0xFF) {
		if (blinker.states[blinker.Entity] == 0) {
			WmNodeMark::create(BlinkOn, node, 0x1B, blinker.Entity);
		} else {
			WmNodeMark::create(BlinkOff, node, 0x1B, blinker.Entity);
		}
	} else {
		WmNodeMark::create(DispOff, -1, 0x1B, blinker.Entity);
	}

	issueTask(Idle, blinker);

}


void WmEntityMark::suspendBlink() {

	if (node == 0xFF)
		return;

	startAnim(DispOn, node, WmNodeMarkBlinker::Entity);

}

void WmEntityMark::resumeBlink(WmNodeMarkBlinker& blinker) {

	if (node == 0xFF || taskID != Idle)
		return;

	if (blinker.states[blinker.Entity] == 0) {
		startAnim(BlinkOn, node, blinker.Entity);
	} else {
		startAnim(BlinkOff, node, blinker.Entity);
	}

}

void WmEntityMark::issueTask(s32 taskID, WmNodeMarkBlinker& blinker) {

	if (taskID >= TaskCount)
		return;

	Task& task = taskTbl[taskID];

	if (task.init != nullptr) {

		if (!(this->*task.init)(blinker))
			return;

	}

	this->taskID = taskID;
	taskFunc = task.main;

}


bool WmEntityMark::initIdle(WmNodeMarkBlinker& blinker) {

	node = save.game.mapEntities[save.game.currentWorld][this->type].node;

	if (node != 0xFF) {
		if (blinker.states[blinker.Entity] == 0) {
			startAnim(BlinkOn, node, blinker.Entity);
		} else {
			startAnim(BlinkOff, node, blinker.Entity);
		}
	} else {
		startAnim(DispOff, -1, blinker.Entity);
	}

	return true;

}

void WmEntityMark::updateIdle(WmNodeMarkBlinker& blinker) {

	if (save.game.mapEntities[save.game.currentWorld][this->type].node != 0xFF) {

		if (node != 0xFF) {
			if (WM::state & WM::ST_EntityMove) {
				issueTask(Move, blinker);
			}
			return;
		}

		// Entity disappeared again...???
		issueTask(Idle, blinker);

	} else if (node != 0xFF) {
		// Entity disappeared from thin air??
		issueTask(Idle, blinker);
	}

}

bool WmEntityMark::initMove(WmNodeMarkBlinker& blinker) {

	if (blinker.states[blinker.Moving] == 0) {
		startAnim(BlinkOn, node, blinker.Moving);
	} else {
		startAnim(BlinkOff, node, blinker.Moving);
	}

	return true;

}

void WmEntityMark::updateMove(WmNodeMarkBlinker& blinker) {

	if (WM::state & WM::ST_EntityMove)
		return;

	// Entities done moving
	issueTask(Idle, blinker);

}


void WmEntityMark::update(WmNodeMarkBlinker& blinker) {

	if (taskFunc != nullptr) {
		(this->*taskFunc)(blinker);
	}

	if (node != 0xFF) {
		updateAnim(blinker);
	}

}



WmPlayerMark::WmPlayerMark() {}
WmPlayerMark::~WmPlayerMark() {}

void WmPlayerMark::create(WmNodeMarkBlinker& blinker) {

	u32 chara = Game::character;
	node = save.game.currentWorldNode;

	WmNodeMark::create(DispOn, node, playerMarkCellTbl[chara], blinker.Shared);
	issueTask(Idle, nullptr, blinker);

}


WmEntityMark* WmPlayerMark::getEntityAtNode(WmEntityMark* entities) {

	WmEntityMark* end = entities + ET_MAX;

	while (entities != end) {
		if (node == entities->node)
			return entities;
		entities++;
	}

	return nullptr;

}

void WmPlayerMark::issueTask(s32 taskID, WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	if (taskID >= TaskCount)
		return;

	Task& task = taskTbl[taskID];

	if (task.init != nullptr) {

		if (!(this->*task.init)(entities, blinker))
			return;

	}

	taskFunc = task.main;

}


bool WmPlayerMark::initIdle(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	node = save.game.currentWorldNode;
	startAnim(DispOn, node, blinker.Shared);
	entity = nullptr;
	return true;

}

void WmPlayerMark::updateIdle(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	if (WM::state & WM::ST_PlayerMove) {
		issueTask(Move, entities, blinker);
		return;
	}

	if (getEntityAtNode(entities)) {
		issueTask(EntityNode, entities, blinker);
	}

}

bool WmPlayerMark::initMove(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	if (entity) {
		entity->resumeBlink(blinker);
	}

	if (blinker.states[blinker.Shared] == 0) {
		startAnim(BlinkOn, node, blinker.Moving);
	} else {
		startAnim(BlinkOff, node, blinker.Moving);
	}

	return true;

}

void WmPlayerMark::updateMove(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	if (WM::state & WM::ST_PlayerMove)
		return;

	// Player done moving
	issueTask(Idle, entities, blinker);

}

bool WmPlayerMark::initEntityNode(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	entity = getEntityAtNode(entities);
	if (entity) {
		entity->suspendBlink();
	}

	if (blinker.states[blinker.Moving] == 0) {
		startAnim(BlinkOn, node, blinker.Shared);
	} else {
		startAnim(BlinkOff, node, blinker.Shared);
	}

	return true;

}

void WmPlayerMark::updateEntityNode(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	// Level exited, entity still present, now moving
	WmEntityMark* entity = getEntityAtNode(entities);
	if (entity == nullptr) {
		issueTask(Idle, entities, blinker);
		return;
	}

	if (entity != this->entity) {
		this->entity = entity;
		this->entity->suspendBlink();
	}

	if (WM::state & WM::ST_PlayerMove) {
		issueTask(Move, entities, blinker);
	}

}


void WmPlayerMark::update(WmEntityMark* entities, WmNodeMarkBlinker& blinker) {

	if (taskFunc != nullptr) {
		(this->*taskFunc)(entities, blinker);
	}

	updateAnim(blinker);

}



WmPathMap::WmPathMap() {}
WmPathMap::~WmPathMap() {}

WmMapPathInfo* WmPathMap::getPathInfo(u32 world) {
	return WmMinimap::paths[WmMinimap::getWorldID(world)];
}

u32 WmPathMap::getUnlockedPathMask() {

	u32 world = save.game.currentWorld;
	u32 mask = 0;

	s32 pathCount = wxPathCount;
	for (int i = 0; i < pathCount; i++) {

		u8 in = i;
		if (u8(save.game.pathStates[world][in] & PS_Unk40) != 0) {
			mask |= 1 << i;
		}

	}

	return mask;

}

void WmPathMap::writeTiles(const WmMapPathTile* tiles, u32 count) {

	if (tiles == nullptr)
		return;

	const WmMapPathTile* end = tiles + count;
	u16* scr = rcast<u16*>(G2S_GetBG0ScrPtr());

	for (; tiles != end; tiles++) {

		u16* srcTile = &scr[tiles->srcTile];
		u16 tile = (*srcTile & 0xFC00) |
			tiles->charNo & 0x3FF;

		MI_CpuCopy8(&tile, srcTile, 2);

	}

}

bool WmPathMap::unlock(u32 pathMask) {

	WmMapPathInfo* info = getPathInfo(save.game.currentWorld);
	bool unlocked = false;

	if (info != nullptr) {

		u32 prevMask = this->pathMask;
		WmMapPath** paths;
		WmMapPath** end = info->paths + info->count;

		for (paths = info->paths; paths != end; ++paths) {

			WmMapPath* path = *paths;
			u32 mask = path->mask;
			if (mask == (mask & pathMask) && mask != (mask & prevMask)) {
				writeTiles(path->tiles, path->count);
				prevMask |= (*paths)->mask;
				unlocked = true;
			}

		}

		this->pathMask = pathMask;

	}

	return unlocked;

}


void WmPathMap::create() {

	u32 mask = getUnlockedPathMask();
	pathMask = 0;
	unlock(mask);

}

void WmPathMap::update() {

	u32 mask = getUnlockedPathMask();
	if (mask != pathMask) {
		unlock(mask);
	}

}


u32 WmPathMap::getNscFile(u32 world) {
	return WmMinimap::mainNscTbl[WmMinimap::getWorldID(world)];
}

u32 WmPathMap::getMaskNscFile(u32 world) {
	return WmMinimap::maskNscTbl[WmMinimap::getWorldID(world)];
}
