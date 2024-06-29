#pragma once

#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem::Importer::FS {
  class i3dShapes
  {
  public:
    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<Lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr) {
      auto l = std::source_location::current();
      throw Lorem::Error::NotImplemented(std::string(l.file_name()) + ":" + std::string(l.function_name()));
    }
  };
}