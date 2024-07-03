export module daan.i3de.lorem.scene:Material;

import daan.i3de.lorem.types;

export namespace Lorem::Scene {
  struct Material
  {
  public:
    Material() = default;
    virtual ~Material() = default;

    t_map_ss attributes = {};

    explicit operator bool() const {
      return !attributes.empty();
    }
  };
}