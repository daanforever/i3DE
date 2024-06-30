#include "pch.h"

#include "Lorem/Utils.h"
#include "Lorem/Importer/FS/i3d.shapes.h"

namespace Lorem::Importer::FS {
  const std::string filename = "../../../../Tests/Samples/test.i3d.shapes";
  const auto file_ptr = Lorem::Utils::loadFile(filename);

  TEST(i3dShapes, Contructor) {
    ASSERT_NO_THROW(i3dShapes());
  }

  TEST(i3dShapes, load) {
    ASSERT_NO_THROW(i3dShapes());

    ASSERT_NO_THROW(i3dShapes().load(file_ptr));
  }

}
