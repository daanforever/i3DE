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
    t_directory_ptr Converted = {};

  public:
    // Raw content of modDesc.xml
    std::string getModDescRaw() const;

    // Parsed content of modDesc.xml
    pugi::xml_document parseModDescXML() const;
    std::vector<std::string> getStoreItems() const;
    std::string getFileNameWithoutExtension(const std::string_view filename) const;
    t_directory_ptr convertStoreItemsToFBX();
    t_file_ptr convertFileToFBX(const std::string_view input, const std::string_view output) const;
  };
}
