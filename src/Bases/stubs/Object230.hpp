#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 230  |  ov088  |  profile @ 0x02181f00
class Object230 : public StageEntity {
public:
	static void *create();
	inline Object230() {};
	inline ~Object230() {};

	void func_ov088_0217de94();
	void func_ov088_0217df14();
	void func_ov088_0217df3c();
	void func_ov088_0217df78();
	void func_ov088_0217df7c();
	void func_ov088_0217dfac();
	void func_ov088_0217dfd4();
	void func_ov088_0217e054();
	void func_ov088_0217e07c();
	void func_ov088_0217e0bc();
	void func_ov088_0217e0c0();
	void func_ov088_0217e0e8();
};

extern ActorProfile Object230_Profile;

