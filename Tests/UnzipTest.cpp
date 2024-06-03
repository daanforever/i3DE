#include "pch.h"

#include  <stdlib.h>
#include "Lorem/Unzip.h"
#include "zip.h"

namespace Unzip {

  const auto ZipFileName = "../../../Tests/Sample/file.zip";
  const auto unzip = std::make_unique<Lorem::Unzip>(ZipFileName);

  TEST(ConstructorTestCase, ConstructorTest) {
    EXPECT_EQ(unzip->Filename, ZipFileName);
  }

  TEST(ToMemoryTestCase, SizeTest) {
    const auto content = unzip->ToMemory();
    EXPECT_EQ(unzip->Errors.All.size(), 0);
    EXPECT_EQ(content.size(), 1);
  }

  TEST(ToMemoryTestCase, ContentTest) {
    const auto expected_string = "123";
    const auto content = unzip->ToMemory();
    EXPECT_EQ(content.size(), 1);

    auto unzipped = *content[0].get();

    for (int i = 0; i < unzipped.size(); i++) {
      EXPECT_EQ(expected_string[i], unzipped[i]);
    }
  }

}