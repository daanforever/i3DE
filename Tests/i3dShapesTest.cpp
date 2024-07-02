#include "pch.h"

#include "Lorem/Base.h"
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

  TEST(i3dShapes, Header) {
    auto empty_reader = Lorem::Reader::Base();
    auto reader = Lorem::Reader::Base().open(file_ptr);

    ASSERT_THROW(i3dShapes::Header(empty_reader).seed, Lorem::Error::UninitializedReaderError);
    ASSERT_NO_THROW(i3dShapes::Header(reader).seed);

    auto header = i3dShapes::Header(reader.reset());

    EXPECT_EQ(5, header.version);
  }
}
