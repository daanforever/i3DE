#include "tests.h"

import daan.i3de.lorem.base;

namespace lorem::importer::FS {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = lorem::extractor().ToMemory(ModFileName);
  const auto modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));

  using ::testing::HasSubstr;

  TEST(ModDescTest, DefaultConstructor) {
    ASSERT_NO_THROW(ModDesc());
  };

  TEST(ModDescTest, ParseNoThrow) {
    ASSERT_NO_THROW(ModDesc().load(dir_ptr->find("modDesc.xml")));
  };

  TEST(ModDescTest, PrepareAuthor) {
    EXPECT_EQ("FarmAndrei,Krystian", modDesc.Author);
  };

  TEST(ModDescTest, PrepareContributors) {
    EXPECT_THAT(modDesc.Contributors, HasSubstr("DiZik"));
  };

  TEST(ModDescTest, PrepareIcon) {
    EXPECT_NE("", modDesc.Icon);
    EXPECT_EQ("icon.png", modDesc.Icon);
  };

  TEST(ModDescTest, PrepareVersion) {
    EXPECT_EQ("1.0.0.0", modDesc.Version);
  };

  TEST(ModDescTest, PrepareTitle) {
    EXPECT_EQ(3, modDesc.Title.size());
    EXPECT_EQ("en", modDesc.Title.find("en")->first);
    EXPECT_EQ("PLN Plows Pack", modDesc.Title.find("en")->second);
  };

  TEST(ModDescTest, PrepareDescription) {
    EXPECT_EQ(3, modDesc.Description.size());
    EXPECT_EQ("en", modDesc.Description.find("en")->first);
  };

  TEST(ModDescTest, PrepareStoreItems) {
    EXPECT_EQ(3, modDesc.StoreItems.size());
    EXPECT_NE("", modDesc.StoreItems[0]);
  }

  TEST(ModDescTest, PrepareBrands) {
    EXPECT_EQ(1, modDesc.Brands.size());
    EXPECT_EQ("PLN", modDesc.Brands[0].Name);
    EXPECT_EQ("PLN", modDesc.Brands[0].Title);
    EXPECT_NE("", modDesc.Brands[0].Image);
  }
}
