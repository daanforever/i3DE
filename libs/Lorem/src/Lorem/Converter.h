#pragma once

#include <memory>
#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class Converter
  {

  public:
    Converter() = default;
    explicit Converter(t_file_ptr imported);

  private:
    t_file_ptr Imported = {};
    t_file_ptr Converted = {};

  public:
  };
}
