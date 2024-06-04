#include "pch.h"

#include  <stdlib.h>
#include "Lorem/Unzip.h"
#include "zip.h"

namespace Unzip {

  const auto ZipFileName = "../../../../Tests/Sample/file.zip";

  TEST(ConstructorTestCase, ConstructorTest) {
    auto unzip = Lorem::Unzip(ZipFileName);
    EXPECT_EQ(unzip.Filename, ZipFileName);
  }

  TEST(ToMemoryTestCase, SizeTest) {
    auto unzip = Lorem::Unzip(ZipFileName);
    auto content = unzip.ToMemory();
    EXPECT_EQ(unzip.Errors.All.size(), 0);
    EXPECT_EQ(content.size(), 1);
  }

  TEST(ToMemoryTestCase, FilenameTest) {
    auto unzip = Lorem::Unzip(ZipFileName);
    auto name = "file.txt";
    auto content = unzip.ToMemory();

    ASSERT_EQ(content.size(), 1);

    auto entry = &content[0];
    EXPECT_EQ(name, entry->filename);
  }

  TEST(ToMemoryTestCase, ContentTest) {
    auto expected_string = "123";
    auto unzip = Lorem::Unzip(ZipFileName);
    auto content = unzip.ToMemory();

    ASSERT_EQ(content.size(), 1);

    auto entry = &content[0];

    for (int i = 0; i < entry->content.size(); i++) {
      EXPECT_EQ(expected_string[i], entry->content[i]);
    }
  }

}