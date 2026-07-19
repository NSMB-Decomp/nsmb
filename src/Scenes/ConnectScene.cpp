#include "ConnectScene.hpp"

ConnectScene::ConnectScene()
{

}
void *ConnectScene::create()
{
	return new ConnectScene();
}

u32 ConnectScene::func_020037e4() {
	func_0200917c(0x9, 0x0);
	func_0200917c(0x5, 0x0);
	Nitro::FS_Overlays_loadOverlay(OVERLAY_11);
	Nitro::FS_Overlays_loadOverlay(OVERLAY_LEVEL);
	Nitro::FS_Overlays_loadOverlay(OVERLAY_52);
	func_ov052_021535a0();
	func_020125c4();
	func_02011c64();
	return func_020090f8(0x5);
}


ConnectScene::~ConnectScene()
{

}