#include "pch.h"
#include "Lorem/Extractor.h"
#include "Lorem/ModDesc.cpp"

namespace ModDesc {
  const std::string ModFileName = "../../../../Tests/Samples/mod.zip";
  const auto dir = Lorem::Extractor(ModFileName).ToMemory();
  const auto modDesc = Lorem::ModDesc().parse(dir);

  using ::testing::HasSubstr;

  TEST(DefaultCase, DefaultConstructor) {
    EXPECT_NO_THROW(Lorem::ModDesc());
  };

  TEST(DefaultCase, ParseNoThrow) {
    EXPECT_NO_THROW(Lorem::ModDesc().parse(dir));
  };

  TEST(DefaultCase, PrepareAuthor) {
    EXPECT_EQ("FarmAndrei,Krystian", modDesc.Author);
  };

  TEST(DefaultCase, PrepareContributors) {
    EXPECT_THAT(modDesc.Contributors, HasSubstr("DiZik"));
  };

  TEST(DefaultCase, PrepareIcon) {
    EXPECT_NE(nullptr, modDesc.Icon);
    EXPECT_EQ("icon.dds", modDesc.Icon->name);
  };

  TEST(DefaultCase, PrepareVersion) {
    EXPECT_EQ("1.0.0.0", modDesc.Version);
  };

  TEST(DefaultCase, PrepareTitle) {
    EXPECT_EQ(3, modDesc.Title.size());
    EXPECT_EQ("en", modDesc.Title.find("en")->first);
    EXPECT_EQ("PLN Plows Pack", modDesc.Title.find("en")->second);
  };

  TEST(DefaultCase, PrepareDescription) {
    EXPECT_EQ(3, modDesc.Description.size());
    EXPECT_EQ("en", modDesc.Description.find("en")->first);
  };

  TEST(DefaultCase, PrepareStoreItems) {
    EXPECT_EQ(3, modDesc.StoreItems.size());
    EXPECT_NE(nullptr, modDesc.StoreItems[0]);
  }

  TEST(DefaultCase, PrepareBrands) {
    EXPECT_EQ(1, modDesc.Brands.size());
    EXPECT_EQ("PLN", modDesc.Brands[0].Name);
    EXPECT_EQ("PLN", modDesc.Brands[0].Title);
    EXPECT_NE(nullptr, modDesc.Brands[0].Image);
  }
}
