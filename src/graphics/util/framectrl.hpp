#pragma once
#include "Nitro.hpp"

class FrameCtrl {
public:

	enum {
		TypeMask = 0xC0000000,
		LastFrameMask = 0x3FFFFFFF
	};

	enum Type {
		Looping = 0x00000000,
		Standard = 0x40000000,
	};


	FrameCtrl();

	inline ~FrameCtrl();

	//0201feb8
	void update(); //Updates currentFrame by speed. If it's looping, currentFrame is wrapped around. If not, currentFrame is incremented until it reaches frames - 1. When timer becomes negative due to negative speeds, it's kept at 0.

	//0201fe9c
	void init(u16 frames, u32 type, i32 speed, u16 startFrame); //Initializes the controller with the given parameters

	inline u16 getFrame() const {
		return currentFrame >> 12;
	}

	inline void setFrame(u16 frame) {
		currentFrame = frame << 12;
	}

	//0201fe88
	u16 getFrameCount() const; //returns the frame count (truncated integer)

	inline void setFrameCount(u16 count) {
		settings &= ~LastFrameMask;
		settings |= (count << 12) & LastFrameMask;
	}

	//0201fe74
	void setAnimationType(FrameCtrl::Type type); //Sets the animation type

	inline u32 getAnimationType() const {
		return settings & TypeMask;
	}

	//0201fe34
	bool finished() const; //If speed is positive, it returns true if current frame exceeds frames - 1. If speed is negative, it returns true if currentFrame equals 0 or less.

	//0201fd1c
	bool passing(i16 targetFrame) const; //returns true if the next update passes targetFrame, false otherwise


	u32 settings;
	i32 currentFrame;
	i32 speed;

};
size_assert(FrameCtrl, 0xC);
