export module daan.i3de.lorem.converter;

import daan.i3de.lorem.types;

namespace lorem {
  export class Converter
  {
  public:
    Converter() = default;
    explicit Converter(t_file_ptr imported);

  private:
    t_file_ptr imported = {};
    t_file_ptr converted = {};

  public:
  };

  Converter::Converter(t_file_ptr file_ptr) : imported(file_ptr)
  {
    if (!imported) {
      throw lorem::Error::EmptyInputError();
    }
  }
}

