#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 39  |  ov066  |  profile @ 0x02178af0
class Object39 : public StageEntity {
public:
	static void *create();
	inline Object39() {};
	inline ~Object39() {};
};

extern ActorProfile Object39_Profile;

