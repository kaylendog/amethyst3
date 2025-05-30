#pragma once

#include <glm/glm.hpp>

#include <amethyst/Math/Vec3.hpp>
#include <amethyst/Transform/Quaternion.hpp>

namespace amethyst {

class Transform {
  public:
    /// @brief Construct a Transform with no translation, rotation, or scale.
    static Transform from_xyz(const float x, const float y, const float z);

    /// @brief Construct a Transform with no translation, rotation, or scale.
    static Transform from_position(const Vec3 position);

    /// @brief Construct a Transform with no translation, rotation, or scale.
    Transform() = default;

    /// @brief Return the postion of the transform.
    Vec3 position() const;

    /// @brief Return the rotation of the transform.
    Quaternion rotation() const;

    /// @brief Return this transform with the given position.
    Transform with_position(const Vec3 position) const;

    /// @brief Return this transform with the given rotation.
    Transform with_rotation(const Quaternion rotation) const;

    /// @brief Return this transform with the given scale.
    Transform with_scale(const Vec3 scale) const;

  private:
    glm::mat4 m_transform;
};

} // namespace amethyst
