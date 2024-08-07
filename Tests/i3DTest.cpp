#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem::importer::FS {
  const std::string filename = "../../../../Tests/Samples/test.i3d";
  const auto file_ptr = lorem::utils::load(filename);

  TEST(i3dTest, Constructor) {
    ASSERT_NO_THROW(i3d());
  };

  TEST(i3dTest, ParseXML) {
    ASSERT_NO_THROW(i3d().load(file_ptr));
  };

  TEST(i3dTest, NameAndVersion) {
    auto name = i3d().load(file_ptr).name;
    auto version = i3d().load(file_ptr).version;

    EXPECT_EQ("PLN_3_35_new", name);
    EXPECT_EQ("1.6", version);
  };

  TEST(i3dTest, Files) {
    auto files = i3d().load(file_ptr).find("Files");

    ASSERT_TRUE(files);
    ASSERT_EQ(7, files.children.size());
    EXPECT_EQ("5", files.children[0].attr("fileId"));
  };

}
