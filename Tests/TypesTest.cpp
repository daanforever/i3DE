#include "pch.h"
#include "Lorem/Extractor.h"

namespace Lorem {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = Extractor().ToMemory(ModFileName);

  using ::testing::HasSubstr;

  TEST(Types, DirPtr) {
    ASSERT_EQ(dir_ptr->name, "/");
    EXPECT_TRUE(dir_ptr->find("modDesc.xml"));
    EXPECT_TRUE(dir_ptr->find("modDesc.xml")->find("modDesc.xml"));
  };
}
