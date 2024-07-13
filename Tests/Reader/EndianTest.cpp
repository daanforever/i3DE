#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem::reader::EndianTests {
  const auto bad_file_ptr = lorem::utils::load("not_found");
  const auto empty_file_ptr = lorem::utils::load("../../../../Tests/Samples/file.zip");
  const auto simple_file_ptr = lorem::utils::load("../../../../Tests/Samples/file2.txt");
  const auto mod_file_ptr = lorem::utils::load("../../../../Tests/Samples/mod.zip");

  TEST(EndianTest, ExternalValidation) {
    ASSERT_NO_THROW( Base().open(simple_file_ptr) );
  }

  TEST(EndianTest, ConstructorDefault) {
    ASSERT_NO_THROW( Endian() );
  }

  void ConstructorWithIntance(Endianness endian) {
    auto& base_reader = Base().open(simple_file_ptr);

    ASSERT_NO_THROW(Endian(base_reader, endian));

    auto endian_reader = Endian(base_reader, endian);

    ASSERT_EQ(simple_file_ptr, endian_reader.file_ptr);

    ASSERT_EQ(0, endian_reader.position);
    ASSERT_EQ(&base_reader, endian_reader.parent);
  }

  TEST(EndianTest, ConstructorEndian) {
    {
      SCOPED_TRACE("Little endian");
      ConstructorWithIntance(Endianness::Little);
    }
    {
      SCOPED_TRACE("Big endian");
      ConstructorWithIntance(Endianness::Big);
    }
  }

  TEST(EndianTest, open) {
    ASSERT_NO_THROW(Endian().open(simple_file_ptr));
  }

  TEST(EndianTest, read) {
    ASSERT_NO_THROW(Endian().open(simple_file_ptr).read(0));
  }

  TEST(EndianTest, getNegative) {
    ASSERT_NO_THROW((void)Endian().open(simple_file_ptr).get((size_t)-1).size());
    ASSERT_EQ(11, Endian().open(simple_file_ptr).get((size_t)-1).size());
  }

  TEST(EndianTest, getZero) {
    ASSERT_NO_THROW((void)Endian().open(simple_file_ptr).get(0).size());
    ASSERT_EQ(0, Endian().open(simple_file_ptr).get(0).size());
  }

  TEST(EndianTest, getFloat) {
    ASSERT_NO_THROW((void)Endian().open(simple_file_ptr).get((size_t)0.1).size());
    ASSERT_EQ(0, Endian().open(simple_file_ptr).get((size_t)0.1).size());
  }

  TEST(EndianTest, getOne) {
    auto result = Endian().open(simple_file_ptr).get(1);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(49, (int)result.front());
  }

  TEST(EndianTest, get100) {
    ASSERT_NO_THROW(Endian().open(simple_file_ptr).get(100));
    auto result = Endian().open(simple_file_ptr).get(100);
    ASSERT_EQ(11, result.size());
    ASSERT_EQ(49, (int)result.front());
  }

  template<typename T>
  void getNum1Testing(T value) {
    ASSERT_NO_THROW(Endian(Endianness::Big).open(simple_file_ptr).get<T>(1));

    auto endianStream = Endian(Endianness::Big).open(simple_file_ptr);

    ASSERT_EQ(1, endianStream.get<T>(1).size());
    ASSERT_NO_THROW(endianStream.reset());
    EXPECT_PRED_FORMAT2(AssertHexEQ, value, endianStream.get<T>(1).front());
  }

  TEST(EndianTest, get) {
    {
      SCOPED_TRACE("int");
      getNum1Testing<int>(0x31323334);
    }

    {
      SCOPED_TRACE("uint8_t");
      getNum1Testing<uint8_t>(0x31);
    }

    {
      SCOPED_TRACE("uint16_t");
      getNum1Testing<uint16_t>(0x3132);
    }

    {
      SCOPED_TRACE("uint32_t");
      getNum1Testing<uint32_t>(0x31323334);
    }

    {
      SCOPED_TRACE("uint64_t");
      getNum1Testing<uint64_t>(0x3132333435363738);
    }

    {
      SCOPED_TRACE("float");
      getNum1Testing<float>((float)0x1.6466680000000p-29);
    }
  }


  TEST(EndianTest, getBigEndianInt64) {
    ASSERT_NO_THROW(Endian(Endianness::Big).open(simple_file_ptr).get<std::uint64_t>(1));

    auto endianStream = Endian(Endianness::Big).open(simple_file_ptr);

    ASSERT_EQ((std::uint64_t)0x3132333435363738, endianStream.get<std::uint64_t>(1).front());
  }
  
  TEST(EndianTest, getBigEndianFloat) {
    ASSERT_NO_THROW(Endian(Endianness::Big).open(simple_file_ptr).get<float>(1));

    auto endianStream = Endian(Endianness::Big).open(simple_file_ptr);

    ASSERT_EQ((float)0x1.6466680000000p-29, endianStream.get<float>(1).front());
  }

}
