export module daan.i3de.lorem.reader:Cipher;

import daan.i3de.lorem.types;
import :Base;

export namespace lorem::reader {
  class Cipher : public Base {
    std::uint8_t seed = 0;
  public:
    Cipher() : Base() {};
    Cipher(const std::uint8_t new_seed) : Base(), seed(new_seed) {};
    Cipher(Base& instance, const std::uint8_t new_seed) : Base(instance), seed(new_seed) {};

    virtual Cipher& open(const t_file_ptr ptr) override;

    template<typename T = std::byte>
    std::vector<T> get(size_t n);
  };

  Cipher& Cipher::open(const t_file_ptr ptr)
  {
    if (parent) {
      parent->open(ptr);
    }
    else {
      Base::open(ptr);
    }

    return *this;
  }

  template<typename T>
  std::vector<T> Cipher::get(size_t n)
  {
    std::vector<T> result = {};

    if (parent) {
      result = parent->get<T>(n);
    }
    else {
      result = Base::get<T>(n);
    }

    for (auto& item : result) {
      item++;
    }

    return result;
  }
}