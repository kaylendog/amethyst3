#include <UnitTest++/UnitTest++.h>

#include <amethyst/ECS/Schedule.hpp>

SUITE(DependencyGraph) {
    using namespace amethyst;

    TEST(DependencyGraph_Basic) {
        DependencyGraph graph;
        graph.add_system(1);
        graph.add_system(2);
        graph.add_dependency(1, 2);

        auto order = graph.build();
        CHECK_EQUAL(order.size(), 2);
        CHECK_EQUAL(order[0], 1);
        CHECK_EQUAL(order[1], 2);
    }

    TEST(DependencyGraph_CycleDetection) {
        DependencyGraph graph;
        graph.add_system(1);
        graph.add_system(2);
        graph.add_dependency(1, 2);
        graph.add_dependency(2, 1);

        CHECK_THROW(graph.build(), std::runtime_error);
    }
}
