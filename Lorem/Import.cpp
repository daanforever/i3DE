#include "Import.h"
#include <bit>
#include <sstream>   

Lorem::Import::Import(const std::string& filename) : Filename(filename) {
  Load();
}

void Lorem::Import::Load()
{
  std::ifstream file(Filename, std::ios::binary | std::ios::ate);

  if (!file.is_open()) {
    std::cout << "Unable to open file '" << Filename << "'" << std::endl;
    return;
  }

  std::streampos fileSize = file.tellg();
  file.seekg(0, std::ios::beg);

  Content = make_unique<std::vector<std::uint8_t>>(fileSize);
  
  file.read(std::bit_cast<char*>(Content->data()), fileSize);
  file.close();
}

std::shared_ptr<std::vector<uint8_t>> Lorem::Import::Get(const unsigned long int Pos, const unsigned long int Length)
{
  auto p1 = Content->begin() + Pos;
  auto p2 = p1 + Length;

  return std::make_shared< std::vector<uint8_t> >(p1, p2);
}

std::string Lorem::Import::Dump()
{
  std::stringstream buffer;
  buffer << "Version: " << Header.Version << std::endl;
  return buffer.str();
}
