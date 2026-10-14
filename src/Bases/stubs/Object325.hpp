#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 325  |  ov010  |  profile @ 0x02123d58
class Object325 : public Actor {
public:
	static void *create();
	inline Object325() {};
	inline ~Object325() {};

	virtual s32 onRender();
	virtual s32 onUpdate();
};

extern ActorProfile Object325_Profile;

