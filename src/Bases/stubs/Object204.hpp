#pragma once
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 204  |  ov059  |  profile @ 0x02174718
class Object204 : public StageEntity {
public:
	u8 _pad0[0x38];
	Collider _42c;
	u8 _pad1[0x30];
	
	static void *create();
	inline Object204() {};
	inline ~Object204() {};
};

extern ActorProfile Object204_Profile;

