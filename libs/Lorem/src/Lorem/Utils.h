#pragma once

#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class Utils
  {
  public:
    static t_file_ptr getFilePtr(const t_file_ptr dir_ptr, std::string_view filename);
    static std::string fileWithoutExt(std::string_view filename);
    static t_shared_xml getXML(const t_file_ptr file_ptr);
    static t_file_ptr loadFile(std::string_view filename);
  };
}
