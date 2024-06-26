#include "pch.h"
#include "Lorem/Importer.h"
#include "Lorem/Converter.h"


namespace Converter {
  const std::string ZipBadFileName = "not_found";
  const std::string ZipEmptyFileName = "../../../../Tests/Samples/file.zip";
  const std::string ZipGoodFileName = "../../../../Tests/Samples/mod.zip";

  TEST(ConvertCaseName, DefaultConstructorTest) {
    auto converter = Lorem::Converter();

    EXPECT_TRUE(true);
  }
}
