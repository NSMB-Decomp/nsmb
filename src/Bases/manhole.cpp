#include "manhole.hpp"
#include "../graphics/3d/util.hpp"
#include "player/PlayerActor.hpp"

ActorProfile Manhole::profile = {
    Manhole::create,
    AC_Manhole,
    233,
};

ObjectInfo Manhole::objectInfo = {
	16, 4,
	2, 2,
	0, -1,
	0, 0,
	u16(1U << 13)
};


const AcConfig Manhole::acConfig = {

	0, _FixedFlt(-3.0),
	_FixedFlt(16.0), _FixedFlt(6.0),

	AC_GRP_Entity,
	AC_ATK_None,
	((1U<<AC_GRP_Player)|(1U<<AC_GRP_PlayerSpecial)),
	0,
	0,

	Manhole::activeCallback

};



s32 Manhole::onCreate() {

	if (!prepareResourcesSafe(64, Memory_gameHeap))
		return 0;

	collisionType = CT_Collisionless;

	activeSize.set(32, 48);
	viewOffset.set(0, 0);
	renderSize.set(32, 48);

	scale.set(4096, 4096, 4096);
	rotation.x = C_DEG(-90);

	platform.init(this, 0, 0, _FixedFlt(3.0), _FixedFlt(16.0), _FixedFlt(-16.0), 0, 0);
	activeCollider.init(this, acConfig, false);
	activeCollider.resetCollisionState();

	roll = 0;
	rollAngle = 0;
	rollAmplitude = 0;

	playerJumping = false;
	playerGroundPounding = false;
	rollTimer = 0;
	playerStanding = false;

	accelV = 0;

	updateFunction = nullptr;
	switchState(&Manhole::solidIdle, 0);

	return 1;

}

s32 Manhole::onRender() {

	MTX::setTranslation(Game_modelMatrix, position);
	MTX::rotateX(Game_modelMatrix, rotation.x);

	model.matrix = Game_modelMatrix;
	model.render(&scale);

	return 1;

}

s32 Manhole::onDestroy() {

	platform.unlink();

	return 1;

}

bool Manhole::onPrepareResources() {

	void* modelBMD = FS::Cache::getFile(1549 - 131);

	return model.create(modelBMD, 0, 0) != false;

}



bool Manhole::updateMain() {

	if (destroyInactive(0))
		return true;

	updateState(0);
	playerJumping = false;
	playerGroundPounding = false;

	return true;

}



bool Manhole::switchState(StateFunction function, u32 arg) {

	if (updateFunction != function) {

		if (updateFunction) {
			updateStep = FN_EXIT;
			(this->*updateFunction)(arg);
		}

		updateFunction = function;
		updateStep = FN_INIT;
		(this->*updateFunction)(arg);

	}

	return true;

}

void Manhole::updateState(u32 arg) {
	(this->*updateFunction)(arg);
}

bool Manhole::solidIdle(u32 arg) {

	if (updateStep == FN_INIT) {
		updateStep++;

		platform.link();

		roll = 0;
		rollAngle = 0;
		playerStanding = false;

	} else if (updateStep == FN_EXIT) {
		platform.unlink();
	} else {

		// Update forward tilt animation
		if (rollTimer) {
			rollTimer--;

			if (rollTimer == 0) {
				roll = 0;
			} else {
				s32 amplitude = Math::max(rollAmplitude - ((rollAmplitude / 8) + 16), 0);
				rollAmplitude = amplitude;

				u16 angle = rollAngle + 0x1000;
				rollAngle = angle;
				roll = _FixedMul(amplitude, _FixedSin(angle));
			}
		}

		rotation.x = roll + C_DEG(270);

		// Player is jumping through the gate from below, roll backward
		if (playerJumping) {
			switchState(&Manhole::rollBackward, 0);
		}
		else {
			CollisionKind coll = getPlatformCollision();

			switch (coll) {

			case CK_Player:

				if (!playerStanding && !rollTimer) {
					// Initiate small forward tilt
					rollTimer = 16;
					rollAngle = 0;
					rollAmplitude = _FixedFlt(3.0);
					roll = 0;

					func_02012398(0xAD, &position);
				}

				playerStanding = true;
				break;

			// Player is groundpounding on the gate, roll forward
			case CK_GroundPound:
				switchState(&Manhole::rollForward, 0);
				break;

			default:
				playerStanding = false;
				break;

			}

		}

		platform.update();
	}

	return true;

}

bool Manhole::rollForward(u32 arg) {

	s32 step;

	if (updateStep == FN_INIT) {
		updateStep++;

		roll = (roll & 0xFFFF) - _FixedFlt(112.0);
		lastRotationX = rotation.x;
		rollTimer = 16;

	} else if (updateStep != FN_EXIT) {

		step = roll;
		step = Math::min(step - Math::max((step >> 6) - _FixedFlt(0.25), _FixedFlt(-1)), 0);

		// s32 step = (roll / 64) - _FixedFlt(0.25);
		// if (step < _FixedFlt(-1.0))
		// 	step = _FixedFlt(-1.0);

		// step = roll - step;
		// if (step > 0)
		// 	step = 0;

		roll = step;
		rotation.x = step + C_DEG(270);

		updateRollingSound();

		lastRotationX = rotation.x;

		if (step) {
			bool jumping = false;
			bool groundPounding = false;

			if (rollTimer) {
				rollTimer--;
			}
			else {
				jumping = playerJumping;
				groundPounding = playerGroundPounding;
			}

			if (jumping) {
				// Player is jumping through the gate, roll backward
				switchState(&Manhole::rollBackward, 0);
			}
			else if (groundPounding) {
				step = (step & 0xFFFF) - _FixedFlt(112.0);
				// Player is groundpounding through the gate, continue rolling forward
				rollTimer = 16;
				roll = step;
			}

		}
		else {
			// Initiate small forward tilt
			rollAmplitude = _FixedFlt(3.0);
			rollTimer = 16;

			// Forward rolling stopped, re-enable solid collision
			switchState(&Manhole::solidIdle, 0);
		}
	}

	return true;

}

bool Manhole::rollBackward(u32 arg) {

	s32 step;

	if (updateStep == FN_INIT) {
		updateStep++;

		/* step = roll & 0xffff;
		step += 0x20000;
		roll = step; */
		roll = (roll & 0xFFFF) + _FixedFlt(32.0);
		lastRotationX = rotation.x;
		rollTimer = 16;

	} else if (updateStep == FN_EXIT) {

	} else {

		// s32 step_ = roll >> 6;
		// step_ += 0x400;
		// //step_ = (roll >> 6) + _FixedFlt(0.25);
		// if (step_ > _FixedFlt(0.625))
		// 	step_ = _FixedFlt(0.625);

		//s32 step_ = ;

		// step_ = roll - step_;
		// if (step_ < 0)
		// 	step_ = 0;

		step = roll;
		step = Math::max(step - Math::min((step >> 6) + 0x400, _FixedFlt(0.625)), 0);

		//i32 rot = step_ + C_DEG(270);

		roll = step;
		rotation.x = step + C_DEG(270);

		updateRollingSound();

		lastRotationX = rotation.x;

		if (step != 0) {
			bool jumping = false;
			bool groundPounding = false;

			if (rollTimer) {
				rollTimer--;
			}
			else {
				jumping = playerJumping;
				groundPounding = playerGroundPounding;
			}

			if (groundPounding) {
				// Player is groundpounding through the gate, roll forward
				switchState(&Manhole::rollForward, 0);
			} else if (jumping) {
				// Player is jumping through the gate, continue rolling backward
				step = (step & 0xFFFF) + _FixedFlt(32.0);
				rollTimer = 16;
				roll = step;
			}

		}
		else {
			// Initiate small forward tilt
			rollAmplitude = _FixedFlt(3.0);
			rollTimer = 16;

			// Backward rolling stopped, re-enable solid collision
			switchState(&Manhole::solidIdle, 0);
		}
	}

	return true;

}



inline s32 getPrevRot(s32 a) {
	return a - 0xC000;
}

#pragma optimization_level 3

void Manhole::updateRollingSound() {

	// IDA output:
	/* int v1; // r3
	int v2; // r2

	v1 = (s16)(lastRotationX - 0xC000);
	if ( v1 <= (s16)(rotation.x - 0xC000) )
	{
		v2 = (s16)(lastRotationX - 0xC000);
		v1 = (s16)(rotation.x - 0xC000);
	}
	else
	{
		v2 = (s16)(rotation.x - 0xC000);
	}
	if ( v2 < 0 && v1 >= 0 || v2 <= 0 && v1 > 0 )
		func_02012398(174, &position); */

	// Ghidra output:
	/* int iVar1;
	int iVar2;
	int iVar3;

	iVar1 = (lastRotationX + -0xc000) * 0x10000 >> 0x10;
	iVar2 = (rotation.x + -0xc000) * 0x10000 >> 0x10;
	iVar3 = iVar1;
	if (iVar1 <= iVar2) {
		iVar3 = iVar2;
		iVar2 = iVar1;
	}
	if ((0 <+ iVar2) || (iVar3 < 0)) {
		if (0 < iVar2) {
			return;
		}
		if (iVar3 <= 0) {
			return;
		}
	}
	func_02012398(0xae, &position); */

	// BinaryNinja output: (correct but regswaps everywhere!)
    /* s32 r1_4 = (rotation.x - 0xc000) << 0x10 >> 0x10;
    s32 r3 = (lastRotationX - 0xc000) << 0x10 >> 0x10;
    s32 r2_3;

    if (r3 > r1_4)
        r2_3 = r1_4;
    else
    {
        r2_3 = r3;
        r3 = r1_4;
    }

    if (r2_3 >= 0 || r3 < 0)
    {
        if (r2_3 > 0)
            return;

        if (r3 <= 0)
            return;
    }

    return func_02012398(0xae, &position); */

	// "Reko" (whatever the fuck that is) output:
	s32 r2_15 = getPrevRot(rotation.x) << 16;
	s32 r1_14 = getPrevRot(lastRotationX) << 16;
	s32 r3_16 = r1_14 >> 16;
	s32 r2_20 = r2_15;
	if (r1_14 >> 16 > r2_15 >> 16)
		r2_20 = r2_15 >> 16;
	if (r1_14 >> 16 <= r2_15 >> 16)
	{
		r2_20 = r1_14 >> 16;
		r3_16 = r2_15 >> 16;
	}
	if (r2_20 >= 0x00 || r3_16 < 0x00)
	{
		if (r2_20 > 0x00)
			return;
		if (r3_16 <= 0x00)
			return;
	}
	func_02012398(0xAE, &position);

	// s16 l = getPrevRot(rotation.x);
	// s16 a = getPrevRot(lastRotationX);
	// s16 b = l;

	// if (a > l) {
	// 	b = a;
	// 	a = l;
	// } else {
	// 	b = l;
	// }

	// if ((b < 0 && a >= 0) || (b <= 0 && a > 0)) {
	// 	func_02012398(0xAE, &position);
	// }

}

Manhole::CollisionKind Manhole::getPlatformCollision() {

	CollisionKind coll = CK_None;

	for (PlatformMgr* mgr = platform.manager; mgr; mgr = mgr->next) {

		if (mgr->owner->actorType != 1) // TODO: Enum!!!
			continue;

		PlayerActor& player = *static_cast<PlayerActor*>(mgr->owner);
		if (player._778 & 0x800000) // TODO: Enum/macro?
			return CK_GroundPound;

		coll = CK_Player;
	}

	return coll;

}



bool Manhole::loadResources() {

	FS::Cache::loadFile(1549 - 131, false);

	return true;

}

void Manhole::activeCallback(ActiveCollider& self, ActiveCollider& other) {

	Manhole& manhole = *static_cast<Manhole*>(self.owner);
	PlayerActor& player = *static_cast<PlayerActor*>(other.owner);

	if (other.owner->actorType != 1) // TODO: ENUM!!!
		return;

	if (player._778 & 0x800000) {
		manhole.playerGroundPounding = true;
		return;
	}

	if (player.velocity.y > 0) {
		manhole.playerJumping = true;
	}

}

void* Manhole::create() {
	return new Manhole();
}
