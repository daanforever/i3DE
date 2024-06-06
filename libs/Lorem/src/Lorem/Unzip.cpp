#include "pch.h"
#include <filesystem>

#include "Unzip.h"
#include "Lorem/Logger.h"

Lorem::Unzip::Unzip(const std::string& file) : Filename(file) {}

t_directory_ptr Lorem::Unzip::ToMemory()
{
  t_directory_ptr ptr;
  int errnum = 0;

  if (zip_t* zip = zip_openwitherror(Filename.c_str(), 0, 'r', &errnum); zip) {
    ptr = ExtractFiles(zip);
    zip_close(zip);
  }
  else {
    
    std::string cwd{ std::filesystem::current_path().generic_string() };
    Errors << "Error occuried while openning " << Filename << zip_strerror(errnum);
    Errors << "Current path is " << cwd;
  }

  return ptr;
}

t_directory_ptr Lorem::Unzip::ExtractFiles(zip_t* zip)
{
  t_file_ptr entry_ptr = {};
  t_directory content = {};

  if (ssize_t zip_entries = zip_entries_total(zip); zip_entries < 0) {

    Errors << zip_strerror((int)zip_entries);

  }
  else {

    for (int i = 0; i < zip_entries; i++) {

      entry_ptr = ExtractFileByIndex(zip, i);
      content.files.push_back(entry_ptr);
      content.names.try_emplace(entry_ptr->name, entry_ptr);

    }

  }
  return std::make_shared<t_directory>(content);
}

t_file_ptr Lorem::Unzip::ExtractFileByIndex(zip_t* zip, size_t index)
{
  void* buffer = nullptr;
  size_t bufsize = 0;
  t_file entry = {};

  if (int err = zip_entry_openbyindex(zip, index); err < 0) {
    Errors << zip_strerror(err);
  }
  else {
    bufsize = zip_entry_size(zip);

    zip_entry_read(zip, &buffer, &bufsize);
    entry.content.assign((unsigned char*)buffer, (unsigned char*)buffer + bufsize);
    entry.name = zip_entry_name(zip);
    entry.directory = zip_entry_isdir(zip);

    zip_entry_close(zip);
  }

  return std::make_shared<t_file>(entry);
}
