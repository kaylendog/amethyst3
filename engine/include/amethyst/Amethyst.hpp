#include <amethyst/ECS/System.hpp>

namespace amethyst {

class Amethyst {
  public:
    Amethyst() = default;
    ~Amethyst() = default;

    /// @brief Add systems to the engine instance.
    /// @return
    template <typename... Systems,
              typename = std::enable_if_t<
                  (std::is_base_of_v<System<>, std::decay_t<Systems>> && ...)>>
    Amethyst add_system(Systems &&...systems);
};

} // namespace amethyst
