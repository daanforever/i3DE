#pragma once

#include "pch.h"
#include "zip.h"
#include "Lorem/Types.h"
#include "Lorem/IError.h"

namespace Lorem {
  class Extractor : public Lorem::IError
  {
  public:

    explicit Extractor(const std::string& file);
    virtual ~Extractor() = default;

    const std::string Filename = {};

    virtual t_directory_ptr ToMemory();
    virtual t_directory_ptr ExtractFiles(zip_t* zip);
    virtual t_file_ptr ExtractFileByIndex(zip_t* zip, size_t index);
  };
}
