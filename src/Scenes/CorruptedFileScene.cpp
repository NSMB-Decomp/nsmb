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
    func_02014820(&this->a); // TODO: Is this a class?
}

CorruptedFileScene::~CorruptedFileScene()
{
    func_0201481c(&this->a); // TODO: Is this a class?
}

bool CorruptedFileScene::onCreate() {

}
bool CorruptedFileScene::onDestroy() {
    
}
bool CorruptedFileScene::onRender() {
    
}
bool CorruptedFileScene::onUpdate() {
    
}
void CorruptedFileScene::pendingDestroy() {

}