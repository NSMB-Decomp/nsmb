#include "base_types.hpp"
#include "ProcessManager.hpp"

struct a {
  u32 a;
  u32 b;
};

u32 data_02085224 = 1;
u32 data_02085248[2] = {0x10, 1};
u32 data_02085240[2] = {0x00, 1};
u32 data_02085238[2] = {0x04, 1};
u32 data_02085230[2] = {0x0C, 1};
u32 data_02085228[2] = {0x08, 1};
u32 data_02085250[2] = {0x14, 1};

class Base {
public:
  enum State {
    pendingInit,
    one,
    two
  };

  u32 guid;
  u32 settings;
  u16 object_id;
  State state;
  bool pending_destroy;
  u8 __1;
  u8 __2;
  u8 __3;
  u8 __4;
  ProcessLink process_link;
  u32 __5;
  void* heap;

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

  virtual bool onCreate();
  virtual bool preCreate();
  virtual bool postCreate();
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