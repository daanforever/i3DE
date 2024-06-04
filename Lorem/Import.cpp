#include <sstream>
#include "Import.h"

Lorem::Import::Import(const std::string& filename) : Filename(filename) {
  //@SuppressWarnings("cpp:S125")
  const auto unzip = std::make_unique<Lorem::Unzip>(Filename);
  Content = unzip->ToMemory();
   
  if (unzip->Errors.All.empty()) {
    LINFO << "Extract ok" << std::endl;
  }
  else {
    LERROR << "Errors on extract: " << unzip->Errors.All;
  }

#ifndef NDEBUG
  DebugPrint();
#endif // !NDEBUG

}

void Lorem::Import::DebugPrint() const
{
  LDEBUG << DumpZipContent();
}

std::stringstream Lorem::Import::DumpZipContent() const
{
  std::stringstream buffer;

  buffer << Filename << " content:" << std::endl;
  std::string tab = "";

  for (auto& entry : Content) {
    if (entry.filename.ends_with('/') || entry.filename.find('/') == std::string::npos) {
      tab = "  ";
    }
    else {
      tab = "    ";
    }

    buffer << tab << entry.filename << std::endl << std::endl;
  }

  return buffer;
}

std::string Lorem::Import::Dump()
{
  std::stringstream buffer;
  buffer << "Version: " << Header.Version << std::endl;
  return buffer.str();
}
