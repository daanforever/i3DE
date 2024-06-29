#include "pch.h"
#include "Lorem/Importer/FS/Base.h"

namespace Lorem::Importer::FS {
  const std::string ZipFileName = "../../../../Tests/Samples/file.zip";

  TEST(Base, DefaultConstructor) {
    ASSERT_NO_THROW(Base());
  }

}
