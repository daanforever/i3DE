#pragma once

#include <iostream>
#include <sstream>

#include <source_location>
#include <list>
#include <functional>

namespace Lorem {
  class Logger {
  public:
    //template<class T>
    //Lorem::Logger operator<<(T& text) const {
    //  std::cout << text;
    //  return *this;
    //};

    template<class T>
    Lorem::Logger operator<<(T text) const {
      std::cout << text;
      return *this;
    };


    //Lorem::Logger operator<<(int num) const {
    //  std::cout << num;
    //  return *this;
    //};

    Lorem::Logger operator<<(std::string text) const {
      std::cout << text;
      return *this;
    };

    Lorem::Logger operator<<(std::stringstream const& ss) const {
      std::cout << ss.str();
      return *this;
    };

    Lorem::Logger operator<<(std::ostream& (*OStreamMani)(std::ostream&)) {
      std::cout << OStreamMani;
      return *this;
    };

    Lorem::Logger operator<<(std::list<std::string>& strings) const {
      if (strings.size() > 0) {
        std::cout << std::endl;
      }

      for (const auto& text : strings) {
        std::cout << text << std::endl;
      }
      return *this;
    };

    Lorem::Logger operator<<(std::vector<std::string> strings) const {
      if (strings.size() > 0) {
        std::cout << std::endl;
      }

      for (const auto& text : strings) {
        std::cout << text << std::endl;
      }
      return *this;
    };

    Lorem::Logger operator<<(std::shared_ptr<std::string> text_ptr) const {
      std::cout << *text_ptr.get();
      return *this;
    };

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

