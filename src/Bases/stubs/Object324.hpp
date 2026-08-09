#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 324  |  ov008  |  profile @ 0x020e9bf0
class Object324 : public StageEntity {
public:
	static void *create();
	inline Object324() {};
	inline ~Object324() {};
};

extern ActorProfile Object324_Profile;

