#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 166, 167 share this class.
// ov010  |  vtable @ 0x02125f40
class Object166 : public StageEntity {
public:
	static void *create();
	static void *create2();
	inline Object166() {};
	inline ~Object166() {};
};

extern ActorProfile Object167_Profile;
extern ActorProfile Object166_Profile;
