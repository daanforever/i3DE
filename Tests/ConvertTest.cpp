#include "pch.h"
#include "Lorem/Importer.h"
#include "Lorem/Convert.h"


namespace Convert {
  const std::string ZipBadFileName = "not_found";
  const std::string ZipEmptyFileName = "../../../../Tests/Samples/file.zip";
  const std::string ZipGoodFileName = "../../../../Tests/Samples/mod.zip";

  TEST(ConvertCaseName, DefaultConstructorTest) {
    auto converter = Lorem::Convert();

    EXPECT_TRUE(true);
  }

  TEST(ConvertCaseName, modDescFailTest) {
    auto importer = Lorem::Importer(ZipEmptyFileName);
    auto converter = Lorem::Convert(importer.Content);

    EXPECT_THROW(converter.modDesc(), Lorem::Error::NotFoundError);
  }

  TEST(ConvertCaseName, modDescTest) {
    auto importer = Lorem::Importer(ZipGoodFileName);
    auto converter = Lorem::Convert(importer.Content);

    EXPECT_NE("", converter.modDesc());
  }

  TEST(ConvertCaseName, modDescXmlTest) {
    auto importer = Lorem::Importer(ZipGoodFileName);
    auto converter = Lorem::Convert(importer.Content);

    EXPECT_EQ(true, converter.modDescXML());
  }

}
