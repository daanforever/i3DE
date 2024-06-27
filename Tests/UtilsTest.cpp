#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/Utils.cpp"

namespace Utils {
  const std::string modFilename = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = Lorem::Extractor().ToMemory(modFilename);
  const auto file_ptr = Lorem::Utils::getFilePtr(dir_ptr, "modDesc.xml");

  TEST(fileWithoutExt, One) {
    EXPECT_EQ("file", Lorem::Utils::fileWithoutExt("file.ext"));
  };

  TEST(getFilePtr, One) {
    EXPECT_NE(nullptr, Lorem::Utils::getFilePtr(dir_ptr, "modDesc.xml"));
  };

  TEST(getXML, One) {
    EXPECT_NO_THROW(Lorem::Utils::getXML(file_ptr));
  };
}
