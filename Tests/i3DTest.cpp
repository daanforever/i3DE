#include "pch.h"

#include "Lorem/i3D.cpp"

namespace i3D {
  const std::string filename = "../../../../Tests/Samples/pln_3_35.i3d";
  const auto file_ptr = Lorem::Utils::loadFile(filename);

  TEST(I3D, DefaultConstructor) {
    EXPECT_NO_THROW(Lorem::I3D());
  };

  TEST(I3D, ParseXML) {
    EXPECT_NO_THROW(Lorem::I3D().load(file_ptr));
  };

  TEST(I3D, NameAndVersion) {
    auto name = Lorem::I3D().load(file_ptr).name;
    auto version = Lorem::I3D().load(file_ptr).version;
    EXPECT_EQ("PLN_3_35_new", name);
    EXPECT_EQ("1.6", version);
  };

  TEST(I3D, Files) {
    auto files = Lorem::I3D().load(file_ptr).find("Files");

    ASSERT_TRUE(files);
    ASSERT_EQ(7, files.children.size());
    EXPECT_EQ("5", files.children[0].attr("fileId"));
  };

}
