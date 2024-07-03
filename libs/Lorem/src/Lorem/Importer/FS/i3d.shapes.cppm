export module daan.i3de.lorem.importer.fs:i3dshapes;

import daan.i3de.lorem.types;
import daan.i3de.lorem.reader;
import daan.i3de.lorem.scene;

namespace Lorem::Importer::FS {
  class i3dShapes
  {
  public:

    struct Header {
      Header() = default;
      explicit Header(Lorem::Reader::Base& reader);

      std::uint16_t version = 0;
      std::uint8_t  seed = 0;
    };

    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<Lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr);
  };

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
    if (!file_ptr) {
      throw Lorem::Error::NullPtrError();
    }

    auto stream = Lorem::Reader::Base().open(file_ptr);
    auto header = i3dShapes::Header(stream);
    /*auto cipher = I3DCipher(header.seed);

    auto cipherStream = Lorem::Reader::Base::Cipher(stream, cipher);
    auto binaryReader = Lorem::Reader::Base::Endian(cipherStream, endian);*/

    return *this;
  }
}
