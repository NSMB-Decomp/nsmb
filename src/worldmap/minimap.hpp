#pragma once
#include "scene.hpp"

struct WmMapPathTile {
	u16 srcTile;
	u16 charNo;
};
size_assert(WmMapPathTile, 0x4);

struct WmMapPath {
	u32 mask;
	WmMapPathTile* tiles;
	u8 count;
};
size_assert(WmMapPath, 0xC);

struct WmMapPathInfo {
	WmMapPath** paths;
	u8 count;
};
size_assert(WmMapPathInfo, 0x8);

struct WmMapNodePos {
	s16 x;
	s16 y;
};
size_assert(WmMapNodePos, 0x4);

struct WmMapNodeInfo {
	WmMapNodePos* nodes;
	u8 count;
};
size_assert(WmMapNodeInfo, 0x8);

class WmNodeMarkBlinker {
public:

	enum State {
		DispOn,
		DispOff,
		StateCount
	};

	enum BlinkType {
		Entity,
		Shared,
		Moving,
		TypeCount
	};

	WmNodeMarkBlinker();
	~WmNodeMarkBlinker();

	void create();
	void update();

	static const u16 blinkTbl[TypeCount][StateCount];

	u16 timers[TypeCount];
	u8 states[TypeCount];

};
size_assert(WmNodeMarkBlinker, 0xA);

class WmNodeMark {
public:

	typedef bool(WmNodeMark::* AnimInitFunc)(s32 node, u32 blinkType);
	typedef void(WmNodeMark::* AnimMainFunc)(WmNodeMarkBlinker& blinker);

	enum AnimID {
		DispOff,
		DispOn,
		BlinkOff,
		BlinkOn,
		AnimCount
	};

	struct AnimTask {
		AnimInitFunc init;
		AnimMainFunc main;
	};

	WmNodeMark();
	~WmNodeMark();

	void create(s32 animID, s32 node, u32 cellIdx, u32 blinkType);

	void getNodePos(WmMapNodePos& pos, u32 node);
	void startAnim(s32 animID, s32 node, u32 blinkType);

	bool initDispOff(s32 node, u32 blinkType);
	bool initDispOn(s32 node, u32 blinkType);
	bool initBlinkOff(s32 node, u32 blinkType);
	void updateBlinkOff(WmNodeMarkBlinker& blinker);
	bool initBlinkOn(s32 node, u32 blinkType);
	void updateBlinkOn(WmNodeMarkBlinker& blinker);

	void updateAnim(WmNodeMarkBlinker& blinker);
	void render();

	static AnimTask taskTbl[AnimCount];

	AnimMainFunc animFunc;
	WmMapNodePos pos;
	u32 cellIdx;
	u8 visible;
	u32 blinkType;

};
size_assert(WmNodeMark, 0x18);

class WmEntityMark : public WmNodeMark {
public:

	typedef bool(WmEntityMark::* InitFunc)(WmNodeMarkBlinker& blinker);
	typedef void(WmEntityMark::* MainFunc)(WmNodeMarkBlinker& blinker);

	enum TaskID {
		Idle,
		Move,
		TaskCount
	};

	struct Task {
		InitFunc init;
		MainFunc main;
	};

	WmEntityMark();
	~WmEntityMark();

	void create(u32 type, WmNodeMarkBlinker& blinker);

	void suspendBlink();
	void resumeBlink(WmNodeMarkBlinker& blinker);
	void issueTask(s32 taskID, WmNodeMarkBlinker& blinker);

	bool initIdle(WmNodeMarkBlinker& blinker);
	void updateIdle(WmNodeMarkBlinker& blinker);
	bool initMove(WmNodeMarkBlinker& blinker);
	void updateMove(WmNodeMarkBlinker& blinker);

	void update(WmNodeMarkBlinker& blinker);

	static Task taskTbl[TaskCount];

	MainFunc taskFunc;
	u32 type;
	u32 taskID;
	u8 node;

};
size_assert(WmEntityMark, 0x2C);

class WmPlayerMark : public WmNodeMark  {
public:

	typedef bool(WmPlayerMark::* InitFunc)(WmEntityMark*, WmNodeMarkBlinker&);
	typedef void(WmPlayerMark::* MainFunc)(WmEntityMark*, WmNodeMarkBlinker&);

	enum TaskID {
		Idle,
		Move,
		EntityNode,
		TaskCount
	};

	struct Task {
		InitFunc init;
		MainFunc main;
	};

	WmPlayerMark();
	~WmPlayerMark();

	void create(WmNodeMarkBlinker& blinker);

	WmEntityMark* getEntityAtNode(WmEntityMark* entities);
	void issueTask(s32 taskID, WmEntityMark* entities, WmNodeMarkBlinker& blinker);

	bool initIdle(WmEntityMark* entities, WmNodeMarkBlinker& blinker);
	void updateIdle(WmEntityMark* entities, WmNodeMarkBlinker& blinker);
	bool initMove(WmEntityMark* entities, WmNodeMarkBlinker& blinker);
	void updateMove(WmEntityMark* entities, WmNodeMarkBlinker& blinker);
	bool initEntityNode(WmEntityMark* entities, WmNodeMarkBlinker& blinker);
	void updateEntityNode(WmEntityMark* entities, WmNodeMarkBlinker& blinker);

	void update(WmEntityMark* entities, WmNodeMarkBlinker& blinker);

	static const u32 playerMarkCellTbl[2]; // TODO: Character count constant
	static Task taskTbl[TaskCount];

	MainFunc taskFunc;
	WmEntityMark* entity;
	u8 node;

};
size_assert(WmPlayerMark, 0x28);

class WmPathMap {
public:

	WmPathMap();
	~WmPathMap();

	static WmMapPathInfo* getPathInfo(u32 world);
	static u32 getUnlockedPathMask();
	void writeTiles(const WmMapPathTile* tiles, u32 count);
	int unlock(u32 pathMask);

	void create();
	void update();

	static u32 getNscFile(u32 world);
	static u32 getMaskNscFile(u32 world);

	u32 pathMask;

};
size_assert(WmPathMap, 0x4);

class WmMinimap : public Object {
public:

	WmMinimap();
	~WmMinimap();

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();

	static u32 getWorldID(u32 world);
	static void* create();

	static WmMapPath w1Paths[7];
	static WmMapPath w2Paths[11];
	static WmMapPath w3Paths[8];
	static WmMapPath w4Paths[7];
	static WmMapPath w5Paths[10];
	static WmMapPath w6Paths[5];
	static WmMapPath w7Paths[13];
	static WmMapPath w8Paths[3];
	static WmMapPath w8Paths2[3];
	static WmMapPathInfo w1PathInfo;
	static WmMapPathInfo w2PathInfo;
	static WmMapPathInfo w3PathInfo;
	static WmMapPathInfo w4PathInfo;
	static WmMapPathInfo w5PathInfo;
	static WmMapPathInfo w6PathInfo;
	static WmMapPathInfo w7PathInfo;
	static WmMapPathInfo w8PathInfo;
	static WmMapPathInfo w8PathInfo2;
	static WmMapPathInfo* paths[9];
	static const WmMapNodeInfo nodes[9];
	static const u32 mainNscTbl[9];
	static const u32 maskNscTbl[9];
	static ObjectProfile profile;

	WmEntityMark entityMarks[WM::ET_MAX];
	WmPlayerMark playerMark;
	WmPathMap pathMap;
	WmNodeMarkBlinker markBlinker;

};
size_assert(WmMinimap, 0xEC);
