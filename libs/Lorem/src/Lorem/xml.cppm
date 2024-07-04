export module daan.i3de.lorem.xml;

export import "pugixml.hpp";
import daan.i3de.lorem.types;

export namespace lorem {
  using t_shared_xml = std::shared_ptr<pugi::xml_document>;
}
