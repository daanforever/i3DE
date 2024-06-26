#pragma once

#include <memory>
#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class Converter
  {

  public:
    Converter() = default;
    explicit Converter(t_directory_ptr imported);

  private:
    t_directory_ptr Imported = {};
    t_directory_ptr Converted = {};

  public:
  };
}
