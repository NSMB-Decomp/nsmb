#pragma once
#include "../../Bases/Object.hpp"
#include "../../Vec.hpp"

class View : public Object
{
public:

	Mat4x4 unk5C;
	Mat4x3 viewMatrix;

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~View();


};
NTR_SIZE_GUARD(View, 0xCC);
