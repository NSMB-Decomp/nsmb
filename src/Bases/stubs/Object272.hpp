#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 272  |  ov010  |  profile @ 0x02124800
class Object272 : public StageEntity {
public:
	static void *create();
	inline Object272() {};
	inline ~Object272() {};
};

extern ActorProfile Object272_Profile;

