#pragma once
#include "scene.hpp"
#include "entitymodel.hpp"
#include "playermodel.hpp"
#include "../graphics/graphics3d.hpp"
#include "../Bases/Actor.hpp"

struct WmEnvParticleState {
	EmitterT emitterID;
	u32 unknown;
};
NTR_SIZE_GUARD(WmEnvParticleState, 0x8);
NTR_OFFSET_GUARD(WmEnvParticleState, emitterID, 0x0);

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


	WmController();

	~WmController();


	void issueTask(u32 taskID);


	void moveEntities();

	static void moveEntitiesLoop(u8* entityMoves, u32 entityIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order);

	static void moveEntitiesOnce(u8* entityMoves, u32 entityIdx, u32 moveIdx, u8* moveTbl, u8* nodeTbl, u32* entityNodes, BOOL order);

	static s32 getEntityMoveIndex(u32 entityIndex, u32 moveCount, u32 moveStep);

	static bool isEntityAtNode(u8 node, u32 entityIdx, u32* entityNodes);

	static bool canEntityTransitLink(WM::NodeLink* link);

	static bool canEntityStopAtNode(WM::NodeLink* link);


	static void* create();


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

	WM::Anim* unk1E18;

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
	WM::NodeLink* selectedLink;

	TaskFunc taskFunc;
	u32 taskID;
	u32 startTask; // BOOL?

	s32 entityDirs[2];
	u32 unk2088;
	u32 unk208C;
	s32 entityUnk2090[2];
	s32 entityUnk2098[2];
	s32 entityUnk20A0[2];
	s32 entityUnk20A8[2];
	u32 unk20B0;
	u32 unk20B4;

	s32 playerCursorFrame;

	s32 unk20BC;
	u32 unk20C0;
	u32 unk20C4;
	u32 unk20C8;
	s32 unk20CC;

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
	s32 entityUnk20F8[2];

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
	s32 unk2228[2];
	EmitterT envEmitterIDs[2];
	EmitterT flamesEmitterIDs[2][3]; // 2 flames, 3 emitters
	u32 entityUnk2250[2];
	WmEnvParticleState envParticles[2];
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
	s16 unk2294[2];
	s16 entityUnk2298[2];

	u16 cameraScaleAngle;
	u16 unk229E;
	u32 towerCastleModelFlags[4];
	u8 nodeStates[25];
	u8 signStates[5];
	u8 toadHouseStates[8];
	u8 unk22D6[2];
	u8 entityStates[2][2];
	u8 unk22DC[2];
	u8 entityNoRotY[2];
	u8 unk22E0;
	u8 unk22E1;
	u8 unk22E2;
	u8 unk22E3;
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
	u8 unk22F2;
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
NTR_SIZE_GUARD(WmController, 0x22FC);
NTR_OFFSET_GUARD(WmController, entityUnk2090, 0x2090);
NTR_OFFSET_GUARD(WmController, entityUnk2098, 0x2098);
NTR_OFFSET_GUARD(WmController, entityUnk20A0, 0x20A0);
NTR_OFFSET_GUARD(WmController, entityUnk20A8, 0x20A8);
NTR_OFFSET_GUARD(WmController, entityUnk20F8, 0x20F8);
NTR_OFFSET_GUARD(WmController, selectedLink, 0x206C);
NTR_OFFSET_GUARD(WmController, unk2294, 0x2294);
NTR_OFFSET_GUARD(WmController, entityUnk2298, 0x2298);

namespace WM {
	extern WmController* instance;
}

extern "C" {
	extern u8 data_ov008_020ee3a8;
	extern WmController::TaskFunc data_ov008_020ee65c[];
	extern WmController::TaskFunc data_ov008_020ee6fc[];
	extern const u32 data_ov008_020e952c[4];
	extern fx32 data_ov008_020e956c[];
	extern const u8 data_ov008_020e2e3c[];
	extern const u8 data_ov008_020e2e41[];
	extern const u8 data_ov008_020e2e44[];

	void func_ov008_020d23b4(WmController* controller, void* callbackContext);
	void func_ov008_020d32c4(WmController* controller, u32 task);
	u32 func_ov008_020da730();
	u32 func_ov008_020da7f4(
		u32 currentWorld, u32 destinationWorld, u32 node);
	u32 func_ov008_020daa18(u32 world, WM::NodeLink* link);

	void func_ov008_020d24b0(void* callbackContext);
	void func_ov008_020d2b68(WmController* controller);
	u32 func_ov008_020d2be4(WmController* controller);
	void func_ov008_020d2024(WmController* controller, u32 index);
	u32 func_ov008_020d20ac();
	void func_ov008_020d21d0(WmController* controller, u32 node);
	void func_ov008_020d2264(WmController* controller, fx32 scale);
	u32 func_ov008_020d2c54(WmController* controller);
	u32 func_ov008_020d2c90(WmController* controller);
	u32 func_ov008_020d2cc8(WmController* controller);
	u32 func_ov008_020d2cf8(WmController* controller);
	u32 func_ov008_020d2d40(WmController* controller);
	u32 func_ov008_020d2d7c(WmController* controller, u32 value);
	void func_ov008_020d3240(WmController* controller);
	void func_ov008_020d3304(WmController* controller);
	void func_ov008_020d36fc(WmController* controller);
	void func_ov008_020d3774(WmController* controller);
	void func_ov008_020d3b1c(WmController* controller);
	void func_ov008_020d3b44(WmController* controller);
	void func_ov008_020d4278(WmController* controller);
	void func_ov008_020d4330(WmController* controller);
	void func_ov008_020d4378(WmController* controller);
	void func_ov008_020d4514(WmController* controller);
	void func_ov008_020d4548(WmController* controller);
	void func_ov008_020d511c(WmController* controller);
	void func_ov008_020d5140(WmController* controller, u8 value);
	void func_ov008_020d5294(WmController* controller);
	void func_ov008_020d52f0(WmController* controller);
	void func_ov008_020d582c(WmController* controller);
	void func_ov008_020d58f4(WmController* controller, u32 entity);
	void func_ov008_020d59a8(
		WmController* controller, u32 entity, WM::NodeLink* link);
	void func_ov008_020d5ab8(WmController* controller);
	void func_ov008_020d5af0(WmController* controller);
	void func_ov008_020d5b28(WmController* controller);
	void func_ov008_020d5d4c(WmController* controller);
	void func_ov008_020d5e64(WmController* controller);
	void func_ov008_020d61d8(WmController* controller);
	void func_ov008_020d6284(WmController* controller);
	void func_ov008_020d6384(WmController* controller);
	bool func_ov008_020d63e4(WmController* controller, u32 flags);
	void func_ov008_020d65dc(WmController* controller);
	void func_ov008_020d67f8(WmController* controller);
	void func_ov008_020d6a14(WmController* controller);
	void func_ov008_020d6a50(WmController* controller);
	void func_ov008_020d4368(WmController* controller);
	void func_ov008_020d3e58(WmController* controller);
	void func_ov008_020d3e7c(WmController* controller);
	void func_ov008_020d4a5c(WmController* controller);
	void func_ov008_020d4a74(WmController* controller);
	void func_ov008_020d45c0(WmController* controller);
	void func_ov008_020d45c4(WmController* controller);
	void func_ov008_020d4784(WmController* controller);
	void func_ov008_020d4788(WmController* controller);
	void func_ov008_020d4cdc(WmController* controller);
	void func_ov008_020d4e34(WmController* controller);
	void func_ov008_020d24c8(WmController* controller);
	void func_ov008_020d2694(
		WmController* controller, u32 emitUnlockEffect);
	u32 func_ov008_020d4d00(WmController* controller);
	void func_ov008_020d5284(WmController* controller);
	void func_ov008_020d6a40(WmController* controller);
	void func_ov008_020d6e1c();
	u32 func_ov008_020d6e30(WmController* controller);
	void func_ov008_020d81cc(WmController* controller);
	bool func_ov008_020d81d0(WmController* controller);
	u32 func_ov008_020d8a0c(WmController* controller);
	u32 func_ov008_020d29a0(WmController* controller);
	u32 func_ov008_020d2e00(WmController* controller);
	u32 func_ov008_020da724();
	u32 func_ov008_020da9a4(u32 world, WM::NodeLink* link);
}
