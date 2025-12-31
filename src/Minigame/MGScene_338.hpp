#include "MGDebugScene.hpp"

class MGScene_338 : public MGDebugScene {
public:
  u8 _pad[0xc];
  u32 _68;
  u8 _pa2[0x10];

  ~MGScene_338();
  inline MGScene_338();
  void* create();

  bool onCreate();
  bool onDestroy();
  void virt_18();
  u32 virt_19(u32);
  void virt_20();
};