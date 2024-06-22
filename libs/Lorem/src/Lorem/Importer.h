#pragma once

#include <string>

#include "Lorem/Logger.h"
#include "Lorem/Extractor.h"

namespace Lorem {
  class Importer
  {
  public:
    explicit Importer(const std::string& filename);
    virtual ~Importer() = default;

    std::string Filename = "";
    t_directory_ptr Content = nullptr;

    virtual std::string Dump() const;
  };
};