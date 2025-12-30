#include "../Bases/Object.hpp"

class MGScene: public Object {
public:
  inline ~MGScene();
  MGScene();

  bool preCreate();
  void postCreate(u32);
  bool preDestroy();
  void postDestroy(u32);
  bool preUpdate();
  void postUpdate();
  bool preRender();
  void postRender();
};
MGScene::~MGScene(){};