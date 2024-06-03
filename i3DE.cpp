// i3DE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#include "Lorem/Logger.h"
#include "Lorem/Import.h"
#include "Lorem/Unzip.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  
  const auto unzip = std::make_unique<Lorem::Unzip>(argv[1]);
  auto a = unzip->ToMemory();

  if (unzip->Errors.All.empty()) {
    LINFO << "Extract ok";
  }
  else {
    LERROR << "Errors on extract: " << unzip->Errors.All;
  }

  // @SuppressWarnings("cpp:S125")
  //std::string filename = argv[1];
  //auto Import = Lorem::Import(filename);
  //std::cout << Import.Dump() << std::endl;

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
