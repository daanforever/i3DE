// i3DE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <fstream>
//#include <string>

import std;
import daan.i3de.lorem.types;
import daan.i3de.lorem.base;

#define LDEBUG lorem::logger::debug()

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  //std::string filename = "not_found";

  //const auto dir_ptr = lorem::extractor().ToMemory(filename);
  const auto simple_file_ptr = lorem::utils::load("./Tests/Samples/file2.txt");

  auto endianStream = lorem::reader::Endian(lorem::reader::Endian::Endianness::Big);
  endianStream.open(simple_file_ptr);
  auto result = endianStream.get(1);

  if (result.size() > 0) {
    LDEBUG << "Not empty" << std::endl;
    LDEBUG << std::hex << result << std::endl;

    lorem::reader::Endian().open(simple_file_ptr).get(1);
  }
  else {
    LDEBUG << "Empty array" << std::endl;
  }

  return 0;
}
