export module daan.i3de.lorem.importer.fs:i3dshapes;

import daan.i3de.lorem.types;
import daan.i3de.lorem.reader;
import daan.i3de.lorem.scene;

export namespace lorem::importer::FS {
  class i3dShapes
  {
  public:

    struct Header {
      Header() = default;
      explicit Header(lorem::reader::Base& reader);

      std::uint16_t version = 0;
      std::uint8_t  seed = 0;
    };

    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr);
  };

  // i3dShapes::Header
  i3dShapes::Header::Header(lorem::reader::Base& reader)
  {
    if (!reader) {
      throw lorem::Error::UninitializedReaderError();
    }

    auto head = reader.get<uint8_t>(4);

    if (head.size() < 4) {
      throw lorem::Error::UnsupportedVersionError("Unknown version");
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
      throw lorem::Error::UnsupportedVersionError("Unknown version");
    }
  }

  // i3dShapes

  // Load .i3d.shapes file
  // Param file_ptr can't be nullptr at all
  i3dShapes& i3dShapes::load(t_file_ptr file_ptr)
  {
    if (!file_ptr) {
      throw lorem::Error::NullPtrError();
    }

    auto stream = lorem::reader::Base().open(file_ptr);
    auto header = i3dShapes::Header(stream);
    /*auto cipher = lorem::reader::i3dCipher(header.seed);

    auto cipherStream = lorem::reader::Base::Cipher(stream, cipher);
    auto binaryReader = lorem::reader::Base::Endian(cipherStream, endian);*/

    return *this;
  }
}
