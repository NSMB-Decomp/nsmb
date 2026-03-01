#include "../lib/Nitro/Nitro.hpp"

class Vec3_32 : public Vec3_32s
{
      public:
	Vec3_32 sub(Vec3_32s *a);
	operator Vec3_32s *()
	{
		return this;
	}

	// Vec3();
	virtual inline ~Vec3_32() {};
};

class Vec2_32
{
      public:
	i32 x;
	i32 y;

	// Vec3();
	virtual inline ~Vec2_32() {};
};

class Vec3_16
{
      public:
	i16 x;
	i16 y;
	i16 z;

	// Vec3s();
	virtual inline ~Vec3_16() {};
};

struct Rect32 {
	i32 x;
	i32 y;
	i32 half_w;
	i32 half_h;
};
