#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem {

  const auto fileName = "../../../../Tests/Samples/file.zip";

  TEST(ExtractorTest, ConstructorTest) {
    ASSERT_NO_THROW(extractor());
  }

  TEST(ExtractorTest, ToMemory) {
    auto extract = extractor();
    ASSERT_NO_THROW(extract.ToMemory(fileName));
  }

  TEST(ExtractorTest, SizeTest) {
    auto extract = extractor();

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    EXPECT_EQ(content->files.size(), 1);
    EXPECT_EQ(content->index.size(), 1);
  }

  TEST(ExtractorTest, FilenameTest) {
    auto extract = extractor();
    auto name = "file.txt";

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto entry_ptr = &content->files[0];
    EXPECT_EQ(name, entry_ptr->get()->name);
  }

  TEST(ExtractorTest, ContentTest) {
    auto expected_string = "123";
    auto extract = extractor();

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto file_ptr = content->files.front();

    EXPECT_EQ(expected_string, file_ptr->string());
  }

}