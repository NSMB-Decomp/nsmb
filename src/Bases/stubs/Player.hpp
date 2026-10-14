#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 21  |  ov010  |  profile @ 0x02128458
class Player : public StageEntity {
public:
	static void *create();
	inline Player() {};
	inline ~Player() {};
};

extern ObjectProfile Player_Profile;

