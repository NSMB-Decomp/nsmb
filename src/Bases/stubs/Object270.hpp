#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 270  |  ov010  |  profile @ 0x021246c8
class Object270 : public StageEntity {
public:
	static void *create();
	inline Object270() {};
	inline ~Object270() {};
};

extern ActorProfile Object270_Profile;

