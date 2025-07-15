typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef void* unknown_pointer;


class Base {
public:
  u32 guid;
  u32 settings;
  u16 object_id;
  u8 state;
  bool destroy;
  u8 __1;
  u8 __2;
  u8 __3;
  u8 __4;
  /*ProcessLink process_link;*/

  Base* spawnParent(u16, u32, u32);
  void spawnChild();
  void unloadSceneOverlay();
  Base* spawn(u16, u32, u32, u32);
  void setSpawnParams();
  void hasChildNotCreated();
  void processDestroy();
  void processCreate();
  void* operator new(u32 count);
  void __operator_delete();
  void onHeapCreated();
  void prepareResourcesFast();
  void prepareResourcesSafe();
  void getParent();
  void destroySelf();
  void pendingDestroy();
  void postDestroy();
  void preDestroy();
  void onDestroy();
  void postCreate();
  virtual bool onCreate();
  virtual bool preCreate();
  Base();
  ~Base();

};
