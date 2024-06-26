#pragma once

#include <string>

#include "pugixml.hpp"

#include "Lorem/Logger.h"
#include "Lorem/Error.h"
#include "Lorem/Types.h"
#include "Lorem/ModDesc.h"
#include "Lorem/Scene.h"

namespace Lorem {
  class Importer
  {
  public:
    Importer() = default;
    virtual ~Importer() = default;

    virtual Lorem::Scene importMod(const t_directory_ptr dir);
  };
};