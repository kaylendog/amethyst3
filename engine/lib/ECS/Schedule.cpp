#include <set>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include <amethyst/ECS/Schedule.hpp>

namespace amethyst {

class DependencyGraph {
  public:
    DependencyGraph() = default;
    ~DependencyGraph() = default;

    /// @brief Add a system to the dependency graph.
    void add_system(std::size_t system) { indices.push_back(system); }

    /// @brief Add a dependency between two systems.
    void add_dependency(std::size_t before, std::size_t after) {
        forward[before].insert(after);
        backward[after].insert(before);
    }

    /// @brief Build the dependency graph and return a vector of vectors
    /// representing the order of systems to execute.
    std::vector<std::size_t> build() {
        std::vector<std::size_t> order;
        std::set<std::size_t> pure;

        // initialize pure set with no edges
        for (const auto &dep : forward) {
            if (dep.second.empty()) {
                pure.insert(dep.first);
            }
        }

        while (!pure.empty()) {
            // take system from pure set and append
            auto first = *pure.begin();
            pure.erase(first);
            order.push_back({first});

            // remove all dependencies from the forward map
            for (const auto &after : forward[first]) {
                backward[after].erase(first);
                if (backward[after].empty()) {
                    pure.insert(after);
                }
            }

            order.push_back(first);
        }

        // check if there are any cycles
        for (const auto &pair : backward) {
            if (!pair.second.empty()) {
                throw std::runtime_error("Dependency graph has cycles.");
            }
        }

        return order;
    }

  private:
    std::vector<std::size_t> indices;
    /// @brief Forward dependencies - i.e. values depend on key.
    std::unordered_map<std::size_t, std::set<std::size_t>> forward;
    /// @brief Backward dependencies - i.e. key depends on values.
    std::unordered_map<std::size_t, std::set<std::size_t>> backward;
};

} // namespace amethyst
