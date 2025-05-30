#pragma once

#include <cstdint>
#include <vector>

#include <amethyst/Math/Vec3.hpp>

namespace amethyst {

class Mesh {
  public:
    /// @brief Default constructor for Mesh.
    Mesh() = default;

    /// @brief Destructor for Mesh.
    ~Mesh() = default;

    /// @brief Add a vertex to the mesh.
    /// @param vertex The vertex to add.
    void insert_vertex(const Vec3 &vertex);

  private:
    std::vector<float> m_vertices;
    std::vector<uint32_t> m_indices;
};

} // namespace amethyst
