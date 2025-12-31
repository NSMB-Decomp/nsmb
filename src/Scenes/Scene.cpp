#include "Scene.hpp"

Scene::Scene()
{
    this->skipFlags |= 1;
    this->skipFlags |= 4;
    Stage::actorFreezeFlag = 0;
    data_ov000_020ca84c = 0;
    data_02088f34 = 0;
}

bool func_02046c5c();
bool Wifi_isMultiBootCart();
void func_0200f3d8();
void func_02009b64();
u32 data_02085a84;
u32 data_0208ae58;
void func_ov052_02152bf0();
u32 data_02089504;
Scene::~Scene()
{
    if (data_02088f34 != 0)
    {
        bool a = false;
        bool b = false;
        if ((data_020887fc != 0) && (data_020887fc != 0x9))
        {
            b = true;
        }
        if (b && (data_020887fc != 0x8))
        {
            a = true;
        }
        if (a)
        {
            bool c = func_02046c5c();
            if (c != 0 && !Wifi_isMultiBootCart())
            {
                data_02085ad4[0] = *((u32*)&data_02088bdc+0xd2); // TODO: Do not offset using pointers
            }
            func_0200f3d8();
        }
        func_02009b64();
        if ((BOOL(data_02085a84 != 0) && (data_0208ae58 != 0)) == TRUE)
        {
            func_ov052_02152bf0();
            data_0208ae58 = 0;
        }
        
        GlobalFader.fadingTarget[0] |= 2;
        GlobalFader.fadingTarget[1] |= 2;
        GlobalFader.brightnessFactor[ 0] = 0x1000;
        GlobalFader.brightnessFactor[1] = 0x1000;
    }
}

bool Scene::preCreate()
{
    return true;
}

void Scene::postCreate(u32 a)
{
}

void Scene::postUpdate(u32) {
}
void Scene::postRender() {}