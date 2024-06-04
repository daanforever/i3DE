#pragma once

#include <memory>
#include <string>
#include <vector>
#include "zip.h"
#include "Lorem/IError.h"

struct t_zip_entry {
  std::string filename = {};
  bool directory = false;
  std::vector<unsigned char> content = {};
};

using t_zip_content = std::vector<t_zip_entry>;

namespace Lorem {
  class Unzip : public Lorem::IError
  {
  public:

    explicit Unzip(const std::string& file);
    virtual ~Unzip() = default;

    const std::string Filename = {};

    virtual t_zip_content ToMemory();
    virtual t_zip_content ExtractFiles(zip_t* zip);
    virtual t_zip_entry ExtractFileByIndex(zip_t* zip, size_t index);
  };
}
