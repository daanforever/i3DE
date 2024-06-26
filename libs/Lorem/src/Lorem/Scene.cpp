#include "pch.h"
#include "Scene.h"

// Implementation of the addShape method
inline void Lorem::Scene::addShape(const Shape& shape) {
  shapes.push_back(shape);
}

// Implementation of the getShapes method
inline const std::vector<Lorem::Shape>& Lorem::Scene::getShapes() const {
  return shapes;
}

// Implementation of the addMaterial method (optional)
inline void Lorem::Scene::addMaterial(const Material& material) {
  materials.push_back(material);
}

// Implementation of the getMaterials method (optional)
inline const std::vector<Lorem::Material>& Lorem::Scene::getMaterials() const {
  return materials;
}