#include "Base.hpp"

class Object: public Base {
public:
    void* spawnObject();
    void* spawnScene();
    void __stub();

    void postCreate(u32);
    inline ~Object();
};
Object::~Object() {}