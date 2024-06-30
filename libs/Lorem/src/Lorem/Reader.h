#pragma once

#include <vector>

#include "endian/stream_reader.hpp"

#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class Reader
  {
  public:
    Reader() = default;
    virtual ~Reader() = default;

    Reader& open(const t_file_ptr ptr) {
      if (!ptr) {
        throw Lorem::Error::NullPtrError();
      }

      file_ptr = ptr;
      position = 0;
      return *this;
    };

    Reader& reset() {
      position = 0;
      return *this;
    }

    std::vector<std::byte> get(size_t size) {
      if (!file_ptr || position == SIZE_MAX) {
        throw Lorem::Error::UninitializedReaderError("Use Reader().open(file_ptr) first");
      }

      const auto& content = file_ptr->content;
      const auto ibegin = content.begin();
      const auto iend = content.end();

      if (position + size > content.size()) {
        size = content.size() - position;
      }

      auto result = std::vector<std::byte>(
        ibegin + position, 
        ibegin + position + size
      );

      position += size;

      return result;
    }

  private:
    t_file_ptr file_ptr = nullptr;
    size_t position = SIZE_MAX;
  };
}
