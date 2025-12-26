#include "Base.hpp"
#include "../Scenes/Scene.hpp"

class Object: public Base {
public:
    Object* spawnObject(u32, u32, u32);
    static Scene* spawnScene(u32, u32, u32);
    void __stub();

    void postCreate(u32);
    inline ~Object();
};
Object::~Object() {}