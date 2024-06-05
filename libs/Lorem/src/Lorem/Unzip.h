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

    virtual std::unique_ptr<t_directory> ToMemory();
    virtual t_directory ExtractFiles(zip_t* zip);
    virtual t_file ExtractFileByIndex(zip_t* zip, size_t index);
  };
}
