#include "base_types.hpp"
#include "Base.hpp"

class Actor: public Base {
public:
    u32 x;
    u8 actorCategory;
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();
    bool preCreate();
    bool postCreate();
    void postDestroy(u32);
    bool preUpdate();


    virtual void setPosX(u32);
    virtual void incPosX(u32);
};