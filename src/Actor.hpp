#include "base_types.hpp"
#include "Base.hpp"
#include "Vec.hpp"

class Actor: public Base {
public:
    u32 x;
    u8 actorCategory;
    Vec3 position;
    Vec3 lastStep;
    Vec3 lastPosition;
    bool visible;
    u8 actorType;
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    bool postCreate();
    void postDestroy(u32);
    bool preUpdate();
    void postUpdate();
    bool preRender();


    virtual void setPosX(u32);
    virtual void incPosX(u32);
};