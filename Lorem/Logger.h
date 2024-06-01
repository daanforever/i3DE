#pragma once

#include <iostream>
#include <source_location>

namespace Lorem {
  class Logger {
  public:
    Lorem::Logger operator<< (const char* text) const {
      std::cout << text << std::endl;
      return *this;
    };

    Lorem::Logger position(std::source_location location = std::source_location::current()) const {
      std::cout << "[" << location.file_name() << ":" << location.line() << "] ";
      return *this;
    }

    Lorem::Logger prefix(const std::string& level) const {
      std::cout << "[" << level << "] ";
      return *this;
    }
  };
}

#ifndef LOREM_LOGGER
#define LOREM_LOGGER
const auto LoremLogger = std::make_unique<Lorem::Logger>();
#endif // !LOREM_LOGGER

#ifndef LDEBUG
#define LDEBUG LoremLogger->prefix("DEBUG")
#endif

#ifndef LINFO
#define LINFO LoremLogger->prefix("INFO")
#endif

#ifndef LWARNING
#define LWARNING LoremLogger->prefix("WARNING")
#endif

#ifndef LERROR
#define LERROR LoremLogger->prefix("ERROR")
#endif

