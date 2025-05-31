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

    TEST(multiply_quat) {
        auto q1 = Quaternion::from_axis_angle(Vec3(1.0f, 0.0f, 0.0f), 1.57f);
        auto q2 = Quaternion::from_axis_angle(Vec3(0.0f, 1.0f, 0.0f), 1.57f);
        auto result = q1 * q2;

        CHECK_CLOSE(0.5f, result.x(), 0.001f);
        CHECK_CLOSE(0.5f, result.y(), 0.001f);
        CHECK_CLOSE(0.5f, result.z(), 0.001f);
        CHECK_CLOSE(0.5f, result.w(), 0.001f);

        // multiplication by identity
        auto identity = Quaternion::IDENTITY;
        auto identity_result = q1 * identity;

        CHECK_CLOSE(q1.x(), identity_result.x(), 0.001f);
        CHECK_CLOSE(q1.y(), identity_result.y(), 0.001f);
        CHECK_CLOSE(q1.z(), identity_result.z(), 0.001f);
        CHECK_CLOSE(q1.w(), identity_result.w(), 0.001f);
    }

    TEST(multiply_vec) {
        auto quaternion =
            Quaternion::from_axis_angle(Vec3(0.0f, 1.0f, 0.0f), 1.57f);
        Vec3 vec(1.0f, 0.0f, 0.0f);
        Vec3 result = quaternion * vec;

        CHECK_CLOSE(0.0f, result.x(), 0.001f);
        CHECK_CLOSE(0.0f, result.y(), 0.001f);
        CHECK_CLOSE(-1.0f, result.z(), 0.001f);
    }
}
