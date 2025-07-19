#include "base_types.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

ObjectProfile** CurrentProfileTable;
