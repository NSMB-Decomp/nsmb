#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 54  |  ov068  |  profile @ 0x02179180
class Object54 : public StageEntity {
public:
	static void *create();
	inline Object54() {};
	inline ~Object54() {};
};

extern ActorProfile Object54_Profile;

