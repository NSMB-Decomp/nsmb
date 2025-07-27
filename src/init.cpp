#include "Nitro/Nitro.hpp"
#include "base_types.hpp"

void func_0204c7f4(u32, void *);
void func_02005098();
void SystemThreadsSleep();
void func_02005230();
void func_02021654();
void func_0200a594();
void func_020132a0();
void func_02014a44();
void func_01ff9010();
void func_0201031c();
void func_020058c0();
void func_02010094();
void func_02014a30();
void Graphics_2DStep();
void ProcessManager_ExecuteTasks();
void func_020123d8();
void func_02005ab0();
bool Wifi_isMultiBootCart();
void func_020046d8();
void func_02013100();
void FS_init();
void FS_Overlays_loadOverlay(u32);
void FS_Overlays_unload(u32);
void func_020097d0();
void func_01ff80e0(u32);
void func_02012744();
void func_0202176c();
void func_02010444(u32);
void func_0204c8fc();
void func_02044ad8(u32, u32);
void func_0200a9d0();
void func_02006cf4();
void func_0200e508();
void Graphics_Init();
void func_020125d4();
void func_020125e8();
void func_02043d10();
void func_0202187c();
void func_020133a4();
void func_01ff9010();
void func_0200e040();
void func_02014a58();
void __stub_1();
void __stub_2();
void __stub_3();
void func_020455d8();
void __stub_4();
void func_0200a0b4();
void func_020050ec();
void func_020050d8();
void func_020050c0();

void func_ov001_020cceb4();

u32 *CurrentProfileTable;
u32 MainProfileTable;
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
  func_020046d8();
  Nitro::func_0206d554();
  func_0204c7f4(0xd01, GAME_NAME);
  func_02013100();
  FS_init();
  func_020097d0();
  if (is_multiboot_cart != false) {
    func_01ff80e0(0x100000);
  } 
  if (is_multiboot_cart == false) {
    func_02012744();
  }
  func_0202176c();
  func_02010444(2);
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
  func_01ff9010();
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
    func_02005230();
    func_02021654();
    func_0200a594();
    Nitro::Graphics::ResetOAM();
    bool rendered_frame = Nitro::Graphics::Step();
    if (rendered_frame) {
      func_020132a0();
      ProcessManager_ExecuteTasks();
      func_02014a44();
    }
    FrameCounter += 1;
    func_01ff9010();
    Nitro::Graphics::SwapBuffer(data_02085a78, data_02085a74);
    func_0201031c();
    func_020058c0();
    func_02010094();
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
  Nitro::func_0206f3cc(*func_02005098);
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