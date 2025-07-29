#include "Nitro/Nitro.hpp"
#include "base_types.hpp"
#include "AAA.hpp"

u16 data_020850e8;
void (*data_0203981c)();
void (*data_02039820)();
void (*data_02039824)();
char GAME_NAME[8] = "Mario2d";

void InitGame() {
  u16 *REG_IME = (u16 *)0x04000208;

  Nitro::func_02063fd4();
  func_02005ab0();
  Nitro::func_01ff8128(1);
  u16 ime = *REG_IME;
  *REG_IME = 1;
  Nitro::func_01ffa5ec(1, ime);
  Nitro::func_02060e38(1);
  bool is_multiboot_cart = Wifi_isMultiBootCart();
  Nitro::Math::__stub();
  setupGraphicsForDebugScreen();
  Nitro::func_0206d554();
  Save_setupBackup(0xd01, GAME_NAME);
  Save_clearLoadedSaves();
  FS_init();
  FS_Archive_loadMainGameArchives();
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

u32 FrameCounter;
u32 data_02085a78;
u32 data_02085a74;
void StartGameLoop() {
  u32 *GFX_FIFO_SWAP_BUFFERS = (u32 *)0x04000540;

  SystemThreadsSleep();
  Nitro::EnableDisplay();

  do {
    doFadingTransition();
    TouchPad_update();
    Input_update();
    Nitro::Graphics::ResetOAM();
    bool rendered_frame = Nitro::Graphics::Step();
    if (rendered_frame) {
      Scene_tryChangeScene();
      ProcessManager_ExecuteTasks();
      Font_updateFont();
    }
    FrameCounter += 1;
    Nitro::func_01ff9010();
    Nitro::Graphics::SwapBuffer(data_02085a78, data_02085a74);
    Wifi_updatePackets();
    System_waitForVBlank();
    Wifi_update();
    func_02014a30();
    Graphics_2DStep();
    func_020123d8();
  } while (true);
}

void InitNitroMainGame() {
  // Temp values
  u32 a = 0x1234; // arm9_mainCODE
  u32 b = 0x4321; // autoload_3.bss
  Nitro::Tick::Init();
  Nitro::Timer::Init();
  Nitro::MultiThread::Init();
  Nitro::Exception::SetHandler(a, b);
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

void initExtendedIds() {
  u32 overlay_id = 1; // This need to be a pooled at the bottom
  FS_Overlays_loadOverlay(overlay_id);
  func_ov001_020cceb4();
  FS_Overlays_unload(overlay_id);
}

void sceneBaseInit() {
  u32 overlay_id = 0;
  bool a = Wifi_isMultiBootCart();
  if (a != false) {
    func_020125e8();
  }
  FS_Overlays_loadOverlay(overlay_id);
  initExtendedIds();
  func_0200a0b4();
  data_0203981c = func_020050ec;
  data_02039820 = func_020050d8;
  data_02039824 = func_020050c0;
}