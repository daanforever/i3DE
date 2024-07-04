export module daan.i3de.lorem.utils;

import std;
import daan.i3de.lorem.types;
import daan.i3de.lorem.xml;

export namespace lorem {
  class utils
  {
  public:
    static std::string fileWithoutExt(std::string_view filename);
    static t_shared_xml getXML(const t_file_ptr file_ptr);
    static t_file_ptr loadFile(std::string_view filename);
  };

  std::string utils::fileWithoutExt(std::string_view name)
  {
    auto path = std::filesystem::path(name);
    return path.replace_extension().generic_string();
  }

  t_shared_xml utils::getXML(const t_file_ptr file_ptr)
  {
    auto doc = std::make_shared<pugi::xml_document>();
    auto str = file_ptr->string();

    pugi::xml_parse_result result = doc->load_string(str.c_str());

    if (!result) {
      throw Error::XMLParseError(file_ptr->name);
    }

    return doc;
  }

  t_file_ptr utils::loadFile(std::string_view filename) {
    auto file_ptr = std::make_shared<t_file>();
    file_ptr->name = filename;

    if (!std::filesystem::exists(filename)) {
      throw lorem::Error::NotFoundError("File not found: " + std::string(filename));
    }

    auto length{ std::filesystem::file_size(filename) };
    std::ifstream file(filename.data(), std::ios::in | std::ios::binary);

    if (!file) {
      throw lorem::Error::FileReadError("Unable to open file: " + std::string(filename));
    }

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    file_ptr->content.resize(length);

    if (!file.read(std::bit_cast<char*>(file_ptr->content.data()), length)) {
      throw lorem::Error::FileReadError("Error reading file: " + std::string(filename));
    }

    return file_ptr;
  }
}