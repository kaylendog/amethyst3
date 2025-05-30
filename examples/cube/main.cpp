#include <iostream>

#include <amethyst/Window/Window.hpp>

int main() {
    amethyst::WindowOptions opts;
    opts.width = 800;
    opts.height = 600;
    opts.title = "Amethyst Cube Example";

    amethyst::Window window(opts);

    return 0;
}
