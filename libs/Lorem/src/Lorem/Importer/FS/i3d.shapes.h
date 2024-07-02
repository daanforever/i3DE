#pragma once

#include "Lorem/Base.h"

namespace Lorem::Importer::FS {
  class i3dShapes
  {
  public:

    struct Header {
      Header() = default;
      explicit Header(Lorem::Reader::Base& reader);

      uint16_t version = 0;
      uint8_t  seed = 0;
    };

    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<Lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr);
  };
}