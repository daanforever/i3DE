#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Lorem {

  // Class representing a scene
  class Scene {
  public:
    class Shape;
    class Material;
    class Sounds;

    Scene() = default;
    ~Scene() = default;

    std::string name;
    std::vector<Shape> shapes; // Collection of shapes
    std::vector<Material> materials; // Collection of materials (if used)

    // Method to add a shape to the scene
    void addShape(const Shape& shape);

    // Method to get all shapes in the scene
    const std::vector<Shape>& getShapes() const;

    // Method to add a material to the scene (optional)
    void addMaterial(const Material& material);

    // Method to get all materials in the scene (optional)
    const std::vector<Material>& getMaterials() const;
  };

}

