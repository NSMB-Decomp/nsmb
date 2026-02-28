#include "MGDebugMenuScene.hpp"

struct STRS {
	char *strings[27];
};
const STRS MG_DEBUG_STRINGS = {
    {"1P MODE", "MULTIBOOT VS MENU MODE", "ROM VS MENU MODE - PARENT", "ROM VS CHILD", "ROM VS FAKE CHILD"},
};

MGDebugMenuScene::MGDebugMenuScene()
{
}
MGDebugMenuScene::~MGDebugMenuScene()
{
}
void MGDebugMenuScene::virt_18()
{
	this->_68 = 5;
}

char *MGDebugMenuScene::virt_19(u32 param_1)
{
	return MG_DEBUG_STRINGS.strings[param_1];
}

void MGDebugMenuScene::virt_20(u32 param_1)
{
	switch (param_1) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}
