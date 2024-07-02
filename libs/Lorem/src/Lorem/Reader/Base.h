#pragma once

#include <vector>
#include <bit>

#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem::Reader {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    Base& open(const t_file_ptr ptr);

    explicit operator bool() const {
      return file_ptr ? true : false;
    }

    Base& reset();

    // Get n bytes from file
    std::vector<std::byte> get(size_t n);

    template<typename T>
    std::vector<T> get(size_t n);

  private:
    t_file_ptr file_ptr = nullptr;
    size_t position = SIZE_MAX;
  };
}
