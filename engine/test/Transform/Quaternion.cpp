#include <UnitTest++/UnitTest++.h>

#include <amethyst/Transform/Quaternion.hpp>

using namespace amethyst;

SUITE(Quaternion) {
    TEST(from_axis_angle) {
        auto quaternion =
            Quaternion::from_axis_angle(Vec3(1.0f, 0.0f, 0.0f), 3.14f);
        CHECK_CLOSE(1.0f, quaternion.x(), 0.001f);
        CHECK_CLOSE(0.0f, quaternion.y(), 0.001f);
        CHECK_CLOSE(0.0f, quaternion.z(), 0.001f);
        CHECK_CLOSE(0.0f, quaternion.w(), 0.001f);
    }

    TEST(from_euler_angles) {
        auto quaternion = Quaternion::from_euler_angles(1.57f, 0.0f, 0.0f,
                                                        RotationOrder::XYZ);
        CHECK_CLOSE(0.707f, quaternion.x(), 0.001f);
        CHECK_CLOSE(0.0f, quaternion.y(), 0.001f);
        CHECK_CLOSE(0.0f, quaternion.z(), 0.001f);
        CHECK_CLOSE(0.707f, quaternion.w(), 0.001f);
    }
}
