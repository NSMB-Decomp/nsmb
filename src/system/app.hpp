#pragma once
#include "../nsmb_nitro.hpp"

namespace App {

	typedef i32 (*CallbackFunction)();
	typedef void (*BootTargetFunction)();

	enum SleepPhase {
		SleepPhase_Awake,
		SleepPhase_LidClosing,
		SleepPhase_LidClosed,
		SleepPhase_Sleeping,
		SleepPhase_LidOpening,
		SleepPhase_LidOpened,
		SleepPhase_WakeUp,
		SleepPhase_Stop
	};

	enum SleepControl {

		// States that will switch to a "partial sleep".
		SleepControl_UsingWifi = 0x2,				// Wireless communications are running
		SleepControl_WritingSave = 0x10,			// Backup chip is being written to

		// States that will disable sleeping entirely
		SleepControl_LoadingStage = 0x20,		// Currently loading and setting up a stage
		SleepControl_SwitchingScene = 0x40,		// Currently in the process of switching scenes
		SleepControl_UnloadingStage = 0x80,		// Currently unloading and cleaning up stage resources

		/*
			"Partial sleep" states will not make the game go into full hardware sleep mode (which includes power saving).
			Instead the game will simply turn off/on the LCD power while keeping tasks running in the background.
		*/
		SleepControl_PartialSleepMask = 0x1F,
		/*
			"Disable sleep" states will disable sleeping entirely, or, in case the game is already sleeping,
			it will prevent it from waking up from sleep mode.
			Considering a full hardware sleep mode cannot be triggered during a "disable sleep" state,
			this second circumstance is only possible when the game goes to sleep during a "partial sleep" state:
			In this case the game will not power on the LCD until the "disable sleep" state has been cleared.
		*/
		SleepControl_DisableSleepMask = ~SleepControl_PartialSleepMask

	};

	enum BootScene {
		Boot,
		TitleScreen
	};

	enum BootTarget {
		Game,
		Minigames
	};

	const u32 BootTargetCount = 2;


	NTR_INLINE u32 makeResetParam(u32 target, u32 scene, u32 param = 1) {
		return (target & 0xF) | (scene & 0xF) << 8 | (param & 0xF) << 16;
	}


	void branchToStartup();

	void branchToMain();

	void setBootTarget(u32 target);

	u32 getBootTarget();

	NTR_INLINE BOOL isGameBoot() {
		return getBootTarget() == Game;
	}

	NTR_INLINE BOOL isMinigamesBoot() {
		return getBootTarget() == Minigames;
	}

	void setBootScene(u32 scene);

	u32 getBootScene();

	NTR_INLINE BOOL isRegularBoot() {
		return getBootScene() == Boot;
	}

	NTR_INLINE BOOL isTitleScreenBoot() {
		return getBootScene() == TitleScreen;
	}

	void setBootParam(u32 param);

	i32 defaultCallback();

	void onInitialize();

	void powerOffBacklight();

	void powerOnBacklight();

	void stopDisplayDMA();

	void updateSleep();

	void forceDisplayOn();

	void stop();

	void reset(u32 param);

	NTR_INLINE void reset(u32 target, u32 scene, u32 param = 1) {
		reset(makeResetParam(target, scene, param));
	}

	BOOL isSleeping();

	i32 playSFX(u32 sfxID, i32 successValue);

	i32 onLidClosedDefault();

	i32 onLidOpenedDefault();

	i32 updateTaskDefault();

	void onStartup();

	BOOL onCardPulledOut();

	void gameInit();

	void gameLoop();

	void initialize();

	void gameMain();

	void commonStartup();

	void initFileCount(BOOL multiboot);

	void initBoot(u32);

	void resetVram();

	void resetGpu();


	extern const Mat2x2 identityMtx;

	extern u8 frameLength;
	extern CallbackFunction preLidClosed;
	extern CallbackFunction postLidOpened;
	extern CallbackFunction onLidClosed;
	extern CallbackFunction onLidOpened;
	extern CallbackFunction updateTask;
	extern BootTargetFunction startupTbl[BootTargetCount];
	extern BootTargetFunction mainTbl[BootTargetCount];
	extern char backupSignature[8];

	extern u8 sleepPhase;        // sleepA??????
	extern bool backlightOff;    // sleepBacklightOff
	extern u8 sleepControl;      // sleepControl
	extern bool sleeping;        // sleepFlag
	extern i16 sleepPhaseTimer;  // sleepPhaseTimer
	extern u16 sleepWakeUpTimer; // sleepWakeUpTimer
	extern u32 backlightTop;     // are these even ordered by name
	extern u32 backlightBottom;  //
	extern u32 bootParam;        // why is (bo) before (ba)
	extern u32 bootTarget;       //
	extern u32 bootScene;        //


	NTR_INLINE void setUpdateTask(CallbackFunction func) {
		updateTask = func;
	}

	NTR_INLINE void setOnLidOpened(CallbackFunction func) {
		onLidOpened = func;
	}

	NTR_INLINE void setOnLidClosed(CallbackFunction func) {
		onLidClosed = func;
	}

	NTR_INLINE void setPostLidOpened(CallbackFunction func) {
		postLidOpened = func;
	}

	NTR_INLINE void setPreLidClosed(CallbackFunction func) {
		preLidClosed = func;
	}

	NTR_INLINE void setFrameLength(u8 length) {
		frameLength = length;
	}

	NTR_INLINE u32 getBootParam() {
		return bootParam;
	}

	// This control flag is automatically set in App::updateSleep()
	NTR_INLINE void startUsingWifi() {
		sleepControl |= SleepControl_UsingWifi;
	}

	NTR_INLINE void finishUsingWifi() {
		sleepControl &= ~SleepControl_UsingWifi;
	}

	NTR_INLINE void startWritingSave() {
		sleepControl |= SleepControl_WritingSave;
	}

	NTR_INLINE void finishWritingSave() {
		sleepControl &= ~SleepControl_WritingSave;
	}

	NTR_INLINE void startLoadingStage() {
		sleepControl |= SleepControl_LoadingStage;
	}

	NTR_INLINE void finishLoadingStage() {
		sleepControl &= ~SleepControl_LoadingStage;
	}

	NTR_INLINE void startSwitchingScene() {
		sleepControl |= SleepControl_SwitchingScene;
	}

	NTR_INLINE void finishSwitchingScene() {
		sleepControl &= ~SleepControl_SwitchingScene;
	}

	NTR_INLINE void startUnloadingStage() {
		sleepControl |= SleepControl_UnloadingStage;
	}

	NTR_INLINE void finishUnloadingStage() {
		sleepControl &= ~SleepControl_UnloadingStage;
	}

}
