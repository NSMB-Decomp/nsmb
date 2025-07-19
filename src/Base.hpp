#include "base_types.hpp"
#include "ProcessLink.hpp"

static u32 data_0208fae0;
static u8 data_0208fae8;
static u8 SpawnParam4;
static u16 data_0208faf0;
static u16 SpawnParam1;
static ProcessLink* SpawnParam2;
static u32 data_0208fafc;
static u32 data_0208fb00;
static u32 SpawnParam3;
static u32 data_0208fb08;

class Base {
public:
  enum State {
    zero,
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

  static Base* spawnParent(u16, u32, u8);
  static Base* spawnChild(u16, Base*, u32, u8);
  void unloadSceneOverlay();
  static u32 loadSceneOverlay(u16);
  static Base* spawn(u16, ProcessLink*, u32, u8);
  static void setSpawnParams(u16, ProcessLink*, u32, u8);
  bool hasChildNotCreated();
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
  virtual void postDestroy();
  // Missing some funcs here
  virtual bool func_01ffd51c();
  virtual bool func_01ffd4f4();
  virtual void func_01ffd4f0();
  virtual bool func_01ffd4e8();
  virtual bool func_01ffd4c0();
  virtual void func_01ffd4bc();
  virtual void pendingDestroy();
  virtual void prepareResourcesSafe();
  virtual void prepareResourcesFast();
  virtual bool onHeapCreated();
  virtual ~Base();
};