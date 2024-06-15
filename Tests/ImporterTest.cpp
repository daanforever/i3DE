#include "pch.h"
#include "Lorem/Importer.cpp"

namespace Importer {
  const std::string ZipFileName = "../../../../Tests/Samples/file.zip";

  TEST(ImporterCaseName, DumpTest) {
    auto importer = Lorem::Importer(ZipFileName);
    EXPECT_NE("", importer.Dump());
  }

  TEST(ImporterCaseName, FileNotFoundTest) {
    auto importer = Lorem::Importer("not_found");
    EXPECT_EQ("", importer.Dump());
  }

}
