#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 109  |  ov070  |  profile @ 0x02177740
class Object109 : public StageEntity {
public:
	static void *create();
	inline Object109() {};
	inline ~Object109() {};
};

extern ActorProfile Object109_Profile;

