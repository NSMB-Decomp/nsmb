#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 70  |  ov056  |  profile @ 0x02175818
class Object70 : public StageEntity {
public:
	static void *create();
	inline Object70() {};
	inline ~Object70() {};

	void func_ov056_021743f4();
	void func_ov056_021744ec();
	void func_ov056_02174684();
	void func_ov056_02174758();
	void func_ov056_02174804();
};

extern ActorProfile Object70_Profile;

