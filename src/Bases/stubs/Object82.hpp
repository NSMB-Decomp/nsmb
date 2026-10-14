#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 82  |  ov111  |  profile @ 0x0218a518
class Object82 : public StageEntity {
public:
	static void *create();
	inline Object82() {};
	inline ~Object82() {};
};

extern ActorProfile Object82_Profile;

