#include "VSConnectScene.hpp"
#include "../system/app.hpp"

extern "C" {
void func_0200419c(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, s32);
void func_02043fe0(Vec2_32 *, Vec2_32 *, s32, s32, s32);
bool func_02007cb0(Fader *);
void func_02007b90(Fader *);
bool func_02007c68(Fader *);
void func_02007c20(Fader *);
void func_02007c44(Fader *);
void func_02007bb4(Fader *);
bool func_02010a14(u8);
bool func_02010a3c(VSConnectScene *);
bool func_02010a60(VSConnectScene *);
void func_02017e2c(void *, u32, u32);
void func_02017ff8(void *, u32 *);
void func_02017b94(void *);
void func_0200d87c(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_02003e20(void *);
void func_ov052_021535a0();
void func_02018060(void *);
void func_02008970();
void func_0200f608();
void func_0200f65c();
void func_0200f3d8();
void func_0200e944(u32, u32, u32);
void func_02017a80(void *);
void func_02017a90(void *);
void func_02016438(void *, const void *, u8);
s32 func_02046c78();
s32 func_0200f1b4(u8);
void func_02003f3c(void *);
void func_02003ed8(void *);
void func_02046b80();
s32 func_0200ec2c();
s32 func_02047694();
s32 func_02004c30();
s32 func_02010b34(void *, void *);
void func_0200e7c4(u32);
s32 func_0200e7ac(u32);
void func_0200e7b8(u32);
void func_0200e748();
void func_0201e00c();
void func_ov000_020bd604();
void func_02010bb0(void *, u32, void (*)(int, VSConnectScene *), VSConnectScene *);
void func_020180c0(void *, u32);
void func_02011d24(u32);
void func_02011c64();
void func_02008980();
int strncmp(const char *, const char *, u32);
}

namespace Wifi {
NicknameInfo *func_02001050(s32 aid);
u8 *func_0200102c(s32 aid);
void func_02001000();
void func_020010a8();
}

namespace Nitro {
u32 func_02055a0c(const BNBL *, u8, u8);
u32 func_02061e84();
u32 func_020620ac();
u32 func_02061e34();
u32 func_0206202c();
}

namespace Layout {
void initSub(void *, void *, void *);
}

namespace Net {
extern u8 connectionState;
}

struct NicknameInfo
{
	u8 data[0x1d];
	u8 valid;
};

extern u32 data_0208ae58;
extern u8 data_ov011_0212f54c[];
extern u32 data_ov052_0215af24[];
extern u8 data_02088804;
extern NicknameInfo *data_02088850;
extern u8 data_0208b4e8;
extern u8 data_0208b4ec;
extern u8 data_0208b4f4;
extern u8 data_0208adcc[];
extern u8 data_02088f30;
extern u8 data_02088800;
extern u16 data_0208883c;
extern u8 data_0208b4c4;
extern u8 data_0208b4c8[];
extern u8 data_0208b4c9[];
extern u8 data_0208b4ca[];
extern u8 data_0208b4cb[];
extern u8 data_0208ae54[];

static inline u32 &sceneWord(VSConnectScene *scene, u32 offset)
{
	return *(u32 *)((u8 *)scene + offset);
}

static inline u8 &sceneByte(VSConnectScene *scene, u32 offset)
{
	return *((u8 *)scene + offset);
}

static inline void renderSubMenuBackground()
{
	func_0200d87c(data_ov011_0212f54c, 0x80, 0x60, 0, 0, 0, 0, 0, 0, 0);
}

VSConnectScene::TextButton::TextButton()
{
	owner = 0;
}

VSConnectScene *VSConnectScene::construct()
{
	return new VSConnectScene();
}

void VSConnectScene::syncInputSchemeWrapper(int aid, VSConnectScene *owner)
{
	owner->syncInputScheme(aid);
}

void VSConnectScene::loadMvsLFilesThread()
{
	func_ov052_021535a0();
	data_0208ae58 = 1;
}

s32 VSConnectScene::onCreate()
{
	Nitro::FS_Overlays_loadOverlay(OVERLAY_ID(10));
	Nitro::FS_Overlays_loadOverlay(OVERLAY_ID(11));
	Nitro::FS_Overlays_loadOverlay(OVERLAY_ID(52));
	func_0200917c(5, 0);
	REG_DISPCNT &= ~0x07000000;
	REG_DISPCNT = (REG_DISPCNT & ~0x38000000) | 0x08000000;
	*(vu16 *)0x04000304 |= 0x8000;
	Nitro::func_02061ac4(8);
	Nitro::func_02061958(1);
	Nitro::func_02060d78(1, 0, 0);

	REG_DISPCNT = (REG_DISPCNT & 0xffcfffef) | 0x00200010;
	vu16 *bg3Main = (vu16 *)0x0400000e;
	*bg3Main = (*bg3Main & 0x43) | 0x108;
	FS::loadFileLZ77(0x75f, (void *)Nitro::func_02061e84());
	FS::loadFileLZ77(0x761, (void *)Nitro::func_020620ac());
	FS::loadFileLZ77(0x760, (void *)0x05000000);
	func_0200b87c();
	data_02087700 = 0;
	func_0200b83c(0);
	FS::loadFileLZ77(0x763, (void *)0x05000200);
	data_02085a88 = 0x18;
	*bg3Main = (*bg3Main & ~3) | 3;
	*(vu32 *)0x0400001c = 0;
	*bg3Main &= ~0x40;
	Nitro::func_020613c8(0x80);
	Nitro::func_0206134c(0x100);
	Nitro::func_02060d5c(0);

	vu16 *bg3Sub = (vu16 *)0x0400100e;
	*bg3Sub = (*bg3Sub & 0x43) | 0xd00;
	FS::loadFileLZ77(0x75f, (void *)Nitro::func_02061e34());
	FS::loadFileLZ77(0x762, (void *)Nitro::func_0206202c());
	FS::loadFileLZ77(0x760, (void *)0x05000400);
	FS::loadFileLZ77(0x78f, (void *)0x06600000);
	func_ov000_020bd604();
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffcfffef) | 0x10;
	FS::loadFileLZ77(0x763, (void *)0x05000600);
	*bg3Sub = (*bg3Sub & ~3) | 3;
	*(vu32 *)0x0400101c = 0;
	*bg3Sub &= ~0x40;

	sceneWord(this, 0x5c) = 0x9c;
	sceneWord(this, 0x60) = 0xf;
	scheduledSubMenu = 0;
	searchType = 3;
	subMenuState = 0;
	subMenuTimer = 0;
	selectMode = 0;
	inputScheme = 0;
	_17d = 0;
	specialMode = 0;
	_180[0] = 0;
	_164 = 0;
	for (s32 i = 0; i < 6; i++)
		_174[i] = 0;
	_174[6] = 0;
	func_02010bb0(&_204, 2, syncInputSchemeWrapper, this);
	_204.data[0x18] = data_02085ad4[0];
	_204.data[0x19] = save.options.soundMode;
	syncedAidMask = 0;
	for (s32 i = 0; i < 3; i++)
		activeButtons[i] = 0;
	buttons[2].create(0, 0, 0, 0);
	func_020180c0(&primaryText, 4);
	func_020180c0(&secondaryText, 2);
	changeSubMenu(&selectModeSM);
	subMenuChangeDelay = 0;
	func_02006674(1);
	func_02011d24(0x24);
	func_02011c64();
	func_02011e7c(0x1f, 0);
	func_02008980();
	return 1;
}

s32 VSConnectScene::onUpdate()
{
	func_02021808();
	for (s32 i = 0; i < 3; i++) {
		if (activeButtons[i])
			activeButtons[i]->update();
	}

	if (subMenuChangeDelay > 0) {
		if (--subMenuChangeDelay <= 0)
			changeSubMenu(scheduledSubMenu);
	} else if (currentSubMenu.update) {
		(this->*currentSubMenu.update)();
	}
	return 1;
}

s32 VSConnectScene::onRender()
{
	func_02018060(&primaryText);
	func_02018060(&secondaryText);
	if (currentSubMenu.render)
		(this->*currentSubMenu.render)();
	for (s32 i = 0; i < 3; i++) {
		if (activeButtons[i])
			activeButtons[i]->render();
	}
	return 1;
}

s32 VSConnectScene::onDestroy()
{
	func_020180a4(&primaryText);
	func_020180a4(&secondaryText);
	Nitro::FS_Overlays_unload(OVERLAY_ID(10));
	Nitro::FS_Overlays_unload(OVERLAY_ID(11));
	Nitro::FS_Overlays_unload(OVERLAY_ID(52));
	if (data_0203bd30 == 5) {
		func_020090f8(5);
		func_0200917c(9, 0);
	} else {
		func_020090f8(5);
		func_02008970();
	}
	func_0200f608();
	func_02011e3c(0);
	return 1;
}

void VSConnectScene::scheduleSubMenuChange(SubMenu *subMenu, s32 delay, bool playSound)
{
	sceneWord(this, 0x15c) = (u32)subMenu;
	sceneWord(this, 0x160) = delay;
	if (!playSound)
		return;

	if (sceneByte(this, 0x17f))
		func_02012398(0xea, (Vec3_32 *)0);
	else
		func_02012398(0xe9, (Vec3_32 *)0);
}

void VSConnectScene::changeSubMenu(SubMenu *subMenu)
{
	if (!subMenu) {
		func_020131fc(4, 0);
		func_02011e3c(0x1e);
		return;
	}

	currentSubMenu = *subMenu;
	specialMode = 0;
	for (s32 i = 0; i < 3; i++)
		activeButtons[i] = 0;

	if (currentSubMenu.create)
		(this->*currentSubMenu.create)();
}

void VSConnectScene::createSelectModeSM()
{
	void *bnbl = FS::Cache::loadFile(0x790, false);
	void *bncl = FS::Cache::loadFile(0x791, false);
	Layout::initSub((void *)0, bncl, bnbl);
	REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (data_02085a88 << 8);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	loadSelectModeText();
	func_0200f65c();

	textButtons[0].create(1, -0x100, 0, 5);
	textButtons[0].setup(0, 0, this);
	activeButtons[0] = &textButtons[0];
	textButtons[1].create(2, 0x100, 0, 5);
	textButtons[1].setup(0, 0, this);
	activeButtons[1] = &textButtons[1];

	sceneWord(this, 0x2b8) = -0x100;
	sceneWord(this, 0x2bc) = 0;
	sceneWord(this, 0x2c0) = 0x100;
	sceneWord(this, 0x2c4) = 0;
	buttons[2].palette = 0;
	activeButtons[2] = &buttons[2];
	selectButton(selectMode);
	subMenuState = 0;
}

void VSConnectScene::updateSelectModeSM()
{
	if (subMenuState == 0) {
		BOOL stopped = BOOL(textButtons[0].animType == Button::Static);
		if (stopped == FALSE)
			return;
		stopped = BOOL(textButtons[1].animType == Button::Static);
		if (stopped != FALSE)
			subMenuState = 1;
		return;
	}

	u32 previous = selectMode;
	s32 action = -1;
	u16 keys = Input::consoleKeys[Input::localConsoleID][0];
	if (keys & 1) {
		action = previous;
	} else if (keys & 2) {
		action = 2;
	} else {
		BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (connected != FALSE)
			action = Nitro::func_02055a0c(Layout::bnbl[1], data_0208b4e8, data_0208b4f4);
	}

	switch (action) {
	case 0:
	case 1:
		selectMode = action;
		inputScheme = 0;
		textButtons[selectMode].click();
		scheduleSubMenuChange(&charSelectSM, 0x1e, true);
		break;
	case 2:
		specialMode = 1;
		buttons[2].click();
		scheduleSubMenuChange(0, 0x1e, true);
		break;
	default:
		if (selectMode == 0) {
			if (Input::consoleKeys[Input::localConsoleID][0] & 0x80)
				selectMode = 1;
		} else if (Input::consoleKeys[Input::localConsoleID][0] & 0x40) {
			selectMode = 0;
		}
		if (selectMode != previous)
			func_02012398(0xe5, 0);
		break;
	}

	if (selectMode == previous && subMenuChangeDelay == 0)
		return;
	selectButton(selectMode);
	loadSelectModeText();
}

void VSConnectScene::renderSelectModeSM()
{
}

void VSConnectScene::createCharSelectSM()
{
	void *bnbl = FS::Cache::loadFile(0x792, false);
	void *bncl = FS::Cache::loadFile(0x793, false);
	Layout::initSub((void *)0, bncl, bnbl);
	REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (data_02085a88 << 8);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	u32 textID = 2;
	func_02017ff8(&primaryText, &textID);
	func_0200f65c();

	buttons[0].create(1, -0x100, 0, 1);
	buttons[0].setup(0, 0);
	activeButtons[0] = &buttons[0];
	buttons[1].create(2, 0x100, 0, 2);
	buttons[1].setup(0, 0);
	activeButtons[1] = &buttons[1];
	buttons[2].palette = 0;
	activeButtons[2] = &buttons[2];
	selectButton(inputScheme);
	subMenuState = 0;
}

void VSConnectScene::updateCharSelectSM()
{
	if (subMenuState == 0) {
		BOOL stopped = BOOL(buttons[0].animType == Button::Static);
		if (stopped == FALSE)
			return;
		stopped = BOOL(buttons[1].animType == Button::Static);
		if (stopped != FALSE)
			subMenuState = 1;
		return;
	}

	u32 previous = inputScheme;
	s32 action = -1;
	u16 keys = Input::consoleKeys[Input::localConsoleID][0];
	if (keys & 1) {
		action = previous;
	} else if (keys & 2) {
		action = 2;
	} else {
		BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;
		if (connected != FALSE)
			action = Nitro::func_02055a0c(Layout::bnbl[1], data_0208b4e8, data_0208b4f4);
	}

	switch (action) {
	case 0:
	case 1:
		inputScheme = action;
		buttons[inputScheme].click();
		scheduleSubMenuChange(&searchSM, 0x1e, true);
		break;
	case 2:
		specialMode = 1;
		buttons[2].click();
		scheduleSubMenuChange(&selectModeSM, 0x1e, true);
		break;
	default:
		if (inputScheme == 0) {
			if (Input::consoleKeys[Input::localConsoleID][0] & 0x80)
				inputScheme = 1;
		} else if (Input::consoleKeys[Input::localConsoleID][0] & 0x40) {
			inputScheme = 0;
		}
		if (inputScheme != previous)
			func_02012398(0xe5, 0);
		break;
	}

	if (inputScheme == previous && subMenuChangeDelay == 0)
		return;
	selectButton(inputScheme);
}

void VSConnectScene::renderCharSelectSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::createSearchSM()
{
	if (sceneWord(this, 0x168) == 3) {
		if (sceneByte(this, 0x17b))
			sceneWord(this, 0x168) = 0;
		else if (sceneByte(this, 0x17c))
			sceneWord(this, 0x168) = 2;
		else
			sceneWord(this, 0x168) = 1;
	}

	u32 textID = data_ov052_0215af24[sceneWord(this, 0x168)];
	func_02017ff8((u8 *)this + 0x220, &textID);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	buttons[2].palette = 0;
	sceneWord(this, 0x13c) = (u32)&buttons[2];
	sceneWord(this, 0x16c) = 0;
}

void VSConnectScene::updateSearchSM()
{
	func_02017a90(&primaryText);
	if (_164 > 0)
		_164--;
	else
		_180[0] = 0;

	BOOL connected;
	BOOL invalidConnection;
	BOOL invalidState;
	NicknameInfo *nickname;
	if (Input::consoleKeys[Input::localConsoleID][0] & 2)
		goto cancel;
	connected = BOOL(data_0208b4f0 != 0 && data_0208b4ec != 0);
	if (connected != FALSE) {
		if (Nitro::func_02055a0c(Layout::bnbl[1], data_0208b4e8, data_0208b4f4) == 2)
			goto cancel;
	}
	goto normal;

cancel:
	specialMode = 1;
	buttons[2].click();
	scheduleSubMenuChange(&charSelectSM, 0x1e, true);
	searchType = 3;
	_180[0] = 0;
	_164 = 0;
	func_0200f3d8();
	func_02017a80(&primaryText);
	return;

normal:
	if (subMenuState == 0) {
		invalidConnection = false;
		invalidState = false;
		if (Net::connectionState != 0 && Net::connectionState != 9)
			invalidState = true;
		if (invalidState && Net::connectionState != 8)
			invalidConnection = true;
		if (invalidConnection)
			return;

		if (startConsoleSearch()) {
			func_0200e944(sceneWord(this, 0x5c), sceneWord(this, 0x60), 0);
			subMenuState = 1;
			func_02017b94(&primaryText);
			return;
		}
		scheduleSubMenuChange(&connectionInterruptedSM, 1, true);
		return;
	}

	if (_164 >= 540)
		return;
	nickname = getOpponentNickname();
	if (!nickname)
		return;
	scheduleSubMenuChange(&confirmSM, 1, true);
	func_02016438(data_0208adcc, &nickname->data[2], nickname->data[1]);
	func_02017a80(&primaryText);
}

void VSConnectScene::renderSearchSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::createConfirmSM()
{
	_17d = 0;
	if (inputScheme == 1) {
		u32 textID = 6;
		func_02017ff8(&primaryText, &textID);
	} else {
		u32 textID = 5;
		func_02017ff8(&primaryText, &textID);
	}
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	buttons[0].create(3, -0x100, 0, 3);
	buttons[0].setup(0, 0);
	activeButtons[0] = &buttons[0];
	buttons[1].create(4, 0x100, 0, 4);
	buttons[1].setup(0, 0);
	activeButtons[1] = &buttons[1];
	selectButton(_17d);
	subMenuState = 0;
}

void VSConnectScene::updateConfirmSM()
{
	switch (subMenuState) {
	case 0:
		BOOL stopped = BOOL(buttons[0].animType == Button::Static);
		if (stopped == FALSE)
			return;
		stopped = BOOL(buttons[1].animType == Button::Static);
		if (stopped != FALSE)
			subMenuState = 1;
		return;

	case 1: {
		if (func_02046c78() != 0 && data_02088804 < 2) {
			func_02012398(0xe9, 0);
			subMenuState = 4;
			return;
		}

		u32 previous = _17d;
		s32 action = -1;
		u16 keys = Input::consoleKeys[Input::localConsoleID][0];
		if (keys & 1) {
			action = previous;
		} else if (keys & 2) {
			action = 1;
		} else {
			BOOL connected = data_0208b4f0 != 0 && data_0208b4ec != 0;
			if (connected != FALSE)
				action = Nitro::func_02055a0c(Layout::bnbl[1], data_0208b4e8, data_0208b4f4);
		}

		switch (action) {
		case 0:
			_17d = action;
			buttons[_17d].click();
			buttons[_17d ^ 1].palette = 2;
			if (searchType == 0) {
				Wifi::func_020010a8();
				subMenuTimer = 0x1e;
				subMenuState = 2;
				func_02012398(0xe9, 0);
			} else if (searchType == 1) {
				Wifi::func_02001000();
				scheduleSubMenuChange(&loadGameSM, 0x1e, true);
			} else {
				scheduleSubMenuChange(&waitHostConfirmSM, 0x1e, true);
			}
			data_02088f30 = 0;
			return;

		case 1:
			_17d = action;
			buttons[_17d].click();
			buttons[_17d ^ 1].palette = 2;
			func_02012398(0xe9, 0);
			subMenuState = 3;
			return;

		default:
			if (_17d == 0) {
				if (Input::consoleKeys[Input::localConsoleID][0] & 0x80)
					_17d = 1;
			} else if (Input::consoleKeys[Input::localConsoleID][0] & 0x40) {
				_17d = 0;
			}
			if (_17d != previous) {
				activeButtons[_17d]->palette = 0;
				activeButtons[_17d ^ 1]->palette = 2;
				func_02012398(0xe5, 0);
			}
			return;
		}
	}

	case 2:
		if (--subMenuTimer > 0)
			return;
		func_02007c20(&GlobalFader);
		func_02007b90(&GlobalFader);
		func_02011e3c(0x1e);
		scheduleSubMenuChange(&loadGameSM, 0x21, false);
		return;

	case 3:
		func_0200f3d8();
		scheduleSubMenuChange(&searchSM, 0x1e, false);
		return;

	case 4:
		func_0200f3d8();
		scheduleSubMenuChange(&playerLeftSM, 0x1e, false);
		return;
	}
}

void VSConnectScene::renderConfirmSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::createWaitHostConfirmSM()
{
	sceneWord(this, 0x16c) = 0;
	u32 textID = 9;
	func_02017ff8((u8 *)this + 0x220, &textID);
	func_02017b94((u8 *)this + 0x220);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	buttons[2].palette = 0;
	sceneWord(this, 0x13c) = (u32)&buttons[2];
}

void VSConnectScene::updateWaitHostConfirmSM()
{
	func_02017a90(&primaryText);
	u32 console;
	BOOL connected;
	u16 ready;
	if (Input::consoleKeys[Input::localConsoleID][0] & 2)
		goto cancel;
	console = data_0208b4c4;
	connected = false;
	if (data_0208b4c8[console * 4] == 0)
		goto checkConnection;
	if (data_0208b4c9[console * 4] != 0)
		connected = true;
checkConnection:
	if (connected != FALSE) {
		if (Nitro::func_02055a0c(Layout::bnbl[1], data_0208b4ca[console * 4],
				data_0208b4cb[console * 4]) == 2)
			goto cancel;
	}
	goto normal;

cancel:
		specialMode = 1;
		buttons[2].click();
		scheduleSubMenuChange(&searchSM, 0x1e, true);
		func_0200f3d8();
		data_02088f30 = 1;
		func_02017a80(&primaryText);
		return;


normal:
	if (subMenuState == 0) {
		if (func_0200f1b4(_174[6]) != 0) {
			subMenuState = 1;
			return;
		}
	} else {
		if (BOOL(data_02088800 == 2) != FALSE) {
			scheduleSubMenuChange(&loadGameSM, 0x1e, true);
			func_02017a80(&primaryText);
			return;
		}
		ready = data_0208883c & 4;
		if (ready == 0)
			return;
	}

	func_0200f3d8();
	scheduleSubMenuChange(&playerLeftSM, 1, true);
	data_02088f30 = 1;
	func_02017a80(&primaryText);
}

void VSConnectScene::renderWaitHostConfirmSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::createPlayerLeftSM()
{
	if (sceneByte(this, 0x17c) == 1) {
		u32 textID = 8;
		func_02017ff8((u8 *)this + 0x220, &textID);
	} else {
		u32 textID = 7;
		func_02017ff8((u8 *)this + 0x220, &textID);
	}
	sceneWord(this, 0x170) = 0x78;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
}

void VSConnectScene::updatePlayerLeftSM()
{
	if (--(s32 &)sceneWord(this, 0x170) > 0)
		return;
	sceneByte(this, 0x17f) = 1;
	scheduleSubMenuChange(&searchSM, 0x1e, true);
}

void VSConnectScene::renderPlayerLeftSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::createLoadGameSM()
{
	u32 textID = 9;
	func_02017ff8(&primaryText, &textID);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
	if (searchType == 0 && inputScheme == 1) {
		data_0208ae54[0] = 1;
		data_0208ae54[1] = 0;
	} else {
		data_0208ae54[0] = 0;
		data_0208ae54[1] = 1;
	}
	if (searchType == 0) {
		func_02003f3c(_180 + 4);
		func_02007bb4(&GlobalFader);
		subMenuState = 0;
	} else {
		subMenuState = 1;
	}
	subMenuTimer = 0;
}

void VSConnectScene::updateLoadGameSM()
{
	if (func_02007cb0(&GlobalFader))
		func_02007c44(&GlobalFader);

	switch (subMenuState) {
	case 0:
		if (BOOL(Net::connectionState == 1) != FALSE) {
			subMenuTimer++;
			if (subMenuTimer >= 0x708)
				data_0208883c |= 0x8000;
		} else {
			subMenuState = 1;
			subMenuTimer = 0;
		}
		break;

	case 1:
		if (BOOL(data_02088800 == 2) != FALSE) {
			if (data_02088804 != 2) {
				data_0208883c |= 0x8000;
				break;
			}
			if (func_02046c78() != 0)
				func_02046b80();
			if (func_0200ec2c() == 0)
				data_02085a84 = 1;
			else
				data_02085a84 = 2;
			subMenuState = 2;
			subMenuTimer = 0;
		} else {
			subMenuTimer++;
			if (subMenuTimer >= 900)
				data_0208883c |= 0x8000;
		}
		break;

	case 2:
		if (func_0200ec2c() == 0 || func_02047694() != 0) {
			func_02004cb8((u32)&loadMvsLFilesThread, 0, 0x14, 0, 0x1000);
			subMenuState = 3;
		}
		break;

	case 3:
		if (BOOL(data_02088800 == 2) == FALSE || func_02004c30() == 0)
			break;
		subMenuState = 4;
	case 4:
		if (func_02010b34(&_204, _180 + 0x9c) != 0)
			subMenuState = 5;
		break;

	case 5: {
		bool synced = true;
		for (s32 aid = 0; aid < 2; aid++) {
			if ((syncedAidMask & (1 << aid)) == 0) {
				synced = false;
				break;
			}
		}
		if (synced) {
			func_0200e7c4(0);
			subMenuState = 6;
		}
		break;
	}

	case 6:
		if (func_0200e7ac(0) != 0) {
			func_0200e7b8(0);
			func_0200e748();
			func_0201e00c();
			if (func_0200ec2c() == 0) {
				func_020131fc(5, 1);
				func_02011e3c(0x1e);
			} else {
				func_020131fc(5, 0);
			}
			subMenuState = 7;
		}
		break;
	}

	if (subMenuState >= 2 && subMenuState < 7) {
		subMenuTimer++;
		if (subMenuTimer >= 0x1518)
			data_0208883c |= 0x8000;
	}
	if (searchType == 0)
		func_02003ed8(_180 + 4);
}

void VSConnectScene::renderLoadGameSM()
{
	renderSubMenuBackground();
	if (sceneWord(this, 0x168) == 0)
		func_02003e20((u8 *)this + 0x184);
}

void VSConnectScene::createConnectionInterruptedSM()
{
	u32 textID = 0x12;
	func_02017ff8((u8 *)this + 0x2d0, &textID);
	sceneWord(this, 0x170) = 0x78;
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
}

void VSConnectScene::updateConnectionInterruptedSM()
{
	if (sceneWord(this, 0x16c) == 0) {
		if ((Input::consoleKeys[Input::localConsoleID][0] & 1) == 0)
			return;
		func_02007b90(&GlobalFader);
		sceneWord(this, 0x16c) = 1;
	} else if (func_02007c68(&GlobalFader)) {
		App::reset(0x10100);
	}
}

void VSConnectScene::renderConnectionInterruptedSM()
{
	renderSubMenuBackground();
}

void VSConnectScene::selectButton(int id)
{
	if (!sceneByte(this, 0x17f) && sceneWord(this, 0x160) == 0)
		(*(Button **)((u8 *)this + 0x134 + id * 4))->palette = 0;
	id ^= 1;
	(*(Button **)((u8 *)this + 0x134 + id * 4))->palette = 2;
}

void VSConnectScene::loadSelectModeText()
{
	func_02017e2c((u8 *)this + 0x220, sceneByte(this, 0x17b) == 0, 1);
}

void VSConnectScene::updateTextButtonText()
{
	s32 x0 = textButtons[0].position.x;
	s32 y1 = textButtons[1].position.y;
	s32 x1 = textButtons[1].position.x;
	s32 y0 = textButtons[0].position.y;
	*(s32 *)((u8 *)this + 0x2b8) = x0 >> 12;
	*(s32 *)((u8 *)this + 0x2bc) = y0 >> 12;
	*(s32 *)((u8 *)this + 0x2c0) = x1 >> 12;
	*(s32 *)((u8 *)this + 0x2c4) = y1 >> 12;
}

bool VSConnectScene::startConsoleSearch()
{
	bool result = false;
	switch (sceneWord(this, 0x168)) {
	case 1:
		result = func_02010a60(this);
		break;
	case 2:
		result = func_02010a3c(this);
		break;
	case 0:
		result = func_02010a14(sceneByte(this, 0x17c));
		break;
	}
	return result;
}

NicknameInfo *VSConnectScene::getOpponentNickname()
{
	if (searchType == 2) {
		for (s32 aid = 0; aid < 4; aid++) {
			NicknameInfo *nickname = Wifi::func_02001050(aid);
			if (!nickname)
				continue;

			u8 *address = Wifi::func_0200102c(aid);
			if (!_180[0] || strncmp((char *)address, (char *)_174, 6)) {
				_174[6] = aid;
				MI_CpuCopy8(address, _174, 6);
				_180[0] = 1;
				_164 = 600;
				return nickname;
			}
		}
	} else if (data_02088804 == 2) {
		for (s32 aid = 1; aid < 4; aid++) {
			NicknameInfo *nickname = &data_02088850[aid];
			NicknameInfo *result = nickname->valid ? nickname : 0;
			if (result)
				return result;
		}
	}
	return 0;
}

void VSConnectScene::syncInputScheme(int aid)
{
	u32 searchType = sceneWord(this, 0x168);
	u32 entry = *(u32 *)((u8 *)this + 0x208 + aid * 4);
	if (searchType == 0 && aid != 0)
		data_02085ad4[aid] = data_02085ad4[0];
	else
		data_02085ad4[aid] = *(u8 *)entry;
	sceneByte(this, 0x17e) |= 1 << aid;
}

void VSConnectScene::Button::update()
{
	if (!func_02007cb0(&GlobalFader))
		return;

	switch (animType) {
	case Lerp:
		func_02043fe0(&position, &endPosition, 0x400, 0x30000, 0x800);
		if ((position.x >> 12) == 0)
			animType = Static;
		break;

	case SlightMove:
		animFrame = (s8)animFrame + 1;
		switch ((s8)animFrame) {
		case 1:
		case 3:
			move((position.x >> 12) + 1, (position.y >> 12) + 1);
			break;
		case 7:
			animType = Static;
		case 5:
			move((position.x >> 12) - 1, (position.y >> 12) - 1);
			break;
		}
		break;
	}
}

void VSConnectScene::Button::render()
{
	func_0200419c(bnclRectID, (u32)buttonOamAttrs[oamAttrID], 0, palette,
		0, 0, 0, 0, 0, position.x >> 12, position.y >> 12);
}

void VSConnectScene::Button::create(s32 rectID, s32 x, s32 y, s32 attrID)
{
	position.x = x << 12;
	position.y = y << 12;
	bnclRectID = rectID;
	oamAttrID = attrID;
	palette = 0;
}

void VSConnectScene::Button::move(s32 x, s32 y)
{
	position.x = x << 12;
	position.y = y << 12;
}

void VSConnectScene::Button::setup(s32 x, s32 y)
{
	endPosition.x = x << 12;
	endPosition.y = y << 12;
	animType = Lerp;
}

void VSConnectScene::Button::click()
{
	palette = 1;
	animFrame = 0;
	animType = SlightMove;
}

void VSConnectScene::TextButton::update()
{
	Button::update();
	if (owner)
		owner->updateTextButtonText();
}

void VSConnectScene::TextButton::render()
{
	func_0200419c(bnclRectID, (u32)buttonOamAttrs[oamAttrID], 0x30, palette,
		0, 0, 0, 0, 0, position.x >> 12, position.y >> 12);
}

void VSConnectScene::TextButton::setup(s32 x, s32 y, VSConnectScene *scene)
{
	Button::setup(x, y);
	owner = scene;
}

VSConnectScene::TextButton::~TextButton()
{
}

VSConnectScene::~VSConnectScene()
{
}
