#pragma once

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

} // namespace amethyst
