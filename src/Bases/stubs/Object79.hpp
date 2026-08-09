#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 79  |  ov047  |  profile @ 0x02148284
class Object79 : public StageEntity {
public:
	static void *create();
	inline Object79() {};
	inline ~Object79() {};
};

extern ActorProfile Object79_Profile;

