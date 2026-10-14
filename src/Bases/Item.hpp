#include "../graphics//3d/model.hpp"
#include "../graphics//3d/modelanm.hpp"
#include "../nsmb_nitro.hpp"
#include "StageEntity.hpp"

class Item : public StageEntity
{
      public:
	u32 _3f4;
	ModelAnm modelAnm;
	Model model;
	u8 _pad0[0x18];
	Vec3_32 _548;
	Vec2_32 _558;
	u8 _pad1[0x6c];

	static Item *create();
	inline Item() {};
	inline ~Item() {};

	virtual s32 onCreate();
	virtual s32 onDestroy();
};

class ToadItem : public Item
{
      public:
	static ToadItem *create();
	inline ToadItem() {};
	inline ~ToadItem() {};
};
