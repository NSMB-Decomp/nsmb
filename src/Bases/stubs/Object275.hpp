#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 275  |  ov010  |  profile @ 0x02124938
class Object275 : public StageEntity {
public:
	static void *create();
	inline Object275() {};
	inline ~Object275() {};
};

extern ActorProfile Object275_Profile;

