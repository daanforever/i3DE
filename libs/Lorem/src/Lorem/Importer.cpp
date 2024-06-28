#include "pch.h"
#include <sstream>

#include "Importer.h"

Lorem::Scene Lorem::Importer::importMod(const t_directory_ptr dir_ptr)
{
  Lorem::Scene scene = {};

  auto modDesc = Lorem::ModDesc().load(dir_ptr->find("modDesc.xml"));
  std::string shapesFilename;
  Lorem::Shape shape;

  for (std::string filename : modDesc.StoreItems) {

    auto file = dir_ptr->find(filename);

    if (!file) continue;

    if (I3D().load(file).find("Shapes").children.empty()) {

      shapesFilename = I3D().load(file).find("Shapes").attr("externalShapesFile");
      //shape = Lorem::Shape().load(shapesFilename);

    }
    else {

      for (auto child : I3D().load(file).find("Shapes").children) {
        shapesFilename = child.attr("externalShapesFile");
      }

    }

  }

  return scene;
}

