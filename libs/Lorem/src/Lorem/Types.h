#pragma once

#include <string>
#include <vector>
#include <map>

struct t_file {
  std::string name = {};
  bool directory = false;
  std::vector<unsigned char> content = {};
};

struct t_directory {
  std::vector<t_file> files;
  std::map<std::string, t_file*, std::less<>> names;
};