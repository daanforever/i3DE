#pragma once

#include <memory>
#include "pugixml.hpp"

namespace Lorem {
  using t_shared_xml = std::shared_ptr<pugi::xml_document>;
}
