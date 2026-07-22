#include "app.hpp"
#include "../Bases/Object.hpp"
#include "../Scenes/Scene.hpp"
#include "exception.hpp"
#include "vblank.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/core/wifi.hpp>


inline u32 enableIrq() {
	u32 prev = *rcast<vu16*>(0x04000208);
	*rcast<vu16*>(0x04000208) = 1;
	return prev;
}

namespace App {

	const Mat2x2 identityMtx = {
		_FixedFlt(1.0), 0,
		0, _FixedFlt(1.0)
	};


	BootTargetFunction startupTbl[BootTargetCount] = {
		&commonStartup, &commonStartup
	};

	BootTargetFunction mainTbl[BootTargetCount] = {
		&gameMain, &InitMiniGame // TODO: Minigames main
	};

	CallbackFunction updateTask = &defaultCallback;
	CallbackFunction onLidOpened = &defaultCallback;
	CallbackFunction onLidClosed = &defaultCallback;
	CallbackFunction postLidOpened = &defaultCallback;
	CallbackFunction preLidClosed = &defaultCallback;

	u8 frameLength = 1;

	char backupSignature[8] = {
		CONFIG_BACKUP_SIGNATURE
	};


#pragma section autobss_3 begin
	u8 sleepPhase;
	bool backlightOff;
	u8 sleepControl;
	bool sleeping;
	i16 sleepPhaseTimer;
	u16 sleepWakeUpTimer;
	u32 backlightTop;
	u32 backlightBottom;
	u32 bootParam;
	u32 bootTarget;
	u32 bootScene;
#pragma section autobss_3 end


	void branchToStartup() {
		startupTbl[bootTarget]();
	}

	void branchToMain() {
		mainTbl[bootTarget]();
	}

	void setBootTarget(u32 target) {
		bootTarget = target;
	}

	u32 getBootTarget() {
		return bootTarget;
	}

	void setBootScene(u32 scene) {
		bootScene = scene;
	}

	u32 getBootScene() {
		return bootScene;
	}

	void setBootParam(u32 param) {
		bootParam = param;
	}

	i32 defaultCallback() {
		return 0;
	}

	void onInitialize() {

	}

	void powerOffBacklight() {

		if (backlightOff)
			return;

		NDS::Power::getBacklights(&backlightTop, &backlightBottom);
		NDS::Power::setBacklight(2, 0);
		backlightOff = true;

	}

	void powerOnBacklight() {

		if (!backlightOff)
			return;

		if (!NDS::Power::setBacklight(0, backlightTop) && !NDS::Power::setBacklight(1, backlightBottom)) {
			backlightOff = false;
			return;
		}

		s32 attempts = 0;
		while (true) {

			System::sleepSystemThread();

			if (!NDS::Power::setBacklight(0, backlightTop) && !NDS::Power::setBacklight(1, backlightBottom)) {
				backlightOff = false;
				return;
			}

			if (++attempts >= 10) {
				NDS::System::halt();
				return;
			}

		}

	}

	void stopDisplayDMA() {

		u32 i;
		vu32* reg = rcast<vu32*>(0x040000B8);

		for (i = 0; i < 3; i++, reg += 3) {

			u32 cnt = *reg;
			if ((cnt & 0x80000000) == 0)
				continue;

			cnt &= 0x38000000;
			if (cnt == 0x8000000 || cnt == 0x10000000)
				func_01ff8378(i);

		}

	}

	void updateSleep() {

		u8 phase = sleepPhase;
		i32 timer = sleepPhaseTimer;

		BOOL wifiOn = Net::isConnected() || Wifi::isWmInitialized();

		if (wifiOn) {
			startUsingWifi();
		} else {
			finishUsingWifi();
		}

		BOOL disableSleep = (sleepControl & SleepControl_DisableSleepMask) != 0;
		BOOL partialSleep = (sleepControl & SleepControl_PartialSleepMask) != 0;

		u8 frames = frameLength;
		BOOL lidClosed = NDS::Input::isLidClosed();

		if (phase == SleepPhase_Awake) {

			if (lidClosed && !disableSleep) {
				preLidClosed();
				powerOffBacklight();
				phase = SleepPhase_LidClosing;
			}

		}

		if (phase == SleepPhase_LidClosing) {
			timer = onLidClosed();
			phase = SleepPhase_LidClosed;
		}

		if (phase == SleepPhase_LidClosed) {

			if (!lidClosed) {

				// Lid reopened
				powerOnBacklight();
				phase = SleepPhase_LidOpened;
				timer = 1;

			} else {

				if (timer <= 0) {

					if (partialSleep) {
						NDS::Power::setDisplayPower(0);
					}

					phase = SleepPhase_Sleeping;

				} else {
					timer -= frames;
				}

			}

		}

		if (phase == SleepPhase_Sleeping) {

			sleeping = 1;
			sleepWakeUpTimer = 0;

			if (!partialSleep) {

				stopDisplayDMA();
				NDS::Power::sleep(0xC, 0, 0);
				phase = SleepPhase_LidOpening;

			} else {

				if (!lidClosed)
					phase = SleepPhase_LidOpening;

			}

		}

		if (phase == SleepPhase_LidOpening) {

			if (NDS::Power::getDisplayPower() == 1 || NDS::Power::setDisplayPower(1) == 1) {
				powerOnBacklight();
				phase = SleepPhase_LidOpened;
				timer = 1;
			}

		}

		if (phase == SleepPhase_LidOpened) {
			if (timer <= 0) {
				if (!disableSleep) {
					timer = onLidOpened();
					phase = SleepPhase_WakeUp;
				}
			} else {
				timer -= frames;
			}
		}

		if (phase == SleepPhase_WakeUp) {
			if (timer <= 0) {
				postLidOpened();
				phase = SleepPhase_Awake;
			} else {
				timer -= frames;
			}
		}

		if (sleeping && !lidClosed) {

			sleepWakeUpTimer += frames;
			if (sleepWakeUpTimer >= 30) {
				sleeping = 0;
				sleepWakeUpTimer = 0;
			}

		}

		sleepPhase = phase;
		sleepPhaseTimer = timer;

	}

	void forceDisplayOn() {

		while (NDS::Power::getDisplayPower() != 1 && NDS::Power::setDisplayPower(true) != 1) {
			System::sleepSystemThread();
		}

		powerOnBacklight();
		sleepPhase = SleepPhase_Stop;

	}

	void stop() {

		s32 timeout = 180;

		if (sleepPhase == SleepPhase_Stop)
			sleepPhase = SleepPhase_Awake;

		while (true) {

			u32 rate = frameLength;

			if (timeout <= 0) {
				updateSleep();
			} else {
				timeout -= rate;
			}

			System::waitForVBlank();
			updateTask();

		}

	}

	void reset(u32 param) {

		while (sleepPhase != SleepPhase_Awake) {

			updateSleep();
			System::waitForVBlank();
			updateTask();

		}

		NDS::System::reset(param);

	}

	BOOL isSleeping() {
		return sleeping;
	}

	s32 playSFX(u32 sfxID, s32 successValue) {

		if (!Net::isError()) {
			func_02012398(sfxID, nullptr);
			return successValue;
		}

		return 0;

	}

	s32 onLidClosedDefault() {
		//Log() << "[App] Lid closed\n";
		return playSFX(0xEF, 60);
	}

	s32 onLidOpenedDefault() {
		//Log() << "[App] Lid opened\n";
		return playSFX(0xF0, 120);
	}

	s32 updateTaskDefault() {
		func_020123d8();
		return 0;
	}

	void onStartup() {}

	BOOL onCardPulledOut() {

		for (u32 i = 0; i < 4; i++) {
			func_01ff8378(i);
		}

		return TRUE;

	}

	void gameInit() { // InitGame

		NDS::Graphics::initializeInterruptTable();

		System::setupGameVBlank();

		NDS::Interrupts::enableMask(1);
		enableIrq();
		NDS::Interrupts::enableCpuInterrupts();
		NDS::Graphics::signalVerticalBlank(1);

		BOOL multiboot = Wifi::isMultiBootChild();

		NDS::Math::initializeFixedPoint();
		resetGpu();
		NDS::Power::initializeManagement();

		Save_setupBackup(CONFIG_BACKUP_TYPE, backupSignature);
		Save_clearLoadedSaves();

		FS::init();
		FS::Archive::loadMainGameArchives();

		if (multiboot != 0) {
			NDS::Interrupts::disableMask(0x100000);
		}

		if (multiboot == 0) {
			loadBuildtimeFile();
		}

		TouchPad_init();
		prepareWifiStuff(2);
		func_0204c8fc();

		func_02044ad8(0x38000, 0);

		func_0200a9d0();

		// init a bunch of stuff
		func_02006cf4();
		func_0200e508();

		Graphics_Init();

		if (multiboot) {
			func_020125d4();
		} else {
			func_020125e8();
		}

		// init frame counters
		func_02043d10();

		CurrentProfileTable = &MainProfileTable;

		func_0202187c();
		Scene::prepareFirstScene();

		NDS::Graphics::flushGeometry();

		NDS::Graphics::assignTextureBank(3);

		u32 *GFX_FIFO_LIGHT_DIRECTION = (u32 *)0x040004c8;
		*GFX_FIFO_LIGHT_DIRECTION = 0x296a5800;
		u32 *GFX_FIFO_LIGHT_COLOR = (u32 *)0x040004cc;
		*GFX_FIFO_LIGHT_COLOR = 0x7fff;
		u32 *GFX_FIFO_MATERIAL_DIFFUSE_AMBIENT = (u32 *)0x040004c0;
		*GFX_FIFO_MATERIAL_DIFFUSE_AMBIENT = 0x7fff;
		u32 *GFX_FIFO_MATERIAL_SPECULAR_EMISSION = (u32 *)0x040004c4;
		*GFX_FIFO_MATERIAL_SPECULAR_EMISSION = 0;

		// set load overlay functions
		func_0200e040();

		REG_POWER_CNT = REG_POWER_CNT | 0x8000;

		func_02014a58();

		Object::onInitialize();

		onInitialize();

	}

	void gameLoop() { // StartGameLoop

		u32 *GFX_FIFO_SWAP_BUFFERS = (u32 *)0x04000540;

		System::sleepSystemThread();
		NDS::Graphics::enableDisplays();

		while (true) {

			updateSleep();

			TouchPad_update();
			Input_update();

			func_02006fac();
			if (func_02006fb8()) {
				Scene::tryChangeScene();
				ProcessManager_ExecuteTasks();
				Font_updateFont();
			}

			FrameCounter += 1;
			NDS::Graphics::flushGeometry();
			NDS::Graphics::swapBuffers(data_02085a78, data_02085a74);

			Wifi_updatePackets();

			System::waitForVBlank();

			Wifi_update();

			func_02014a30();

			Graphics_2DStep();

			func_020123d8();

		}

	}

	void initialize() {

		NDS::Clock::initializeCounter();
		NDS::Clock::initializeAlarms();
		NDS::Threads::initialize();

		Exception::setupHandler();

	}

	void gameMain() {

		initialize();
		gameInit();
		gameLoop();

	}

	void commonStartup() {

		NDS::System::initialize();

		onStartup();

		NDS::Card::setRemovalCallback(&onCardPulledOut);
		data_020850e8 = 1;

		func_020455d8();

		Save_onStartup();

	}

	void initFileCount(BOOL multiboot) {

		u32 overlay_id = OVERLAY_BOOT;
		FS::Overlay::load(overlay_id);
		func_ov001_020cceb4();
		FS::Overlay::untrack(overlay_id);

	}

	void initBoot(u32) {

		BOOL multiboot = Wifi::isMultiBootChild();
		if (multiboot) {
			func_020125e8();
		}

		FS::Overlay::load(OVERLAY_MISC);
		initFileCount(multiboot);

		FS::Cache::setupCacheEntries();

		setOnLidClosed(&onLidClosedDefault);
		setOnLidOpened(&onLidOpenedDefault);
		setUpdateTask(&updateTaskDefault);

	}


	extern "C" void NitroStartUp() {
		App::branchToStartup();
	}


	void resetVram() {

		NDS::Graphics::disableLcdcBank();
		NDS::Graphics::disableMainBackgroundBank();
		NDS::Graphics::disableMainObjectBank();
		NDS::Graphics::disableArm7Bank();
		NDS::Graphics::disableTextureBank();
		NDS::Graphics::disableTexturePaletteBank();
		NDS::Graphics::disableClearImageBank();
		NDS::Graphics::disableMainBackgroundPaletteBank();
		NDS::Graphics::disableMainObjectPaletteBank();
		NDS::Graphics::disableSubBackgroundBank();
		NDS::Graphics::disableSubObjectBank();
		NDS::Graphics::disableSubBackgroundPaletteBank();
		NDS::Graphics::disableSubObjectPaletteBank();

	}

	void resetGpu() {

		if (getBootScene() == Boot || getBootTarget() == Minigames) {
			NDS::Memory::clear16(0xFFFF, rcast<void*>(0x05000000), 0x2);
			NDS::Memory::clear16(0xFFFF, rcast<void*>(0x05000400), 0x2);
		} else {
			NDS::Memory::clear16(0x0000, rcast<void*>(0x05000000), 0x2);
			NDS::Memory::clear16(0x0000, rcast<void*>(0x05000400), 0x2);
		}

		REG_POWER_CNT = REG_POWER_CNT | 0x8000;
		REG_POWER_CNT = (REG_POWER_CNT & ~0x20E) | 0x20E;

		resetVram();

		NDS::Graphics::signalHorizontalBlank(FALSE);
		NDS::Graphics::signalVerticalBlank(TRUE);

		NDS::Graphics::setMainDisplayMode(1, 0, 0);

		// Hide all planes and windows
		REG_DISPCNT = REG_DISPCNT & ~0x1F00;
		REG_DISPCNT = REG_DISPCNT & ~0xE000;

		// Reset BG screen and char offsets
		REG_DISPCNT = REG_DISPCNT & ~0x38000000;
		REG_DISPCNT = REG_DISPCNT & ~0x7000000;

		// Reset OBJ mapping modes
		REG_DISPCNT = REG_DISPCNT & ~0x300010;
		REG_DISPCNT = REG_DISPCNT & ~0x400060;
		REG_DISPCNT = REG_DISPCNT & ~0x800000;

		// Reset capture control register
		REG_CAPCNT = 0x80000000;

		// Reset BG control registers
		REG_BG0CNT = REG_BG0CNT & 0x43;
		REG_BG1CNT = REG_BG1CNT & 0x43;
		REG_BG2CNT = REG_BG2CNT & 0x43;
		REG_BG3CNT = REG_BG3CNT & 0x43;

		// Reset mosaic for all BGs
		REG_BG0CNT = REG_BG0CNT & ~0x40;
		REG_BG1CNT = REG_BG1CNT & ~0x40;
		REG_BG2CNT = REG_BG2CNT & ~0x40;
		REG_BG3CNT = REG_BG3CNT & ~0x40;

		// Reset priority for all BGs
		REG_BG0CNT = REG_BG0CNT & ~0x3;
		REG_BG1CNT = REG_BG1CNT & ~0x3;
		REG_BG2CNT = REG_BG2CNT & ~0x3;
		REG_BG3CNT = REG_BG3CNT & ~0x3;

		// Reset BG offsets
		REG_BG0OFS = 0;
		REG_BG1OFS = 0;
		REG_BG2OFS = 0;
		REG_BG3OFS = 0;

		NDS::Graphics::applyAffine2D(rcast<void*>(0x04000020), &identityMtx, 0, 0, 0, 0);
		NDS::Graphics::applyAffine2D(rcast<void*>(0x04000030), &identityMtx, 0, 0, 0, 0);

		REG_WININ = REG_WININ & ~0x3F;
		REG_WININ = REG_WININ & ~0x3F00;
		REG_WINOUT = REG_WINOUT & ~0x3F;
		REG_WINOUT = REG_WINOUT & ~0x3F00;

		REG_WIN0H = 0;
		REG_WIN0V = 0;
		REG_WIN1H = 0;
		REG_WIN1V = 0;

		REG_MOSAIC_BG = 0;
		REG_MOSAIC_OBJ = 0;

		NDS::Graphics::setMasterBrightness(rcast<void*>(0x0400006C), 0);

		NDS::Graphics::setSubDisplayMode(0);

		// Hide all planes and windows
		REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x1F00;
		REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0xE000;

		// Reset OBJ mapping modes
		REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x300010;
		REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x60;
		REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x800000;

		// Reset BG control registers
		REG_BG0CNT_SUB = REG_BG0CNT_SUB & 0x43;
		REG_BG1CNT_SUB = REG_BG1CNT_SUB & 0x43;
		REG_BG2CNT_SUB = REG_BG2CNT_SUB & 0x43;
		REG_BG3CNT_SUB = REG_BG3CNT_SUB & 0x43;

		// Reset mosaic for all BGs
		REG_BG0CNT_SUB = REG_BG0CNT_SUB & ~0x40;
		REG_BG1CNT_SUB = REG_BG1CNT_SUB & ~0x40;
		REG_BG2CNT_SUB = REG_BG2CNT_SUB & ~0x40;
		REG_BG3CNT_SUB = REG_BG3CNT_SUB & ~0x40;

		// Reset priority for all BGs
		REG_BG0CNT_SUB = REG_BG0CNT_SUB & ~0x3;
		REG_BG1CNT_SUB = REG_BG1CNT_SUB & ~0x3;
		REG_BG2CNT_SUB = REG_BG2CNT_SUB & ~0x3;
		REG_BG3CNT_SUB = REG_BG3CNT_SUB & ~0x3;

		// Reset BG offsets
		REG_BG0OFS_SUB = 0;
		REG_BG1OFS_SUB = 0;
		REG_BG2OFS_SUB = 0;
		REG_BG3OFS_SUB = 0;

		NDS::Graphics::applyAffine2D(rcast<void*>(0x04001020), &identityMtx, 0, 0, 0, 0);
		NDS::Graphics::applyAffine2D(rcast<void*>(0x04001030), &identityMtx, 0, 0, 0, 0);

		REG_WININ_SUB = REG_WININ_SUB & ~0x3F;
		REG_WININ_SUB = REG_WININ_SUB & ~0x3F00;
		REG_WINOUT_SUB = REG_WINOUT_SUB & ~0x3F;
		REG_WINOUT_SUB = REG_WINOUT_SUB & ~0x3F00;

		REG_WIN0H_SUB = 0;
		REG_WIN0V_SUB = 0;
		REG_WIN1H_SUB = 0;
		REG_WIN1V_SUB = 0;

		REG_MOSAIC_BG_SUB = 0;
		REG_MOSAIC_OBJ_SUB = 0;

		NDS::Graphics::setMasterBrightness(rcast<void*>(0x0400106C), 0);

	}


}
