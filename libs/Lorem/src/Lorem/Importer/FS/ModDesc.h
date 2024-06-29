#pragma once

#include <string>
#include <vector>
#include <map>

#include "pugixml.hpp"

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Utils.h"

namespace Lorem::Importer::FS {
  class ModDesc {
    public: // Constructor
      ModDesc() = default;
      virtual ~ModDesc() = default;

    public: // Attributes
      struct t_brand {
        std::string Name;
        std::string Title;
        std::string Image;
      };

      std::string Author;
      std::string Contributors;

      std::string Version;
      std::string Icon;

      t_map_ss    Title;
      t_map_ss    Description;

      std::vector<std::string> StoreItems;
      std::vector<t_brand>     Brands;

    public: // Methods
      friend std::ostream& operator<<(std::ostream& os, const ModDesc& modDesc)
      {
        os << modDesc.Title.find("en")->second << std::endl;
        os << "Author: " << modDesc.Author << std::endl;
        return os;
      }

      virtual ModDesc& load(t_file_ptr file_ptr);

      // Parsed content of modDesc.xml
      virtual t_shared_xml parse(t_file_ptr file_ptr) const;

      virtual std::string prepareAuthor(const t_shared_xml xml) const;
      virtual std::string prepareContributors(const t_shared_xml xml) const;
      virtual std::string prepareVersion(const t_shared_xml xml) const;
      virtual std::string prepareIcon(const t_shared_xml xml) const;
      virtual t_map_ss prepareTitle(const t_shared_xml xml) const;
      virtual t_map_ss prepareDescription(const t_shared_xml xml) const;
      virtual std::vector<std::string> prepareStoreItems(const t_shared_xml xml) const;
      virtual std::vector<t_brand> prepareBrands(const t_shared_xml xml) const;

    };
}



