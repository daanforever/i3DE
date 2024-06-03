#include <filesystem>

#include "Unzip.h"
#include "Lorem/Logger.h"

Lorem::Unzip::Unzip(const std::string& file) : Filename(file) {}

t_zip_content Lorem::Unzip::ToMemory()
{
  t_zip_content buffer;
  int errnum = 0;

  if (zip_t* zip = zip_openwitherror(Filename.c_str(), 0, 'r', &errnum); zip) {
    buffer = ExtractFiles(zip);
    zip_close(zip);
  }
  else {
    
    std::string cwd{ std::filesystem::current_path().generic_string() };
    Errors << "Error occuried while openning " << Filename << zip_strerror(errnum);
    Errors << "Current path is " << cwd;
  }

  return buffer;
}

t_zip_content Lorem::Unzip::ExtractFiles(zip_t* zip)
{
  t_zip_entry entry = {};
  t_zip_content content = {};

  if (ssize_t zip_entries = zip_entries_total(zip); zip_entries < 0) {

    Errors << zip_strerror((int)zip_entries);

  }
  else {

    for (int i = 0; i < zip_entries; i++) {

      if (entry = ExtractFileByIndex(zip, i); entry) {
        content.push_back(entry);
      }

    }

  }
  return content;
}

t_zip_entry Lorem::Unzip::ExtractFileByIndex(zip_t* zip, size_t index)
{
  void* buffer = nullptr;
  size_t bufsize = 0;

  if (int err = zip_entry_openbyindex(zip, index); err < 0) {
    Errors << zip_strerror(err);
  }
  else {
    bufsize = zip_entry_size(zip);

    zip_entry_read(zip, &buffer, &bufsize);
    zip_entry_close(zip);
  }

  return std::make_shared<std::vector<unsigned char>>((unsigned char*)buffer, (unsigned char*)buffer + bufsize);
}
