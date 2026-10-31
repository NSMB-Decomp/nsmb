#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 43  |  ov019  |  profile @ 0x02137458
class Object43 : public StageEntity {
public:
	static void *create();
	inline Object43() {};
	inline ~Object43() {};

	void func_ov019_021332ec();
	void func_ov019_02133510();
	void func_ov019_0213386c();
	void func_ov019_02133924();
	void func_ov019_02133ccc();
	void func_ov019_02134320();
	void func_ov019_02134480();
	void func_ov019_0213454c();
};

extern ActorProfile Object43_Profile;

