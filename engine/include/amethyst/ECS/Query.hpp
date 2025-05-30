#pragma once

#include <iterator>
#include <optional>
#include <tuple>

namespace amethyst {

/// @brief A Query is a way to fetch entities from the ECS that match a
/// specific set of components.
template <typename... Components> class Query {
  public:
    /// @brief Default constructor for Query.
    Query() = default;

    /// @brief Default destructor for Query.
    ~Query() = default;

    /// @brief Fetch the first entity that matches the query.
    std::tuple<Components...> one();

    /// @brief Fetch the first entity that matches the query, wrapping the
    /// result in an optional. If no entity matches, returns std::nullopt.
    std::optional<std::tuple<Components...>> maybe_one();

    /// @brief Fetch all entities that match the query.
    std::iterator<std::tuple<Components...>> many();

    /// @brief Fetch all entities that match the query, wrapping the result in
    /// an optional. If no entities match, returns std::nullopt.
    std::optional<std::iterator<std::tuple<Components...>>> maybe_many();
};

} // namespace amethyst
