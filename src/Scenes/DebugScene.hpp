#include "Scene.hpp"

class DebugScene : public Scene
{
public:
    u8 _pad0[0x17c];
    u32 _1d8;
    u32 _1dc;
    u32 _1e0;
    u32 _1e4;
    i32 _1fc;
    i32 _204;
    u8 _pad2[0x40];

    inline DebugScene();
    ~DebugScene();
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
