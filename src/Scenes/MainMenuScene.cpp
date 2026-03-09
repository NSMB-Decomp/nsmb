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

// void (Object229::*data_ov099_02186614[4])() = {
//     Object229::func_ov099_021860f0,
//     Object229::func_ov099_02186080,
//     Object229::func_ov099_02186028,
//     Object229::func_ov099_02185fb4,
// };
u32 data_ov009_020dbb94;
bool MainMenuScene::onRender()
{
	if ((data_ov009_020dbb94 & 1) == 0) {
		data_ov009_020dbbb4[0] = MainMenuScene::onRender_0;
		data_ov009_020dbbb4[1] = MainMenuScene::onRender_1;
		data_ov009_020dbbb4[2] = MainMenuScene::onRender_2;
		data_ov009_020dbbb4[3] = MainMenuScene::onRender_3;
		data_ov009_020dbbb4[4] = MainMenuScene::onRender_4;
		data_ov009_020dbb94 |= 1;
	}
	(this->*(data_ov009_020dbbb4[this->menuID]))();
	this->cutscene.func_ov009_020cd994();
	return true;
}

u32 data_ov009_020db914;
u32 data_ov009_020db854;
void MainMenuScene::onRender_1()
{
	if (this->stateID != 0x0) {
		this->label.func_02018060();
		i32 i = 0;
		do {
			i32 v = this->func_ov009_020ce944(i);
			this->func_ov009_020ceaec(i, v);
			i += 1;
		} while (i <= 2);
		Game::drawBNCLSpriteSub(0x15, &data_ov009_020db914, 0, this->func_ov009_020ce86c(), 0, 0, 0, 0, 0, this->button1Offset, this->buttonHitTimer + this->button1Offset);
		Game::drawBNCLSpriteSub(0x16, &data_ov009_020db854, 0, this->func_ov009_020ce86c(), 0, 0, 0, 0, 0, this->button2Offset, this->buttonHitTimer + this->button2Offset);
		this->func_ov009_020cea8c();
		this->func_ov009_020cea44(0);
	}
}
