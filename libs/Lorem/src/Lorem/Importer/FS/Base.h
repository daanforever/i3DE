#pragma once

#include <string>

#include "pugixml.hpp"

#include "Lorem/Logger.h"
#include "Lorem/Error.h"
#include "Lorem/Types.h"
#include "Lorem/Importer/FS/ModDesc.h"
#include "Lorem/Importer/FS/i3d.h"
#include "Lorem/Importer/FS/i3d.shapes.h"
#include "Lorem/Scene/Shape.h"

namespace Lorem::Importer::FS {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    std::vector<Lorem::Scene> scenes;

    // Load Farming Simulator mod and import content
    virtual Base& process(const t_file_ptr dir_ptr);
  };
};