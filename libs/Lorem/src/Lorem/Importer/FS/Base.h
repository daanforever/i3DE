#pragma once

#include <string>

#include "pugixml.hpp"

#include "Lorem/Logger.h"
#include "Lorem/Error.h"
#include "Lorem/Types.h"
#include "Lorem/Importer/FS/ModDesc.h"
#include "Lorem/Importer/FS/i3d.h"
#include "Lorem/Scene/Shape.h"

namespace Lorem::Importer::FS {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    virtual Lorem::Scene load(const t_file_ptr file_ptr);
    // import Shapes from .i3d file
    virtual std::vector<Lorem::Scene::Shape> importShapes(const t_file_ptr dir_ptr);

    // find Shape and emplace in vector
    virtual bool findShape(const t_file_ptr file_ptr, std::vector<Lorem::Scene::Shape>& result) const;

    // import Shape from .i3d.shapes file
    virtual Lorem::Scene::Shape importShape(const t_file_ptr file_ptr) const;
  };
};