export module daan.i3de.lorem.scene:Shape;

import std;
import :Material;

export namespace lorem::Scene {
  
  // Structure representing a shape
  struct Shape {
  public:
    std::string name = {};
    std::vector<float> vertices = {}; // Vertices in the format (x, y, z)
    std::vector<std::uint32_t> indices = {}; // Indices for forming triangles
    Scene::Material material = {};

    explicit operator bool() const {
      return !name.empty() || !vertices.empty() || !indices.empty() || material;
    }
  };

}


