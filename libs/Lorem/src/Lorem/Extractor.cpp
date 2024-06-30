#include "pch.h"
#include <filesystem>

#include "Lorem/Extractor.h"

namespace Lorem {
    t_file_ptr Extractor::ToMemory(std::string_view filename)
  {
    t_file_ptr ptr = {};
    int errnum = 0;

    if (zip_t* zip = zip_openwitherror(filename.data(), 0, 'r', &errnum); zip) {
      ptr = ExtractFiles(zip);
      zip_close(zip);
    }
    else {

      std::string cwd{ std::filesystem::current_path().generic_string() };
      throw Lorem::Error::FileReadError(
        cwd + "/" + filename.data() + ": " + zip_strerror(errnum)
      );
    }

    return ptr;
  }

  t_file_ptr Extractor::ExtractFiles(zip_t* zip)
  {
    auto dir_ptr = std::make_shared<t_file>("/");
    t_file_ptr file_ptr = {};

    if (ssize_t zip_entries = zip_entries_total(zip); zip_entries < 0) {

      throw Lorem::Error::FileReadError(zip_strerror((int)zip_entries));

    }
    else {

      for (int i = 0; i < zip_entries; i++) {

        file_ptr = ExtractFileByIndex(zip, i);
        dir_ptr->add(file_ptr);

      }

    }
    return dir_ptr;
  }

  t_file_ptr Extractor::ExtractFileByIndex(zip_t* zip, size_t index)
  {
    size_t bufsize = 0;
    t_file entry = {};

    if (int err = zip_entry_openbyindex(zip, index); err < 0) {
      throw Lorem::Error::FileReadError(zip_strerror(err));
    }
    else {
      bufsize = zip_entry_size(zip);

      entry.name = zip_entry_name(zip);

      if (zip_entry_isdir(zip)) {
        entry.content = {};
        entry.isDirectory = true;
      }
      else {
        void* buffer = nullptr;
        if (zip_entry_read(zip, &buffer, &bufsize) < 0) {
          throw Lorem::Error::EmptyInputError();
        }
        entry.content.assign((std::byte*)buffer, (std::byte*)buffer + bufsize);
        entry.isDirectory = false;
      }

      zip_entry_close(zip);
    }

    return std::make_shared<t_file>(entry);
  }

}
