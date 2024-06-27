#pragma once
#include <string>
#include <vector>
#include <map>

#include "Lorem/Types.h"
#include "Lorem/Error.h"
#include "Lorem/Utils.h"

namespace Lorem {

  class I3DFile {
  public:
    std::string fileId;
    std::string filename;
  };

  class I3DMaterial {
  public:
    std::string name;
    int materialId;
    bool alphaBlending;
    int customShaderId;
    std::string customShaderVariation;
    std::vector<int> textureFileIds;
    Lorem::t_map_ss customParameters;
  };

  class I3DTransformGroup;

  class I3DShape {
  public:
    int shapeId;
    std::string name;
    bool dynamic;
    bool compound;
    int collisionMask;
    float density;
    int clipDistance;
    int nodeId;
    std::vector<int> materialIds;
    bool castsShadows;
    bool receiveShadows;
    bool nonRenderable;
    std::vector<I3DShape> children;
    std::vector<I3DTransformGroup> transformGroups;
  };

  class I3DTransformGroup {
  public:
    std::string name;
    int nodeId;
    std::vector<float> translation;
    std::vector<float> rotation;
    std::vector<I3DShape> shapes;
    std::vector<I3DTransformGroup> transformGroups;
  };

  class I3DScene {
  public:
    std::vector<I3DShape> shapes;
  };

  class I3DDocument {
  public:
    I3DDocument() = default;
    virtual ~I3DDocument() = default;

    std::string name;
    std::string version;

    std::vector<I3DFile> files;
    std::vector<I3DMaterial> materials;
    std::string externalShapesFile;
    std::string dynamics;  // Currently empty
    I3DScene scene;

    virtual I3DDocument& parseXML(const t_directory_ptr dir_ptr, const std::string& filename);
    virtual I3DDocument& parseXML(const t_file_ptr file_ptr);

  };
}

