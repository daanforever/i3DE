export module daan.i3de.lorem.importer.fs;

import daan.i3de.lorem.types;
import daan.i3de.lorem.scene;

export import :i3d;
export import :i3dshapes;
export import :moddesc;

export namespace lorem::importer::FS {
  class Base
  {
  public:
    Base() = default;
    virtual ~Base() = default;

    std::vector<lorem::Scene::Base> scenes;

    // Load Farming Simulator mod and import content
    virtual Base& process(const t_file_ptr dir_ptr);
  };

  Base& Base::process(const t_file_ptr dir_ptr)
  {
    lorem::Scene::Base scene = {};
    i3d i3dFile = {};
    i3dShapes i3dShps = {};
    std::vector<std::string> filenames;
    std::vector<lorem::Scene::Shape> shapes;

    const auto& modDesc = ModDesc().load(dir_ptr->find("modDesc.xml"));

    for (const auto& filename : modDesc.StoreItems) {

      filenames = i3dFile.load( dir_ptr->find(filename) ).shapes;

      for (const auto& filename : filenames) {
        shapes = i3dShps.load( dir_ptr->find(filename) ).shapes;
        scene.shapes = shapes;
      }

      if (scene) {
        scenes.push_back(scene);
      }

    }

    return *this;
  }

}

