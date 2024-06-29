#include "pch.h"
#include "Lorem/Extractor.h"

namespace Lorem {

  const auto fileName = "../../../../Tests/Samples/file.zip";

  TEST(Extractor, ConstructorTest) {
    ASSERT_NO_THROW(Extractor());
  }

  TEST(Extractor, ToMemory) {
    auto extract = Extractor();
    ASSERT_NO_THROW(extract.ToMemory(fileName));
  }

  TEST(Extractor, SizeTest) {
    auto extract = Extractor();

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    EXPECT_EQ(content->files.size(), 1);
    EXPECT_EQ(content->index.size(), 1);
  }

  TEST(Extractor, FilenameTest) {
    auto extract = Extractor();
    auto name = "file.txt";

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto entry_ptr = &content->files[0];
    EXPECT_EQ(name, entry_ptr->get()->name);
  }

  TEST(Extractor, ContentTest) {
    auto expected_string = "123";
    auto extract = Extractor();

    ASSERT_NO_THROW(extract.ToMemory(fileName));
    auto content = extract.ToMemory(fileName);

    ASSERT_EQ(content->files.size(), 1);

    auto file_ptr = content->files.front();

    EXPECT_EQ(expected_string, file_ptr->string());
  }

}