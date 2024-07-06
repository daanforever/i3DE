#include "tests.h"

import daan.i3de.lorem.base;

namespace lorem {
  const std::string ZipBadFileName = "not_found";
  const std::string ZipEmptyFileName = "../../../../Tests/Samples/file.zip";
  const std::string ZipGoodFileName = "../../../../Tests/Samples/mod.zip";

  TEST(ConverterTest, DefaultConstructorTest) {
    auto converter = Converter();

    EXPECT_TRUE(true);
  }
}
