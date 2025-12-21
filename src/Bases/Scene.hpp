#include "Base.hpp"

class Scene: public Base {
public:
  bool preCreate();
  void postCreate(u32);
  bool preDestroy();
  void postDestroy(u32);
  bool preUpdate();
  void postUpdate(u32);
  bool preRender();
  void postRender(u32);
};