#include "pch.h"

#include <sstream>
#include <filesystem>
#include "Convert.h"

Lorem::Convert::Convert(t_directory_ptr imported) : Imported(imported)
{
  if (!imported) {
    throw Lorem::Error::EmptyInputError();
  }
}

std::string Lorem::Convert::getModDescRaw() const
{
  std::string result = "";
  auto modDesc = Imported->names.find("modDesc.xml");

  if (modDesc == Imported->names.end()) {
    throw Lorem::Error::NotFoundError("modDesc.xml");
  }

  for (auto content = modDesc->second->content; auto c : content) {
    result += (const char)c;
  }
  
  return result;
}

pugi::xml_document Lorem::Convert::parseModDescXML() const
{
  pugi::xml_document doc = {};
  pugi::xml_parse_result result = doc.load_string( getModDescRaw().c_str() );

  if (!result) {
    throw Lorem::Error::UnableToParseXML("modDesc.xml");
  }

  return doc;
}

std::vector<std::string> Lorem::Convert::getStoreItems() const
{
  std::vector<std::string> result = {};

  pugi::xml_document doc = parseModDescXML();
  pugi::xpath_node_set storeItems = doc.select_nodes("/modDesc/storeItems/*");

  for (pugi::xpath_node storeItem : storeItems)
  {
    auto node = storeItem.node();
    if (node) {
      auto attr = node.attribute("xmlFilename");
      if (attr) {
        result.emplace_back(attr.value());
      }
    }
  }

  return result;
}

// Function to extract the file name without extension (helper function)
std::string Lorem::Convert::getFileNameWithoutExtension(const std::string_view filename) const
{
  std::filesystem::path file(filename);
  return file.replace_extension().generic_string();
}

t_directory_ptr Lorem::Convert::convertStoreItemsToFBX()
{
  // Assuming Converted is a prepared directory structure where FBX files will be stored
  Converted = std::make_shared<t_directory>();

  std::vector<std::string> storeItems = getStoreItems();
  for (const std::string& inputFile : storeItems) {
    // Generate output path for the converted FBX file
    std::string outputFile = getFileNameWithoutExtension(inputFile) + ".fbx";

    // Store the converted file in the directory structure (implementation-specific)
    Converted->files.push_back( convertFileToFBX(inputFile, outputFile) );
  }

  return Converted;
}

t_file_ptr Lorem::Convert::convertFileToFBX(const std::string_view input, const std::string_view output) const {
  return t_file_ptr();
}
