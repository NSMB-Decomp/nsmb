#include "../Bases/Object.hpp"

class Scene : public Object
{
      public:
	u32 wifiIconOBJIndex;
	u32 wifiIconOBJPalette;

	~Scene();
	Scene();

	static void prepareFirstScene();
	static Scene *tryChangeScene();
	static void switchToCorruptedSave(u32 settings);

	bool preCreate();
	void postCreate(u32);
	bool preDestroy();
	void postDestroy(u32);
	bool preUpdate();
	void postUpdate(u32);
	bool preRender();
	void postRender(u32);
};

NTR_SIZE_GUARD(Scene, 0x64);
NTR_OFFSET_GUARD(Scene, wifiIconOBJIndex, 0x5c);
NTR_OFFSET_GUARD(Scene, wifiIconOBJPalette, 0x60);
