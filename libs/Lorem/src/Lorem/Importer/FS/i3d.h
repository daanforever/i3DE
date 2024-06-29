#pragma once
#include <string>
#include <vector>
#include <map>

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Utils.h"
#include "Lorem/Scene/Shape.h"

namespace Lorem::Importer::FS {
  class i3dEntry {
  public:
    i3dEntry() = default;
    virtual ~i3dEntry() = default;

    std::string name = {};
    t_map_ss attributes = {};
    std::vector<i3dEntry> children = {};

    virtual explicit operator bool() const {
      return !name.empty();
    }

    virtual std::string attr(std::string_view what) const;
  };

  class i3d {
  public:
    i3d() = default;
    virtual ~i3d() = default;

    std::string name = {};
    std::string version = {};

    std::vector<std::string> shapes = {};
    std::map<std::string, i3dEntry, std::less<>> content = {};

    virtual i3d& load(const t_file_ptr file_ptr);
    virtual i3d& parse(const t_file_ptr file_ptr);

    virtual i3dEntry getEntry(pugi::xml_node node) const;
    virtual i3dEntry find(std::string_view what) const;
  };
}

