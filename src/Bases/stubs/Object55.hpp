#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 55  |  ov024  |  profile @ 0x0213f450
class Object55 : public StageEntity {
public:
	static void *create();
	inline Object55() {};
	inline ~Object55() {};

	void func_ov024_0213c710();
	void func_ov024_0213cadc();
	void func_ov024_0213cb80();
	void func_ov024_0213cea4();
	void func_ov024_0213cfbc();
	void func_ov024_0213d070();
};

extern ActorProfile Object55_Profile;

// MainProfileTable slot 56  |  ov024  |  profile @ 0x0213f45c
class Object56 : public StageEntity {
public:
	static void *create();
	inline Object56() {};
	inline ~Object56() {};
};

extern ActorProfile Object56_Profile;

