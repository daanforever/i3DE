#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Lorem {

  // Structure representing a material (optional)
  struct Material {
    std::string name = ""; // Material name
    // Other material properties such as color, textures, etc.
  };

  // Structure representing a shape
  struct Shape {
    std::string name = "";
    std::vector<float> vertices = {}; // Vertices in the format (x, y, z)
    std::vector<uint32_t> indices = {}; // Indices for forming triangles
    Material material = {};
  };

  // Class representing a scene
  class Scene {
  public:
    Scene() = default;
    ~Scene() = default;

    // Method to add a shape to the scene
    void addShape(const Shape& shape);

    // Method to get all shapes in the scene
    const std::vector<Shape>& getShapes() const;

    // Method to add a material to the scene (optional)
    void addMaterial(const Material& material);

    // Method to get all materials in the scene (optional)
    const std::vector<Material>& getMaterials() const;

  private:
    std::vector<Shape> shapes; // Collection of shapes
    std::vector<Material> materials; // Collection of materials (if used)
  };

}

