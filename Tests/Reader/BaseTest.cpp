#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem::reader::BaseTests {
  const std::string file = "../../../../Tests/Samples/file2.txt";
  const auto file_ptr = lorem::utils::load(file);

  TEST(ReaderBaseTest, DefaultConstructor) {
    ASSERT_NO_THROW(Base());
  };

  TEST(ReaderBaseTest, ConstructorWithIntance) {
    ASSERT_NO_THROW(Base().open(file_ptr));

    auto base_reader = Base().open(file_ptr);

    ASSERT_NO_THROW(Base(base_reader).file_ptr);
  }

  TEST(ReaderBaseTest, open) {
    ASSERT_THROW(Base().open(nullptr), lorem::Error::NullPtrError);
    ASSERT_NO_THROW(Base().open(file_ptr));
  };

  TEST(ReaderBaseTest, read) {
    auto result = Base().open(file_ptr).read(20);

    ASSERT_EQ(11, result.size());
    ASSERT_EQ('1', (char)result[0]);
    ASSERT_EQ('2', (char)result[1]);
    ASSERT_EQ('1', (char)result.back());
  }

  TEST(ReaderBaseTest, getByte) {

    ASSERT_NO_THROW(
      auto reader = Base().open(file_ptr);
      reader.reset();
      reader.get<std::byte>(0);
      (void)reader.get<std::byte>(10).size();
    );

    // default get
    auto result = Base().open(file_ptr).get<std::byte>(10);

    ASSERT_EQ('1', (char)result[0]);
    ASSERT_EQ('2', (char)result[1]);
    ASSERT_EQ('3', (char)result[2]);
  }

  TEST(ReaderBaseTest, getChar) {
    // get<char>
    auto char_result = Base().open(file_ptr).get<char>(10);

    ASSERT_EQ('1', char_result[0]);
    ASSERT_EQ('2', char_result[1]);
    ASSERT_EQ('3', char_result[2]);
  }

  TEST(ReaderBaseTest, getInt) {
    // file_ptr.content contains 3 bytes

    ASSERT_NO_THROW(
      auto reader = Base().open(file_ptr);
      reader.reset();
      reader.get<int>(0);
      (void)reader.get<int>(10).size();
    );

    auto& reader = Base().open(file_ptr);

    // should truncate result
    ASSERT_EQ(2, reader.get<int>(10).size());

    reader.reset();

    // sequental read
    ASSERT_EQ(1, reader.get<int>(1).size());
    ASSERT_EQ(1, reader.get<int>(10).size());
    ASSERT_EQ(0, reader.get<int>(10).size());

    auto result = reader.reset().get<int>(10);

    ASSERT_EQ(0x34333231, result[0]);
    ASSERT_EQ(0x38373635, result[1]);
  }

  TEST(ReaderBaseTest, getInt64) {
    // get<int>
    auto int64_result = Base().open(file_ptr).get<std::uint64_t>(4);

    ASSERT_EQ(1, int64_result.size());

    ASSERT_EQ((std::uint64_t)0x3837363534333231, int64_result[0]);
  }
}
