#include "pch.h"
#include "Importer.h"
#include <sstream>

Lorem::Importer::Importer(const std::string& filename) : Filename(filename) {
  auto unzip = Lorem::Extractor(Filename);
  Content = unzip.ToMemory();
   
  if (unzip.Errors.All.empty()) {
    if (Content) {
      LINFO << "Extract ok" << std::endl;
    }
    else {
      LERROR << "Empty zip content received" << std::endl;
    }
  }
  else {
    LERROR << "Errors on extract: " << std::endl << unzip.Errors.All << std::endl;
  }
}

std::string Lorem::Importer::Dump() const
{
  std::stringstream buffer = {};
  std::string tab = "";

  if (Content) {
    buffer << Filename << " content:" << std::endl;

    for (const auto& entry : Content->files) {
      if (entry->name.ends_with('/') || entry->name.find('/') == std::string::npos) {
        tab = "  ";
      }
      else {
        tab = "    ";
      }

      buffer << tab << entry->name << std::endl;
    }

    buffer << std::endl;
  }

  return buffer.str();
}

