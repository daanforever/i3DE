#include "pch.h"

#include <sstream>
#include "Convert.h"

Lorem::Convert::Convert(t_directory_ptr imported) : Imported(imported)
{
  if (!imported) {
    throw Lorem::Error::EmptyInputError();
  }
}

std::string Lorem::Convert::modDesc() const
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

pugi::xml_document Lorem::Convert::modDescXML()
{
  pugi::xml_document doc = {};
  pugi::xml_parse_result result = doc.load_string( modDesc().c_str() );

  return doc;
}

std::vector<std::string> Lorem::Convert::storeItems()
{
  std::vector<std::string> result = {};

  pugi::xpath_node_set storeItems = modDescXML().select_nodes("/Profile/Tools/Tool[@Timeout > 0]");

  return result;
}
