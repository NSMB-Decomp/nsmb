#include "./base_types.hpp"
#include "AAA.hpp"

enum GAME_MODE { A, B };

u32 DAT_027FFC20;
int main() {
  u32 game_mode;
  u32 boot_scene;

  if (isMultiBootCart()) {
    if ((func_020109c8() != 0)) {
      game_mode = A;
    } else {
      game_mode = B;
    }
    boot_scene = 0;
  } else {
    game_mode = DAT_027FFC20 & 0xf;
    boot_scene = (DAT_027FFC20 & 0xf00) >> 0x8;
  };
  u32 a = (DAT_027FFC20 & 0xf0000) >> 0x10;
  SetMasterGameMode(game_mode);
  SetBootScene(boot_scene);
  SetExtraBootParam((a));

  while (true) {
    InitGame();
  };
};
