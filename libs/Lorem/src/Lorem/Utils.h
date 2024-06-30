#pragma once

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/XML.h"

namespace Lorem {
  class Utils
  {
  public:
    static std::string fileWithoutExt(std::string_view filename);
    static t_shared_xml getXML(const t_file_ptr file_ptr);
    static t_file_ptr loadFile(std::string_view filename);
  };
}
