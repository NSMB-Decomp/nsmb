#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 112  |  ov046  |  profile @ 0x02148548
class Object112 : public StageEntity {
public:
	static void *create();
	inline Object112() {};
	inline ~Object112() {};

	void func_ov046_021470c8();
	void func_ov046_021471dc();
	void func_ov046_02147278();
	void func_ov046_021476a8();
	void func_ov046_02147a18();
};

extern ActorProfile Object112_Profile;

