#include "pch.h"
#include "i3D.h"


namespace Lorem {
  I3DDocument& I3DDocument::parseXML(const t_directory_ptr dir_ptr, const std::string& filename)
  {
    parseXML(Utils::getFilePtr(dir_ptr, filename));
    return *this;
  }

  I3DDocument& I3DDocument::parseXML(const t_file_ptr file_ptr)
  {
    auto xml_ptr = Lorem::Utils::getXML(file_ptr);

    name    = xml_ptr->select_node("/i3D").node().attribute("name").value();
    version = xml_ptr->select_node("/i3D").node().attribute("version").value();

    return *this;
  }
}
