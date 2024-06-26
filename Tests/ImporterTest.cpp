#include "pch.h"
#include "Lorem/Importer.cpp"

namespace Importer {
  const std::string ZipFileName = "../../../../Tests/Samples/file.zip";

  TEST(ImporterCaseName, DefaultConstructor) {
    EXPECT_NO_THROW(Lorem::Importer());
  }

}
