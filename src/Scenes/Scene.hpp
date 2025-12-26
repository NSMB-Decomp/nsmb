#include "../Bases/Object.hpp"

class Scene: public Object {
public:
  ~Scene();
  Scene();

  bool preCreate();
  void postCreate(u32);
  bool preDestroy();
  void postDestroy(u32);
  bool preUpdate();
  void postUpdate(u32);
  bool preRender();
  void postRender(u32);
};