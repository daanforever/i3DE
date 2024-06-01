#pragma once

#include <memory>
#include <string>
#include <vector>
#include "zip.h"

using t_zip_entry = std::unique_ptr<std::vector<unsigned char>>;
using t_zip_file = std::vector<t_zip_entry>;

namespace Lorem {
  class Unzip
  {
  public:

    explicit Unzip(const std::string& file);
    virtual ~Unzip() = default;

    const std::string Filename;
    virtual t_zip_file ToMemory();
    virtual t_zip_file ExtractFiles(zip_t* zip);
    virtual t_zip_entry ExtractFileByIndex(zip_t* zip, size_t index);

  };
}
