#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 161  |  ov010  |  profile @ 0x02125904
class Object161 : public StageEntity {
public:
	static void *create();
	inline Object161() {};
	inline ~Object161() {};
};

extern ActorProfile Object161_Profile;

