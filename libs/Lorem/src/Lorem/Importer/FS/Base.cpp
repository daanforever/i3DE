#include "pch.h"
#include <sstream>

#include "Lorem/Importer/FS/Base.h"

namespace Lorem::Importer::FS {
  Lorem::Scene Base::load(const t_file_ptr dir_ptr)
  {
    Lorem::Scene scene = {};

    auto modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));
    std::vector<Lorem::Scene::Shape> shapes;

    for (std::string filename : modDesc.StoreItems) {
      shapes = importShapes(dir_ptr->find(filename));
    }

    return scene;
  }

  // import Shapes from .i3d file
  std::vector<Lorem::Scene::Shape> Base::importShapes(const t_file_ptr dir_ptr)
  {
    std::vector<Lorem::Scene::Shape> result;

    if (!dir_ptr) {
      LERROR << "Unable to import. Invalid directory pointer." << std::endl;
      return result;
    }

    auto entry = I3D().load(dir_ptr).find("Shapes");

    if (entry.children.empty()) {
      t_file_ptr externalFile = dir_ptr->find(entry.attr("externalShapesFile"));
      if (externalFile) {
        findShape(externalFile, result);
      }
      else {
        LERROR << "External shapes file not found for " << dir_ptr->name << std::endl;
      }
    }
    else {
      for (const auto& child : entry.children) {
        t_file_ptr externalFile = dir_ptr->find(child.attr("externalShapesFile"));
        if (externalFile) {
          findShape(externalFile, result);
        }
        else {
          LERROR << "External shapes file not found for child entry" << std::endl;
        }
      }
    }

    return result;
  }

  // find Shape and emplace in vector
  bool Base::findShape(const t_file_ptr file_ptr, std::vector<Lorem::Scene::Shape>& result) const
  {
    if (!file_ptr) {
      LERROR << "Invalid file pointer in findShape." << std::endl;
      return false;
    }

    if (auto shape = importShape(file_ptr); shape) {
      result.push_back(shape);
    }
    else {
      LERROR << "Failed to import shape from file " << file_ptr->name << std::endl;
      return false;
    }

    return true;
  }

  // import Shape from .i3d.shapes file
  Lorem::Scene::Shape Base::importShape(const t_file_ptr file_ptr) const
  {
    if (!file_ptr) {
      LERROR << "Invalid file pointer in importShape." << std::endl;
      return Lorem::Scene::Shape();
    }

    // Replace with actual implementation to load the shape
    return Lorem::Scene::Shape();
  }


}

