#include "../Bases/Object.hpp"

class MGScene: public Object {
public:
  inline ~MGScene();
  MGScene();

  static void func_02024ab8();
  static void func_02024bec(u16, u32, u32);
  static void func_02024ad0(void*);

  bool preCreate();
  void postCreate(u32);
  bool preDestroy();
  void postDestroy(u32);
  bool preUpdate();
  void postUpdate(u32);
  bool preRender();
  void postRender();
};
MGScene::~MGScene(){};