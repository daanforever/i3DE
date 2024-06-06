#include "pch.h"

#include <sstream>
#include "Convert.h"

std::shared_ptr<std::string> Lorem::Convert::modDesc() const
{
  std::string result = "";

  if (Imported) {
    for (auto content = Imported->names.find("modDesc.xml")->second->content; auto c : content) {
      result += (const char)c;
    }
  }

  return std::make_shared<std::string>(result);
}
