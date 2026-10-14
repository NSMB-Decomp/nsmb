#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

class StageLayoutBase : public Object {
	public:
	StageLayoutBase();
	~StageLayoutBase();
};

// MainProfileTable slot 303  |  ov000  |  profile @ 0x020c9388
class StageLayout : public StageLayoutBase {
public:
	u8 _pad0[0xa8f4];
	
	static void *create();
	inline StageLayout() {};
	inline ~StageLayout() {};
};

extern ActorProfile StageLayout_Profile;

