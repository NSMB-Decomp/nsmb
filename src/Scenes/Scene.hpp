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
  void postUpdate();
  bool preRender();
  void postRender();
};