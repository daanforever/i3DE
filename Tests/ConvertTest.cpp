#include "pch.h"
#include "Lorem/Importer.h"
#include "Lorem/Converter.h"


namespace Convert {
  const std::string ZipBadFileName = "not_found";
  const std::string ZipEmptyFileName = "../../../../Tests/Samples/file.zip";
  const std::string ZipGoodFileName = "../../../../Tests/Samples/mod.zip";

  TEST(ConvertCaseName, DefaultConstructorTest) {
    auto converter = Lorem::Converter();

    EXPECT_TRUE(true);
  }

  TEST(ConvertCaseName, modDescFailTest) {
    auto importer = Lorem::Importer(ZipEmptyFileName);
    auto converter = Lorem::Converter(importer.Content);

    EXPECT_THROW(converter.getModDescRaw(), Lorem::Error::NotFoundError);
  }

  TEST(ConvertCaseName, modDescTest) {
    auto importer = Lorem::Importer(ZipGoodFileName);
    auto converter = Lorem::Converter(importer.Content);

    EXPECT_NE("", converter.getModDescRaw());
  }

  TEST(ConvertCaseName, modDescXmlTest) {
    auto importer = Lorem::Importer(ZipGoodFileName);
    auto converter = Lorem::Converter(importer.Content);

    EXPECT_NO_THROW(converter.parseModDescXML());
  }

  TEST(ConvertCaseName, getStoreItems) {
    auto importer = Lorem::Importer(ZipGoodFileName);
    auto converter = Lorem::Converter(importer.Content);

    EXPECT_EQ(3, converter.getStoreItems().size());
  }

}
