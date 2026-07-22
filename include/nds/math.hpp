#pragma once

struct Vec3_32s;

namespace NDS {
namespace Math {

void addVector32(const Vec3_32s *left, const Vec3_32s *right, Vec3_32s *result);
void initializeFixedPoint();

}
}
