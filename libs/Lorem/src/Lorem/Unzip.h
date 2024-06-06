#pragma once

#include "pch.h"
#include "zip.h"
#include "Lorem/Types.h"
#include "Lorem/IError.h"

namespace Lorem {
  class Unzip : public Lorem::IError
  {
  public:

    explicit Unzip(const std::string& file);
    virtual ~Unzip() = default;

    const std::string Filename = {};

    virtual t_directory_ptr ToMemory();
    virtual t_directory_ptr ExtractFiles(zip_t* zip);
    virtual t_file_ptr ExtractFileByIndex(zip_t* zip, size_t index);
  };
}
