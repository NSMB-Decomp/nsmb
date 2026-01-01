#include "StageEntity.hpp"
#include "Model.hpp"

class Object_156 : public StageEntity {
public:
    Model model;
    inline Object_156();
    ~Object_156();
    void* create();
};
//size_assert(Object_156, 0x4dc)