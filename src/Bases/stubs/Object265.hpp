#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 265  |  ov013  |  profile @ 0x0213bd2c
class Object265 : public StageEntity {
public:
	static void *create();
	inline Object265() {};
	inline ~Object265() {};
};

extern ActorProfile Object265_Profile;

