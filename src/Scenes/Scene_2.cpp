#include "Scene_2.hpp"

Scene_2::Scene_2() {}
void *Scene_2::operator new(u32 a)
{
    return new Scene_2();
}

bool Scene_2::onCreate()
{
    return true;
}

bool Scene_2::onHeapCreated()
{
    return true;
}

bool Scene_2::onDestroy()
{
    u16 a[1];
    FS::Cache::clear();
    a[0] = 0;
    Nitro_::func_02063af0(a, 0, 2);
    return true;
}

void Scene_2::pendingDestroy()
{
}

bool Scene_2::onRender()
{
    return true;
}

bool Scene_2::onUpdate()
{
    return true;
}

void Scene_2::func_ov002_020cc514()
{
}

void Scene_2::func_ov002_020cc328()
{
}

Scene_2::~Scene_2() {}

struct Profile{u32 constructor;u16 a;u16 b;};
Profile Scene2_Profile[2] = {(u32)Scene_2::operator new,2,9};

u8 data_ov002_020cd220[4] = {1, 1, 3, 0};
char data_ov002_020cd224[4] = "KEY";
char data_ov002_020cd228[8] = "SAVE";
char data_ov002_020cd230[8] = "MGVS";
char data_ov002_020cd238[8] = "KINO3";
char data_ov002_020cd248[8] = "TITLE";
char data_ov002_020cd250[8] = "CRSIN";
char data_ov002_020cd258[8] = "KINOK";
char data_ov002_020cd260[8] = "GOVER";
char data_ov002_020cd268[8] = "ENTRY";
char data_ov002_020cd270[8] = "SOUND";
char data_ov002_020cd278[8] = "ERROR";
char data_ov002_020cd280[8] = "WORLD";
char data_ov002_020cd288[8] = "KINO2";
char data_ov002_020cd290[8] = "ENDIN";

struct LPTMF
{
    void (Scene_2::*a)();
    u32 b;
};
LPTMF data_ov002_020cd308[2] = {
    {Scene_2::func_ov002_020cc514, 0},
    {Scene_2::func_ov002_020cc328, 0}};
