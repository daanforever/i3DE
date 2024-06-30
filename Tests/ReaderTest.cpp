#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/Reader.h"
#include "Lorem/Utils.h"

namespace Lorem {
  const std::string file = "../../../../Tests/Samples/file.txt";
  const auto file_ptr = Lorem::Utils::loadFile(file);

  TEST(Reader, DefaultConstructor) {
    ASSERT_NO_THROW(Reader());
  };

  TEST(Reader, open) {
    ASSERT_THROW(Reader().open(nullptr), Lorem::Error::NullPtrError);
    ASSERT_NO_THROW(Reader().open(file_ptr));
  };

  TEST(Reader, get) {
    ASSERT_NO_THROW(Reader().open(file_ptr).get(0));
    ASSERT_NO_THROW(Reader().open(file_ptr).get(1));
    ASSERT_NO_THROW(Reader().open(file_ptr).get(10));
    ASSERT_EQ(3, Reader().open(file_ptr).get(10).size());

    auto reader = Reader().open(file_ptr);

    ASSERT_EQ(1, reader.get(1).size());
    ASSERT_EQ(2, reader.get(10).size());
    ASSERT_EQ(0, reader.get(10).size());

    auto result = Reader().open(file_ptr).get(10);

    ASSERT_EQ('1', (char)result[0]);
    ASSERT_EQ('2', (char)result[1]);
    ASSERT_EQ('3', (char)result[2]);
  }

}
