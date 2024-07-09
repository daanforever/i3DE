#include "tests.cppm"

import daan.i3de.lorem.base;

namespace lorem::reader::i3dCipherTests {
  const auto bad_file_ptr = lorem::utils::load("not_found");
  const auto empty_file_ptr = lorem::utils::load("../../../../Tests/Samples/file.zip");
  const auto simple_file_ptr = lorem::utils::load("../../../../Tests/Samples/file2.txt");
  const auto mod_file_ptr = lorem::utils::load("../../../../Tests/Samples/mod.zip");

  TEST(i3dCipherTest, ExternalValidation) {
    ASSERT_NO_THROW( Base().open(simple_file_ptr) );
  }

  TEST(i3dCipherTest, ConstructorDefault) {
    ASSERT_NO_THROW( i3dCipher() );
  }

  TEST(i3dCipherTest, ConstructorWithIntance) {
    auto base_reader = Base().open(simple_file_ptr);

    ASSERT_NO_THROW( (i3dCipher(base_reader, 0)) );

    ASSERT_EQ(simple_file_ptr, i3dCipher(base_reader, 0).file_ptr);
    ASSERT_EQ(0, i3dCipher(base_reader, 0).position);
    ASSERT_EQ(&base_reader, i3dCipher(base_reader, 0).parent);
  }

  TEST(i3dCipherTest, open) {
    ASSERT_NO_THROW(i3dCipher().open(simple_file_ptr));
  }

  TEST(i3dCipherTest, read) {
    ASSERT_NO_THROW(i3dCipher().open(simple_file_ptr).read(0));
  }

  TEST(i3dCipherTest, get) {
    ASSERT_NO_THROW(i3dCipher().open(simple_file_ptr).get<int>(0));

    auto cipherStream = i3dCipher().open(simple_file_ptr);

    ASSERT_EQ(0x34333232, cipherStream.get<int>(1).front());
  }

}
