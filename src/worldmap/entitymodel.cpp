#include "entitymodel.hpp"

using namespace WM;

enum {
	f_hammer_bros_nsbca = 1430 - 131,
	f_hammer_bros_nsbmd = 1431 - 131,
	f_pata_block_nsbmd = 1591 - 131,
	f_pata_block_nsbtp = 1592 - 131,
	f_hammer_map_nsbmd = 1698 - 131,
	f_map_shadow_nsbca = 1705 - 131,
	f_map_shadow_nsbmd = 1706 - 131,
	f_map_swing_nsbca = 1707 - 131,
};

u16 WmEntityModel::paletteBase;
u32 WmEntityModel::subAnimTbl[2];
u32 WmEntityModel::mainAnimTbl[WM::ET_MAX][2];

WmEntityModel::FileInfo WmEntityModel::fileInfo[WM::ET_MAX] = {
	{ f_hammer_bros_nsbmd, f_hammer_bros_nsbca  }, // HammerBro
	{ f_pata_block_nsbmd,  f_map_swing_nsbca    }  // FlyingBlock
};


WmEntityModel::WmEntityModel() {}

WmEntityModel::~WmEntityModel() {}


bool WmEntityModel::create(u32 type) {

	void* modelFile = FS::Cache::getFile(fileInfo[type].modelFile);
	void* animFile = FS::Cache::getFile(fileInfo[type].animFile);
	if (!model.create(modelFile, animFile, 0, 0, 0))
		return false;

	if (type == ET_HammerBro) {

		modelFile = FS::Cache::getFile(f_hammer_map_nsbmd);
		if (!subModel.create(modelFile, 0, 0))
			return false;

	} else if (type == ET_FlyingBlock) {

		animFile = FS::Cache::getFile(f_pata_block_nsbtp);
		if (!anim.createCtrl(&model.drawable, animFile, 0, model.texture))
			return false;

		// Set flying ? block color to red
		anim.setFrame(1);

		modelFile = FS::Cache::getFile(f_map_shadow_nsbmd);
		if (!subModel.create(modelFile, 0, 0))
			return false;

		animFile = FS::Cache::getFile(f_map_shadow_nsbca);
		if (!subAnim.createCtrl(&subModel.drawable, animFile, 0, nullptr))
			return false;

	}

	this->type = type;
	return true;

}

void WmEntityModel::render(const Mat4x3& mtx, const Vec3_32& scale, const Vec3_32& offset) {

	if (entityPlttOfsTbl[type] != 0xFFFF) {
		Ns3dMaterialData* matData = model.getMaterialData(0);
		u16 paletteOffset = entityPlttOfsTbl[type];
		matData->paletteParam = paletteOffset + paletteBase;
	}

	model.matrix = mtx;
	model.render(&scale);

	Mat4x3 n;
	Mat4x3 t;
	Mat4x3 m;

	if (type == ET_HammerBro) {

		// Get hand node matrix
		if (model.getNodeMatrix(3, &n)) {
			Game_modelMatrix = n;
			MTX::rotateX(Game_modelMatrix, C_DEG(-90));
			MTX::rotateY(Game_modelMatrix, C_DEG(-180));
			MTX::translate(Game_modelMatrix, 0, _FixedFlt(5.0), 0);

			// Render hammer to hand transform
			subModel.matrix = Game_modelMatrix;
			subModel.render(&scale);

		}

		return;
	}

	if (type == ET_FlyingBlock) {

		MTX::setTranslation(t, 0, -offset.y, 0);
		ConcatMat4x3(&t, &mtx, &m);

		subModel.matrix = m;
		subModel.render(&scale);

		return;
	}

}

void WmEntityModel::update() {

	model.update();

	if (type == ET_FlyingBlock) {
		subAnim.update();
	}

}

void WmEntityModel::init(u32 animID) {

	model.init(mainAnimTbl[type][animID], FrameCtrl::Looping, _FixedFlt(0.5), 0);

	if (type == ET_FlyingBlock) {
		subAnim.init(subAnimTbl[animID], FrameCtrl::Looping, _FixedFlt(0.5), 0);
	}

}


bool WmEntityModel::loadResources() {

	void* modelFile = FS::Cache::loadFile(f_hammer_bros_nsbmd, false);
	if (modelFile != nullptr) {
		Ns3dModelList* modelList = Ns_3dGetModelList(scast<Ns3dFileHeader*>(modelFile));
		Ns3dModelData* modelData = Ns_3dGetModel(modelList, 0);
		Ns3dMaterialList* matList =  Ns_3dGetMaterials(modelData);
		Ns3dMaterialData* matData = Ns_3dGetMaterial(matList, 0);
		paletteBase = matData->paletteParam;
	}

	FS::Cache::loadFile(f_hammer_bros_nsbca, false);
	FS::Cache::loadFile(f_hammer_map_nsbmd, false);
	FS::Cache::loadFile(f_pata_block_nsbmd, false);
	FS::Cache::loadFile(f_pata_block_nsbtp, false);
	FS::Cache::loadFile(f_map_swing_nsbca, false);
	FS::Cache::loadFile(f_map_shadow_nsbmd, false);
	FS::Cache::loadFile(f_map_shadow_nsbca, false);

	return true;

}