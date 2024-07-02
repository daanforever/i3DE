#include "pch.h"
#include "Lorem/Reader/Base.h"

namespace Lorem::Reader {
  Base& Base::open(const t_file_ptr ptr) {
    if (!ptr) {
      throw Lorem::Error::NullPtrError();
    }

    file_ptr = ptr;
    position = 0;
    return *this;
  }

  Base& Base::reset() {
    position = 0;
    return *this;
  }

  // Get n bytes from file
  std::vector<std::byte> Base::get(size_t n) {
    if (!file_ptr || position == SIZE_MAX) {
      throw Lorem::Error::UninitializedReaderError();
    }

    auto& content = file_ptr->content;
    const auto ibegin = content.begin();
    const auto iend = content.end();

    if (position + n > content.size()) {
      n = content.size() - position;
    }

    auto result = std::vector<std::byte>(
      ibegin + position,
      ibegin + position + n
    );

    position += n;

    return result;
  }

  template<typename T>
  std::vector<T> Base::get(size_t n) {
    auto bytes = get(n);
    std::vector<T> result(n);

    if (sizeof(std::byte) > sizeof(T)) {
      throw Lorem::Error::BadTypeError("Wrong type given");
    }

    for (size_t i = 0; i < bytes.size(); i++) {
      std::memcpy(&result[i], &bytes[i], sizeof(std::byte));
    }

    return result;
  }
}