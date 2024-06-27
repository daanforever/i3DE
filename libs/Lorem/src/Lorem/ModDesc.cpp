#include "pch.h"
#include "ModDesc.h"

#include <filesystem>

namespace Lorem {

  ModDesc& ModDesc::process(const t_directory_ptr dir)
  {
    auto raw     = getModDescRaw(dir);
    auto xml     = getModDescXML(raw);

    Author       = prepareAuthor(xml);
    Contributors = prepareContributors(xml);

    Version      = prepareVersion(xml);
    Icon         = prepareIcon(xml, dir);

    Title        = prepareTitle(xml);
    Description  = prepareDescription(xml);

    StoreItems   = prepareStoreItems(xml, dir);
    Brands       = prepareBrands(xml, dir);

    return *this;
  }

  std::string ModDesc::getModDescRaw(const t_directory_ptr dir) const
  {
    const std::string filename = "modDesc.xml";
    auto modDescPtr = dir->names.find(filename);

    if (modDescPtr == dir->names.end()) {
      throw Error::NotFoundError(filename);
    }

    auto file_ptr = Lorem::Utils::getFilePtr(dir, filename);

    return file_ptr->string();
  }

  t_shared_xml ModDesc::getModDescXML(std::string_view raw) const
  {
    auto doc = std::make_shared<pugi::xml_document>();
    pugi::xml_parse_result result = doc->load_string(raw.data());

    if (!result) {
      throw Error::UnableToParseXML("modDesc.xml");
    }

    return doc;
  }

  std::string ModDesc::prepareAuthor(t_shared_xml xml) const
  {
    return xml->select_node("/modDesc/author").node().child_value();
  }

  std::string ModDesc::prepareContributors(t_shared_xml xml) const
  {
    return xml->select_node("/modDesc/contributors").node().child_value();
  }

  std::string ModDesc::prepareVersion(t_shared_xml xml) const
  {
    return xml->select_node("/modDesc/version").node().child_value();
  }

  t_file_ptr ModDesc::prepareIcon(t_shared_xml xml, const t_directory_ptr dir) const
  {
    std::string iconFilename = xml->select_node("/modDesc/iconFilename").node().child_value();

    auto icon = Utils::getFilePtr(dir, iconFilename);

    if (!icon) { // try to check different file extension
      icon = Utils::getFilePtr(dir, Utils::fileWithoutExt(iconFilename) + ".dds");
    }

    return icon;
  }

  t_map_ss ModDesc::prepareTitle(t_shared_xml xml) const
  {
    t_map_ss result;

    for (auto node : xml->select_node("/modDesc/title").node().children()) {
      result.try_emplace(node.name(), node.child_value());
    }

    return result;
  }

  t_map_ss ModDesc::prepareDescription(t_shared_xml xml) const
  {
    t_map_ss result;

    for (auto node : xml->select_node("/modDesc/description").node().children()) {
      result.try_emplace(node.name(), node.child_value());
    }

    return result;
  }

  std::vector<t_file_ptr> ModDesc::prepareStoreItems(const t_shared_xml xml, const t_directory_ptr dir) const
  {
    std::vector<t_file_ptr> result = {};

    const auto storeItems = xml->select_nodes("/modDesc/storeItems/*");

    for (const auto& storeItem : storeItems)
    {
      const auto node = storeItem.node();
      if (!node) continue;

      const auto attr = node.attribute("xmlFilename");
      if (!attr) continue;

      const auto value = dir->names.find(attr.value());
      if (value != dir->names.end()) {
        result.emplace_back(value->second);
      }
      else {
        throw Error::NotFoundError(attr.value());
      }
    }

    return result;
  }

  std::vector<ModDesc::t_brand> ModDesc::prepareBrands(t_shared_xml xml, const t_directory_ptr dir) const
  {
    std::vector<ModDesc::t_brand> result = {};

    const auto xnodes = xml->select_nodes("/modDesc/brands/*");

    for (const auto& xnode : xnodes)
    {
      const auto node = xnode.node();
      if (!node) continue;

      const auto name = node.attribute("name").value();
      const auto title = node.attribute("title").value();
      const auto image_name = node.attribute("image").value();

      const auto image_ptr = Utils::getFilePtr(dir, image_name);

      result.emplace_back(name, title, image_ptr);
    }

    return result;
  }

}
