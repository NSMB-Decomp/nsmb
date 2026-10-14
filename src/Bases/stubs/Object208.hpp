#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 208  |  ov096  |  profile @ 0x02188208
class Object208 : public StageEntity {
public:
	static void *create();
	inline Object208() {};
	inline ~Object208() {};
};

extern ActorProfile Object208_Profile;

