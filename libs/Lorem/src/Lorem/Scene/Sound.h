#pragma once

#include <string>
#include <vector>

#include "Lorem/Types.h"
#include "Lorem/Scene.h"

namespace Lorem {
  // Structure representing a shape
  class Scene::Sound {
  public:
    Sound() = default;
    virtual ~Sound() = default;
    
    t_file_ptr file_ptr = {};

    explicit operator bool() const {
      return !file_ptr;
    }
  };
}


