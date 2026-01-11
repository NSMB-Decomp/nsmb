#include "../base_types.hpp"
#include "../Vec.hpp"
#include "Object.hpp"

Vec3_32 *ActorSpawnPosition;
Vec3_16 *ActorSpawnRotation;
i8 *ActorSpawnPlayer;
i32 *ActorSpawnScale;

struct Rect
{
    i32 x;
    i32 y;
    i32 halfWidth;
    i32 halfHeight;
};
size_assert(Rect, 0x10);

class Actor : public Object
{
public:
    Vec3_32 position;
    Vec3_32 lastPosition;
    Vec3_32 lastStep; // 0x78
    Vec3_32 centerOffset;
    Vec3_16 rotation;
    Vec3_16 lastRotation;
    i32 velH; // TODO: These names are awful, fix them D:<.
    i32 minVelH;
    i32 accelV;
    i32 minVelV;
    i32 accelH;       // 0xC4
    u32 _c8;          // 0xC8
    Vec3_32 velocity; // 0xCA
    Vec3_32 minVelocity;
    Vec3_32 scale;
    Vec3_32 acceleration;
    Vec3_32 velocitylimit;
    u8 actorType; // 0x11C
    bool visible;
    i8 linked_player; // 0x11E
    u8 actorCategory; // 0x11F

    void linkPlayer(i32);
    u32 getActorCount(u8);
    void applyVelocity();
    void updateVerticalVelocity();
    void updateHorizontalVelocity();
    void setDirectionalVelocity3D();
    void applyDirectionalVelocity3D();
    void attenuateAcceleration();
    static Actor *spawnActor(u16, u32, Vec3_32 *, Vec3_16 *, i32 *, i8 *);
    void applyDirectionalVelocity();
    static void setSpawnParams(Vec3_32 *, Vec3_16 *, i32 *, i8 *);
    void applyVelocityToPosition(Vec3_32 *);
    Vec3_32 applyAcceleration(Vec3_32 *);
    void StepVelocityYClamped();
    void StepVelocityXClamped();
    void stepVelocityClamped();
    Vec3_32 getCenteredPosition();
    bool isOutOfViewVertical(Rect *, int);
    bool isInFrontOfTarget(Actor*);
    bool isBehindTarget(Actor*);
    i32 getDistanceToPlayer(i32, i32);
    static i32 calcDistanceToPlayerNoWrap(i32, i32, i32, i32);
    static i32 calcDistanceToPlayerWrap(i32, i32, i32, i32);
    static bool isBehindTargetWrap(i32, i32);
    static void setCalcPositionToPlayerFunction(u32);
    static void wrapPosition(u32, u32, u32);
    static bool isBehindTargetNoWrap(i32, i32);
    static void initWrapFunctions(u32);
    static void setIsBehindTargetFunction(u32);
    static void setWrapPositionFunction();
    Actor();
    ~Actor();

    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    void postCreate(u32);
    void postDestroy(u32);
    bool preUpdate();
    void postUpdate(u32);
    bool preRender();
    void postRender(u32);

    virtual void setPosX(u32);
    virtual void incPosX(u32);
};