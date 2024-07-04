export module daan.i3de.lorem.scene:Base;

import std;

import :Shape;
import :Material;
import :Sound;

export namespace lorem::Scene {
  // Representing a scene
  class Base {
  public:
    Base() = default;
    ~Base() = default;

    std::string name;
    std::vector<Shape> shapes; // Collection of shapes
    std::vector<Material> materials; // Collection of materials
    std::vector<Sound> sounds; // Collection of sound files

    // Method to add a shape to the scene
    void addShape(const Shape& shape);

    // Method to get all shapes in the scene
    const std::vector<Shape>& getShapes() const;

    // Method to add a material to the scene (optional)
    void addMaterial(const Material& material);

    // Method to get all materials in the scene (optional)
    const std::vector<Material>& getMaterials() const;

    explicit operator bool() const {
      return !shapes.empty() || !materials.empty() || !sounds.empty();
    }
  };

  // Implementation of the addShape method
  inline void Base::addShape(const Scene::Shape& shape) {
    shapes.push_back(shape);
  }

  // Implementation of the getShapes method
  inline const std::vector<Scene::Shape>& Base::getShapes() const {
    return shapes;
  }

  // Implementation of the addMaterial method (optional)
  inline void Base::addMaterial(const Scene::Material& material) {
    materials.push_back(material);
  }

  // Implementation of the getMaterials method (optional)
  inline const std::vector<Scene::Material>& Base::getMaterials() const {
    return materials;
  }
}