#pragma once
#include "view.hpp"

//ov8
class PerspView : public View
{
public:

	Vec3_32 target;
	Vec3_32 position;
	Vec3_32 up;
	Vec3_16 rotation;

	//D0:0218cd58
	//D1:0218cd00
	virtual ~PerspView();

};
NTR_SIZE_GUARD(PerspView, 0x108);
