#pragma once
#include "../graphics/3d/modelanm.hpp"
#include "../graphics/3d/animationctrl.hpp"

class WmEntityModel {
public:

	struct FileInfo {
		u32 modelFile;
		u32 animFile;
	};

	virtual ~WmEntityModel();


	ModelAnm model;
	AnimationCtrl texAnim;
	Model shadowModel;
	AnimationCtrl shadowAnim;
	u32 type;

};
size_assert(WmEntityModel, 0x198);
