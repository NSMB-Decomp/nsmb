#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 183  |  ov096  |  profile @ 0x02188040
class Object183 : public StageEntity {
public:
	static void *create();
	inline Object183() {};
	inline ~Object183() {};
};

extern ActorProfile Object183_Profile;

