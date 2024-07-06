module;
#include "tests.h"

export module daan.i3de.tests.lorem.importer.fs.BaseTest;
import daan.i3de.lorem.base;

namespace lorem::importer::FS {
  const std::string ZipFileName = "../../../../Tests/Samples/mod.zip";

  TEST(BaseTest, DefaultConstructor) {
    ASSERT_NO_THROW(Base());
  }

}
