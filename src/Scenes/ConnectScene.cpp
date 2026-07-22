#include "ConnectScene.hpp"
#include "../system/app.hpp"

ConnectScene::ConnectScene()
{

}
void *ConnectScene::create()
{
	return new ConnectScene();
}

u32 ConnectScene::func_020037e4(u32) {
	func_0200917c(0x9, 0x0);
	func_0200917c(0x5, 0x0);
	FS::Overlay::load(OVERLAY_11);
	FS::Overlay::load(OVERLAY_LEVEL);
	FS::Overlay::load(OVERLAY_52);
	func_ov052_021535a0();
	func_020125c4();
	func_02011c64();
	return func_020090f8(0x5);
}

u32 data_0208ae58;
void ConnectScene::func_020037b4() {
	App::initBoot(0x0);
	ConnectScene::func_020037e4(0x0);
	data_0208ae58 = 0x1;
}

u32 ConnectScene::func_0200379c(u32 a, u32 b) {
	return ConnectScene::func_02003250(b, a, a);
}

bool ConnectScene::func_020032ac(u32 param_r0) {
	func_02003e20(&this->connectionStatus);
	return true;
}

bool ConnectScene::func_020032a4() {
	return true;
}

//u32 ConnectScene::func_02003250(u32 param_r0, u32 param_r1) {
//	u32 local_r2;
//	u32 local_r4;
//	u32 local_r5;
//	local_r4 = param_r1;
//	local_r5 = param_r0;
//	if ((local_r4 != 0x0)) {
//	} else {
//		param_r0 = (local_r5 + (local_r4 << 0x2));
//		local_r2 = (*rcast<u32*>((param_r0 + 0xe8)));
//		param_r0 = (u32)&data_02085ad4;
//		param_r1 = (*rcast<u8*>((local_r2 + 0x0)));
//		data_02085ad4 = param_r1;
//		param_r1 = (*rcast<u8*>((local_r2 + 0x0)));
//		(*rcast<u32*>(0x02085ad8)) = param_r1;
//		param_r0 = (*rcast<u8*>((local_r2 + 0x1)));
//		(param_r0 = func_02006444((*rcast<u8*>(((*rcast<u32*>(((local_r5 + (local_r4 << 0x2)) + 0xe8))) + 0x1))), (*rcast<u8*>(((*rcast<u32*>(((local_r5 + (local_r4 << 0x2)) + 0xe8))) + 0x0))), (*rcast<u32*>(((local_r5 + (local_r4 << 0x2)) + 0xe8)))));
//	}
//	param_r1 = (*rcast<u8*>((local_r5 + 0x104)));
//	param_r0 = (param_r1 | (0x1 << local_r4));
//	(*rcast<u8*>((local_r5 + 0x104))) = param_r0;
//	return param_r0;
//}


ConnectScene::~ConnectScene()
{

}
