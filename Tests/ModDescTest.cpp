#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/Importer/FS/ModDesc.h"

namespace Lorem::Importer::FS {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir_ptr = Lorem::Extractor().ToMemory(ModFileName);
  const auto modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));

  using ::testing::HasSubstr;

  TEST(ModDesc, DefaultConstructor) {
    ASSERT_NO_THROW(ModDesc());
  };

  TEST(ModDesc, ParseNoThrow) {
    ASSERT_NO_THROW(ModDesc().load(dir_ptr->find("modDesc.xml")));
  };

  TEST(ModDesc, PrepareAuthor) {
    EXPECT_EQ("FarmAndrei,Krystian", modDesc.Author);
  };

  TEST(ModDesc, PrepareContributors) {
    EXPECT_THAT(modDesc.Contributors, HasSubstr("DiZik"));
  };

  TEST(ModDesc, PrepareIcon) {
    EXPECT_NE("", modDesc.Icon);
    EXPECT_EQ("icon.png", modDesc.Icon);
  };

  TEST(ModDesc, PrepareVersion) {
    EXPECT_EQ("1.0.0.0", modDesc.Version);
  };

  TEST(ModDesc, PrepareTitle) {
    EXPECT_EQ(3, modDesc.Title.size());
    EXPECT_EQ("en", modDesc.Title.find("en")->first);
    EXPECT_EQ("PLN Plows Pack", modDesc.Title.find("en")->second);
  };

  TEST(ModDesc, PrepareDescription) {
    EXPECT_EQ(3, modDesc.Description.size());
    EXPECT_EQ("en", modDesc.Description.find("en")->first);
  };

  TEST(ModDesc, PrepareStoreItems) {
    EXPECT_EQ(3, modDesc.StoreItems.size());
    EXPECT_NE("", modDesc.StoreItems[0]);
  }

  TEST(ModDesc, PrepareBrands) {
    EXPECT_EQ(1, modDesc.Brands.size());
    EXPECT_EQ("PLN", modDesc.Brands[0].Name);
    EXPECT_EQ("PLN", modDesc.Brands[0].Title);
    EXPECT_NE("", modDesc.Brands[0].Image);
  }
}
