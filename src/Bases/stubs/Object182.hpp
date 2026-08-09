#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 182  |  ov012  |  profile @ 0x02132364
class Object182 : public StageEntity {
public:
	static void *create();
	inline Object182() {};
	inline ~Object182() {};
};

extern ActorProfile Object182_Profile;

