#pragma once

#include <string>
#include <vector>
#include <map>

#include "pugixml.hpp"

#include "Lorem/Types.h"
#include "Lorem/Error.h"

namespace Lorem {
  class ModDesc {
    public: // Constructor
      ModDesc() = default;
      virtual ~ModDesc() = default;

    public: // Attributes
      struct t_brand {
        std::string       Name;
        std::string       Title;
        Lorem::t_file_ptr Image;
      };

      std::string             Author;
      std::string             Contributors;

      std::string             Version;
      t_file_ptr              Icon;

      t_map_ss                Title;
      t_map_ss                Description;

      std::vector<t_file_ptr> StoreItems;
      std::vector<t_brand>    Brands;

    public: // Methods
      friend std::ostream& operator<<(std::ostream& os, const Lorem::ModDesc& modDesc)
      {
        os << modDesc.Title.find("en")->second << std::endl;
        os << "Author: " << modDesc.Author << std::endl;
        return os;
      }

      virtual ModDesc& process(const t_directory_ptr dir);

      // Raw content of modDesc.xml
      virtual std::string getModDescRaw(const t_directory_ptr dir) const;

      // Parsed content of modDesc.xml
      virtual t_shared_xml getModDescXML(std::string_view modDescContent) const;

      virtual std::string prepareAuthor(const t_shared_xml xml) const;
      virtual std::string prepareContributors(const t_shared_xml xml) const;
      virtual std::string prepareVersion(const t_shared_xml xml) const;
      virtual t_file_ptr prepareIcon(const t_shared_xml xml, const t_directory_ptr dir) const;
      virtual t_map_ss prepareTitle(const t_shared_xml xml) const;
      virtual t_map_ss prepareDescription(const t_shared_xml xml) const;
      virtual std::vector<t_file_ptr> prepareStoreItems(const t_shared_xml xml, const t_directory_ptr dir) const;
      virtual std::vector<t_brand> prepareBrands(const t_shared_xml xml, const t_directory_ptr dir) const;
      

      // Utility methods
      virtual t_file_ptr findFile(const t_directory_ptr dir, std::string_view name) const;
      virtual std::string fileWithoutExt(std::string_view name) const;
    };
}



