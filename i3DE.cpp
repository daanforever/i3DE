// i3DE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#include "Lorem/Logger.h"
#include "Lorem/Importer.h"
#include "Lorem/Convert.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  //std::string filename = "not_found";

  auto importer = Lorem::Importer(filename);
  auto converter = Lorem::Convert(importer.Content);
  LDEBUG << converter.modDesc();

  return 0;
}
