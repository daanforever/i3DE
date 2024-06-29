#include "pch.h"

#include "Lorem/Importer/FS/i3d.h"

namespace Lorem::Importer::FS {
  const std::string filename = "../../../../Tests/Samples/pln_3_35.i3d";
  const auto file_ptr = Lorem::Utils::loadFile(filename);

  TEST(i3d, DefaultConstructor) {
    ASSERT_NO_THROW(i3d());
  };

  TEST(i3d, ParseXML) {
    ASSERT_NO_THROW(i3d().load(file_ptr));
  };

  TEST(i3d, NameAndVersion) {
    auto name = i3d().load(file_ptr).name;
    auto version = i3d().load(file_ptr).version;
    EXPECT_EQ("PLN_3_35_new", name);
    EXPECT_EQ("1.6", version);
  };

  TEST(i3d, Files) {
    auto files = i3d().load(file_ptr).find("Files");

    ASSERT_TRUE(files);
    ASSERT_EQ(7, files.children.size());
    EXPECT_EQ("5", files.children[0].attr("fileId"));
  };

}
