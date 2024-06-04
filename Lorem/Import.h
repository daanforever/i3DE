#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Lorem/Unzip.h"

namespace Lorem {
  struct FileHeader {
    uint16_t Version = 0;
    uint8_t  Seed = 0;
  };

  class Import
  {
  public:
    explicit Import(const std::string& filename);
    virtual ~Import() = default;

  private:
    std::string Filename = "";
    t_zip_content Content = {};
    FileHeader Header = {};

  public:
    void DebugPrint() const;
    virtual std::stringstream DumpZipContent() const;
    virtual std::string Dump();
  };
};

