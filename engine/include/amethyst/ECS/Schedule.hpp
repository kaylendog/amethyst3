#pragma once

#include <cstddef>
#include <set>
#include <unordered_map>
#include <vector>

namespace amethyst {

/// @brief A schedule is a collection of systems and their execution order.
class Schedule {
  public:
    /// @brief Default constructor for Schedule.
    Schedule() = default;

    /// @brief Default destructor for Schedule.
    ~Schedule() = default;

    /// @brief Add a system to the schedule.
    /// @tparam T
    /// @param system
    /// @return
    template <typename T> Schedule &insert(T system);

    /// @brief Remove a system from the schedule.
    /// @tparam T
    /// @param system
    /// @return
    template <typename T> Schedule &remove(T system);

    /// @brief Insert a system after another system in the schedule.
    /// @tparam T
    /// @tparam ...TX
    /// @param system
    /// @param ...others
    /// @return
    template <typename T, typename... TX>
    Schedule &insert_after(T system, TX... others);

    /// @brief Insert a system before another system in the schedule.
    template <typename T, typename... TX>
    Schedule &insert_before(T system, TX... others);

    /// @brief Add systems to the schedule that run sequentially.
    template <typename... TX> Schedule &sequential(TX... systems);
};

class DependencyGraph {
  public:
    DependencyGraph();
    ~DependencyGraph();

    /// @brief Add a system to the dependency graph.
    void add_system(std::size_t system);

    /// @brief Add a dependency between two systems.
    void add_dependency(std::size_t before, std::size_t after);

    /// @brief Build the dependency graph and return a vector of vectors
    /// representing the order of systems to execute.
    std::vector<std::size_t> build();

  private:
    std::vector<std::size_t> indices;
    /// @brief Forward dependencies - i.e. values depend on key.
    std::unordered_map<std::size_t, std::set<std::size_t>> forward;
    /// @brief Backward dependencies - i.e. key depends on values.
    std::unordered_map<std::size_t, std::set<std::size_t>> backward;
};

} // namespace amethyst
