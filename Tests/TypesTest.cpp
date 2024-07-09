#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = extractor().ToMemory(ModFileName);

  TEST(typesTest, DirPtr) {
    ASSERT_EQ(dir_ptr->name, "/");
    EXPECT_TRUE(dir_ptr->find("modDesc.xml"));
    EXPECT_TRUE(dir_ptr->find("modDesc.xml")->find("modDesc.xml"));
  };
}
