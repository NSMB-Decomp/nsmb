#include "base_types.hpp"
#include "ProcessLink.hpp"


class Base {
public:
  static u8 data_0208fae8;
  static u16 data_0208faf0;
  static u32 data_0208fb00;
  static u32 data_0208fafc;

  static u8 SpawnParam4;
  static u16 SpawnParam1;
  static u32 SpawnParam2;
  static u32 SpawnParam3;

  u32 guid;
  u32 settings;
  u16 object_id;
  u8 state;
  bool pending_destroy;
  u8 __1;
  u8 __2;
  u8 __3;
  u8 __4;
  ProcessLink process_link;

  Base* spawnParent(u16, u32, u32);
  Base* spawnChild(u16, Base*, u32, u32);
  static void unloadSceneOverlay();
  void loadSceneOverlay(u32);
  Base* spawn(u16, ProcessLink*, u32, u32);
  static void setSpawnParams(u16, u32, u32, u8);
  void hasChildNotCreated();
  void processDestroy();
  void processCreate();
  void create();
  void* operator new(u32 count);
  void operator delete(void* ptr);
  Base* getParent();
  void destroy();

  Base();

  virtual bool onCreate();
  virtual bool preCreate();
  virtual bool postCreate();
  virtual bool onDestroy();
  virtual void preDestroy();
  virtual void postDestroy();
  // Missing some funcs here
  virtual void missing_1();
  virtual void missing_2();
  virtual void missing_3();
  virtual void missing_4();
  virtual void missing_5();
  virtual void missing_6();
  virtual void pendingDestroy();
  virtual void prepareResourcesSafe();
  virtual void prepareResourcesFast();
  virtual bool onHeapCreated();
};