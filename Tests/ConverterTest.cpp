#include "pch.h"
#include "Lorem/Converter.h"

namespace Lorem {
  const std::string ZipBadFileName = "not_found";
  const std::string ZipEmptyFileName = "../../../../Tests/Samples/file.zip";
  const std::string ZipGoodFileName = "../../../../Tests/Samples/mod.zip";

  TEST(Converter, DefaultConstructorTest) {
    auto converter = Converter();

    EXPECT_TRUE(true);
  }
}
