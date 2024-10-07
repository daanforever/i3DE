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
      explicit Header(reader::Base& reader);

      std::uint16_t version = 0;
      std::uint8_t  seed = 0;
      Endianness    endian{Little};
    };

    i3dShapes() = default;
    virtual ~i3dShapes() = default;

    std::vector<lorem::Scene::Shape> shapes;

    // Load .i3d.shapes file and import content
    i3dShapes& load(t_file_ptr file_ptr);
  };

  // i3dShapes::Header
  i3dShapes::Header::Header(reader::Base& reader)
  {
    constexpr std::uint8_t VERSION_2 = 2;
    constexpr std::uint8_t VERSION_3 = 3;
    constexpr std::uint8_t VERSION_4 = 4;

    if (!reader) {
      throw lorem::Error::UninitializedReaderError();
    }

    auto head = reader.get<std::uint8_t>(4);

    if (head.size() < 4) {
      throw lorem::Error::UnsupportedVersionError("Unknown version");
    }

    if (head[0] >= VERSION_4) {

      version = head[0];
      seed = head[2];

    }
    else if (head[3] == VERSION_2 || head[3] == VERSION_3) {

      version = head[3];
      seed = head[1];

    }
    else {
      throw lorem::Error::UnsupportedVersionError("Unknown version: " + std::to_string(head[0]));
    }

    endian = version >= VERSION_4 ? Endianness::Little : Endianness::Big;
  }

  // i3dShapes

  // Load .i3d.shapes file
  // Param file_ptr can't be nullptr at all
  i3dShapes& i3dShapes::load(t_file_ptr file_ptr)
  {
    if (!file_ptr) {
      throw lorem::Error::NullPtrError();
    }

    auto& sample = lorem::reader::Base().open(file_ptr);
    auto  header = i3dShapes::Header(sample);
    auto  cipher = lorem::reader::Cipher(sample, header.seed);
    auto  stream = lorem::reader::Endian(cipher, header.endian);

    return *this;
  }
}
