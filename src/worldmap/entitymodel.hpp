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

	void render(Mat4x3* mtx, Vec3_32* scale);

	void update();

	void init(u32 animID);


	static bool loadResources();


	ModelAnm model;
	AnimationCtrl texAnim;
	Model shadowModel;
	AnimationCtrl shadowAnim;
	u32 type;

};
size_assert(WmEntityModel, 0x198);
