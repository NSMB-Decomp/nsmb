#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 107  |  ov070  |  profile @ 0x02177488
class Object107 : public StageEntity {
public:
	u8 _pad0[0x10];

	static void *create();
	inline Object107() {};
	inline ~Object107() {};
};

extern ActorProfile Object107_Profile;

