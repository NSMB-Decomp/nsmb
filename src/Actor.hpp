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
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    bool postCreate();
    void postDestroy(u32);
    bool preUpdate();


    virtual void setPosX(u32);
    virtual void incPosX(u32);
};