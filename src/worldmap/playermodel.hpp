#pragma once
#include "../player/model.hpp"
#include "../graphics/3d/modelanm.hpp"
#include "../graphics/3d/animationctrl.hpp"

class WmPlayerModel {
public:

	enum Powerup {
		P_Small,
		P_Super,
		P_Fire,
		P_Mini, // Unused
		P_Shell,
		P_MAX
	};

	enum AnimID {
		A_Wait,
		A_Walk,
		A_Run,
		A_PipePose,
		A_CourseIn,
		A_CoinComp,
		A_MAX
	};

	struct Anim {
		u32 fileID;
		u32 animID;
		fx32 speed;
		u32 type;
		u32 unk10;
		u32 headAnimID;
	};

	struct Config {
		s8 modelState;
		s8 paletteID;
	};

	WmPlayerModel();

	virtual ~WmPlayerModel();


	bool create(u8 playerID, u8 powerup, u32 animID);

	void render(Mat4x3* mtx, Vec3_32* scale);

	void update(u8 moveState);

	void init(u32 animID, BOOL resume);

	void initHead(u32 animID);


	static bool loadResources();


	static const u32 charaRunAnimIDs[2];
	static const u32 charaWalkAnimIDs[2];
	static const u32 charaWaitAnimIDs[2];
	static const Config configTbl[P_MAX];
	static const Anim animTbl[A_MAX];

	PlayerModel model;
	const Config* config;
	u32 animID;
	u32 headAnimID;
	u8 playerID;
	s8 modelState;
	s8 powerup;

};
size_assert(WmPlayerModel, 0x3D8);
