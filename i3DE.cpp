// i3DE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <fstream>
//#include <string>

import std;
import daan.i3de.lorem.types;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  //std::string filename = "not_found";

  //const auto dir_ptr = Lorem::Extractor().ToMemory(filename);
  ////const auto mod = Lorem::ModDesc().parse(dir);

  //LDEBUG << "Filename: " << filename << std::endl;
  ////LDEBUG << Lorem::Importer().importMod(dir_ptr) << std::endl;
  //LDEBUG << "First file: " << dir_ptr->name << std::endl;
  //LDEBUG << "Files count: " << dir_ptr->index.size() << std::endl;
  //Lorem::Importer::FS::Base().process(dir_ptr);

  return 0;
}
