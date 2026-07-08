#pragma once
#include "../ProcessManager.hpp"

enum State { PendingInit, Active, Inactive };
enum SkipFlags { UpdateChildren = 1, Update = 2, RenderChildren = 4, Render = 8 };
class Base
{
      public:
	u32 guid;		  /* 0x04 */
	u32 settings;		  /* 0x08 */
	u16 object_id;		  /* 0x0c */
	u8 state;		  /* 0x0e */
	bool pending_destroy;	  /* 0x0f */
	bool pending_update;	  /* 0x10 */
	bool pending_create;	  /* 0x11 */
	u8 _12;			  /* 0x12 */
	u8 skipFlags;		  /* 0x13 */
	ProcessLink process_link; /* 0x14 */
	void *_54;		  /* 0x54 */
	void *heap;		  /* 0x58 */

	static Base *spawnParent(u16, u32, u8);
	static Base *spawnChild(u16, Base *, u32, u8);
	static void unloadSceneOverlay(u16);
	static u32 loadSceneOverlay(u16);
	static Base *spawn(u16, ProcessLink *, u32, u8);
	static void setSpawnParams(u16, ProcessLink *, u32, u8);
	bool hasChildPendingCreation();
	void create();
	void* operator new(size_t);
	void operator delete(void *);
	Base *getParent();
	void destroy();
	Base();
	i32 processDestroy();
	i32 processCreate();
	i32 doOrderProc();
	i32 processUpdate();
	i32 procesRender();
	i32 process(s32 (Base::*)(), bool (Base::*)(), void (Base::*)(u32));
	void func_01ffd290();

	virtual s32 onCreate();
	virtual bool preCreate();
	virtual void postCreate(u32);
	virtual s32 onDestroy();
	virtual bool preDestroy();
	virtual void postDestroy(u32);
	// Missing some funcs here
	virtual s32 onUpdate();
	virtual bool preUpdate();
	virtual void postUpdate(u32);
	virtual s32 onRender();
	virtual bool preRender();
	virtual void postRender(u32);
	virtual void pendingDestroy();
	virtual bool prepareResourcesSafe(u32, Heap *);
	virtual bool prepareResourcesFast(u32, Heap *);
	virtual bool onHeapCreated();
	virtual ~Base() = 0;
};
NTR_SIZE_GUARD(Base, 0x5C);
