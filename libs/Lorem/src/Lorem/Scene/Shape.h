#pragma once

#include <string>
#include <vector>

#include "Lorem/Scene.h"
#include "Lorem/Scene/Material.h"

namespace Lorem {
  class Scene::Material;

  // Structure representing a shape
  class Scene::Shape {
  public:
    std::string name = {};
    std::vector<float> vertices = {}; // Vertices in the format (x, y, z)
    std::vector<uint32_t> indices = {}; // Indices for forming triangles
    Scene::Material material = {};

    explicit operator bool() const {
      return !name.empty() || !vertices.empty() || !indices.empty() || material;
    }
  };
}


