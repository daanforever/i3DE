export module daan.i3de.lorem.reader:Endian;

import :Base;
import daan.i3de.lorem.types;

import "endian/big_endian.hpp";
import "endian/little_endian.hpp";

export namespace lorem::reader {
  class Endian : public Base {
  public:
    Endian() : Base() {};
    Endian(lorem::Endianness new_endian) : Base(), endianness(new_endian) {};
    Endian(Base& instance, lorem::Endianness new_endian) : Base(instance), endianness(new_endian) {};
    virtual ~Endian() = default;

    lorem::Endianness endianness = lorem::Endianness::Little;

    virtual Endian& open(const t_file_ptr ptr) override;

    template<typename T = std::uint8_t>
    std::vector<T> get(size_t n);
  };

  Endian& Endian::open(const t_file_ptr ptr)
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
  std::vector<T> Endian::get(size_t n)
  {
    if constexpr(sizeof(T) < sizeof(std::byte)) {
      throw lorem::Error::BadTypeError("Given type can't be less than std::byte");
    }
    
    std::vector<T> result = (parent) ? parent->get<T>(n) : Base::get<T>(n);

    if ((result.size() > 0) && (endianness == Endianness::Big)) {
      std::vector<uint8_t> buffer(sizeof(T));

      for (auto& item : result) {
        endian::big_endian::put(item, buffer.data());
        endian::little_endian::get(item, buffer.data());
      }
    }

    return result;
  }
}