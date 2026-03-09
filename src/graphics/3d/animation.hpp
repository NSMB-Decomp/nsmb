#pragma once
#include "Nitro.hpp"

class Animation {
public:

	Ns3dDrawable* renderObj;
	Ns3dModelData* modelInfo;
	Ns3dTextureData* texture;
	void* animFile; //Anim file
	Ns3dAnimation* animation;
	u32 animID; //Anim ID
	u16 frameCount; //Total animation frames

	//C1:02018f68
	//C2:02018f90
	Animation();

	//D0:02018f38
	//D1:02018f58
	//D2:02018f28
	virtual ~Animation();

	//02018e74
	bool create(Ns3dDrawable* model, void* animFile, u32 animID, Ns3dTextureData* texture);

	//02018e28
	void init(u32 animID, u16 startFrame);

	//02018dd8
	bool reset(u32 animID);

	//02018dc0
	void attach();

	//02018da8
	void detach();

	/* inline void setFrame(i32 frame) {
		_Ns3dAnimSetFrame(animation, frame);
	} */

};
size_assert(Animation, 0x20);
