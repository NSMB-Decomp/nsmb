#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 337  |  ov130  |  profile @ 0x02138e44
class Object337 : public StageEntity {
public:
	u8 _pad0[0xfc];

	static void *create();
	Object337();
	inline ~Object337() {};
};

extern ActorProfile Object337_Profile;

