#include "Scene.hpp"
#include <nsmb/core/ui/text_label.hpp>

struct TitleScreenButton {
	i32 posX;
	i32 posY;
	i32 velX;
	i32 velY;
};
typedef enum SaveStateFlag { Empty = 1, Saved = 2, StoryCompleted = 4, StandardLevelsCompleted = 8, GameCompleted = 16 } SaveStateFlag;
struct SaveState {
	u32 flags;
	u32 lives;
	u32 coins;
	u32 score;
	u32 starCoins;
	u32 currentWorld;
};

enum TitleScreenPage {
	TitleScreenPage_Main = 0,
	TitleScreenPage_FileSelect = 1,
	TitleScreenPage_FileCopy = 2,
	TitleScreenPage_FileErase = 3,
	TitleScreenPage_Options = 4
};

enum TitleScreenState {
	TitleScreenState_Initialize = 0,
	TitleScreenState_WaitForFade = 1,
	TitleScreenState_SelectButton = 2,
	TitleScreenState_PressButton = 3,
	TitleScreenState_ReleaseButton = 4,
	TitleScreenState_WaitAfterSelection = 5,
	TitleScreenState_ExecuteSelection = 6
};

enum FileSelectState {
	FileSelectState_Initialize = 0,
	FileSelectState_Enter = 1,
	FileSelectState_SelectButton = 2,
	FileSelectState_PressButton = 3,
	FileSelectState_ReleaseButton = 4,
	FileSelectState_ExecuteSelection = 5,
	FileSelectState_ExitToMainMenu = 6,
	FileSelectState_ExitToFileOperation = 7
};

enum FileCopyState {
	FileCopyState_Initialize = 0,
	FileCopyState_Enter = 1,
	FileCopyState_SelectSource = 2,
	FileCopyState_HideSourcePrompt = 3,
	FileCopyState_ShowDestinationPrompt = 4,
	FileCopyState_SelectDestination = 5,
	FileCopyState_RestoreDestinationSelection = 6,
	FileCopyState_ShowOverwriteConfirmation = 7,
	FileCopyState_ConfirmOverwrite = 8,
	FileCopyState_ShowCopyingPrompt = 9,
	FileCopyState_CopyFile = 10,
	FileCopyState_CopyComplete = 11,
	FileCopyState_ExitAfterCopy = 12,
	FileCopyState_PressButton = 13,
	FileCopyState_ReleaseButton = 14,
	FileCopyState_ExecuteSelection = 15,
	FileCopyState_ExitToFileSelect = 16,
	FileCopyState_ReturnToSourceSelect = 17,
	FileCopyState_FinalizeDestinationSelection = 18,
	FileCopyState_AcceptOverwrite = 19,
	FileCopyState_DeclineOverwrite = 20
};

enum FileEraseState {
	FileEraseState_Initialize = 0,
	FileEraseState_Enter = 1,
	FileEraseState_SelectFile = 2,
	FileEraseState_PressButton = 3,
	FileEraseState_ReleaseButton = 4,
	FileEraseState_ExecuteSelection = 5,
	FileEraseState_ExitToFileSelect = 6,
	FileEraseState_HideFileSelection = 7,
	FileEraseState_ShowConfirmation = 8,
	FileEraseState_HideConfirmation = 9,
	FileEraseState_ShowFileSelection = 10,
	FileEraseState_ConfirmErase = 11,
	FileEraseState_EraseFile = 12,
	FileEraseState_EraseComplete = 13
};

enum OptionsState {
	OptionsState_Initialize = 0,
	OptionsState_Enter = 1,
	OptionsState_SelectOption = 2,
	OptionsState_PressOK = 3,
	OptionsState_ReleaseOK = 4,
	OptionsState_WaitAfterSelection = 5,
	OptionsState_Exit = 6
};

class TitleScreenScene;

class TitleScreenCutscene
{
      public:
	u8 _pad[0x908];

	TitleScreenCutscene();
	~TitleScreenCutscene();
	void onCreate(TitleScreenScene *scene);
	void onUpdate();
	void onRender();
	void pendingDestroy();
	void onDestroy();
};
class TitleScreenScene : public Scene
{
      public:
	u8 menuID;
	u8 stateID;
	u8 fileCopyReturnState;
	i8 buttonAnimTimer; /* used to animate the button pressed animation */
	u8 fileSelectCurrentButton;
	u8 fileCopySourceFile;	       /* 0-2=file id */
	u8 fileCopyDestinationFile;    /* 0-2=file id */
	u8 fileCopyIgnoredFile;	       /* the third unselected file (neither source nor destination) */
	u8 fileEraseFile;	       /* 0-2=file id */
	u8 fileEraseCurrentButton;     /* 0-2=file,3=back,4='Yes',5='No' */
	u8 optionsCurrentButton;       /* 0=sound mode,1=control mode,2='OK' */
	u8 fileConfirmOperationButton; /* 0='Yes',1='No' */
	bool backButtonSelected;       /* cancel operation */
	bool backButtonHighlighted;
	bool fileSelectionCompleted;  /* set to true when the (copy/erase) file selection is completed */
	bool fileConfirmRequest;      /* set to true when a file operation needs a confirmation (erase=always, copy=overwrite only) */
	bool copyingFile;	      /* used to render the icon */
	bool copyingFileAnimStopping; /* if set to true, the animation will continue until frame 0 is reached */
	u8 copyingFileFrame;	      /* used to animate the icon */
	u8 stateTimer;
	bool buttonsVisible; /* if not true, the enter state should be responsible for sliding them back on screen */
	u8 fileEraseSelected;
	u8 fileCopiedTimer;
	u8 fileCopyCurrentButton;
	u8 unk7c;
	bool fileOperationFailed; /* set to true when a file operation fails */
	u8 _pad2;
	u8 _pad3;
	int buttonHitTimer;
	i32 button1Offset;	   /* copy/sound mode */
	int button2Offset;	   /* erase/control mode */
	int optionsOKButtonOffset; /* pos Y = pos X + offset */
	int optionsOKButtonPosX;   /* relative to the BNCL cell (ofc) */
	int guiTimer;		   /* used to move the GUI in/out of the screen */
	int buttonsTimer;	   /* used to move the buttons in/out of the screen */
	int backButtonOffset;
	int soundMode;
	int controlMode;
	int fileButtonsTargetY[3];
	TitleScreenButton mainMenuButtons[4];
	TitleScreenButton fileSelectFileButtons[3];
	TitleScreenButton fileSelectButtons1[2];
	TitleScreenButton fileSelectButtons2[2];
	SaveState saves[3];
	TitleScreenCutscene cutscene;
	TextLabel label;

	TitleScreenScene();
	inline ~TitleScreenScene();
	void *create();
	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();

	s32 hasSavedFile();
	s32 isBackButtonTouched();
	void resetFileSelectButtons();
	void reloadSaveData();
	void updateSelectionFeedback(u8 previousState, u8 state,
		u8 previousButton, u8 button, s32 distance);
	u8 getConfirmButtonPalette(s32 buttonID);
	u8 getEraseButtonPalette();
	u8 getCopyButtonPalette();
	i32 getSaveFilePalette(s32 fileID);
	void renderFileMenuHeader(s32 value);
	void renderBackButton();
	void renderSaveFile(s32 fileID, s32 palette);

	void loadMainMenuGraphics();
	void updateMainMenu();
	void initializeMainMenu();
	void waitForMainMenuFade();
	void selectMainMenuButton();
	void pressMainMenuButton();
	void releaseMainMenuButton();
	void waitAfterMainMenuSelection();
	void executeMainMenuSelection();

	void updateFileSelect();
	void loadFileSelectGraphics();
	void initializeFileSelect();
	void enterFileSelect();
	void selectFile();
	void setFileSelectButtonOffset(s32 offset);
	void pressFileSelectButton();
	void releaseFileSelectButton();
	void executeFileSelectSelection();
	void exitFileSelectToMainMenu();
	void exitFileSelectToOperation();

	void updateFileCopy();
	void initializeFileCopy();
	void enterFileCopy();
	void selectFileCopySource();
	void confirmFileCopySource();
	void cancelFileCopySource();
	void hideFileCopySourcePrompt();
	void showFileCopyDestinationPrompt();
	void selectFileCopyDestination();
	void restoreFileCopyDestinationSelection();
	void confirmFileCopyDestination();
	void cancelFileCopyDestination();
	void showFileCopyOverwriteConfirmation();
	void selectFileCopyOverwriteResponse();
	void selectFileCopyOverwriteYes();
	void selectFileCopyOverwriteNo();
	void showFileCopyingPrompt();
	void copyFile();
	void waitForFileCopyAcknowledgement();
	void exitFileCopyAfterCopy();
	void setFileCopyButtonOffset(s32 offset);
	void pressFileCopyButton();
	void releaseFileCopyButton();
	void executeFileCopySelection();
	void exitFileCopyToFileSelect();
	void returnFileCopyToSourceSelect();
	void finalizeFileCopyDestination();
	void acceptFileCopyOverwrite();
	void declineFileCopyOverwrite();

	void updateFileErase();
	void initializeFileErase();
	void enterFileErase();
	void selectFileToErase();
	void confirmFileEraseSelection();
	void cancelFileEraseSelection();
	void selectFileEraseConfirmation();
	void confirmFileErase();
	void declineFileErase();
	void setFileEraseButtonOffset(s32 offset);
	void updateFileEraseProgress();
	void eraseFile();
	void waitForFileEraseAcknowledgement();
	void pressFileEraseButton();
	void releaseFileEraseButton();
	void executeFileEraseSelection();
	void exitFileEraseToFileSelect();
	void hideFileEraseSelection();
	void showFileEraseConfirmation();
	void hideFileEraseConfirmation();
	void showFileEraseSelection();

	void updateOptions();
	void initializeOptions();
	void enterOptions();
	void selectOption();
	void pressOptionsOK();
	void releaseOptionsOK();
	void waitAfterOptionsSelection();
	void exitOptions();

	void onRender_0();
	void onRender_1();
	void onRender_2();
	void onRender_3();
	void onRender_4();
};

union TitleScreenStateHandler {
	struct {
		void (*function)(TitleScreenScene *);
		s32 adjustment;
	} parts;
	void (TitleScreenScene::*member)();
};
NTR_SIZE_GUARD(TitleScreenStateHandler, 8);

extern TitleScreenStateHandler data_ov009_020dbc04[7];
extern u32 data_ov009_020dbb9c;
extern TitleScreenStateHandler data_ov009_020da82c;
extern TitleScreenStateHandler data_ov009_020da834;
extern TitleScreenStateHandler data_ov009_020da83c;
extern TitleScreenStateHandler data_ov009_020da844;
extern TitleScreenStateHandler data_ov009_020da84c;
extern TitleScreenStateHandler data_ov009_020da854;
extern TitleScreenStateHandler data_ov009_020da85c;
extern TitleScreenStateHandler data_ov009_020dbcb4[14];
extern u32 data_ov009_020dbb90;
extern TitleScreenStateHandler data_ov009_020da874;
extern TitleScreenStateHandler data_ov009_020da87c;
extern TitleScreenStateHandler data_ov009_020da884;
extern TitleScreenStateHandler data_ov009_020da88c;
extern TitleScreenStateHandler data_ov009_020da894;
extern TitleScreenStateHandler data_ov009_020da89c;
extern TitleScreenStateHandler data_ov009_020da8a4;
extern TitleScreenStateHandler data_ov009_020da8ac;
extern TitleScreenStateHandler data_ov009_020da8b4;
extern TitleScreenStateHandler data_ov009_020da8bc;
extern TitleScreenStateHandler data_ov009_020da8c4;
extern TitleScreenStateHandler data_ov009_020da8cc;
extern TitleScreenStateHandler data_ov009_020da8d4;
extern TitleScreenStateHandler data_ov009_020da8dc;
extern TitleScreenStateHandler data_ov009_020dbda4[21];
extern u32 data_ov009_020dbb8c;
extern TitleScreenStateHandler data_ov009_020da99c;
extern TitleScreenStateHandler data_ov009_020da93c;
extern TitleScreenStateHandler data_ov009_020da94c;
extern TitleScreenStateHandler data_ov009_020da984;
extern TitleScreenStateHandler data_ov009_020da97c;
extern TitleScreenStateHandler data_ov009_020da76c;
extern TitleScreenStateHandler data_ov009_020da974;
extern TitleScreenStateHandler data_ov009_020da684;
extern TitleScreenStateHandler data_ov009_020da95c;
extern TitleScreenStateHandler data_ov009_020da77c;
extern TitleScreenStateHandler data_ov009_020da964;
extern TitleScreenStateHandler data_ov009_020da944;
extern TitleScreenStateHandler data_ov009_020da764;
extern TitleScreenStateHandler data_ov009_020da934;
extern TitleScreenStateHandler data_ov009_020da75c;
extern TitleScreenStateHandler data_ov009_020da924;
extern TitleScreenStateHandler data_ov009_020da754;
extern TitleScreenStateHandler data_ov009_020da914;
extern TitleScreenStateHandler data_ov009_020da74c;
extern TitleScreenStateHandler data_ov009_020da904;
extern TitleScreenStateHandler data_ov009_020da744;
extern TitleScreenStateHandler data_ov009_020dbc74[8];
extern u32 data_ov009_020dbb98;
extern TitleScreenStateHandler data_ov009_020da634;
extern TitleScreenStateHandler data_ov009_020da694;
extern TitleScreenStateHandler data_ov009_020da9dc;
extern TitleScreenStateHandler data_ov009_020da9d4;
extern TitleScreenStateHandler data_ov009_020da9cc;
extern TitleScreenStateHandler data_ov009_020da9c4;
extern TitleScreenStateHandler data_ov009_020da9bc;
extern TitleScreenStateHandler data_ov009_020da9b4;
extern TitleScreenStateHandler data_ov009_020dbc3c[7];
extern u32 data_ov009_020dbba4;
extern TitleScreenStateHandler data_ov009_020da994;
extern TitleScreenStateHandler data_ov009_020da6cc;
extern TitleScreenStateHandler data_ov009_020da79c;
extern TitleScreenStateHandler data_ov009_020da654;
extern TitleScreenStateHandler data_ov009_020da7ac;
extern TitleScreenStateHandler data_ov009_020da7b4;
extern TitleScreenStateHandler data_ov009_020da7c4;
extern TitleScreenStateHandler data_ov009_020dbbdc[5];
extern u32 data_ov009_020dbba0;
extern TitleScreenStateHandler data_ov009_020da7a4;
extern TitleScreenStateHandler data_ov009_020da8ec;
extern TitleScreenStateHandler data_ov009_020da6c4;
extern TitleScreenStateHandler data_ov009_020da63c;
extern TitleScreenStateHandler data_ov009_020da6ac;
extern TitleScreenStateHandler data_ov009_020dbbb4[5];
extern u32 data_ov009_020dbb94;
extern TitleScreenStateHandler data_ov009_020da66c;
extern TitleScreenStateHandler data_ov009_020da6bc;
extern TitleScreenStateHandler data_ov009_020da78c;
extern TitleScreenStateHandler data_ov009_020da7fc;
extern TitleScreenStateHandler data_ov009_020da7f4;


// #include "base_types.hpp"

// // Titlescreen Logo
// class Logo
// {
//       public:
// 	u32 _00;
// 	u32 _04;
// 	u32 _08;
// 	u32 _0c;
// 	i32 _10;
// 	i32 _14;
// 	i32 _18;
// 	i16 _1c;
// 	i16 _1e;
// 	i16 _20;

// 	void func_ov009_020cc914();
// 	void func_ov009_020cc8ac();
// 	void func_ov009_020cc87c(u32);
// 	void func_ov009_020cd014();
// 	void func_ov009_020ccf38();
// };

// // func_0200421c - render sprite. Nitro Function?
// void Logo::func_ov009_020cd014()
// {	// render static logo segments
// 	/*
// 	  if (*(int *)(param_1 + 0x78) != 0) {
// 			// Unknown TODO: What does this render?
// 	    func_0200421c(3,&data_ov009_020db9f4,0,0,0,0,0,0,0,1,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
// 			    // Copyright
// 	    func_0200421c(4,&data_ov009_020dba70,0,0,0,0,0,0,0,0,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
// 			    // Logo with Shadow + Trademark
// 	    func_0200421c(5,&data_ov009_020dba98,0,0,0,0,0,0,0,3,-*(int *)(_DAT_020dbbb0 + 200) >> 0xc);
// 	}
// 	iVar1 = 0;
// 	do {
// 	    func_ov009_020ccf38(param_1,iVar1);
// 	    iVar1 = iVar1 + 1;
// 	    param_1 = param_1 + 0x28;
// 	} while (iVar1 < 3);
//       */
// }

// void Logo::func_ov009_020ccf38()
// {	// Render dynamic Logo
// 	/*

// 	{
// 	undefined4 *puVar1;
// 	undefined2 uVar2;

// 	puVar1 = (undefined4 *)(&data_ov009_020d9684 + *(int *)(param_1 + 0x24) * 0xc + param_2 * 0x18);
// 	if (*(int *)(param_1 + 0x24) == 0) {
// 	    uVar2 = *(undefined2 *)(param_1 + 0x1c);
// 	}
// 	else {
// 	    uVar2 = 0;
// 	}
// 			    // Main Logo
// 	func_0200421c(*puVar1,puVar1[1],0x10,*(undefined1 *)(puVar1 + 2),0,0,uVar2,0,0,
// 			(int)*(char *)((int)puVar1 + 9),
// 			(int)*(char *)((int)puVar1 + 10) +
// 			(*(int *)(param_1 + 0x10) - *(int *)(_DAT_020dbbb0 + 200) >> 0xc));
// 	*/
// }

// void Logo::func_ov009_020cc914()
// {
// }

// void Logo::func_ov009_020cc8ac()
// {
// 	if (0 <= this->_1e) {
// 		if (this->_14 > 0) {
// 			this->_20 = 0x11;
// 		} else {
// 			this->_1e = 0;
// 			this->_20 = 0;
// 		}
// 	}

// 	if (0 <= this->_10) {
// 		this->_14 = 0;
// 		this->_18 = 0;
// 		this->_1c = 0;
// 		this->_1e = 0;
// 		this->_20 = 0;
// 		Logo::func_ov009_020cc87c(0xf);
// 	}
// }

// void func_ov009_020cc8a8()
// {
// }

// void Logo::func_ov009_020cc87c(u32 a)
// {
// 	this->_00 = a;
// 	this->_04 = *(int *)((a * 8) + 0x20dbd24);
// 	this->_08 = *(int *)((a * 8) + 0x20dbd28);
// 	this->_0c = 0;
// }

// void func_ov009_020cc85c()
// {
// }

// void func_ov009_020cc858()
// {
// }

// void func_ov009_020cc854()
// {
// }

// void func_ov009_020cc810(u32 *a)
// {
// }

// void func_ov009_020cc70c(u32 *a)
// {
// }

// void func_02007c44(void *);
// void func_02007bfc(void *);
// void *data_02088f48 = (void *)0x1234;
// void func_ov009_020cc6e8()
// {
// 	func_02007c44(&data_02088f48);
// 	func_02007bfc(&data_02088f48);
// }

// void func_ov009_020cc6d4(i32 *a, i32 b, i32 c)
// {
// 	if (b > *a) {
// 		a[0] = b;
// 		a[1] = c;
// 	}
// }

// u32 _CurrentWindow = (*(u32 *)0x02085b10);
// void func_ov009_020cc6b4(u8 *a)
// {
// 	_CurrentWindow = (u32)a;
// 	a[0] = 0;
// 	a[1] = 0;
// 	a[2] = 0;
// }

// void func_ov009_020cc5f8()
// {
// }

// void func_ov009_020cc5e8(u8 *a, u8 b)
// {
// 	a[0] = 1;
// 	a[1] = b;
// }

// void func_ov009_020cc5d4()
// {
// 	_CurrentWindow = 0;
// }

// void func_ov009_020cc560(u32 *a)
// {
// 	u16 *_REG_BG0CNT = (u16 *)0x04000008;
// 	u16 *_REG_BG1CNT = (u16 *)0x0400000a;
// 	u16 *_REG_BG2CNT = (u16 *)0x0400000c;
// 	u16 *_REG_BG3CNT = (u16 *)0x0400000e;

// 	// TODO: Turn this into a Macro
// 	*_REG_BG0CNT = *_REG_BG0CNT & ~3;
// 	*_REG_BG1CNT = *_REG_BG1CNT & ~3 | 3;
// 	*_REG_BG2CNT = *_REG_BG2CNT & ~3 | 1;
// 	*_REG_BG3CNT = *_REG_BG3CNT & ~3 | 2;
// 	*a = 0;
// }

// void func_ov009_020cc4ec(u32 *a)
// {
// 	u16 *_REG_BG0CNT = (u16 *)0x04000008;
// 	u16 *_REG_BG1CNT = (u16 *)0x0400000a;
// 	u16 *_REG_BG2CNT = (u16 *)0x0400000c;
// 	u16 *_REG_BG3CNT = (u16 *)0x0400000e;

// 	// TODO: Turn this into a Macro
// 	*_REG_BG0CNT = *_REG_BG0CNT & ~3 | 1;
// 	*_REG_BG1CNT = *_REG_BG1CNT & ~3 | 3;
// 	*_REG_BG2CNT = *_REG_BG2CNT & ~3;
// 	*_REG_BG3CNT = *_REG_BG3CNT & ~3 | 2;
// 	*a = 1;
// }

// void func_ov009_020cc4d0(u32 *a)
// {
// 	a[0] = 0;
// 	a[2] = 0;
// 	a[3] = 0;
// 	a[4] = 0;
// 	a[5] = 0;
// }

// void func_ov009_020cc310(u32 *a)
// {
// }

// void func_ov009_020cc304(u32 *a)
// {
// 	*a = 1;
// }

// void func_ov009_020cc2f8(u32 *a)
// {
// 	*a = 2;
// }

// void func_ov009_020cc2ec(u32 *a)
// {
// 	*a = 3;
// }

// void func_ov009_020cc2e0(u32 *a)
// {
// 	*a = 4;
// }
