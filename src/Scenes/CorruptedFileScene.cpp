#include "CorruptedFileScene.hpp"

const u32 data_ov005_020ccd28[4] = {
	1,
	2,
    3,
    4,
};
const u32 data_ov005_020ccd18[4] = {
	0x100,
	0x200,
	0x400,
	0x800,
};

void *CorruptedFileScene::create()
{
	return new CorruptedFileScene();
}
void func_02014820(void*);
void func_0201481c(void*);
CorruptedFileScene::CorruptedFileScene()
{
    func_02014820(&this->_64); // TODO: Is this a class?
}

CorruptedFileScene::~CorruptedFileScene()
{
    func_0201481c(&this->_64); // TODO: Is this a class?
}

bool CorruptedFileScene::onCreate() {

}
bool CorruptedFileScene::onDestroy() {
    
}
void func_02014824(u32, u32);
void func_020144bc(u32*, u32, u32, u32);
void func_020145f8(u32*, u32, u32);
void func_0201486c(u32, u32, u32);
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
			func_020144bc(&this->_64,this->_f4,0,0);
			break;
		case 3:
		case 9:
		case 11:
			func_02014824(0,0);
	}
	func_020145f8(&this->_64,0,0);
  	func_0201486c(0,0,0);
	return true;
}
bool CorruptedFileScene::onUpdate() {
    
}
void CorruptedFileScene::pendingDestroy() {

}