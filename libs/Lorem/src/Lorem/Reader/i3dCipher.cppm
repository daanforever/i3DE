export module daan.i3de.lorem.reader:i3dCipher;

import daan.i3de.lorem.types;
import :Base;

export namespace lorem::reader {
  class i3dCipher : public Base {
    std::uint8_t seed = 0;
  public:
    i3dCipher() = default;
    i3dCipher(Base& instance, const std::uint8_t seed);

    virtual i3dCipher& open(const t_file_ptr ptr) override;

    template<typename T>
    std::vector<T> get(size_t n);
  };

  i3dCipher::i3dCipher(Base& instance, const std::uint8_t new_seed) : 
    Base(instance), seed(new_seed) {};

  i3dCipher& i3dCipher::open(const t_file_ptr ptr)
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
  std::vector<T> i3dCipher::get(size_t n)
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