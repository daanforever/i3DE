#include "pch.h"
#include "Lorem/Importer/FS/i3d.h"

namespace Lorem::Importer::FS {
  I3D& I3D::load(const t_file_ptr dir_ptr, const std::string& filename)
  {
    load(dir_ptr->find(filename));
    return *this;
  }

  I3D& I3D::load(const t_file_ptr file_ptr)
  {
    auto xml_ptr = Lorem::Utils::getXML(file_ptr);

    name = xml_ptr->select_node("/i3D").node().attribute("name").value();
    version = xml_ptr->select_node("/i3D").node().attribute("version").value();

    for (auto xnode : xml_ptr->select_nodes("/i3D/*")) {
      content.try_emplace(xnode.node().name(), getContainer(xnode.node()));
    }

    return *this;
  }

  I3DEntry I3D::getContainer(pugi::xml_node node) const
  {
    I3DEntry result = {};

    result.name = node.name();

    for (auto attr : node.attributes()) {
      result.attributes.try_emplace(attr.name(), attr.value());
    }

    for (auto child : node.children()) {
      result.children.push_back( getContainer(child) );
    }

    return result;
  }

  I3DEntry I3D::find(std::string_view what) const
  {
    I3DEntry result = {};

    if (auto entry = content.find(what); entry != content.end()) {
      result = entry->second;
    }

    return result;
  }

  std::string I3DEntry::attr(std::string_view what) const
  {
    std::string result = {};

    if (auto entry = attributes.find(what); entry != attributes.end()) {
      result = entry->second;
    }

    return result;
  }

}
