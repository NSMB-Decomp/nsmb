#include "_StageController.hpp"

class Object18 : public StageController
{
      public:
	u8 _pad0[0x4c];
	Object18() {};
	~Object18();

	static void *create();

    bool onRender();
};