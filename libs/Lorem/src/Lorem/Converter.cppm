export module daan.i3de.lorem.Converter;

import daan.i3de.lorem.types;

namespace Lorem {
  export class Converter
  {

  public:
    Converter() = default;
    explicit Converter(t_file_ptr imported);

  private:
    t_file_ptr Imported = {};
    t_file_ptr Converted = {};

  public:
  };

  Converter::Converter(t_file_ptr imported) : Imported(imported)
  {
    if (!imported) {
      throw Lorem::Error::EmptyInputError();
    }
  }
}

