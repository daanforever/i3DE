#include "pch.h"
#include "Lorem/Unzip.h"
#include "zip.h"

namespace Lorem {
  const std::string ZipFileName = "testfile.name";
  const auto unzip = std::make_unique<Lorem::Unzip>(ZipFileName);

  TEST(UnzipTestCase, ConstructorTest) {
    EXPECT_EQ(unzip->Filename, ZipFileName);
  }

  TEST(UnzipTestCase, ToMemoryTest) {
    EXPECT_NE(unzip->ToMemory(), nullptr);
  }

}