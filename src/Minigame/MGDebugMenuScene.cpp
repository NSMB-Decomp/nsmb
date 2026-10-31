#include "MGDebugMenuScene.hpp"

// 0x02138980
char *data_ov130_02138980[5] = {
	"1P MODE",
	"MULTIBOOT VS MENU MODE",
	"ROM VS MENU MODE - PARENT",
	"ROM VS CHILD",
	"ROM VS FAKE CHILD",
};

void *MGDebugMenuScene::create()
{
	return new MGDebugMenuScene();
}

void MGDebugMenuScene::virt_18()
{
	this->_68 = 5;
}

char *MGDebugMenuScene::virt_19(u32 param_1)
{
	return data_ov130_02138980[param_1];
}

void func_ov130_02137518(u32);
extern u16 data_ov130_02137de4;
void MGDebugMenuScene::virt_20(u32 param_1)
{
	switch (param_1) {
	case 0:
		func_ov130_02137518(1);
		MGScene::func_02024bec(0x153, 0, 0);
		break;
	case 1:
		data_ov130_02137de4 = 0x14a;
		MGScene::func_02024bec(0x14e, 0, 0);
		func_ov130_02137518(2);
		break;
	case 2:
		data_ov130_02137de4 = 0x14a;
		MGScene::func_02024bec(0x14e, 1, 0);
		func_ov130_02137518(2);
		break;
	case 3:
		data_ov130_02137de4 = 0x14a;
		MGScene::func_02024bec(0x14e, 2, 0);
		func_ov130_02137518(2);
		break;
	case 4:
		data_ov130_02137de4 = 0x152;
		MGScene::func_02024bec(0x14e, 3, 0);
		func_ov130_02137518(2);
		break;
	}
	this->_64 = 0;
}

// 0x02138954
ObjectProfile Object329_Profile = { MGDebugMenuScene::create, 0x149, 0x149 };
