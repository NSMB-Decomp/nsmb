#include "../base_types.hpp"
#include "../AAA.hpp"

class Base {
public:
  enum State {
    PendingInit,
    Active,
    Inactive
  };
  enum SkipFlags {
    UpdateChildren = 1,
    Update = 2,
    RenderChildren = 4,
    Render = 8
  };

  u32 guid; // 0x04
  u32 settings; // 0x08
  u16 object_id; // 0x0c
  State state; // 0x0e
  bool pending_destroy; // 0x0f
  bool pending_update; // 0x10
  bool pending_create; // 0x11
  u8 _12; // 0x12
  u8 skipFlags; //0x13
  ProcessLink process_link; //0x14
  void* _50; // 0x54
  void* heap; //0x58

  static Base* spawnParent(u16, u32, u8);
  static Base* spawnChild(u16, Base*, u32, u8);
  static void unloadSceneOverlay(u16);
  static u32 loadSceneOverlay(u16);
  static Base* spawn(u16, ProcessLink*, u32, u8);
  static void setSpawnParams(u16, ProcessLink*, u32, u8);
  bool hasChildPendingCreation();
  u32 processDestroy();
  void processCreate();
  void create();
  void* operator new(u32);
  void operator delete(void*);
  Base* getParent();
  void destroy();
  Base();
  bool func_01ffd290();
  i32 func_01ffd524(u32, u32, u32, u32, u32, u32);

  virtual bool onCreate();
  virtual bool preCreate();
  virtual void postCreate(u32);
  virtual bool onDestroy();
  virtual bool preDestroy();
  virtual void postDestroy(u32);
  // Missing some funcs here
  virtual bool onUpdate();
  virtual bool preUpdate();
  virtual void postUpdate();
  virtual bool onRender();
  virtual bool preRender();
  virtual void postRender();
  virtual void pendingDestroy();
  virtual bool prepareResourcesSafe(u32, u32);
  virtual bool prepareResourcesFast(u32, u32);
  virtual bool onHeapCreated();
  virtual ~Base();
};