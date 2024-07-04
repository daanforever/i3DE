#include "pch.h"

import daan.i3de.lorem.base;

namespace lorem::reader {
  const std::string file = "../../../../Tests/Samples/file.txt";

  //class BaseTest {};

  TEST(BaseTest, UtilsLoadFile) {
    ASSERT_NO_THROW(lorem::utils::loadFile(file));
  };

  //const auto file_ptr = lorem::utils::loadFile(file);

  //TEST(Reader_Base, DefaultConstructor) {
  //  ASSERT_NO_THROW(Base());
  //};

  //TEST(Reader_Base, open) {
  //  ASSERT_THROW(Base().open(nullptr), lorem::Error::NullPtrError);
  //  ASSERT_NO_THROW(Base().open(file_ptr));
  //};

  //TEST(Reader_Base, get) {
  //  // file_ptr.content contains 3 bytes

  //  ASSERT_NO_THROW(Base().open(file_ptr).get(0));
  //  ASSERT_NO_THROW(Base().open(file_ptr).get(1));
  //  ASSERT_NO_THROW(Base().open(file_ptr).get(10));

  //  ASSERT_EQ(3, Base().open(file_ptr).get(10).size());

  //  auto reader = Base().open(file_ptr);

  //  // sequental read
  //  ASSERT_EQ(1, reader.get(1).size());
  //  ASSERT_EQ(2, reader.get(10).size());
  //  ASSERT_EQ(0, reader.get(10).size());

  //  // default get
  //  auto result = Base().open(file_ptr).get(10);

  //  ASSERT_EQ('1', (char)result[0]);
  //  ASSERT_EQ('2', (char)result[1]);
  //  ASSERT_EQ('3', (char)result[2]);

  //  // get<int>
  //  auto int_result = Base().open(file_ptr).get<int>(4);

  //  ASSERT_EQ(sizeof(int), int_result.size());

  //  ASSERT_EQ(49, int_result[0]);
  //  ASSERT_EQ(50, int_result[1]);
  //  ASSERT_EQ(51, int_result[2]);

  //  // get<char>
  //  auto char_result = Base().open(file_ptr).get<char>(10);

  //  ASSERT_EQ('1', char_result[0]);
  //  ASSERT_EQ('2', char_result[1]);
  //  ASSERT_EQ('3', char_result[2]);
  //}

}
