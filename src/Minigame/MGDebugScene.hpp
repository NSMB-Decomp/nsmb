#include "MGScene.hpp"

class MGDebugScene: public MGScene {
public:
  ~MGDebugScene();
  MGDebugScene();
  
  bool func_ov130_02126ab0();

  bool preCreate();
  bool preUpdate();
  virtual void virt_18();
  virtual char* virt_19(u32);
  virtual void virt_20(u32);
};
inline MGDebugScene::MGDebugScene(){}
inline MGDebugScene::~MGDebugScene(){}