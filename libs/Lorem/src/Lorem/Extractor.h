#pragma once

#include "pch.h"
#include "zip.h"
#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Logger.h"

namespace Lorem {
  class Extractor
  {
  public:
    Extractor() = default;
    virtual ~Extractor() = default;

    virtual t_directory_ptr ToMemory(std::string_view filename);
    virtual t_directory_ptr ExtractFiles(zip_t* zip);
    virtual t_file_ptr ExtractFileByIndex(zip_t* zip, size_t index);
  };
}
