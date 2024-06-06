#pragma once

#include <memory>
#include "Lorem/Types.h"

namespace Lorem {
  class Convert
  {

  public:
    Convert() = default;
    explicit Convert(t_directory_ptr imported) : Imported(imported) {};

  private:
    t_directory_ptr Imported = {};
    t_directory Converted = {};

  public:
    // Content of modDesc.xml
    std::shared_ptr<std::string> modDesc() const;

  };
}
