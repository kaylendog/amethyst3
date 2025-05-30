#include <UnitTest++/UnitTest++.h>

#include <amethyst/Math/Vec3.hpp>

using namespace amethyst;

SUITE(Vec3) {
    TEST(addition) {
        Vec3 vec1(1.0f, 2.0f, 3.0f);
        Vec3 vec2(4.0f, 5.0f, 6.0f);
        Vec3 result = vec1 + vec2;
        CHECK_EQUAL(Vec3(5.0f, 7.0f, 9.0f), result);
    }
}
