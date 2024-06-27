#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/ModDesc.cpp"

namespace ModDesc {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir = Lorem::Extractor().ToMemory(ModFileName);
  const auto modDesc = Lorem::ModDesc().process(dir);

  using ::testing::HasSubstr;

  TEST(ModDescCase, DefaultConstructor) {
    EXPECT_NO_THROW(Lorem::ModDesc());
  };

  TEST(ModDescCase, ParseNoThrow) {
    EXPECT_NO_THROW(Lorem::ModDesc().process(dir));
  };

  TEST(ModDescCase, PrepareAuthor) {
    EXPECT_EQ("FarmAndrei,Krystian", modDesc.Author);
  };

  TEST(ModDescCase, PrepareContributors) {
    EXPECT_THAT(modDesc.Contributors, HasSubstr("DiZik"));
  };

  TEST(ModDescCase, PrepareIcon) {
    EXPECT_NE(nullptr, modDesc.Icon);
    EXPECT_EQ("icon.dds", modDesc.Icon->name);
  };

  TEST(ModDescCase, PrepareVersion) {
    EXPECT_EQ("1.0.0.0", modDesc.Version);
  };

  TEST(ModDescCase, PrepareTitle) {
    EXPECT_EQ(3, modDesc.Title.size());
    EXPECT_EQ("en", modDesc.Title.find("en")->first);
    EXPECT_EQ("PLN Plows Pack", modDesc.Title.find("en")->second);
  };

  TEST(ModDescCase, PrepareDescription) {
    EXPECT_EQ(3, modDesc.Description.size());
    EXPECT_EQ("en", modDesc.Description.find("en")->first);
  };

  TEST(ModDescCase, PrepareStoreItems) {
    EXPECT_EQ(3, modDesc.StoreItems.size());
    EXPECT_NE(nullptr, modDesc.StoreItems[0]);
  }

  TEST(ModDescCase, PrepareBrands) {
    EXPECT_EQ(1, modDesc.Brands.size());
    EXPECT_EQ("PLN", modDesc.Brands[0].Name);
    EXPECT_EQ("PLN", modDesc.Brands[0].Title);
    EXPECT_NE(nullptr, modDesc.Brands[0].Image);
  }
}
