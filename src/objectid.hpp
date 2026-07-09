#pragma once

enum ObjectID {

	// Core
	SC_Boot,			// "BOOT" in SM64DS

	// Game
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

	// Stage Actors
	AC_Manhole = 187,

	// Worldmap Actors
	WM_Controller = 319,
	WM_Character,
	WM_Minimap,
	WM_Camera,

	// Minigames
	SC_MgBoot = 326,

	// Invalid Object ID
	AC_Invalid = 385,
	SC_Invalid = 385,

	ProfileCount

};
