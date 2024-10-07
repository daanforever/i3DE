#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem::reader::CipherTests {
  const auto bad_file_ptr = lorem::utils::load("not_found");
  const auto empty_file_ptr = lorem::utils::load("../../../../Tests/Samples/file.zip");
  const auto simple_file_ptr = lorem::utils::load("../../../../Tests/Samples/file2.txt");
  const auto mod_file_ptr = lorem::utils::load("../../../../Tests/Samples/mod.zip");

  TEST(CipherTest, ExternalValidation) {
    ASSERT_NO_THROW( Base().open(simple_file_ptr) );
  }

  TEST(CipherTest, ConstructorDefault) {
    ASSERT_NO_THROW( Cipher() );
  }

  TEST(CipherTest, ConstructorWithIntance) {
    auto base_reader = Base().open(simple_file_ptr);

    ASSERT_NO_THROW( (Cipher(base_reader, 0)) );

    ASSERT_EQ(simple_file_ptr, Cipher(base_reader, 0).file_ptr);
    ASSERT_EQ(0, Cipher(base_reader, 0).position);
    ASSERT_EQ(&base_reader, Cipher(base_reader, 0).parent);
  }

  TEST(CipherTest, open) {
    ASSERT_NO_THROW(Cipher().open(simple_file_ptr));
  }

  TEST(CipherTest, read) {
    ASSERT_NO_THROW(Cipher().open(simple_file_ptr).read(0));
  }

  TEST(CipherTest, get) {
    ASSERT_NO_THROW(Cipher().open(simple_file_ptr).get<int>(0));

    auto cipherStream = Cipher().open(simple_file_ptr);

    ASSERT_EQ(0x34333232, cipherStream.get<int>(1).front());
  }

}
