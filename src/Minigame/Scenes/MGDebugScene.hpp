#include "MGScene.hpp"

class MGDebugScene: public MGScene {
public:
  inline ~MGDebugScene();
  inline MGDebugScene();
  
  bool func_ov130_02126ab0();

  bool preCreate();
  bool preUpdate();
  virtual void virt_18();
  virtual void virt_19();
  virtual void virt_20();
};
MGDebugScene::MGDebugScene(){}
MGDebugScene::~MGDebugScene(){}