#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <amethyst/Math/Vec3.hpp>

namespace amethyst {

const float PI = 3.14159265358979323846f;
const float TAU = 6.28318530717958647692f;

const float DEG_TO_RAD = PI / 180.0f;
const float RAD_TO_DEG = 180.0f / PI;

enum RotationOrder { XYZ, XZY, YXZ, YZX, ZXY, ZYX };

class Quaternion {
  public:
    /// @brief Identity quaternion, representing no rotation.
    static const Quaternion IDENTITY;

    /// @brief Default constructor for Quaternion, initializes to identity.
    static Quaternion from_euler_angles(float x, float y, float z,
                                        RotationOrder order = XYZ);

    /// @brief Create a Quaternion from an axis and an angle.
    static Quaternion from_axis_angle(const Vec3 &axis, float angle);

    /// @brief Default constructor for Quaternion, initializes to identity.
    Quaternion() = default;

    /// @brief Construct a Quaternion with the given x, y, z, and w
    /// components.
    Quaternion(float x, float y, float z, float w);

    /// @brief Construct a Quaternion from a glm::quat.
    Quaternion(const glm::quat &quat) : m_quat(quat) {}

    /// @brief Return the x component of the quaternion.
    float x() const;

    /// @brief Return the y component of the quaternion.
    float y() const;

    /// @brief Return the z component of the quaternion.
    float z() const;

    /// @brief Return the w component of the quaternion.
    float w() const;

    /// @brief Return the conjugate of the quaternion.
    Quaternion conjugate() const;

    bool operator==(const Quaternion &other) const;

    bool operator!=(const Quaternion &other) const;

    /// @brief Rotate a vector by the quaternion.
    Vec3 operator*(const Vec3 &vec) const;

    /// @brief Multiply two quaternions.
    Quaternion operator*(const Quaternion &other) const;

  private:
    glm::quat m_quat;
};

} // namespace amethyst
