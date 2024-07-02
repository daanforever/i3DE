#include "pch.h"
#include "Lorem/Importer/FS/i3d.shapes.h"

namespace Lorem::Importer::FS {
  // i3dShapes::Header
  i3dShapes::Header::Header(Lorem::Reader::Base& reader)
  {
    if (!reader) {
      throw Lorem::Error::UninitializedReaderError();
    }

    auto head = reader.get<uint8_t>(4);

    if (head.size() < 4) {
      throw Lorem::Error::UnsupportedVersionError("Unknown version");
    }

    if (head[0] >= 4) {
      version = head[0];
      seed = head[2];
    }
    else if (head[3] == 2 || head[3] == 3) {
      version = head[3];
      seed = head[1];
    }
    else {
      throw Lorem::Error::UnsupportedVersionError("Unknown version");
    }
  }

  // i3dShapes

  // Load .i3d.shapes file
  // Param file_ptr can't be nullptr at all
  i3dShapes& i3dShapes::load(t_file_ptr file_ptr)
  {
    assert(file_ptr);

    auto stream = Lorem::Reader::Base().open(file_ptr);
    auto header = i3dShapes::Header(stream);
    /*auto cipher = I3DCipher(header.seed);

    auto cipherStream = Lorem::Reader::Base::Cipher(stream, cipher);
    auto binaryReader = Lorem::Reader::Base::Endian(cipherStream, endian);*/

    return *this;
  }
}
