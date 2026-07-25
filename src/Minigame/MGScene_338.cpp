#include "MGScene_338.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov130/symbols.hpp>

struct STRS {
	char *strings[27];
};

const STRS MG_DEBUG_STRINGS = {
    {
	"HANACHAN", "SNOWBALL", "LUIGI", "COIN", "MEMORY", "BOMROOM",
	"PACHINKO", "TAMAIRE", "JUMP", "JUMP2", "AMIDA", "FLOWER",
	"BOMTHROW", "SPEED", "CARD", "TERESA", "BLACKJACK", "PANEL",
	"TRAMPOLINE2", "MOGURA", "TAMAYOKE", "INDIPORKER", "RIVERSI",
	"BALLOON", "SNOWWAR", "MCARLO", "TITLE",
    },
};

ObjectProfile MGScene_338::profile = {
	MGScene_338::create,
	0x152,
	0x152,
};

u16 data_ov130_02139100[27] = {0x166, 0x169, 0x180, 0x16D, 0x16E, 0x16F, 0x171, 0x172, 0x167, 0x168, 0x16A, 0x16C, 0x170, 0x175, 0x174, 0x173, 0x176, 0x177, 0x178, 0x179, 0x17A, 0x17B, 0x17C, 0x17D, 0x17E, 0x17F, 0x148};

void *MGScene_338::create()
{
	return new MGScene_338();
}

void MGScene_338::virt_18()
{
	this->_68 = 0x1b;
}

char *MGScene_338::virt_19(u32 param_1)
{
	STRS a = MG_DEBUG_STRINGS;
	return a.strings[param_1];
}

void MGScene_338::virt_20(u32 param_1)
{
	bool a = false;
	bool b = false;
	u16 c = data_ov130_02139100[param_1];
	if ((Net::connectionState != 0) && (Net::connectionState != 9)) {
		b = true;
	}
	if (b && (Net::connectionState != 8)) {
		a = true;
	}
	if (a) {
		if (c == 0x148) {
			return;
		}
		if (c == 0x14e) {
			return;
		}
	}
	if ((c == 0x148) || (c == 0x14e)) {
		MGScene::func_02024ab8();
		MGScene::func_02024bec(c, 0, 0);
	} else {
		MGScene::func_02024ad0(&data_ov130_0213ad08);
		func_ov130_02135230(&data_ov130_0213ad08, 0);
		data_ov130_0213ace4 = 1;
		data_0203d318 = data_ov130_02139100[param_1];
		data_ov130_02137de0 = 0x1c;
		data_ov130_02137dec = 0;
		data_ov130_02137df0 = 0;
		MGScene::func_02024bec(0x151, 0, 0);
		u32 i = 0;
		u32 z = data_ov130_02137bf0 / 10; //! note: multiple values works so not sure what makes the most sense (for instance 43 works too)
		for (i = 0; i < z; i++) {
			if (c == data_ov130_02137df8[i].value) {
				data_ov130_02137dec = data_ov130_02137dfa[i].value;
				data_ov130_02137de0 = data_ov130_02137dfc[i].value;
				data_ov130_02137de8 = data_ov130_02137dfe[i].value;
				data_ov130_021395e4 = data_ov130_02137e00[i].value;
				break;
			}
		}
	}
	this->_64 = 0;
}

s32 MGScene_338::onCreate()
{
	u8 previousState = data_ov130_0213ace4;
	data_0208b594 |= 0x10;
	data_ov130_0213ace0 = 0;
	if (previousState != 0) {
		MGScene::func_02024ad0(&data_ov130_0213ad08);
	}
	data_ov130_0213ace4 = 0;
	func_02006674(1);
	return 1;
}

s32 MGScene_338::onDestroy()
{
	if (func_02023328(data_0203d2b0) == 0 && data_0203d2b0 != 0x151) {
		func_ov130_02122f60();
		FS::Archive::unloadMinigameArchives();
	}
	return 1;
}

MGScene_338::MGScene_338()
{
}
MGScene_338::~MGScene_338()
{
}
