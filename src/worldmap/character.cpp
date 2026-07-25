#include "character.hpp"
#include "camera.hpp"
#include <nsmb/core/filesystem.hpp>
#include <nsmb/file_ids.hpp>
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

WmCharacter::TaskFunc data_ov008_020ee79c[4];
WmCharacter::TaskFunc data_ov008_020ee7bc[4];

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

extern "C" void func_ov008_020db380(WmCharacter* character)
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

extern "C" void func_ov008_020db3d8(WmCharacter* character)
{
	if (character->unk2A0 == 0) {
		data_ov008_020ee388 = 1;
	}

	character->unk2A8 = 1;
	character->timer = 10;
}

extern "C" void func_ov008_020db404(WmCharacter* character)
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

extern "C" void func_ov008_020db48c(WmCharacter* character)
{
	character->timer = 60;
}

extern "C" void func_ov008_020db790(WmCharacter* character)
{
	character->unk2A4 = 0;
	character->savedY = character->targetPosition.y;
	character->unk2B0 = 0;

	if ((character->anim->flag & WM::AF_PeachSfxJump) != 0) {
		data_ov008_020ee3b0 = character->anim->flag & WM::AF_ModelType;
	}
}

extern "C" void func_ov008_020db7c4(WmCharacter* character)
{
	if (data_ov008_020ee3d0 != 0) {
		func_ov008_020db354(character, 1);
	}
}

extern "C" void func_ov008_020db7f4()
{
}

extern "C" bool func_ov008_020db7f8(WmCharacter* character)
{
	if (data_ov008_020ee384 != 0) {
		return true;
	}

	if ((WM::state & WmCharacter::SF_UnkBit0) != 0) {
		func_ov008_020db2e0(character);
	}

	return true;
}

extern "C" bool func_ov008_020db840(WmCharacter* character)
{
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

extern "C" void func_ov008_020db9fc()
{
}

extern "C" bool func_ov008_020dba00()
{
	WM::state |= WmCharacter::SF_UnkBit2;
	return true;
}

extern "C" bool func_ov008_020dba1c(WmCharacter* character)
{
	u32 world = save.game.currentWorld;
	WmCharacterSettings settings;
	settings.raw = character->settings;
	character->playerID = settings.bits.playerBits & 1;

	void* modelFile = FS::Cache::getFile(
		data_ov008_020e98d8[character->playerID].fileID);
	void* animFile = FS::Cache::getFile(
		data_ov008_020e98dc[character->playerID].fileID);
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

extern "C" s32 func_ov008_020dbaf0(WmCharacter* character)
{
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

extern "C" WmCharacter* func_ov008_020dbc40()
{
	return new WmCharacter;
}
