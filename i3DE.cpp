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

  if (importer.Content) {
    try {
      Lorem::Convert converter(importer.Content);
      auto storeItems = converter.getStoreItems();
      LDEBUG << converter.getStoreItems();
    }
    catch (const Lorem::Error::EmptyInputError& e) {
      std::cerr << "Empty input directory error: " << e.what() << std::endl;
    }
    catch (const Lorem::Error::NotFoundError& e) {
      std::cerr << "File not found: " << e.what() << std::endl;
    }
    catch (const Lorem::Error::UnableToParseXML& e) {
      std::cerr << "Unable to parse XML: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
      std::cerr << "Unknown error: " << e.what() << std::endl;
    }
  }

  return 0;
}
