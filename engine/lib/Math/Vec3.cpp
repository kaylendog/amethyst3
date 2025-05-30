#include <glm/glm.hpp>

#include <amethyst/Math/Vec3.hpp>

namespace amethyst {

Vec3::Vec3(float x, float y, float z) : m_vec(x, y, z) {}

Vec3::Vec3(const glm::vec3 vec) : m_vec(vec) {}

float Vec3::x() const { return m_vec.x; }

float Vec3::y() const { return m_vec.y; }

float Vec3::z() const { return m_vec.z; }

Vec3 Vec3::operator+(const Vec3 &other) const {
    return Vec3(m_vec.x + other.m_vec.x, m_vec.y + other.m_vec.y,
                m_vec.z + other.m_vec.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    return Vec3(m_vec.x - other.m_vec.x, m_vec.y - other.m_vec.y,
                m_vec.z - other.m_vec.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(m_vec.x * scalar, m_vec.y * scalar, m_vec.z * scalar);
}

Vec3 Vec3::operator/(float scalar) const {
    return Vec3(m_vec.x / scalar, m_vec.y / scalar, m_vec.z / scalar);
}

bool Vec3::operator==(const Vec3 &other) const {
    return m_vec.x == other.m_vec.x && m_vec.y == other.m_vec.y &&
           m_vec.z == other.m_vec.z;
}

std::ostream &operator<<(std::ostream &os, const Vec3 &vec) {
    os << "Vec3(" << vec.m_vec.x << ", " << vec.m_vec.y << ", " << vec.m_vec.z
       << ")";
    return os;
}

float Vec3::length() { return glm::length(m_vec); }

Vec3 Vec3::normalize() { return Vec3(glm::normalize(m_vec)); }

} // namespace amethyst
