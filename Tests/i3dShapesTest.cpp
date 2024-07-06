#include "tests.h"

import daan.i3de.lorem.base;

namespace lorem::importer::FS {
  const std::string filename = "../../../../Tests/Samples/test.i3d.shapes";
  const auto file_ptr = lorem::utils::load(filename);

  TEST(i3dShapesTest, Contructor) {
    ASSERT_NO_THROW(i3dShapes());
  }

  TEST(i3dShapesTest, load) {
    ASSERT_NO_THROW(i3dShapes());

    ASSERT_NO_THROW(i3dShapes().load(file_ptr));
  }

  TEST(i3dShapesTest, Header) {
    auto empty_reader = lorem::reader::Base();
    auto& reader = lorem::reader::Base().open(file_ptr);

    ASSERT_THROW(i3dShapes::Header(empty_reader).seed, lorem::Error::UninitializedReaderError);
    ASSERT_NO_THROW(i3dShapes::Header(reader).seed);

    auto header = i3dShapes::Header(reader.reset());

    EXPECT_EQ(5, header.version);
  }
}
