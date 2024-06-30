#include "pch.h"
#include "Utils.h"

#include <filesystem>
#include <sstream>
#include <fstream>
#include <istream>

namespace Lorem {
  std::string Utils::fileWithoutExt(std::string_view name)
  {
    auto path = std::filesystem::path(name);
    return path.replace_extension().generic_string();
  }

  t_shared_xml Utils::getXML(const t_file_ptr file_ptr)
  {
    auto doc = std::make_shared<pugi::xml_document>();
    auto str = file_ptr->string();

    pugi::xml_parse_result result = doc->load_string(str.c_str());

    if (!result) {
      throw Error::UnableToParseXML(file_ptr->name);
    }

    return doc;
  }

  t_file_ptr Utils::loadFile(std::string_view filename) {
    auto file_ptr = std::make_shared<t_file>();
    file_ptr->name = filename;

    if (!std::filesystem::exists(filename)) {
      throw Lorem::Error::NotFoundError("File not found: " + std::string(filename));
    }

    auto length{ std::filesystem::file_size(filename) };
    std::ifstream file(filename.data(), std::ios::in | std::ios::binary);

    if (!file) {
      throw Lorem::Error::FileReadError("Unable to open file: " + std::string(filename));
    }

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    file_ptr->content.resize(length);

    if (!file.read(std::bit_cast<char*>(file_ptr->content.data()), length)) {
      throw Lorem::Error::FileReadError("Error reading file: " + std::string(filename));
    }

    return file_ptr;
  }
}