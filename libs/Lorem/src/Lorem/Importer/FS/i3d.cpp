#include "pch.h"
#include "Lorem/Importer/FS/i3d.h"

namespace Lorem::Importer::FS {

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

      LERROR << "Unable to import. Invalid directory pointer." << std::endl;
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
    auto xml_ptr = Lorem::Utils::getXML(file_ptr);

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
