#pragma once
#include "nsmb_nitro.hpp"

struct FxRect {
	fx32 x;
	fx32 y;
	fx32 halfWidth;
	fx32 halfHeight;
};
NTR_SIZE_GUARD(FxRect, 0x10);

struct Vec3_32 : public Vec3_32s {
      public:
	inline Vec3_32() {};
	virtual inline ~Vec3_32() {};

	// operator Vec3_32s *()
	// {
	// 	return (Vec3_32s *)(((u32)this) + 4);
	// }
	Vec3_32 sub(Vec3_32s *a);

	inline Vec3_32(const Vec3_32 &v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}
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
	inline Vec3_32(i32 v) {
		x = v;
		y = v;
		z = v;
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
	inline void set(i32 v) {
		x = v;
		y = v;
		z = v;
	}
	inline void set(i32 x, i32 y, i32 z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
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

	inline Vec3_32 operator+(const Vec3_32& rhs) {
		Vec3_32 v = *this;
		Nitro::Math_AddVec3_32s(&v, &rhs, &v);
		return v;
	}

	/* inline Vec3_32s* vec() {
		return (Vec3_32s*)&x;
	}

	inline const Vec3_32s* vec() const {
		const u8* p = (const u8*)this;
		return (const Vec3_32s*)(p+4);
		//return (const Vec3_32s*)&x;
	} */

	inline void add1(const Vec3_32& rhs) {
		const Vec3_32s* b = (const Vec3_32s*)(((const u8*)&rhs)+4);
		Vec3_32s* v = this;
		Nitro::Math_AddVec3_32s(v, b, v);
	}

	inline void add2(const Vec3_32& rhs) {
		const Vec3_32s* b = (const Vec3_32s*)&rhs.x;
		Vec3_32s* a = this;
		Nitro::Math_AddVec3_32s(a, b, a);
	}

	// inline static void add3(const Vec3_32& lhs, const Vec3_32& rhs, Vec3_32& res) {
	// 	Vec3_32s* r = &res;
	// 	const Vec3_32s* a = &lhs;
	// 	const Vec3_32s* b = (const Vec3_32s*)&rhs.x;
	// 	Nitro::Math_AddVec3_32s(a, b, r);
	// }

	inline static void add4(const Vec3_32& lhs, const Vec3_32s* rhs, Vec3_32& res) {
		Vec3_32s* r = &res;
		const Vec3_32s* a = &lhs;
		Nitro::Math_AddVec3_32s(a, rhs, r);
	}

	// static inline Vec3_32 add(const Vec3_32& lhs, const Vec3_32& rhs) {
	// 	Vec3_32 v = lhs;
	// 	Nitro::Math_AddVec3_32s(&v, &rhs, &v);
	// 	return v;
	// }

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

	// Vec2_32();
	inline Vec2_32() {}
	inline Vec2_32(i32 v) {
		x = v;
		y = v;
	}
	inline Vec2_32(i32 x0, i32 y0) {
		x = x0;
		y = y0;
	}
	inline void set(i32 v) {
		x = v;
		y = v;
	}
	inline void set(i32 x0, i32 y0) {
		x = x0;
		y = y0;
	}
	virtual inline ~Vec2_32() {};
};

struct Vec3_16 : public Vec3_16s {
      public:
	inline Vec3_16() : Vec3_16s() {};
	inline Vec3_16(Vec3_16 *a) : Vec3_16s() {};
	virtual inline ~Vec3_16() {};
};
