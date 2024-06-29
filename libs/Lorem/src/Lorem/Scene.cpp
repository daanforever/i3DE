#include "pch.h"
#include "Scene.h"
#include "Scene/Material.h"
#include "Scene/Shape.h"

namespace Lorem {
  // Implementation of the addShape method
  inline void Scene::addShape(const Scene::Shape& shape) {
    shapes.push_back(shape);
  }

  // Implementation of the getShapes method
  inline const std::vector<Scene::Shape>& Scene::getShapes() const {
    return shapes;
  }

  // Implementation of the addMaterial method (optional)
  inline void Scene::addMaterial(const Scene::Material& material) {
    materials.push_back(material);
  }

  // Implementation of the getMaterials method (optional)
  inline const std::vector<Scene::Material>& Scene::getMaterials() const {
    return materials;

  }
}