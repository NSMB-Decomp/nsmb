#include "Base.hpp"
#include "../Scenes/Scene.hpp"

class Object: public Base {
public:
    static Object* spawnObject(u16, Base*, u32, u8);
    static Scene* spawnScene(u16, u32, u8);
    void __stub();

    void postCreate(u32);
    inline ~Object();
};
Object::~Object() {}