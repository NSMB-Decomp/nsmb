#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 96  |  ov034  |  profile @ 0x02145200
class Object96 : public StageEntity {
public:
	static void *create();
	inline Object96() {};
	inline ~Object96() {};
};

extern ActorProfile Object96_Profile;

