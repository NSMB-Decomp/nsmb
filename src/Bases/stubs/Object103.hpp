#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 103  |  ov121  |  profile @ 0x0218dfa8
class Object103 : public StageEntity {
public:
	static void *create();
	inline Object103() {};
	inline ~Object103() {};
};

extern ActorProfile Object103_Profile;

