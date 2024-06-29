#include "pch.h"
#include "Lorem/Importer/FS/Base.h"

namespace Lorem::Importer::FS {
  const std::string ZipFileName = "../../../../Tests/Samples/mod.zip";

  TEST(Base, DefaultConstructor) {
    ASSERT_NO_THROW(Base());
  }

  //Test(Base, Import)

}
