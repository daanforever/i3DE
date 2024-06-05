#include "pch.h"
#include "Importer.h"
#include <sstream>

Lorem::Importer::Importer(const std::string& filename) : Filename(filename) {
  auto unzip = Lorem::Unzip(Filename);
  Content = unzip.ToMemory();
   
  if (unzip.Errors.All.empty()) {
    LINFO << "Extract ok" << std::endl;
  }
  else {
    LERROR << "Errors on extract: " << unzip.Errors.All;
  }
}

std::string Lorem::Importer::Dump() const
{
  std::stringstream buffer = {};
  std::string tab = "";

  buffer << Filename << " content:" << std::endl;
  
  for (const auto& entry : Content->files) {
    if (entry.name.ends_with('/') || entry.name.find('/') == std::string::npos) {
      tab = "  ";
    }
    else {
      tab = "    ";
    }

    buffer << tab << entry.name << std::endl;
  }

  buffer << std::endl;

  return buffer.str();
}

