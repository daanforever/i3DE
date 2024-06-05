#include "pch.h"
#include "Lorem/Importer.cpp"

namespace Importer {
  const std::string ZipFileName = "../../../../Tests/Sample/file.zip";

  TEST(ImporterCaseName, UniqTest) {
    auto importer = Lorem::Importer(ZipFileName);
    EXPECT_NE("", importer.Dump());

  }
}
