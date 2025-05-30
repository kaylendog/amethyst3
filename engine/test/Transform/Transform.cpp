#include <UnitTest++/UnitTest++.h>

#include <amethyst/Transform/Transform.hpp>

using namespace amethyst;

SUITE(Transform) {
    TEST(from_xyz_idempotency) {
        auto transform = Transform::from_xyz(1.0f, 2.0f, 3.0f);
        CHECK_EQUAL(Vec3(1.0f, 2.0f, 3.0f), transform.position());
    }
}
