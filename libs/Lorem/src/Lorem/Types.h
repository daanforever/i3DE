#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

struct t_file {
  std::string name = {};
  bool directory = false;
  std::vector<unsigned char> content = {};
};

using t_file_ptr = std::shared_ptr<t_file>;

struct t_directory {
  std::vector<t_file_ptr> files = {};
  std::map<std::string, t_file_ptr, std::less<>> names = {};

  operator bool() const {
    return files.size() > 0;
  }
};

using t_directory_ptr = std::shared_ptr<t_directory>;
