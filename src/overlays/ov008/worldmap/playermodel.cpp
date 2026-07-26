#include "../../../worldmap/playermodel.hpp"
#include "../../../AAA.hpp"
#include <nsmb/file_ids.hpp>

enum pl_map {
	pl_map_run,
	pl_map_wait,
	pl_map_walk,
	pl_map_pipe_pose,
	pl_map_course_in,
	pl_map_coin_comp,
	pl_map_L_run,
	pl_map_L_wait,
	pl_map_L_walk,
	pl_map_small_wait
};


const u32 WmPlayerModel::charaRunAnimIDs[2] = {
	pl_map_run,
	pl_map_L_run
};

const u32 WmPlayerModel::charaWalkAnimIDs[2] = {
	pl_map_walk,
	pl_map_L_walk
};

const u32 WmPlayerModel::charaWaitAnimIDs[2] = {
	pl_map_wait,
	pl_map_L_wait
};

const WmPlayerModel::Config WmPlayerModel::configTbl[P_MAX] = {
	{ 1, 0 }, // Small
	{ 0, 0 }, // Super
	{ 0, 1 }, // Fire
	{ 1, 0 }, // Mini
	{ 0, 0 } // Shell
};

const WmPlayerModel::Anim WmPlayerModel::animTbl[A_MAX] = {
	// Wait
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_small_wait, _FixedFlt(1.0), FrameCtrl::Looping,  10, 0 },
	// Walk
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_walk,       _FixedFlt(1.0), FrameCtrl::Looping,  5,  0 },
	// Run
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_run,        _FixedFlt(1.0), FrameCtrl::Looping,  5,  0 },
	// PipePose
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_pipe_pose,  _FixedFlt(1.0), FrameCtrl::Looping,  0,  0 },
	// CourseIn
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_course_in,  _FixedFlt(1.0), FrameCtrl::Standard, 0,  0 },
	// CoinComp
	{ NSMB_FID(player_pl_map_LZ_bin), pl_map_coin_comp,  _FixedFlt(1.0), FrameCtrl::Standard, 0,  0 }
};


WmPlayerModel::WmPlayerModel() {}

WmPlayerModel::~WmPlayerModel() {}


bool WmPlayerModel::create(u8 playerID, u8 powerup, u32 animID) {

	if (!model.create(playerID, NSMB_FID(player_pl_map_LZ_bin)))
		return false;

	this->playerID = playerID;

	switch (powerup) {

	case POWERUP_SMALL:
	case POWERUP_SUPER:
	case POWERUP_FIRE:
		this->powerup = powerup;
		break;

	case POWERUP_SHELL:
		this->powerup = P_Shell;
		break;

	case POWERUP_MINI:
	case POWERUP_MEGA:
	default:
		this->powerup = P_Small;
		break;

	}

	config = configTbl + this->powerup;
	modelState = config->modelState;
	model.modelState = modelState;
	model.flags &= ~0x4;
	this->animID = -1;

	init(animID, FALSE);
	return true;

}

void WmPlayerModel::render(Mat4x3* mtx, Vec3_32* scale) {
	if (powerup == P_Shell) {
		model.flags |= F_RenderShell;
	} else {
		model.flags &= ~F_RenderShell;
	}

	model.render(*mtx, *scale, config->paletteID, FALSE,
		data_ov000_020caa30, data_ov000_020caa2c, FALSE);
}

void WmPlayerModel::update(u32 moveState) {

	if (moveState == 0)
		model.update();

}

void WmPlayerModel::init(u32 animID, BOOL resume) {

	this->animID = animID;

	const Anim& anim = animTbl[this->animID];
	u32 resIdx = anim.animID;
	u16 startFrame;

	if (!resume) {
		if (anim.speed < 0) {
			startFrame = model.getAnimationFrameCount() - 1;
		} else {
			startFrame = 0;
		}
	} else {
		startFrame = model.getCurrentAnimationFrame();
	}

	switch (this->animID) {

	case A_Wait:
		if (modelState != 1) {
			resIdx = charaWaitAnimIDs[playerID];
		}
		break;

	case A_Walk:
		resIdx = charaWalkAnimIDs[playerID];
		break;

	case A_Run:
		resIdx = charaRunAnimIDs[playerID];
		break;

	}

	void* animFile = FS::Cache::getFile(anim.fileID);
	if (animFile != nullptr) {
		void* animRes = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), resIdx);
		if (animRes != nullptr) {
			model.setBodyAnimation(animRes, 0, anim.type, anim.speed, startFrame);
		}
	}

	initHead(anim.headAnimID);

}

void WmPlayerModel::initHead(u32 animID) {

	if (headAnimID == animID)
		return;

	headAnimID = animID;

	const PlayerHeadAnimation& headAnim = model.headAnimations[playerID][headAnimID];

	void* animFile = FS::Cache::getFile(model.headPatternFileIDs[playerID]);
	if (animFile != nullptr) {
		void* animRes = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), headAnim.animID);
		if (animRes != nullptr) {
			model.setHeadAnimation(animRes, headAnim.type, headAnim.speed, headAnim.startFrame);
		}
	}

}


bool WmPlayerModel::loadResources() {
	void* modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_model_LZ_bin, Dat_Init_mario_model_LZ_bin), true);
	Ns3dModelList* modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	Ns3dModelData* modelData = Ns_3dGetModel(modelList, 0);
	Ns3dMaterialList* matList = Ns_3dGetMaterials(modelData);
	Ns3dMaterialData* matData = Ns_3dGetMaterial(matList, 0);
	u32 i;
	Game::setPlayerPaletteParams(0, matData->paletteParam);
	Game::setPlayerTextureParams(0, matData->textureParam);

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 0);
	Game::setPlayerPaletteParams(1, matData->paletteParam);
	Game::setPlayerTextureParams(1, matData->textureParam);

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_head_cap_LZ_bin, Dat_Init_mario_head_cap_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(2, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 2, matData->textureParam);
	}

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(3, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 4, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_head_nocap_LZ_bin, Dat_Init_mario_head_nocap_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 6, matData->textureParam);
	}

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 8, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_deadhead_LZ_bin, Dat_Init_mario_deadhead_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(4, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 10, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_deadhead_n_LZ_bin, Dat_Init_mario_deadhead_n_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 14, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_model_LZ_bin, Dat_Init_luigi_model_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 0);
	Game::setPlayerPaletteParams(6, matData->paletteParam);
	Game::setPlayerTextureParams(16, matData->textureParam);

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 0);
	Game::setPlayerPaletteParams(7, matData->paletteParam);
	Game::setPlayerTextureParams(17, matData->textureParam);

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_head_cap_LZ_bin, Dat_Init_luigi_head_cap_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(8, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 18, matData->textureParam);
	}

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(9, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 20, matData->textureParam);
	}

	FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_head_nocap_LZ_bin, Dat_Init_luigi_head_nocap_LZ_bin), true);

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 22, matData->textureParam);
	}

	modelData = Ns_3dGetModel(modelList, 1);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 24, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_deadhead_LZ_bin, Dat_Init_luigi_deadhead_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	matData = Ns_3dGetMaterial(matList, 1);
	Game::setPlayerPaletteParams(10, matData->paletteParam);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 26, matData->textureParam);
	}

	modelFile = FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_deadhead_n_LZ_bin, Dat_Init_luigi_deadhead_n_LZ_bin), true);
	modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));

	modelData = Ns_3dGetModel(modelList, 0);
	matList = Ns_3dGetMaterials(modelData);
	for (i = 0; i < matList->dict.itemCount; i++) {
		matData = Ns_3dGetMaterial(matList, i);
		Game::setPlayerTextureParams(i + 30, matData->textureParam);
	}

	FS::Cache::loadFile(NSMB_FID(player_pl_map_LZ_bin), true);
	FS::Cache::loadFile(
		NSMB_VS_FID(player_mario_LZ_bin, Dat_Init_mario_LZ_bin), true);
	FS::Cache::loadFile(
		NSMB_VS_FID(player_luigi_LZ_bin, Dat_Init_luigi_LZ_bin), true);

	PlayerCap::loadResources();
	PlayerShell::loadResources();
	return true;
}
