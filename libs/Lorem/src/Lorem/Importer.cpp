#include "pch.h"
#include <sstream>

#include "Importer.h"

Lorem::Scene Lorem::Importer::importMod(const t_directory_ptr dir)
{
  Lorem::Scene result = {};

  auto modDesc = Lorem::ModDesc().process(dir);
  //std::vector

  //for (auto file : modDesc.StoreItems) {

  //}

  return result;
}

