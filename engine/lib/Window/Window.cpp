#include <stdexcept>

#include <GLFW/glfw3.h>

#include <amethyst/Window/Window.hpp>

namespace amethyst {

Window::Window(WindowOptions opts) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    m_window =
        glfwCreateWindow(opts.width, opts.height, opts.title, nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
}

} // namespace amethyst
