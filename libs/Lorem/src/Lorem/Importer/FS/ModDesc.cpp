#include "pch.h"
#include "Lorem/Importer/FS/ModDesc.h"

#include <filesystem>

namespace Lorem::Importer::FS {

  ModDesc& ModDesc::load(const t_file_ptr file_ptr)
  {
    auto xml     = parse(file_ptr);

    Author       = prepareAuthor(xml);
    Contributors = prepareContributors(xml);

    Version      = prepareVersion(xml);
    Icon         = prepareIcon(xml);

    Title        = prepareTitle(xml);
    Description  = prepareDescription(xml);

    StoreItems   = prepareStoreItems(xml);
    Brands       = prepareBrands(xml);

    return *this;
  }

  t_shared_xml ModDesc::parse(const t_file_ptr file_ptr) const
  {
    auto doc = std::make_shared<pugi::xml_document>();
    auto raw = file_ptr->string();

    pugi::xml_parse_result result = doc->load_string(raw.c_str());

    if (!result) {
      throw Error::XMLParseError("modDesc.xml");
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

  std::string ModDesc::prepareIcon(t_shared_xml xml) const
  {
    std::string iconFilename = xml->select_node("/modDesc/iconFilename").node().child_value();

    return iconFilename;
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

  std::vector<std::string> ModDesc::prepareStoreItems(const t_shared_xml xml) const
  {
    std::vector<std::string> result = {};

    const auto storeItems = xml->select_nodes("/modDesc/storeItems/*");

    for (const auto& storeItem : storeItems)
    {
      const auto node = storeItem.node();
      if (!node) continue;

      const auto attr = node.attribute("xmlFilename");
      if (!attr) continue;

      result.emplace_back(attr.value());
    }

    return result;
  }

  std::vector<ModDesc::t_brand> ModDesc::prepareBrands(t_shared_xml xml) const
  {
    std::vector<ModDesc::t_brand> result = {};

    const auto xnodes = xml->select_nodes("/modDesc/brands/*");

    for (const auto& xnode : xnodes)
    {
      const auto node = xnode.node();
      if (!node) continue;

      const auto name = node.attribute("name").value();
      const auto title = node.attribute("title").value();
      const auto image = node.attribute("image").value();

      result.emplace_back(name, title, image);
    }

    return result;
  }

}
