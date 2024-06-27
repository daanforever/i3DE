#include "pch.h"
#include "Lorem/Extractor.h"

namespace Extractor {

  const auto fileName = "../../../../Tests/Samples/file.zip";

  TEST(ConstructorTestCase, ConstructorTest) {
    EXPECT_NO_THROW(Lorem::Extractor());
  }

  TEST(ToMemoryTestCase, ToMemory) {
    auto extract = Lorem::Extractor();
    EXPECT_NO_THROW(extract.ToMemory(fileName));
  }

  TEST(ToMemoryTestCase, SizeTest) {
    auto extract = Lorem::Extractor();

    EXPECT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    EXPECT_EQ(content->files.size(), 1);
  }

  TEST(ToMemoryTestCase, FilenameTest) {
    auto extract = Lorem::Extractor();
    auto name = "file.txt";

    EXPECT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto entry_ptr = &content->files[0];
    EXPECT_EQ(name, entry_ptr->get()->name);
  }

  TEST(ToMemoryTestCase, ContentTest) {
    auto expected_string = "123";
    auto extract = Lorem::Extractor();

    EXPECT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto file_ptr = content->files.front();

    EXPECT_STREQ(expected_string, file_ptr->string().data());
  }

}