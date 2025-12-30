#include "Scene.hpp"

class StageScene: public Scene {
    Vec3_32 _3f0;
    u8 _pad0[0x63c4];
public:
    void* operator new(u32);
    StageScene();
};