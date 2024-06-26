// i3DE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#include "Lorem/Logger.h"
#include "Lorem/Extractor.h"
#include "Lorem/Importer.h"
#include "Lorem/Converter.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  //std::string filename = "not_found";

  const auto dir = Lorem::Extractor(filename).ToMemory();
  //const auto mod = Lorem::ModDesc().parse(dir);

  LDEBUG << "Filename: " << filename << std::endl;
  LDEBUG << Lorem::ModDesc().parse(dir);

  return 0;
}
