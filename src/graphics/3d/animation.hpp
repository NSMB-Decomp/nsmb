#pragma once
#include "../../nsmb_nitro.hpp"

class Animation {
public:

	//C1:02018f68
	//C2:02018f90
	Animation();

	//D0:02018f38
	//D1:02018f58
	//D2:02018f28
	virtual ~Animation();

	//02018e74
	bool create(Ns3dDrawable* drw, void* file, u32 animID, Ns3dTextureData* tex);

	//02018e28
	void init(u32 animID, u16 startFrame);

	//02018dd8
	bool reset(u32 animID);

	//02018dc0
	void attach();

	//02018da8
	void detach();

	inline void setFrame(i32 frame) {
		Ns_3dAnimationSetFrame(animation, frame);
	}


	Ns3dDrawable* drawable;
	Ns3dModelData* model;
	Ns3dTextureData* texture;
	void* animFile;
	Ns3dAnimation* animation;
	u32 animID;
	u16 frameCount;

};
NTR_SIZE_GUARD(Animation, 0x20);
