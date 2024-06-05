#include "pch.h"
#include <filesystem>

#include "Unzip.h"
#include "Lorem/Logger.h"

Lorem::Unzip::Unzip(const std::string& file) : Filename(file) {}

std::unique_ptr<t_directory> Lorem::Unzip::ToMemory()
{
  t_directory buffer;
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

  return std::make_unique<t_directory>(buffer);
}

t_directory Lorem::Unzip::ExtractFiles(zip_t* zip)
{
  t_file entry = {};
  t_directory content = {};

  if (ssize_t zip_entries = zip_entries_total(zip); zip_entries < 0) {

    Errors << zip_strerror((int)zip_entries);

  }
  else {

    for (int i = 0; i < zip_entries; i++) {

      entry = ExtractFileByIndex(zip, i);
      content.files.push_back( entry );
      content.names.try_emplace(entry.name, &entry);

    }

  }
  return content;
}

t_file Lorem::Unzip::ExtractFileByIndex(zip_t* zip, size_t index)
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

  return entry;
}
