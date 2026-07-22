#pragma once
#include "../nsmb_nitro.hpp"

// No idea how they managed to use this private variable
extern "C" Thread launcherThread;

namespace Exception {

	struct Context : ArmContext {
		u32 spsr;
		u32 cp15;
		u32 exinfo;
	};


	// Call exception handler without showing the exception screen
	void terminateCaught();

	// Grab current context and display exception screen
	void terminateUncaught();

	void terminate(Context* context);

	void userExceptionHandler(Context* context, void* arg);


	NTR_INLINE void setupHandler() {

		NDS::Exceptions::installHandler(
			reinterpret_cast<void*>(&userExceptionHandler),
			&launcherThread
		);

	}

	NTR_INLINE void invokeHandler(Context* context) {
		userExceptionHandler(context, &launcherThread);
	}

}
