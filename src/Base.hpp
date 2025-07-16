#include "base_types.hpp"
#include "ProcessLink.hpp"


class Base {
public:
  static u8 data_0208fae8;
  static u16 data_0208faf0;
  static u32 data_0208fb00;
  static u32 data_0208fafc;

  static u8 data_0208faec;
  static u16 data_0208faf4;
  static u32 data_0208faf8;
  static u32 data_0208fb04;

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
  void unloadSceneOverlay();
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
  virtual void pendingDestroy();
  virtual void prepareResourcesSafe();
  virtual void prepareResourcesFast();
  virtual bool onHeapCreated();
  virtual ~Base(); // There are meant to be 2 destroys? How to we manage that one?
};