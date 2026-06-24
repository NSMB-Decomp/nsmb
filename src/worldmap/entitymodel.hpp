#pragma once
#include "scene.hpp"
#include "../graphics/3d/modelanm.hpp"
#include "../graphics/3d/animationctrl.hpp"

class WmEntityModel {
public:

	struct FileInfo {
		u32 modelFile;
		u32 animFile;
	};

	WmEntityModel();

	virtual ~WmEntityModel();


	bool create(u32 type);

	void render(const Mat4x3& mtx, const Vec3_32& scale, const Vec3_32& offset);

	void update();

	void init(u32 animID);


	static bool loadResources();


	static u16 paletteBase;
	static u32 subAnimTbl[2];
	static u32 mainAnimTbl[WM::ET_MAX][2];
	static FileInfo fileInfo[WM::ET_MAX];

	ModelAnm model;
	AnimationCtrl anim; // Flying block texture pattern anim
	Model subModel; // Hammer or shadow model
	AnimationCtrl subAnim; // Shadow anim
	u32 type;

};
size_assert(WmEntityModel, 0x198);
