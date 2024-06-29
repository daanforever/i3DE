#include "pch.h"

#include "Lorem/Utils.h"
#include "Lorem/Importer/FS/i3d.shapes.h"

namespace Lorem::Importer::FS {
  const std::string filename = "../../../../Tests/Samples/pln_3_35.i3d";
  const auto file_ptr = Lorem::Utils::loadFile(filename);

}
