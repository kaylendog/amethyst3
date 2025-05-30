#pragma once

#include <functional>

#include <amethyst/ECS/Context.hpp>

namespace amethyst {

/// @brief A System is a function that operates on a Context and a variable
/// number of arguments.
template <typename... Args>
class System : public std::function<void(Context, Args...)> {
  public:
    System() = default;
};

} // namespace amethyst
