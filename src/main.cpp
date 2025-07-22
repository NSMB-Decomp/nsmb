#include "./base_types.hpp"
bool isMultiBootCart();
bool func_020109c8();
void InitGame();
void SetMasterGameMode(u32);
void SetBootScene(u32);
void SetExtraBootParam(u32);

void main() {
  u8 game_mode;
  u32 boot_scene;
  u32 *DAT_0200306c = (u32 *)0x027FFC20;

  if (isMultiBootCart()) {
    game_mode = (u32)func_020109c8() != 0;
    boot_scene = 0;
  } else {
    game_mode = *DAT_0200306c & 0xf;
    boot_scene = (*DAT_0200306c) >> 8;
  };
  u32 a = (*DAT_0200306c & 0xf0000) >> 0x10;
  SetMasterGameMode(game_mode);
  SetBootScene(boot_scene);
  SetExtraBootParam((a));

  while (true) {
    InitGame();
  };
};

