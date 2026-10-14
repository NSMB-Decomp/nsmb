#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 181  |  ov100  |  profile @ 0x02189518
class Object181 : public StageEntity {
public:
	static void *create();
	inline Object181() {};
	inline ~Object181() {};
};

extern ActorProfile Object181_Profile;

