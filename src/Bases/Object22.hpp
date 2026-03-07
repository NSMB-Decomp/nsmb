#include "StageEntity.hpp"

class Object22 : StageEntity
{
      public:
	static ActorProfile Profile;
	inline Object22() {};
	inline ~Object22() {};
	static void *create();
};
ActorProfile Object22::Profile = {
    Object22::create,
    0x16,
    0x1d,
};