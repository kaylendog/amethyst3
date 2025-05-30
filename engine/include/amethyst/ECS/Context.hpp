#pragma once

#include <optional>

#include <amethyst/ECS/Entity.hpp>
#include <amethyst/ECS/World.hpp>

namespace amethyst {

/// @brief EntityContext is a context for an entity that can hold components.
class EntityContext {
  public:
    EntityContext() = default;
    ~EntityContext() = default;

    /// @brief  Add a component to the entity context.
    /// @tparam T
    /// @param component
    template <typename T> EntityContext add_component(T component);

    /// @brief  Get a component from the entity context.
    /// @tparam T
    /// @return The component of type T, or nullptr if it does not exist.
    template <typename T> std::optional<T> get_component();

    /// @brief  Remove a component from the entity context.
    /// @tparam T
    /// @return True if the component was removed, false if it did not exist.
    template <typename T> bool remove_component();

    /// @brief Add a child entity to the context with the specified components.
    template <typename... Components>
    EntityContext add_child(Components... components);
};

/// @brief Context is the main entry point for interacting with the ECS.
class Context {
  public:
    Context() = default;
    ~Context() = default;

    /// @brief Fetch the world associated with this context.
    World world();

    /// @brief Fetch an entity context by its index.
    EntityContext entity(Entity idx);
};

} // namespace amethyst
