export module daan.i3de.lorem.importer.fs:i3d;

import "pugixml.hpp";
import daan.i3de.lorem.types;
import daan.i3de.lorem.utils;

export namespace lorem::importer::FS {

  class i3d {
  public:
    struct Entry {
      Entry() = default;
      virtual ~Entry() = default;

      std::string name = {};
      t_map_ss attributes = {};
      std::vector<Entry> children = {};

      virtual explicit operator bool() const {
        return !name.empty();
      }

      virtual std::string attr(std::string_view what) const;
    };

    i3d() = default;
    virtual ~i3d() = default;

    std::string name = {};
    std::string version = {};

    std::vector<std::string> shapes = {};
    std::map<std::string, Entry, std::less<>> content = {};

    virtual i3d& load(const t_file_ptr file_ptr);
    virtual i3d& parse(const t_file_ptr file_ptr);

    virtual Entry getEntry(pugi::xml_node node) const;
    virtual Entry find(std::string_view what) const;
  };

  // Entry methods
  std::string i3d::Entry::attr(std::string_view what) const
  {
    std::string result = {};

    if (auto entry = attributes.find(what); entry != attributes.end()) {
      result = entry->second;
    }

    return result;
  }


  // i3d methods

  // Fill this.shapes with (std::string)shapes from .i3d file
  i3d& i3d::load(const t_file_ptr file_ptr)
  {
    if (!file_ptr) {

      logger::error() << "Unable to import. Invalid directory pointer." << std::endl;
      return *this;

    }

    auto entry = parse(file_ptr).find("Shapes");

    if (entry.children.empty()) {
      shapes.push_back( entry.attr("externalShapesFile") );
    }
    else {

      for (const auto& child : entry.children) {
        shapes.push_back(child.attr("externalShapesFile"));
      }

    }

    return *this;
  }

  i3d& i3d::parse(const t_file_ptr file_ptr)
  {
    auto xml_ptr = lorem::utils::getXML(file_ptr);

    name = xml_ptr->select_node("/i3D").node().attribute("name").value();
    version = xml_ptr->select_node("/i3D").node().attribute("version").value();

    for (auto xnode : xml_ptr->select_nodes("/i3D/*")) {
      content.try_emplace(xnode.node().name(), getEntry(xnode.node()));
    }

    return *this;
  }

  i3d::Entry i3d::getEntry(pugi::xml_node node) const
  {
    Entry result = {};

    result.name = node.name();

    for (auto attr : node.attributes()) {
      result.attributes.try_emplace(attr.name(), attr.value());
    }

    for (auto child : node.children()) {
      result.children.push_back( getEntry(child) );
    }

    return result;
  }

  i3d::Entry i3d::find(std::string_view what) const
  {
    Entry result = {};

    if (auto entry = content.find(what); entry != content.end()) {
      result = entry->second;
    }

    return result;
  }

}
