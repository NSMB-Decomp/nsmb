#include "Model.hpp"
#include "StageEntity.hpp"

class Object_156 : public StageEntity
{
      public:
	  u8 _pad0[0x2];
	Model model;
	u8 _pad1[0xe4];
	inline Object_156();
	~Object_156();
	void *create();
};
// size_assert(Object_156, 0x4dc)
