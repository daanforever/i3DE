#pragma once

#include <string>

#include "Lorem/Unzip.h"

namespace Lorem {
  class Importer
  {
  public:
    explicit Importer(const std::string& filename);
    virtual ~Importer() = default;

    std::string Filename = "";
    std::unique_ptr<t_directory> Content = nullptr;

    virtual std::string Dump() const;
  };
};