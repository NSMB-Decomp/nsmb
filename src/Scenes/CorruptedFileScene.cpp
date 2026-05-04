#include "CorruptedFileScene.hpp"

const u32 data_ov005_020ccd18[4] = {
	0x100,
	0x200,
	0x400,
	0x800,
};
const u32 data_ov005_020ccd28[4] = {
	1,
	2,
    3,
    4,
};

void *CorruptedFileScene::create()
{
	return new CorruptedFileScene();
}
void func_02014820(void*);
void func_0201481c(void*);
CorruptedFileScene::CorruptedFileScene()
{
}
CorruptedFileScene::~CorruptedFileScene()
{
}


bool CorruptedFileScene::onCreate() {
	REG_POWER_CNT = REG_POWER_CNT & 0xfffffdf1 | 0x20e;
	Nitro::func_02061274();
	Nitro::func_02061260();
	Nitro::func_0206123c();
	Nitro::func_02061218();
	Nitro::func_02061204();
	Nitro::func_020611f0();
	Nitro::func_020611dc();
	Nitro::func_020611c8();
	Nitro::func_020611b4();
	Nitro::func_0206118c();
	Nitro::func_02061164();
	Nitro::func_02061588(6);
	Nitro::func_02061ac4(8);
	Nitro::func_02061494(0x10);
	Nitro::func_02061958(1);
	Nitro::func_02061844(0x40);
	Nitro::func_0206178c(0x20);
	REG_BG0CNT &= ~0x40;
	REG_BG1CNT &= ~0x40;
	REG_BG2CNT &= ~0x40;
	REG_BG3CNT &= ~0x40;
	REG_DISPCNT = REG_DISPCNT & 0xffcfffef | 0x200010;
	REG_DISPCNT = REG_DISPCNT & 0xffbfff9f | 0x20;
	Nitro::func_02056f40(2,1);
	Nitro::func_020571c4(0x10000,1);
	Nitro::func_02060d78(1,5,1);
	REG_POWER_CNT |= 0x8000;
	REG_DISPCNT = REG_DISPCNT & ~0x1f00 | 0x1000;
	data_02085a88 = 0x10;
	REG_BG0CNT &= ~3;
	REG_BG1CNT = REG_BG1CNT & ~3 | 3;
	REG_BG2CNT = REG_BG2CNT & ~3 | 1;
	REG_BG3CNT = REG_BG3CNT & ~3 | 2;
	data_02085e0c = 0;
	func_0200b87c();
	data_02087700 = 0;
	func_0200b83c(0);
	func_02009a30(0x75c,0,1);
	func_02017190(2);
	SceneNode* sn = func_020087f0();
	this->_dc = sn;
	this->_64.func_020144a8();
	this->_64.func_0201443c();
	u32 settings = this->settings;
	u32 settings_2 = settings & 0xff;
	this->_ec = settings & 0xf00;
	switch(settings_2) {
		case 6:
		case 8:
		case 0xf:
		case 0x10:
		case 0x11:
			this->_e4 = 0;
			break;
		case 5:
			this->_e4 = 2;
			this->_e8 = 0x78;
			if (this->_ec != 0xf00) {
				settings_2 = 0;
				this->func_ov005_020cc314();
			}
			break;
		case 0:
			this->_e4 = 2;
			this->_e8 = 0x78;
			this->func_ov005_020cc314();
			break;
		case 7:
			this->_e4 = 2;
			this->_e8 = 0x78;
			this->_ec = 0x1000;
			break;
		case 0xb:
			this->_e4 = 0x6;
			this->_ec = 0x1f00;
			break;
		default:
			this->_e4 = 0;
			break;
	}
	this->func_ov005_020cc3a4(settings_2);
	if (settings_2 == 0) {
		this->func_ov005_020cc2e0();
	}
	func_02012398(0xee,0);
	GlobalFader.func_02007bd8();
	data_02088f30 = 0;
	return true;
}
bool CorruptedFileScene::onDestroy() {
    func_020087c0(this->_dc);
	FS::Cache::clear();
	GlobalFader.func_02007bfc();
	data_02088f30 = 1;
	return true;
}
void CorruptedFileScene::pendingDestroy() {

}
bool CorruptedFileScene::onRender() {
    switch(this->_e4) {
		case 0:
		case 1:
		case 2:
		case 4:
		case 5:
		case 8:
		case 10:
			break;
		case 6:
		case 7:
			this->_64.func_020144bc(this->_f4,0,0);
			break;
		case 3:
		case 9:
		case 11:
			func_02014824(0,0);
	}
	this->_64.func_020145f8(0,0);
  	func_0201486c(0,0,0);
	return true;
}
bool CorruptedFileScene::onUpdate() {
	if (!GlobalFader.func_02007cb0()) {
		return true;
	}

	switch (this->_e4) {
		case 0:
			this->_e4 = 1;
			break;
		case 1:
			this->func_ov005_020cc77c();
			break;
		case 2:
		case 4:
		case 8:
		case 10:
			this->func_ov005_020cc75c();
			break;
		case 3:
		case 9:
		case 11:
			this->func_ov005_020cc664();
			break;
		case 5:
			this->func_ov005_020cc5bc();
			break;
		case 6:
		case 7:
			this->func_ov005_020cc4a4();
			break;
	}
	return true;
}
void CorruptedFileScene::func_ov005_020cc77c() {
	func_020051ec();
	func_020045cc();
}
void CorruptedFileScene::func_ov005_020cc75c() {
	if (this->_e8 > 0) {
		this->_e8 -= 1;
	}else {
		this->_e4 += 1;
	 }
}
void CorruptedFileScene::func_ov005_020cc664() {}
void CorruptedFileScene::func_ov005_020cc5bc() {}
void CorruptedFileScene::func_ov005_020cc4a4() {}
//void CorruptedFileScene::func_ov005_020cc404() {}
//void CorruptedFileScene::func_ov005_020cc3a4() {}
void CorruptedFileScene::func_ov005_020cc314() {}
void CorruptedFileScene::func_ov005_020cc2e0() {
	if (this->_f0 == 3) {
		return;
	}
	u32 a = this->_64.func_020141b8();
	u32 b = this->_f0 + a - 3;
	this->_64.func_020141c0(b);
}
