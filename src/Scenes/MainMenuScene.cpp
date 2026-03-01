#include "MainMenuScene.hpp"

void (MainMenuScene::*data_ov009_020dbbb4[5])();

void *MainMenuScene::create()
{
	return new MainMenuScene();
}

MainMenuScene::MainMenuScene()
{
}

bool MainMenuScene::onCreate()
{
}

// void (Object_229::*data_ov099_02186614[4])() = {
//     Object_229::func_ov099_021860f0,
//     Object_229::func_ov099_02186080,
//     Object_229::func_ov099_02186028,
//     Object_229::func_ov099_02185fb4,
// };
u32 data_ov009_020dbb94;
bool MainMenuScene::onRender()
{
	if ((data_ov009_020dbb94 & 1) == 0) {
		data_ov009_020dbbb4[0] = MainMenuScene::func_ov009_020cf668;
		data_ov009_020dbbb4[1] = MainMenuScene::func_ov009_020cf564;
		data_ov009_020dbbb4[2] = MainMenuScene::func_ov009_020cf314;
		data_ov009_020dbbb4[3] = MainMenuScene::func_ov009_020cf1b4;
		data_ov009_020dbbb4[4] = MainMenuScene::func_ov009_020cecec;
		data_ov009_020dbb94 |= 1;
	}
	(this->*(data_ov009_020dbbb4[this->menuID]))();
	this->cutscene.func_ov009_020cd994();
	return true;
}
