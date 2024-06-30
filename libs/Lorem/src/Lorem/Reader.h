#pragma once

#include "Lorem/Types.h"

namespace Lorem {
  class Reader
  {
  public:
    Reader() = default;
    virtual ~Reader() = default;

    Reader& open(t_file_ptr ptr) {
      file_ptr = ptr;
      position = 0;
      return *this;
    };

    Reader& reset() {
      position = 0;
      return *this;
    }



  private:
    t_file_ptr file_ptr = nullptr;
    uint32_t position = -1;
  };
}
