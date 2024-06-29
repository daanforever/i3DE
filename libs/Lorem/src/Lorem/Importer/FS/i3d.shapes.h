#pragma once

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Scene.h"

namespace Lorem::Importer::FS {
  class i3dShapes
  {
  public:
    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<Lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr) {
      throw Lorem::Error::NotImplemented(std::source_location::current().file_name());
      return *this;
    }
  };
}