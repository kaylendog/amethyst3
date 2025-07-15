#pragma once

#include <functional>

#include <amethyst/ECS/Context.hpp>
#include <amethyst/ECS/Query.hpp>

namespace amethyst {

template <typename T> class Asset;
template <typename T> class Resource;
template <typename... Components> class Query;

namespace detail {

#include <type_traits>

template <typename T> struct is_system_arg : std::false_type {};
template <typename T> struct is_system_arg<Asset<T>> : std::true_type {};
template <typename T> struct is_system_arg<Resource<T>> : std::true_type {};
template <typename... Ts>
struct is_system_arg<Query<Ts...>> : std::true_type,
                                     amethyst::detail::is_query_arg<Ts>... {};

} // namespace detail

template <typename... Args> struct all_valid_args;

template <> struct all_valid_args<> : std::true_type {};

template <typename First, typename... Rest>
struct all_valid_args<First, Rest...>
    : std::conditional_t<detail::is_system_arg<std::decay_t<First>>::value,
                         all_valid_args<Rest...>, std::false_type> {};

/// @brief A System is a function that operates on a Context and a variable
/// number of arguments, each of which must be Asset, Resource, or Query.
template <typename... Args>
class System : public std::function<void(Context, Args...)> {
    static_assert(all_valid_args<Args...>::value,
                  "Each argument to System must be Asset, Resource, or Query");

  public:
    System() = default;
};

} // namespace amethyst
