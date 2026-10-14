#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 148  |  ov038  |  profile @ 0x02143368
class Object148 : public StageEntity {
public:
	static void *create();
	inline Object148() {};
	inline ~Object148() {};
};

extern ActorProfile Object148_Profile;

