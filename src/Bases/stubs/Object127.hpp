#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 127  |  ov071  |  profile @ 0x02179880
class Object127 : public StageEntity {
public:
	static void *create();
	inline Object127() {};
	inline ~Object127() {};
};

extern ActorProfile Object127_Profile;

