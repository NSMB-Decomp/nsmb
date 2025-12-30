#include "Scene.hpp"

class BootScene: public Scene {
public: 
    u8 _pad0[0x24];

    inline BootScene();
    void* operator new(u32);

    bool onCreate();  
};