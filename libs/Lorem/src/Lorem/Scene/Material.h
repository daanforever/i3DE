#pragma once

#include "Lorem/Types.h"
#include "Lorem/Scene.h"

namespace Lorem {
  class Scene;

  class Scene::Material
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