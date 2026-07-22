#pragma once

#include "Scene.hpp"
#include "../Vec.hpp"

struct NicknameInfo;
struct GXOamAttr;

extern "C" {
void func_02010cc8(void *);
void func_02010c74(void *);
void func_02018114(void *);
void func_02018104(void *);
}

class VSConnectUnknown204
{
public:
	inline VSConnectUnknown204() { func_02010cc8(this); }
	inline ~VSConnectUnknown204() { func_02010c74(this); }
	u8 data[0x1c];
};

class VSConnectText
{
public:
	inline VSConnectText() { func_02018114(this); }
	inline ~VSConnectText() { func_02018104(this); }
	u8 data[0xb0];
};

class VSConnectScene : public Scene
{
public:
	class Button
	{
	public:
		enum AnimType {
			Static,
			Lerp,
			SlightMove,
		};

		inline Button()
		{
			animType = Static;
		}
		inline ~Button()
		{
		}
		inline bool isStatic() const
		{
			return animType == Static;
		}

		virtual void update();
		virtual void render();

		void create(s32 bnclRectID, s32 x, s32 y, s32 oamAttrID);
		void move(s32 x, s32 y);
		void setup(s32 x, s32 y);
		void click();

		Vec2_32 position;
		Vec2_32 endPosition;
		s32 bnclRectID;
		s32 oamAttrID;
		u8 animFrame;
		u8 palette;
		u8 animType;
		u8 unused;
	};

	class TextButton : public Button
	{
	public:
		TextButton();
		~TextButton();

		virtual void update();
		virtual void render();

		void setup(s32 x, s32 y, VSConnectScene *owner);

		VSConnectScene *owner;
	};

	struct SubMenu
	{
		inline SubMenu() : create(0), update(0), render(0), unused(0) {}
		void (VSConnectScene::*create)();
		void (VSConnectScene::*update)();
		void (VSConnectScene::*render)();
		u32 unused;
	};

	static VSConnectScene *construct();
	inline VSConnectScene() : currentSubMenu() {}
	virtual ~VSConnectScene();

	static void syncInputSchemeWrapper(int aid, VSConnectScene *owner);
	static void loadMvsLFilesThread();

	virtual s32 onCreate();
	virtual s32 onUpdate();
	virtual s32 onRender();
	virtual s32 onDestroy();

	void scheduleSubMenuChange(SubMenu *subMenu, s32 delay, bool playSound);
	void changeSubMenu(SubMenu *subMenu);

	void createSelectModeSM();
	void updateSelectModeSM();
	void renderSelectModeSM();
	void createCharSelectSM();
	void updateCharSelectSM();
	void renderCharSelectSM();
	void createSearchSM();
	void updateSearchSM();
	void renderSearchSM();
	void createConfirmSM();
	void updateConfirmSM();
	void renderConfirmSM();
	void createWaitHostConfirmSM();
	void updateWaitHostConfirmSM();
	void renderWaitHostConfirmSM();
	void createPlayerLeftSM();
	void updatePlayerLeftSM();
	void renderPlayerLeftSM();
	void createLoadGameSM();
	void updateLoadGameSM();
	void renderLoadGameSM();
	void createConnectionInterruptedSM();
	void updateConnectionInterruptedSM();
	void renderConnectionInterruptedSM();

	void selectButton(int id);
	void loadSelectModeText();
	void updateTextButtonText();
	bool startConsoleSearch();
	NicknameInfo *getOpponentNickname();
	void syncInputScheme(int aid);

	static ObjectProfile profile;
	static SubMenu selectModeSM;
	static SubMenu charSelectSM;
	static SubMenu searchSM;
	static SubMenu confirmSM;
	static SubMenu waitHostConfirmSM;
	static SubMenu playerLeftSM;
	static SubMenu loadGameSM;
	static SubMenu connectionInterruptedSM;
	static GXOamAttr *buttonOamAttrs[7];

	Button buttons[3];
	TextButton textButtons[2];
	Button *activeButtons[3];
	SubMenu currentSubMenu;
	SubMenu *scheduledSubMenu;
	s32 subMenuChangeDelay;
	s32 _164;
	u32 searchType;
	s32 subMenuState;
	s32 subMenuTimer;
	u8 _174[7];
	u8 selectMode;
	u8 inputScheme;
	u8 _17d;
	u8 syncedAidMask;
	u8 specialMode;
	u8 _180[0x84];
	VSConnectUnknown204 _204;
	VSConnectText primaryText;
	VSConnectText secondaryText;
};

NTR_SIZE_GUARD(VSConnectScene::Button, 0x28);
NTR_SIZE_GUARD(VSConnectScene::TextButton, 0x2c);
NTR_SIZE_GUARD(VSConnectScene, 0x380);
