#include <amethyst/Transform/Transform.hpp>

using namespace amethyst;

Transform Transform::from_xyz(const float x, const float y, const float z) {
    return Transform::from_position(Vec3(x, y, z));
}

Transform Transform::from_position(const Vec3 position) {
    return Transform().with_position(position);
}

Transform Transform::with_position(const Vec3 position) const {
    Transform transform = *this;
    transform.m_transform[3][0] = position.x();
    transform.m_transform[3][1] = position.y();
    transform.m_transform[3][2] = position.z();
    return transform;
}

Vec3 Transform::position() const {
    return Vec3(m_transform[3][0], m_transform[3][1], m_transform[3][2]);
}
