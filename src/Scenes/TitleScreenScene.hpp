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
