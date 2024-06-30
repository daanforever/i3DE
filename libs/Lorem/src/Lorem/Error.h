#pragma once

#include <list>
#include <stdexcept>
#include <string>
#include "Lorem/Logger.h"

namespace Lorem {
  class Error {
  public:

    // Empty input error
    class EmptyInputError : public std::runtime_error {
    public:
      EmptyInputError() : std::runtime_error("Empty input provided") {}
    };

    // Read file error
    class FileReadError : public std::runtime_error {
    public:
      explicit FileReadError(std::string_view message)
        : std::runtime_error(message.data()) {}
    };

    // File not found error
    class NotFoundError : public std::runtime_error {
    public:
      explicit NotFoundError(const std::string& filename)
        : std::runtime_error("File not found: " + filename) {}
    };

    // Unable to parse XML error
    class UnableToParseXML : public std::runtime_error {
    public:
      explicit UnableToParseXML(const std::string& filename)
        : std::runtime_error("Unable to parse XML: " + filename) {}
    };

    // Not implemented yet
    class NotImplemented : public std::runtime_error {
    public:
      using runtime_error::runtime_error;
    };

    // Constructor
    Error() = default;

    // Storage for errors
    std::list<std::string> All;

    // Add new error
    template<typename T>
    Error& operator<<(const T& text) {
      All.emplace_back(text);
      return *this;
    }

    void add(const std::string& message) {
      All.push_back(message);
    }

    // Add error and log it
    void logError(const std::string& message) {
      add(message);
      LERROR << message; // Assumes Logger has a static log function
    }
  };
}