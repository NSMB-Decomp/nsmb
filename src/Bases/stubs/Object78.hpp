#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 78  |  ov013  |  profile @ 0x0213bbec
class Object78 : public StageEntity {
public:
	static void *create();
	inline Object78() {};
	inline ~Object78() {};
};

extern ActorProfile Object78_Profile;

