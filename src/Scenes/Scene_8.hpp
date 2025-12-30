#include "Scene.hpp"

class Scene_8 : public Scene
{
public:
    u8 _pad[0xc];

    inline Scene_8();
    ~Scene_8();
    static void *create();

    bool onCreate();
    bool onDestroy();
    bool onUpdate();
    bool onRender();
    void pendingDestroy();
};
