#pragma once
#include "Base.hpp"

enum ObjectID {

	SC_Boot,			// "BOOT" in SM64DS
	SC_Connect,
	SC_Debug,
	SC_Stage,			// "STAGE" in SM64DS
	SC_TitleScreen,		// "TITLE"
	SC_VsSetup__,
	SC_VsMainMenu__,	// "ENTRY"
	SC_Save,			// "SAVE"
	SC_World,			// "WORLD"
	SC_Worldmap,		// "KINOK", "KINO2", "KINO3"
	SC_VsResults__,		// ""
	SC_CorruptedFile,	// "ERROR"
	SC_Ending,			// "ENDIN" ("ENDING")
	SC_StageIntro,		// "CRSIN" ("COURSE IN")
	SC_GameOver,		// "GOVER" or "GAMEOVER" in SM64DS
	SC_VsStageIntro,	// ""
	SC_Sound,			// "SOUND"
	SC_Key,				// "KEY"

	AC_Manhole = 187,

	WM_Controller = 319,
	WM_Character,
	WM_Minimap,
	WM_Camera,

	SC_MgBoot = 326,	// "MGVS"

};

class Object : public Base
{
      public:
	static Object *spawnObject(u16, Base *, u32, u8);
	static Object *spawnScene(u16, u32, u8);
	void __stub();

	void postCreate(u32);
	inline ~Object() {};
};
size_assert(Object, sizeof(Base));
