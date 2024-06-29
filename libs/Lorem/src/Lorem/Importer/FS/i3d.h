#pragma once
#include <string>
#include <vector>
#include <map>

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Utils.h"

namespace Lorem::Importer::FS {
  class I3DEntry {
  public:
    I3DEntry() = default;
    virtual ~I3DEntry() = default;

    std::string name = {};
    t_map_ss attributes = {};
    std::vector<I3DEntry> children = {};

    virtual explicit operator bool() const {
      return !name.empty();
    }

    virtual std::string attr(std::string_view what) const;
  };

  class I3D {
  public:
    I3D() = default;
    virtual ~I3D() = default;

    std::string name = {};
    std::string version = {};

    std::map<std::string, I3DEntry, std::less<>> content = {};

    virtual I3D& load(const t_file_ptr dir_ptr, const std::string& filename);
    virtual I3D& load(const t_file_ptr file_ptr);

    virtual I3DEntry getContainer(pugi::xml_node node) const;
    virtual I3DEntry find(std::string_view what) const;

  };
}

