#include "../../../worldmap/character.hpp"
#include "../../../AAA.hpp"
#include "../../../worldmap/camera.hpp"
#include "../../../objectid.hpp"
#include <nsmb/core/filesystem.hpp>
#include <nsmb/file_ids.hpp>
#include <nsmb/game/particle.hpp>
#include <nsmb/overlays/ov008/symbols.hpp>

namespace {
union WmCharacterSettings {
	u32 raw;
	struct {
		u32 animation : 4;
		u32 unused0 : 24;
		u32 playerBits : 4;
	} bits;
};
}

WmCharacterTaskEntry data_ov008_020e988c = {
	{ WmCharacter_setupTask1, 0 },
};

WmCharacterTaskEntry data_ov008_020e9894 = {
	{ WmCharacter_setupTask0, 0 },
};

WmCharacterTaskEntry data_ov008_020e989c = {
	{ WmCharacter_mainTask2, 0 },
};

WmCharacterTaskEntry data_ov008_020e98a4 = {
	{ WmCharacter_mainTask1, 0 },
};

WmCharacterTaskEntry data_ov008_020e98ac = {
	{ WmCharacter_mainTask0, 0 },
};

WmCharacterTaskEntry data_ov008_020e98b4 = {
	{ WmCharacter_mainTask3, 0 },
};

WmCharacterTaskEntry data_ov008_020e98bc = {
	{ WmCharacter_setupTask3, 0 },
};

WmCharacterTaskEntry data_ov008_020e98c4 = {
	{ WmCharacter_setupTask2, 0 },
};

WmCharacter::TaskFunc data_ov008_020ee79c[4] = {
	data_ov008_020e9894.member,
	data_ov008_020e988c.member,
	data_ov008_020e98c4.member,
	data_ov008_020e98bc.member,
};

WmCharacter::TaskFunc data_ov008_020ee7bc[4] = {
	data_ov008_020e98ac.member,
	data_ov008_020e98a4.member,
	data_ov008_020e989c.member,
	data_ov008_020e98b4.member,
};

ActorProfile WmCharacter::profile = {
	func_ov008_020dbc40,
	WM_Character,
	0x127,
	func_ov008_020db28c,
};

WmCharacterResource WmCharacter::resources[2] = {
	{ NSMB_FID(map_cursor_koopa_jr_nsbmd), NSMB_FID(map_cursor_koopa_jr_nsbca) },
	{ NSMB_FID(map_cursor_peach_nsbmd), NSMB_FID(map_cursor_peach_nsbca) },
};

extern "C" WmCharacter* func_ov008_020db204(WmCharacter* character)
{
	character->WmCharacter::~WmCharacter();
	return character;
}

extern "C" WmCharacter* func_ov008_020db244(WmCharacter* character)
{
	character->WmCharacter::~WmCharacter();
	Base::operator delete(character);
	return character;
}

extern "C" bool func_ov008_020db28c()
{
	FS::Cache::loadFile(NSMB_FID(map_cursor_koopa_jr_nsbmd), false);
	FS::Cache::loadFile(NSMB_FID(map_cursor_koopa_jr_nsbca), false);
	FS::Cache::loadFile(NSMB_FID(map_cursor_peach_nsbmd), false);
	FS::Cache::loadFile(NSMB_FID(map_cursor_peach_nsbca), false);
	return true;
}

extern "C" void func_ov008_020db2e0(WmCharacter* character)
{
	if (character->startTask != 0) {
		(character->*data_ov008_020ee79c[character->taskID])();
		character->startTask = 0;
	}

	(character->*character->taskFunc)();
}

extern "C" void func_ov008_020db354(WmCharacter* character, u32 taskID)
{
	character->taskID = taskID;
	character->taskFunc = data_ov008_020ee7bc[taskID];
	character->startTask = 1;
}

extern "C" void WmCharacter_mainTask3(WmCharacter* character)
{
	if (character->unk2A8 != 0) {
		return;
	}

	character->timer--;
	if (character->timer != 0) {
		return;
	}

	data_ov008_020ee3e8 = data_ov008_020ee48c.x;
	character->destroy();
}

extern "C" void WmCharacter_setupTask3(WmCharacter* character)
{
	if (character->unk2A0 == 0) {
		data_ov008_020ee388 = 1;
	}

	character->unk2A8 = 1;
	character->timer = 10;
}

extern "C" void WmCharacter_mainTask2(WmCharacter* character)
{
	character->model.update();
	character->timer--;
	if (character->timer != 0) {
		return;
	}

	character->unk29C = 0;
	if ((WM::state & WmCharacter::SF_UnkBit3) != 0) {
		data_ov008_020ee3e8 = data_ov008_020ee48c.x;
		data_ov008_020ee3ac = 1;
		character->destroy();
		return;
	}

	func_ov008_020db354(character, 3);
}

extern "C" void WmCharacter_setupTask2(WmCharacter* character)
{
	character->timer = 60;
}

extern "C" void WmCharacter_mainTask1(WmCharacter* character)
{
	u8 flags = character->anim->flag;
	if ((flags & WM::AF_PeachSfxJump) != 0) {
		if (character->scale.x != 0) {
			character->scale.x -= 0x40;
			character->scale.y -= 0x40;
			character->scale.z -= 0x40;
		}
	} else if ((flags & WM::AF_ScaleUp) != 0) {
		if (character->scale.x < 0x1000) {
			character->scale.x += 0x40;
			character->scale.y += 0x40;
			character->scale.z += 0x40;
		}
	} else {
		fx32 currentY = character->targetPosition.y;
		fx32 previousY = character->savedY;
		character->savedY = currentY;
		fx32 distance = currentY - previousY;

		if (character->unk2B0 != 0) {
			if (distance < 0) {
				distance = -distance;
			}
			if (distance < 0x10) {
				func_02022b64(0xd, &character->targetPosition);
				character->unk2B0 = 0;
			}
		} else {
			if (distance > 0x10) {
				func_02022b64(0xd, &character->targetPosition);
				character->unk2B0 = 1;
			} else {
				character->unk2A4 = func_02022890(
					character->unk2A4,
					0x15,
					&character->targetPosition,
					0,
					0,
					0,
					0);
			}

			if (character->playerID == 0
				&& (character->model.frameController.passing(3)
					|| character->model.frameController.passing(0x12))) {
				func_02012398(0x1a, 0);
			}
		}
	}

	character->model.frameController.update();
	character->cursorModel.frameController.update();
	if (!character->cursorModel.frameController.finished()) {
		return;
	}

	flags = character->anim->flag;
	if ((flags & WM::AF_PeachSfxJump) != 0) {
		data_ov008_020ee3b0 = flags & WM::AF_ModelType;
		WM::state |= WM::ST_Unk10;
	} else if ((flags & WM::AF_ScaleUp) != 0) {
		character->scale.x = 0x1000;
		character->scale.y = 0x1000;
		character->scale.z = 0x1000;
	}

	character->anim++;

	if ((character->anim->flag & WM::AF_PeachSfxJump) != 0 && character->playerID != 0) {
		func_02012398(0x1b, 0);
	}
	if ((character->anim->flag & WM::AF_PeachSfxHelp) != 0 && character->playerID != 0) {
		func_02012398(0x27, 0);
	}

	if (character->anim->path == 0xff) {
		u16 nodeFlag = WM::wxNodes[save.game.currentWorldNode].flag & WM::NF_Final;
		if (nodeFlag != 0) {
			character->destroy();
			return;
		}
		func_ov008_020db354(character, 2);
		return;
	}

	character->unk298 = 0;
	s32 speed = 0x1000;
	if ((character->anim->flag & WM::AF_Reverse) != 0) {
		character->unk298 = 1;
		speed = -speed;
	}

	character->cursorModel.init(
		WM::wxPaths[character->anim->path].animID,
		FrameCtrl::Standard,
		speed,
		0);

	if (character->unk298 != 0) {
		character->cursorModel.frameController.currentFrame =
			character->cursorModel.frameController.getFrameCount() << 12;
	}
}

extern "C" void WmCharacter_setupTask1(WmCharacter* character)
{
	character->unk2A4 = 0;
	character->savedY = character->targetPosition.y;
	character->unk2B0 = 0;

	if ((character->anim->flag & WM::AF_PeachSfxJump) != 0) {
		data_ov008_020ee3b0 = character->anim->flag & WM::AF_ModelType;
	}
}

extern "C" void WmCharacter_mainTask0(WmCharacter* character)
{
	if (data_ov008_020ee3d0 != 0) {
		func_ov008_020db354(character, 1);
	}
}

extern "C" void WmCharacter_setupTask0(WmCharacter*)
{
}

s32 WmCharacter::onUpdate()
{
	WmCharacter* character = this;
	if (data_ov008_020ee384 != 0) {
		return true;
	}

	if ((WM::state & WmCharacter::SF_UnkBit0) != 0) {
		func_ov008_020db2e0(character);
	}

	return true;
}

s32 WmCharacter::onRender()
{
	WmCharacter* character = this;
	if ((WM::state & WmCharacter::SF_UnkBit0) != 0) {
		if (character->unk29C != 0) {
			Vec3_32 scale(0x1000);
			MTX::setTranslation(
				Game_modelMatrix,
				character->position.x,
				character->position.y,
				character->position.z);
			character->cursorModel.render(Game_modelMatrix, &scale);
			character->cursorModel.getNodeMatrix(0, &Game_modelMatrix);
			character->targetPosition.x = Game_modelMatrix.s.m30;
			character->targetPosition.y = Game_modelMatrix.s.m31;
			character->targetPosition.z = Game_modelMatrix.s.m32;

			if ((WM::state & WmCharacter::SF_UnkBit0) != 0) {
				if (character->unk298 != 0) {
					MTX::rotateY(Game_modelMatrix, -0x8000);
				}

				Mat4x3 transform = Game_modelMatrix;
				if (character->taskID == 2) {
					transform.s.m00 = 0x1000;
					transform.s.m01 = 0;
					transform.s.m02 = 0;
					transform.s.m10 = 0;
					transform.s.m11 = 0x1000;
					transform.s.m12 = 0;
					transform.s.m20 = 0;
					transform.s.m21 = 0;
					transform.s.m22 = 0x1000;
				}
				character->model.render(transform, &character->scale);
			}
		} else {
			Vec3_32 target = data_ov008_020ee48c;
			character->unk2A8 = Math::expLerp(
				&character->targetPosition.x,
				target.x,
				0x200,
				0x10000,
				0x4400);
		}

		data_ov008_020ee48c.x = character->targetPosition.x;
		data_ov008_020ee48c.y = 0;
		data_ov008_020ee48c.z = 0;
	}

	return true;
}

void WmCharacter::pendingDestroy()
{
}

s32 WmCharacter::onDestroy()
{
	WM::state |= WmCharacter::SF_UnkBit2;
	return true;
}

bool WmCharacter::onHeapCreated()
{
	WmCharacter* character = this;
	u32 world = save.game.currentWorld;
	WmCharacterSettings settings;
	settings.raw = character->settings;
	character->playerID = settings.bits.playerBits & 1;

	void* modelFile = FS::Cache::getFile(
		resources[character->playerID].modelFileID);
	void* animFile = FS::Cache::getFile(
		resources[character->playerID].animFileID);
	if (!character->model.create(modelFile, animFile, 0, 0, 0)) {
		return false;
	}

	modelFile = FS::Cache::getFile(NSMB_FID(map_player_cursor_nsbmd));
	u32 animFileID = func_ov008_020ce214(world, 1);
	animFile = FS::Cache::getFile(animFileID);
	if (!character->cursorModel.create(modelFile, animFile, 0, 0, 0)) {
		return false;
	}
	return true;
}

s32 WmCharacter::onCreate()
{
	WmCharacter* character = this;
	if (!character->prepareResourcesSafe(0xA0, Memory_gameHeap)) {
		return 0;
	}

	character->scale.x = 0x1000;
	character->scale.y = 0x1000;
	character->scale.z = 0x1000;
	character->unk29C = 1;
	character->model.init(0, FrameCtrl::Looping, 0x1000, 0);

	WmCharacterSettings settings;
	settings.raw = character->settings;
	character->unk2A0 = settings.bits.animation;
	character->anim = WM::wxAnims[character->unk2A0];
	character->unk298 = 0;

	s32 speed = 0x1000;
	if ((character->anim->flag & WM::AF_Reverse) != 0) {
		character->unk298 = 1;
		speed = -speed;
	}
	character->cursorModel.init(
		WM::wxPaths[character->anim->path].animID,
		FrameCtrl::Standard, speed, 0);
	character->cursorModel.drawable.flags |= WmCharacter::DrawableFlagUnkBit2;

	if (character->unk298 != 0) {
		character->cursorModel.frameController.currentFrame =
			character->cursorModel.frameController.getFrameCount() << 12;
	}

	if ((character->anim->flag & WmCharacter::AnimFlagUnkBit3) != 0) {
		s32 scale =
			0x1000 - character->cursorModel.frameController.getFrameCount() * 0x40;
		if (scale < 0) {
			scale = 0;
		}
		character->scale.x = scale;
		character->scale.y = scale;
		character->scale.z = scale;
	}

	func_ov008_020db354(character, 1);
	return 1;
}

extern "C" void* func_ov008_020dbc40()
{
	return new WmCharacter;
}
