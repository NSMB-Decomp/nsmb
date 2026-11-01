#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// ov120 is a single TU: MainProfileTable slots 216-223 all live here.

// MainProfileTable slot 216  |  ov120  |  profile @ 0x0218dec8
class Object216 : public StageEntity {
public:
	static void *create();
	inline Object216() {};
	inline ~Object216() {};
};

extern ActorProfile Object216_Profile;

// MainProfileTable slot 217  |  ov120  |  profile @ 0x0218dea4
class Object217 : public StageEntity {
public:
	static void *create();
	inline Object217() {};
	inline ~Object217() {};
};

extern ActorProfile Object217_Profile;

// MainProfileTable slot 218  |  ov120  |  profile @ 0x0218deb0
class Object218 : public StageEntity {
public:
	static void *create();
	inline Object218() {};
	inline ~Object218() {};
};

extern ActorProfile Object218_Profile;

// MainProfileTable slot 219  |  ov120  |  profile @ 0x0218debc
class Object219 : public StageEntity {
public:
	static void *create();
	inline Object219() {};
	inline ~Object219() {};
};

extern ActorProfile Object219_Profile;

// MainProfileTable slot 220  |  ov120  |  profile @ 0x0218de98
class Object220 : public StageEntity {
public:
	static void *create();
	inline Object220() {};
	inline ~Object220() {};
};

extern ActorProfile Object220_Profile;

// MainProfileTable slot 221  |  ov120  |  profile @ 0x0218de8c
class Object221 : public StageEntity {
public:
	static void *create();
	inline Object221() {};
	inline ~Object221() {};
};

extern ActorProfile Object221_Profile;

// MainProfileTable slot 222  |  ov120  |  profile @ 0x0218de74
class Object222 : public StageEntity {
public:
	static void *create();
	inline Object222() {};
	inline ~Object222() {};
};

extern ActorProfile Object222_Profile;

// MainProfileTable slot 223  |  ov120  |  profile @ 0x0218de80
class Object223 : public StageEntity {
public:
	static void *create();
	inline Object223() {};
	inline ~Object223() {};
};

extern ActorProfile Object223_Profile;

// Placeholder name: only known from the ov120 __sinit and its out-of-line ctor/dtor.
class Unk_ov120_0218d860
{
      public:
	u8 _0;
	u8 _1;
	u32 _4;
	u32 _8[12];

	Unk_ov120_0218d860();
	~Unk_ov120_0218d860();
};

extern Unk_ov120_0218d860 data_ov120_0218e058[3];
