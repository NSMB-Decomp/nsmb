#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 191  |  ov090  |  profile @ 0x02185088
class Object191 : public StageEntity {
public:
	static void *create();
	inline Object191() {};
	inline ~Object191() {};
};

extern ActorProfile Object191_Profile;

