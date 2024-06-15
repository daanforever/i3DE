#pragma once

#include <memory>
#include "pugixml.hpp"
#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class Convert
  {

  public:
    Convert() = default;
    explicit Convert(t_directory_ptr imported);

  private:
    t_directory_ptr Imported = {};
    t_directory Converted = {};

  public:
    // Raw content of modDesc.xml
    std::string modDesc() const;

    // Parsed content of modDesc.xml
    pugi::xml_document modDescXML();
    std::vector<std::string> storeItems();
  };
}
