#include "Unzip.h"
#include "Lorem/Logger.h"


Lorem::Unzip::Unzip(const std::string& file) : Filename(file)
{

}

t_zip_content Lorem::Unzip::ToMemory()
{
  t_zip_content buffer;

  if (zip_t* zip = zip_open(Filename.c_str(), 0, 'r'); zip) {
    buffer = ExtractFiles(zip);
    zip_close(zip);
  }

  return t_zip_content();
}

t_zip_content Lorem::Unzip::ExtractFiles(zip_t* zip)
{
  t_zip_entry entry = {};
  t_zip_content content = {};

  if (ssize_t zip_entries = zip_entries_total(zip); zip_entries < 0) {

    LERROR << zip_strerror((int)zip_entries);

  }
  else {

    for (int i = 0; i < zip_entries; i++) {

      if (entry = ExtractFileByIndex(zip, i); entry) {
        content.push_back(entry);
      }

    }

  }
  return t_zip_content();
}

t_zip_entry Lorem::Unzip::ExtractFileByIndex(zip_t* zip, size_t index)
{
  size_t bufsize = {};
  t_zip_entry buffer = {};

  if (int result = zip_entry_openbyindex(zip, index); result < 0) {
    LERROR << zip_strerror(result);
  }
  else {
    bufsize = zip_entry_size(zip);
    buffer = std::make_unique<std::vector<unsigned char>>(bufsize);

    zip_entry_noallocread(zip, buffer.get(), bufsize);
    zip_entry_close(zip);
  }

  return buffer;
}
