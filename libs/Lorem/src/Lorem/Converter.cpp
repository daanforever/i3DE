#include "pch.h"

#include <sstream>
#include <filesystem>
#include "Converter.h"

Lorem::Converter::Converter(t_directory_ptr imported) : Imported(imported)
{
  if (!imported) {
    throw Lorem::Error::EmptyInputError();
  }
}
