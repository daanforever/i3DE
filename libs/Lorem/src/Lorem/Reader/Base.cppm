export module daan.i3de.lorem.reader:Base;

import daan.i3de.lorem.types;

export namespace lorem::reader {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    Base& open(const t_file_ptr ptr);

    explicit operator bool() const;

    Base& reset();

    // Get n bytes from file
    std::vector<std::byte> get(size_t n);

    template<typename T>
    std::vector<T> get(size_t n);

  private:
    t_file_ptr file_ptr = nullptr;
    size_t position = -1;
  };

  Base& Base::open(const t_file_ptr ptr) {
    if (!ptr) {
      throw lorem::Error::NullPtrError();
    }

    file_ptr = ptr;
    position = 0;
    return *this;
  }

  Base::operator bool() const
  {
    return file_ptr ? true : false;
  }

  Base& Base::reset() {
    position = 0;
    return *this;
  }

  // Get n bytes from file
  std::vector<std::byte> Base::get(size_t n) {
    if (!file_ptr || position == -1) {
      throw lorem::Error::UninitializedReaderError();
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
      throw lorem::Error::BadTypeError("Wrong type given");
    }

    for (size_t i = 0; i < bytes.size(); i++) {
      std::memcpy(&result[i], &bytes[i], sizeof(std::byte));
    }

    return result;
  }
}