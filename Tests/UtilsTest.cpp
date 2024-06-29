#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/Utils.cpp"

namespace Lorem {
  const std::string modFilename = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = Extractor().ToMemory(modFilename);
  const auto file_ptr = dir_ptr->find("modDesc.xml");

  TEST(Utils, fileWithoutExt) {
    EXPECT_EQ("file", Utils::fileWithoutExt("file.ext"));
  };

  TEST(Utils, getXML) {
    ASSERT_NO_THROW(Utils::getXML(file_ptr));
  };
}
