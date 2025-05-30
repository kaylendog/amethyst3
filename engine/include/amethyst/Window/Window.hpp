#pragma once

#include <GLFW/glfw3.h>

namespace amethyst {

/// @brief Options for creating a window in the Amethyst engine.
struct WindowOptions {
    int width;
    int height;
    const char *title;
    bool resizable;
};

class Window {
  public:
    Window(WindowOptions opts);
    ~Window() = default;

  private:
    GLFWwindow *m_window = nullptr;
};

} // namespace amethyst
