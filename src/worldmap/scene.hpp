#pragma once
#include "../Scenes/Scene.hpp"

namespace WM {

	// For save data
	enum WorldState {
		WS_Visited        = 0x40,
		WS_Completed      = 0x80, // maybe?
		WS_ArrowToadHouse = 0x1000,
	};

	enum NodeState {
		NS_StarCoin1     = 0x1,
		NS_StarCoin2     = 0x2,
		NS_StarCoin3     = 0x4,
		NS_ToadHouseType = 0x3,
		NS_StandardExit  = 0x10,
		NS_ToadHouseDone = 0x20,
		NS_LevelDone     = 0x40,
		NS_Completed     = 0x80,
	};

	enum PathState {
		PS_Unk40    = 0x40, // can be walked by entity?
		PS_Unlocked = 0x80,
	};


	enum NodeLinkFlag {
		LF_Direction = 0x3,
		LF_Pipe      = 0x10, // maybe?
		LF_Reverse   = 0x40, // maybe?
	};

	struct NodeLink {
		u8 node;
		u8 path;
		u16 flag;
	};

	enum NodeType {
		NT_Arrow,
		NT_1,
		NT_2,
		NT_3,
		NT_4,
		NT_5,
		NT_6,
		NT_7,
		NT_8,
		NT_A,
		NT_B,
		NT_C,
		NT_GhostHouse,
		NT_Tower,
		NT_Castle,
		NT_Pipe,
		NT_Cannon,
		NT_ToadHouseRed,
		NT_ToadHouseGreen,
		NT_ToadHouseYellow,
		NT_Fork,
		NT_Tower2,
		NT_FinalCastle,
		NT_ToadHousePurple,
		NT_MAX
	};

	enum NodeFlag {
		NF_StarCoins   = 0x1,
		NF_Tower       = 0x2,
		NF_Castle      = 0x4,
		NF_Course      = 0x8,
		NF_Final       = 0x10,
		NF_Tower2      = 0x20,
		NF_FinalCastle = 0x40,
		NF_W8Castle    = 0x80,
		NF_Fork        = 0x100,
	};

	struct Node {
		NodeLink* links;
		u16 areaID;
		u8 unk6;
		u8 type;
		u16 flag;
		u16 unkA;
	};
	size_assert(Node, 0xC);

	enum PathFlag {
		PF_Unk1 = 0x1,
		PF_Sign = 0x2,
		PF_Pipe = 0x4,
	};

	struct Path {
		u8 animID;
		u8 price;
		u8 flag;
		u8 unk3;
	};
	size_assert(Path, 0x4);

	enum EntityType {
		ET_HammerBro,
		ET_FlyingBlock,
		ET_MAX,
		ET_Invalid = -1
	};

	struct Entity {
		u8 node;
		u8 type;
	};
	size_assert(Entity, 0x2);

	struct Point {
		u32 unk0;
		u32 unk4;
		u32 unk8;
		fx32 x;
		fx32 y;
		fx32 z;
	};
	size_assert(Point, 0x18);

	struct Sign {
		u32 path;
		fx32 x;
		fx32 y;
		fx32 z;
	};
	size_assert(Sign, 0x10);

	struct ToadHouse {
		u32 node;
		fx32 x;
		fx32 y;
		fx32 z;
	};
	size_assert(ToadHouse, 0x10);

	enum AnimFlag {
		AF_ModelType    = 0x3,
		AF_PeachSfxJump = 0x4,  // maybe?
		AF_Reverse      = 0x10, // maybe?
		AF_PeachSfxHelp = 0x20, // maybe?
	};

	struct Anim { // FortTransit in ghidra
		u8 path;
		u8 flag;
	};
	size_assert(Anim, 0x2);



	struct World {
		Node* nodes;
		Path* paths;
		Entity* entities;
		Point* points;
		Sign* signs;
		void* unk14;
		ToadHouse* toadHouses;
		Anim** anims;
		u16 nodeCount;
		u16 pathCount;
		u16 flag;
		u16 unk26;
	};


	extern World worlds[8];
	extern Node* wxNodes;
	extern Path* wxPaths;
	extern Entity* wxEntities;
	extern Point* wxPoints;
	extern Sign* wxSigns;
	extern u8* wxUnk14;
	extern ToadHouse* wxToadHouses;
	extern Anim** wxAnims;
	extern u32 wxNodeCount;
	extern u32 wxPathCount;

	extern u32 nodeState;

	extern u16 entityPlttOfsTbl[ET_MAX];

}

class WorldmapScene : public Scene {
public:



};
size_assert(WorldmapScene, 0x64);
