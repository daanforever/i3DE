export module daan.i3de.lorem.scene:Sound;

import daan.i3de.lorem.types;

export namespace Lorem::Scene {

  // Structure representing a shape
  struct Sound {
  public:
    Sound() = default;
    virtual ~Sound() = default;
    
    t_file_ptr file_ptr = {};

    explicit operator bool() const {
      return !file_ptr;
    }
  };

}


