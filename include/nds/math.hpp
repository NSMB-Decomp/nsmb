#pragma once

struct Vec3_32s;
union Mat4x3;
union Mat4x4;

namespace NDS {
namespace Math {

void addVector32(const Vec3_32s *left, const Vec3_32s *right, Vec3_32s *result);
void initializeFixedPoint();
void identityMatrix43(Mat4x3 *matrix);
void identityMatrix44(Mat4x4 *matrix);
void transformVector43(const Vec3_32s *vector, const Mat4x3 *matrix,
	Vec3_32s *result);

}
}
