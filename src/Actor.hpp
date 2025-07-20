#include "base_types.hpp"
#include "Base.hpp"

class Actor: public Base {
public:
    u32 x;
    
    // TODO: Do we need to define these as virtual?
    bool preDestroy();


    virtual void setPosX(u32);
    virtual void incPosX(u32);
};