export module daan.i3de.lorem.reader:Base;

import daan.i3de.lorem.types;

export namespace lorem::reader {
  class Base
  {
  public:
    // variables
    Base* parent = nullptr;
    t_file_ptr file_ptr = nullptr;
    const std::size_t upper_bound = std::numeric_limits<std::size_t>::max();
    std::size_t position = upper_bound;

    // methods
    Base() = default;

    Base(const Base& instance) {
      file_ptr = instance.file_ptr;
      position = instance.position;
    };

    Base(Base& instance) {
      parent   = &instance;
      file_ptr = instance.file_ptr;
      position = instance.position;
    };

    virtual explicit operator bool() const;

    virtual Base& open(const t_file_ptr ptr);
    virtual Base& reset();


    template<typename T = std::byte>
    std::vector<T> get(std::size_t n);

    // Get n bytes from file
    virtual std::vector<std::byte> read(std::size_t n);
  };

  Base::operator bool() const
  {
    return file_ptr ? true : false;
  }

  Base& Base::open(const t_file_ptr ptr) {
    if (!ptr) {
      throw lorem::Error::NullPtrError();
    }

    file_ptr = ptr;
    position = 0;
    return *this;
  }

  Base& Base::reset() {
    position = 0;
    return *this;
  }

  template<typename T>
  std::vector<T> Base::get(std::size_t n) {
    if (parent) {
      return parent->get<T>(n);
    }

    if constexpr (sizeof(std::byte) > sizeof(T)) {
      throw lorem::Error::BadTypeError("Wrong type given");
    }

    auto type_size = sizeof(T);
    auto bytes = read(n * type_size);
    auto result_size = bytes.size() / type_size;

    std::vector<T> result(result_size);

    if (result_size > 0) {
      for (auto i = 0; i < result_size; ++i) {
        std::memcpy(&result[i], &bytes[i * type_size], type_size);
      }
    }

    return result;
  }

  // Get n bytes from file
  std::vector<std::byte> Base::read(std::size_t n) {

    if (parent) {
      return parent->read(n);
    }

    if (!file_ptr || position == upper_bound) {
      throw lorem::Error::UninitializedReaderError();
    }

    const auto& content = file_ptr->content;

    if (position + n > content.size()) {
      n = content.size() - position;
    }

    std::vector<std::byte> result;
    result.reserve(n);

    for (auto i = position; i < position + n; ++i) {
      result.push_back(content[i]);
    }

    position += n;

    return result;
  }
}