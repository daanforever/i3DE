#include "pch.h"

import daan.i3de.lorem.base;

namespace lorem::importer::FS {
  const std::string ZipFileName = "../../../../Tests/Samples/mod.zip";

  TEST(BaseTest, DefaultConstructor) {
    ASSERT_NO_THROW(Base());
  }
}
