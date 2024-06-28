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
    bool isDirectory = false;
    std::vector<std::byte> content = {};

    explicit operator bool() const {
      return !name.empty();
    }

    bool empty() const {
      return content.empty();
    }

    bool present() const {
      return !empty();
    }

    std::string string() const {
      return std::string((const char*)content.data(), content.size());
    }
  };

  using t_file_ptr = std::shared_ptr<t_file>;

  // Structure representing a content of zip archive in memory
  struct t_directory {
    std::vector<t_file_ptr> files = {};
    std::map<std::string, t_file_ptr, std::less<>> names = {};

    explicit operator bool() const {
      return !files.empty();
    }

    t_file_ptr find(std::string_view filename) const {
      t_file_ptr result = {};

      if (auto iter = names.find(filename); iter != names.end()) {
        result = iter->second;
      }

      return result;
    }
  };

  using t_directory_ptr = std::shared_ptr<t_directory>;

  using t_map_ss = std::map<std::string, std::string, std::less<>>;
  using t_shared_xml = std::shared_ptr<pugi::xml_document>;
}