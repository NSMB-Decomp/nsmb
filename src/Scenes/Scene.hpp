#include "../Bases/Object.hpp"

class Scene : public Object
{
      public:
	u32 _5c;
	u32 _60;

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
