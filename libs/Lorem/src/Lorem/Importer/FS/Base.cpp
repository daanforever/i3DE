#include "pch.h"
#include <sstream>

#include "Lorem/Importer/FS/Base.h"

namespace Lorem::Importer::FS {
  Base& Base::process(const t_file_ptr dir_ptr)
  {
    Lorem::Scene scene = {};

    i3d i3dFile = {};
    i3dShapes i3dShps = {};
    std::vector<Lorem::Scene::Shape> shapes;

    auto modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));

    std::vector<std::string> shape_files;

    for (const auto& filename : modDesc.StoreItems) {
      shape_files = i3dFile.load(dir_ptr->find(filename)).shapes;

      for (const auto& file : shape_files) {
        shape = i3dSh.load( dir_ptr->find(file) ).shape;
      }

    }

    return *this;
  }

}

