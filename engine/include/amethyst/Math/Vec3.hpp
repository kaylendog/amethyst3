#pragma once

#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace amethyst {

/// @brief A 3D vector class that represents a point or direction in 3D space.
class Vec3 {
  public:
    /// @brief Construct a Vec3 with the given x, y, and z components.
    Vec3(float x, float y, float z);

    /// @brief Default constructor for Vec3, initializes to (0, 0, 0).
    Vec3(glm::vec3 vec);

    /// @brief Return the x component of the vector.
    float x() const;

    /// @brief Return the y component of the vector.
    float y() const;

    /// @brief Return the z component of the vector.
    float z() const;

    /// @brief Compute the element-wise sum of two vectors.
    Vec3 operator+(const Vec3 &other) const;

    /// @brief Compute the element-wise difference of two vectors.
    Vec3 operator-(const Vec3 &other) const;

    /// @brief Compute the element-wise product of a vector and a scalar.
    Vec3 operator*(float scalar) const;

    /// @brief Compute the element-wise division of a vector by a scalar.
    Vec3 operator/(float scalar) const;

    /// @brief Check if two vectors are equal.
    bool operator==(const Vec3 &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Vec3 &vec);

    /// @brief Compute the length of the vector.
    float length();

    /// @brief Compute the normalized vector.
    Vec3 normalized() const;

    /// @brief Compute the dot product of two vectors.
    float dot(const Vec3 &other) const;

    /// @brief Compute the cross product of two vectors.
    Vec3 cross(const Vec3 &other) const;

  private:
    glm::vec3 m_vec;
};

} // namespace amethyst
