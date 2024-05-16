#pragma once

#include <iostream>
#include <fstream>
#include <vector>

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
    std::shared_ptr<std::vector<uint8_t>> Content = nullptr;
    FileHeader Header = {};

  public:
    void Load();
    virtual std::shared_ptr<std::vector<uint8_t>> Get(const unsigned long int Pos, const unsigned long int Length);
    virtual std::string Dump();
  };
};

