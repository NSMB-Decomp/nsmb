#include "framectrl.hpp"

void FrameCtrl::update() {

	i32 last = settings & LastFrameMask;

	if ((settings & TypeMask) == 0) {
		currentFrame = (currentFrame + speed + last) % last;
		return;
	}

	currentFrame += speed;

	if (currentFrame < 0) {
		currentFrame = 0;
	}
	else if (currentFrame >= last) {
		currentFrame = last - 1;
	}

}

void FrameCtrl::init(u16 frames, u32 type, i32 speed, u16 startFrame) {

	this->settings = type | (4096 * frames);
	this->currentFrame = (4096 * startFrame);
	this->speed = speed;

}

u16 FrameCtrl::getFrameCount() const {
	return (settings & LastFrameMask) >> 12;
}

void FrameCtrl::setAnimationType(u32 type) {
	settings = (settings & ~TypeMask) | type;
}

bool FrameCtrl::finished() const {

	if (speed < 0)
		return currentFrame <= 0;

	i32 last = settings & LastFrameMask;

	return currentFrame >= last - 1;

}

bool FrameCtrl::passing(i16 targetFrame) const {

	u32 frame = currentFrame;
	i32 target = (4096 * targetFrame);
	i32 next = frame + speed;
	i32 last = settings & LastFrameMask;

	if ((settings & TypeMask) == 0) {

		// Negative speed, wrapping from start to end
		if (next < 0) {

			next = (next + last) % last;

			if ((target >= 0 && target < currentFrame) || (next <= target && target < last))
				return true;

		}
		// Positive speed, wrapping from end to start
		else if (next >= last) {

			next %= last;

			// TODO: bugfix - this doesn't check if target is negative in the second case

			if ((currentFrame <= target && target < last) || target < next)
				return true;

		}
		// No wrapping
		else {

			// Negative speed
			if (currentFrame <= next) {
				if (currentFrame <= target && target < next)
					return true;
			} else {
				if (next <= target && target < currentFrame)
					return true;
			}

		}

	}
	else {

		if (next < 0)
			next = 0;

		if (next >= last)
			next = last - 1;

		// Negative speed
		if (currentFrame <= next) {
			if (target >= currentFrame && target < next)
				return true;
		} else {
			if (target >= next && target < currentFrame)
				return true;
		}

	}

	return false;

}
