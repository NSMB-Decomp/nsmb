#include "base_types.hpp"
#include "Base.hpp"
#include "Vec.hpp"

class Actor: public Base {
public:
    Vec3 position;
    Vec3 lastPosition;
    Vec3 lastStep;
    Vec3 centerOffset;
    Vec3s rotation;
    Vec3s loastRotation;
    i32 velH; // TODO: These names are awful, fix them D:<.
    i32 minVelH;
    i32 accelH;
    i32 accelV;
    i32 minVelV;
    u32 __unknown;
    Vec3 velocity;
    Vec3 minVelocity;
    Vec3 scale;
    Vec3 acceleration;
    Vec3 velocitylimit;
    u8 actorType;
    bool visible;
    u8 linked_player;
    u8 actorCategory;

    void linkPlayer(u8);
    
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    bool postCreate();
    void postDestroy(u32);
    bool preUpdate();
    void postUpdate();
    bool preRender();
    void postRender();


    virtual void setPosX(u32);
    virtual void incPosX(u32);
};