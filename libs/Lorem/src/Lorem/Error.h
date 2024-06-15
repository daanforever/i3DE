#pragma once

#include <list>
#include "Lorem/Logger.h"

namespace Lorem {
  class Error {
  public:

    class EmptyInputError {};
    class NotFoundError : std::runtime_error {
    public:
      explicit NotFoundError(const std::string& message) : std::runtime_error(message) {};
      explicit NotFoundError(const char* message) : std::runtime_error(message) {};
    };

    // Constructor
    Error() = default;

    // Storage for errors
    std::list<std::string> All = {};
    
    // Add new error
    template<typename T>
    Lorem::Error operator<< (T text) {
      All.emplace_back(text);
      return *this;
    };

    void add(const std::string& message) {
      All.push_back(message);
    }

  };
}