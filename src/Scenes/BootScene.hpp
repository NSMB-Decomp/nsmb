#include "Scene.hpp"

class BootScene : public Scene
{
public:
    u8 _7a;
    u8 _7b;
    u8 _7c;
    u8 _7d;
    u8 _pad0[0x20];

    inline BootScene();
    ~BootScene();
    void *operator new(u32);

    bool onCreate();
    bool onDestroy();
    bool onUpdate();
    bool onRender();
    void pendingDestroy();
};