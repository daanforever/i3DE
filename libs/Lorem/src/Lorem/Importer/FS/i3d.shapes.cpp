#include "pch.h"
#include "Lorem/Importer/FS/i3d.shapes.h"

namespace Lorem::Importer::FS {
  // Load .i3d.shapes file
  // Param file_ptr can't be nullptr at all
  i3dShapes& i3dShapes::load(t_file_ptr file_ptr)
  {
    assert(file_ptr);

    return *this;
  }
}
