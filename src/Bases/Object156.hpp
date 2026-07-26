#pragma once
#include "../graphics/3d/model.hpp"
#include "StageEntity.hpp"

class Object156 : public StageEntity
{
      public:
	Model model;
	u8 _pad1[0x58];
	inline Object156();
	~Object156();
	void *create();
};
NTR_SIZE_GUARD(Object156, 0x4dc);
