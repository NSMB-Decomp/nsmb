#pragma once
#include "scene.hpp"
#include "entitymodel.hpp"
#include "playermodel.hpp"
#include "../graphics/graphics3d.hpp"
#include "../Bases/Actor.hpp"

class WmController : public Actor {
public:

	typedef void(WmController::* TaskFunc)();

	enum TaskID {
		Idle,
		CourseIn,
		Walk,
		Walk2,
		AnimFortOut,
		AnimFortIn,
		AnimCourseIn,
		MoveEntities,
		Task8,
		PathUnlock,
		Th1,
		Th2,
		CameraMove,
		CameraReturn,
		Task14,
		Task15,
		SignRemove,
		SignPrompt,
		Task18,
		Task19
	};

	void issueTask(u32 taskID);


	void moveEntities();

	static void moveEntitiesLoop(u8* entityMoves, u32 entityIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order);

	static void moveEntitiesOnce(u8* entityMoves, u32 entityIdx, u32 moveIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order);

	static s32 getEntityMoveIndex(u32 entityIndex, u32 moveCount, u32 moveStep);

	static bool isEntityAtNode(u8 node, u32 entityIdx, u32* entityNodes);

	static bool canEntityTransitLink(WM::NodeLink* link);

	static bool canEntityStopAtNode(WM::NodeLink* link);


	WmPlayerModel playerModels[2];
	WmEntityModel entityModels[2];

	Model worldModel;
	Model* sourceModel;
	AnimationCtrl worldMatAnim;
	AnimationCtrl worldTexSRT;
	AnimationCtrl worldTexAnim;

	Model treeModel;
	AnimationCtrl treeBoneAnim;
	AnimationCtrl treeTexAnim; // Unused

	ModelAnm towerCastleModels[4];
	ModelAnm bridgeModel;

	Model nodeModels[4];
	AnimationCtrl nodeTexAnims[4];

	Model signModels[5];
	AnimationCtrl signBoneAnims[5];
	AnimationCtrl signTexAnims[5];

	Model toadHouseModels[5];

	Model windowModel;

	ModelAnm playerCursor;
	ModelAnm entityCursor[2];

	u32 unk1E18;

	Vec3_32 cursorPosition;
	Vec3_32 entityRenderPos[2];
	Vec3_32 entityOffset[2];
	Vec3_32 entityPosition[2];
	Vec3_32 playerPowerupScale;
	Vec3_16 unk1E9C;
	Vec3_32 unk1EA8;
	Vec3_16 unk1EB8;
	Vec3_32 unk1EC4;
	Vec3_32 unk1ED4;
	Vec3_32 unk1EE4[4];
	Vec3_32 signPos[5];
	Vec3_16 signRot[5];
	Vec3_32 unk1FB0[8];
	Vec3_32 unk2030;
	Vec3_32 unk2040;
	Vec3_32 unk2050;
	Vec2_32 unk2060;
	u32 unk206C;

	TaskFunc taskFunc;
	u32 taskID;
	u32 startTask; // BOOL?

	s32 entityDirs[2];
	u32 unk2088;
	u32 unk208C;
	u32 entityUnk2090[2];
	u32 unk2098;
	u32 unk209C;
	u32 entityUnk20A0[2];
	u32 entityUnk20A8[2];
	u32 unk20B0;
	u32 unk20B4;

	u32 playerCursorFrame;

	u32 unk20BC;
	u32 unk20C0;
	u32 unk20C4;
	u32 unk20C8;
	u32 unk20CC;

	u32 pathPolyID1;
	u32 pathPolyID2;
	u32 pathPolyID3;
	u32 otherPolyID;

	u32 unk20E0;
	u32 unk20E4;
	u32 unk20E8;
	u32 unk20EC;
	u32 unk20F0;
	u32 unk20F4;
	u32 unk20F8;
	u32 unk20FC;

	u32 entityTypes[2];

	u32 pathMdlNodes[30];
	u32 pathMdlAlpha[30];

	u32 materials[2]; //???

	u32 unk2200;
	u32 unk2204;
	u32 unk2208;
	u32 unk220C;
	u32 unk2210; // Related to music-based tree animation
	u32 unk2214;
	u32 unk2218;
	u32 unk221C;
	u32 unk2220;
	u32 unk2224;
	s32 envParticleIDs[2];
	EmitterT envEmitterIDs[2];
	EmitterT flamesEmitterIDs[2][3]; // 2 flames, 3 emitters
	u32 unk2250;
	u32 unk2254;
	u32 unk2258;
	u32 unk225C;
	u32 unk2260;
	u32 unk2264;
	u32 unk2268;

	u32 exitInteractionType; // None, Tower, Castle, Tower2 or FinalCastle

	u32 worldMatAnimFileID;
	u32 worldTexSRTFileID;
	u32 worldTexAnimFileID;
	u32 treeModelFileID;
	u32 treeBoneAnimFileID;
	u32 treeTexAnimFileID; // Unused
	u32 towerModelFileID;
	u32 castleModelFileID;

	s16 entityRotY[2];
	u16 unk2294[2];
	u16 entityUnk2298[2];

	u16 unk229C[10];
	u8 nodeStates[25];
	u8 signStates[5];
	u8 toadHouseStates[8];
	u8 unk22D6[2];
	u8 entityStates[2][2];
	u8 unk22DC[2];
	u8 entityNoRotY[2];
	u8 unk22E0[4];
	u8 unk22E4;
	u8 bridgeFlags;
	u8 currentNode;
	u8 unk22E7;
	u8 luigiMode;
	u8 playerPowerupMini;
	u8 unk22EA;
	u8 unk22EB;
	u8 unk22EC;
	u8 unk22ED;
	u8 unk22EE;
	u8 unk22EF;
	u8 unk22F0;
	u8 unk22F1;
	s8 unk22F2;
	u8 playerDirection;
	u8 musicPlayReq;
	u8 treeMusicSyncStart;
	u8 unk22F6; // Related to music-based tree animation
	u8 unk22F7;
	u8 levelExit;
	u8 unk22F9;
	u8 unk22FA;
	u8 manualCameraState;

};
size_assert(WmController, 0x22FC);
