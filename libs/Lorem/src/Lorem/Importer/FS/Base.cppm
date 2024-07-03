export module daan.i3de.lorem.importer.fs:base;

import daan.i3de.lorem.types;
import daan.i3de.lorem.scene;

export import :i3d;
export import :i3dshapes;
export import :moddesc;

export namespace Lorem::Importer::FS {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    std::vector<Lorem::Scene::Base> scenes;

    // Load Farming Simulator mod and import content
    virtual Base& process(const t_file_ptr dir_ptr);
  };

  Base& Base::process(const t_file_ptr dir_ptr)
  {
    Lorem::Scene::Base scene = {};

    i3d i3dFile = {};
    i3dShapes i3dShps = {};
    std::vector<Lorem::Scene::Shape> shapes;

    auto modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));

    std::vector<std::string> shape_files;

    for (const auto& filename : modDesc.StoreItems) {
      shape_files = i3dFile.load(dir_ptr->find(filename)).shapes;

      for (const auto& file : shape_files) {
        shapes = i3dShps.load( dir_ptr->find(file) ).shapes;
        const auto location = std::source_location::current();
        //auto location = std::source_location::current().file_name();
        throw Lorem::Error::NotImplemented(location.file_name());
      }

    }

    return *this;
  }

}

