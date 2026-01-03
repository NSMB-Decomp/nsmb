#include "Nitro.hpp"
#include "base_types.hpp"
#include "AAA.hpp"
#include "Scenes/Scene.hpp"

void InitGame() {
  u16 *REG_IME = (u16 *)0x04000208;

  Nitro::func_02063fd4();
  func_02005ab0();
  Nitro::func_01ff8128(1);
  u16 ime = *REG_IME;
  *REG_IME = 1;
  Nitro::func_01ffa5ec(1, ime);
  Nitro::func_02060e38(1);
  bool is_multiboot_cart = Nitro::Wifi_isMultiBootCart();
  Nitro::Math__stub();
  setupGraphicsForDebugScreen();
  Nitro::func_0206d554();
  Save_setupBackup(0xd01, GAME_NAME);
  Save_clearLoadedSaves();
  Nitro::FS_init();
  Nitro::FS_Archive_loadMainGameArchives();
  if (is_multiboot_cart != false) {
    Nitro::func_01ff80e0(0x100000);
  } 
  if (is_multiboot_cart == false) {
    loadBuildtimeFile();
  }
  TouchPad_init();
  prepareWifiStuff(2);
  func_0204c8fc();
  func_02044ad8(0x38000, 0);
  func_0200a9d0();
  func_02006cf4();
  func_0200e508();
  Graphics_Init();
  if (is_multiboot_cart != 0) {
    func_020125d4();
  } else {
    func_020125e8();
  }
  func_02043d10();
  CurrentProfileTable = &MainProfileTable;
  func_0202187c();
  func_020133a4();
  Nitro::func_01ff9010();
  Nitro::func_02061588(3);
  u32 *GFX_FIFO_LIGHT_DIRECTION = (u32 *)0x040004c8;
  *GFX_FIFO_LIGHT_DIRECTION = 0x296a5800;
  u32 *GFX_FIFO_LIGHT_COLOR = (u32 *)0x040004cc;
  *GFX_FIFO_LIGHT_COLOR = 0x7fff;
  u32 *GFX_FIFO_MATERIAL_DIFFUSE_AMBIENT = (u32 *)0x040004c0;
  *GFX_FIFO_MATERIAL_DIFFUSE_AMBIENT = 0x7fff;
  u32 *GFX_FIFO_MATERIAL_SPECULAR_EMISSION = (u32 *)0x040004c4;
  *GFX_FIFO_MATERIAL_SPECULAR_EMISSION = 0;
  func_0200e040();
  u16 *REG_POWER_CNT = (u16 *)0x04000304;
  *REG_POWER_CNT = *REG_POWER_CNT | 0x8000;
  func_02014a58();
  __stub_1();
  __stub_2();
}

void StartGameLoop() {
  u32 *GFX_FIFO_SWAP_BUFFERS = (u32 *)0x04000540;

  SystemThreadsSleep();
  Nitro::EnableDisplay();

  do {
    doFadingTransition();
    TouchPad_update();
    Input_update();
    Nitro::Graphics_ResetOAM();
    bool rendered_frame = Nitro::Graphics_Step();
    if (rendered_frame) {
      Scene::tryChangeScene();
      ProcessManager_ExecuteTasks();
      Font_updateFont();
    }
    FrameCounter += 1;
    Nitro::func_01ff9010();
    Nitro::Graphics_SwapBuffer(data_02085a78, data_02085a74);
    Wifi_updatePackets();
    System_waitForVBlank();
    Wifi_update();
    func_02014a30();
    Graphics_2DStep();
    func_020123d8();
  } while (true);
}

void (*func_020046c0)();
u32* data_02094384;

void InitNitroMainGame() {
  Nitro::OS_InitTick();
  Nitro::OS_InitAlarm();
  Nitro::MultiThread_Init();
  Nitro::Exception_SetHandler(&func_020046c0, &data_02094384);
}

void InitMainGame() {
  InitNitroMainGame();
  InitGame();
  StartGameLoop();
}

void SharedGameInit() {
  Nitro::MainInit();
  __stub_3();
  Nitro::func_0206f3cc(*CardPulledOutCallback);
  data_020850e8 = 1;
  func_020455d8();
  __stub_4();
}

void initExtendedIds(bool) {
  u32 overlay_id = OVERLAY_BOOT;
  Nitro::FS_Overlays_loadOverlay(overlay_id);
  func_ov001_020cceb4();
  Nitro::FS_Overlays_unload(overlay_id);
}

void sceneBaseInit() {
  bool a = Nitro::Wifi_isMultiBootCart();
  if (a) {
    func_020125e8();
  }
  Nitro::FS_Overlays_loadOverlay(OVERLAY_MISC);
  initExtendedIds(a);
  func_0200a0b4();
  data_0203981c = func_020050ec;
  data_02039820 = func_020050d8;
  data_02039824 = func_020050c0;
}