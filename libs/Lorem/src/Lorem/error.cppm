export module daan.i3de.lorem.error;

import std;
import daan.i3de.lorem.logger;

export namespace lorem {
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
    class XMLParseError : public std::runtime_error {
    public:
      explicit XMLParseError(const std::string& filename)
        : std::runtime_error("Unable to parse XML: " + filename) {}
    };

    // Not implemented yet
    class NotImplemented : public std::runtime_error {
    public:
      using runtime_error::runtime_error;
    };

    class UninitializedReaderError : public std::runtime_error {
    public:
      explicit UninitializedReaderError() :
        std::runtime_error("Use .open(file_ptr) first") {}
    };

    class NullPtrError : public std::runtime_error {
    public:
      explicit NullPtrError() : 
        std::runtime_error("nullptr is not valid value") {}
    };

    class UnsupportedVersionError : public std::runtime_error {
    public:
      using runtime_error::runtime_error;
    };

    class BadTypeError : public std::runtime_error {
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
      logger::error() << message;
    }
  };
}