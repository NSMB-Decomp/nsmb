#include "./base_types.hpp"
#include "AAA.hpp"

#define uRam027ffc20 *(u32*)0x27ffc20
int main()
{
	u32 game_mode;
	u32 boot_scene;

	if (isMultiBootCart()) {
		if ((Wifi_isMinigames() != 0)) {
			game_mode = 0;
		} else {
			game_mode = 1;
		}
		boot_scene = 0;
	} else {
		game_mode = uRam027ffc20 & 0xf;
		boot_scene = (uRam027ffc20 & 0xf00) >> 0x8;
	};
	u32 extra_boot_param = (uRam027ffc20 & 0xf0000) >> 0x10;
	SetMasterGameMode(game_mode);
	SetBootScene(boot_scene);
	SetExtraBootParam(extra_boot_param);

	while (true) {
		InitGame();
	};
};
