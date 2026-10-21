#pragma once
#include "StageEntity.hpp"
#include "./Player/PlayerBase.hpp"

class Goomba : public StageEntity
{
public:
    u8 _pad0[0x36];
    i32 _428;
    i16 _42c;
    u8 _pad1[0x12];
    u16 _440;
    u16 _442;
    u16 _444;
    u16 _446;
    u8 _pad2[0xa];
    u16 _452;
    u8 _pad3[0x4];
    u8 _458;
    u8 _pad4[0x1];
    i8 _45a;


	static void *create();
	inline Goomba();

    u32 func_ov010_020e127c();
    u32 megaDroppedState();
    u32 stompedState();
    bool onUpdate_defeated();
    bool func_ov010_020e1694();
    void func_ov010_020e19ac();
    void onStomped();
    bool playerCollision(ActiveCollider* param_2, ActiveCollider* param_3);
    bool updateMusicEvents(s32 param_2);

	s32 onCreate();
};

class ParaGoomba : public Goomba
{
public:

    static void *create();
    ~ParaGoomba();
};

class MiniGoomba : public Goomba
{
public:

    static void *create();
        ~MiniGoomba();

};
