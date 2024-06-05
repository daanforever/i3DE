#pragma once

#include "Lorem/Types.h"

namespace Lorem {
  class Convert
  {
  private:
    t_directory Imported = {};
    t_directory Converted = {};
  public:
    Convert() = default;
    explicit Convert(const t_directory& imported) : Imported(imported) {};
  };
}
