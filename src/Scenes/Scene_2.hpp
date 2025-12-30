#include "Scene.hpp"

class Scene_2 : public Scene
{
public:
    u8 _pad0[0x1d4];

    inline Scene_2();
    ~Scene_2();
    void *operator new(u32);

    void func_ov002_020cc328();
    void func_ov002_020cc514();

    bool onCreate();
    bool onDestroy();
    bool onUpdate();
    bool onRender();
    void pendingDestroy();
    bool onHeapCreated();
};
