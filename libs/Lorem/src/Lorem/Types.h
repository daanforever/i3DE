#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "pugixml.hpp"

namespace Lorem {

  // Structure representing a file in memory
  struct t_file {
    std::string name = {};
    bool directory = false;
    std::vector<unsigned char> content = {};
  };

  using t_file_ptr = std::shared_ptr<t_file>;

  // Structure representing a content of zip archive in memory
  struct t_directory {
    std::vector<t_file_ptr> files = {};
    std::map<std::string, t_file_ptr, std::less<>> names = {};

    explicit operator bool() const {
      return !files.empty();
    }
  };

  using t_directory_ptr = std::shared_ptr<t_directory>;

  using t_map_ss = std::map<std::string, std::string, std::less<>>;
  using t_shared_xml = std::shared_ptr<pugi::xml_document>;
}