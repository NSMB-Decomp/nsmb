#pragma once

#include "../../../src/base_types.hpp"

namespace Game {

void saveBackupParams();
void loadBackupParams();
void resetStageCheckpoint();
bool getStageCheckpoint();
void loadLevel(
	u16 scene,
	u32 versusMode,
	u8 group,
	u8 stage,
	u8 act,
	u8 playerID,
	u8 playerMask,
	u8 character1,
	u8 character2,
	u8 powerup,
	u8 entrance,
	u8 flag,
	u8 unused1,
	u8 controlOptions,
	u8 unused2,
	u8 challengeMode,
	u32 randomSeed);

}
