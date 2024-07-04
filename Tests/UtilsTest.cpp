#include "pch.h"

import daan.i3de.lorem.base;

namespace lorem {
  const std::string modFilename = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = extractor().ToMemory(modFilename);
  const auto file_ptr = dir_ptr->find("modDesc.xml");

  TEST(utils, fileWithoutExt) {
    EXPECT_EQ("file", utils::fileWithoutExt("file.ext"));
  };

  TEST(utils, getXML) {
    ASSERT_NO_THROW(utils::getXML(file_ptr));
  };
}
