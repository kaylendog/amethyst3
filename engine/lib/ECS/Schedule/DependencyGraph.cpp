#include <cstddef>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include <amethyst/ECS/Schedule.hpp>

namespace amethyst {

DependencyGraph::DependencyGraph() = default;
DependencyGraph::~DependencyGraph() = default;

void DependencyGraph::add_system(std::size_t system) {
    indices.push_back(system);
}

void DependencyGraph::add_dependency(std::size_t before, std::size_t after) {
    forward[before].insert(after);
    backward[after].insert(before);
}

std::vector<std::size_t> DependencyGraph::build() {
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
        order.push_back(first);

        // remove all dependencies from the forward map
        for (const auto &after : forward[first]) {
            backward[after].erase(first);
            if (backward[after].empty()) {
                pure.insert(after);
            }
        }
    }

    // check if there are any cycles
    for (const auto &pair : backward) {
        if (!pair.second.empty()) {
            throw std::runtime_error("Dependency graph has cycles.");
        }
    }

    return order;
}

} // namespace amethyst
