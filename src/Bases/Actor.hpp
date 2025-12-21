#include "../base_types.hpp"
#include "../Vec.hpp"
#include "Object.hpp"

class Actor: public Object {
public:
    Vec3_32 position;
    Vec3_32 lastPosition;
    Vec3_32 lastStep;
    Vec3_32 centerOffset;
    Vec3_16 rotation;
    Vec3_16 lastRotation;
    i32 velH; // TODO: These names are awful, fix them D:<.
    i32 minVelH;
    i32 accelH;
    i32 accelV;
    i32 minVelV;
    u32 __unknown;
    Vec3_32 velocity;
    Vec3_32 minVelocity;
    Vec3_32 scale;
    Vec3_32 acceleration;
    Vec3_32 velocitylimit;
    u8 actorType;
    bool visible;
    u8 linked_player;
    u8 actorCategory;

    void linkPlayer(i32);
    u32 getActorCount(u8);
    Actor();
    
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    void postCreate(u32);
    void postDestroy(u32);
    bool preUpdate();
    void postUpdate();
    bool preRender();
    void postRender();

    virtual void setPosX(u32);
    virtual void incPosX(u32);
};