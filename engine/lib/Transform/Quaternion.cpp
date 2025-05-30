#include <amethyst/Math/Vec3.hpp>
#include <amethyst/Transform/Quaternion.hpp>

namespace amethyst {

Quaternion const Quaternion::IDENTITY = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);

Quaternion Quaternion::from_euler_angles(float x, float y, float z,
                                         RotationOrder order) {

    float half_x = x * 0.5f;
    float half_y = y * 0.5f;
    float half_z = z * 0.5f;

    float c1 = cos(half_x);
    float c2 = cos(half_y);
    float c3 = cos(half_z);
    float s1 = sin(half_x);
    float s2 = sin(half_y);
    float s3 = sin(half_z);

    switch (order) {
    case XYZ:
        return Quaternion(
            s1 * c2 * c3 + c1 * s2 * s3, c1 * s2 * c3 - s1 * c2 * s3,
            c1 * c2 * s3 - s1 * s2 * c3, c1 * c2 * c3 + s1 * s2 * s3);
    case XZY:
        return Quaternion(
            s1 * c2 * c3 - c1 * s2 * s3, c1 * s2 * c3 + s1 * c2 * s3,
            c1 * c2 * s3 + s1 * s2 * c3, c1 * c2 * c3 - s1 * s2 * s3);
    case YXZ:
        return Quaternion(
            s1 * c2 * c3 + c1 * s2 * s3, c1 * s2 * c3 - s1 * c2 * s3,
            c1 * c2 * s3 - s1 * s2 * c3, c1 * c2 * c3 + s1 * s2 * s3);
    case YZX:
        return Quaternion(
            s1 * c2 * c3 - c1 * s2 * s3, -c1 * s2 + (s1 + 0.5f) / 0.5f,
            -c1 + (s2 + 0.5f) / 0.5f, c1 * c2 * c3 + s1 * s2 * s3);
    case ZXY:
        return Quaternion(
            s1 * c2 * c3 - c1 * s2 * s3, c1 * s2 * c3 + s1 * c2 * s3,
            c1 * c2 * s3 + s1 * s2 * c3, c1 * c2 * c3 - s1 * s2 * s3);
    case ZYX:
        return Quaternion(
            s1 * c2 * c3 + c1 * s2 * s3, c1 * s2 * c3 - s1 * c2 * s3,
            c1 * c2 * s3 - s1 * s2 * c3, c1 * c2 * c3 + s1 * s2 * s3);
    default:
        return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    }
}

Quaternion Quaternion::from_axis_angle(const Vec3 &axis, float angle) {
    float half_angle = angle * 0.5f;
    float s = sin(half_angle);
    return Quaternion(axis.x() * s, axis.y() * s, axis.z() * s,
                      cos(half_angle));
}

Quaternion::Quaternion(float x, float y, float z, float w)
    : m_quat(x, y, z, w) {}

float Quaternion::x() const { return m_quat.x; }

float Quaternion::y() const { return m_quat.y; }

float Quaternion::z() const { return m_quat.z; }

float Quaternion::w() const { return m_quat.w; }

Quaternion Quaternion::conjugate() const {
    return Quaternion(-m_quat.x, -m_quat.y, -m_quat.z, m_quat.w);
}

bool Quaternion::operator==(const Quaternion &other) const {
    return m_quat == other.m_quat;
}

bool Quaternion::operator!=(const Quaternion &other) const {
    return !(*this == other);
}

Vec3 Quaternion::operator*(const Vec3 &vec) const {
    Vec3 uv = Vec3(m_quat.x, m_quat.y, m_quat.z).cross(vec);
    Vec3 uuv = Vec3(m_quat.x, m_quat.y, m_quat.z).cross(uv);
    return vec + (uv * m_quat.w + uuv) * 2.0f;
}

} // namespace amethyst
