#pragma once
#include "../lib/Nitro/Nitro.hpp"

struct Vec3_32 : public Vec3_32s {
      public:
	inline Vec3_32() {};
	virtual inline ~Vec3_32() {};

	operator Vec3_32s *()
	{
		return (Vec3_32s *)(((u32)this) + 4);
	}
	Vec3_32 sub(Vec3_32s *a);

	inline Vec3_32(const Vec3_32s &v)
	{
		/*
			Can either be in order z, y, x or x, z, y
			But NOT in order x, y, z
			(messes up LDR/STR order in Model functions)
		*/
		z = v.z;
		y = v.y;
		x = v.x;
	}

	inline Vec3_32(i32 x, i32 y, i32 z)
	{
		/*
			Can either be in order z, y, x or x, z, y
			But NOT in order x, y, z
			(messes up LDR/STR order in Model functions)
		*/
		this->z = z;
		this->y = y;
		this->x = x;
	}

	/* inline Vec3_32() = default;

	inline Vec3_32(const Vec3_32& other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	} */

	inline Vec3_32 &operator=(const Vec3_32 &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return *this;
	}

	// Speculation
	inline void setFromMat4x3(const Mat4x3 &matrix)
	{

		// Only matches in Model::getNodePosition() so far
		i32 transZ = matrix.s.m32;
		i32 transY = matrix.s.m31;
		i32 transX = matrix.s.m30;
		x = transX;
		y = transY;
		z = transZ;

		// Nope
		/* z = matrix.m32;
		y = matrix.m31;
		x = matrix.m30; */
	}
};

class Vec2_32
{
      public:
	i32 x;
	i32 y;

	// Vec3();
	virtual inline ~Vec2_32() {};
};

struct Vec3_16 : public Vec3_16s {
      public:
	inline Vec3_16() : Vec3_16s() {};
	inline Vec3_16(Vec3_16 *a) : Vec3_16s() {};
	virtual inline ~Vec3_16() {};
};

struct Rect32 {
	i32 x;
	i32 y;
	i32 half_w;
	i32 half_h;
};
