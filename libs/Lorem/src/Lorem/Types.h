#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

struct t_file {
  std::string name = {};
  bool directory = false;
  std::vector<unsigned char> content = {};
};

using t_file_ptr = std::shared_ptr<t_file>;

struct t_directory {
  std::vector<t_file_ptr> files = {};
  std::map<std::string, t_file_ptr, std::less<>> names = {};

  explicit operator bool() const {
    return !files.empty();
  }
};

using t_directory_ptr = std::shared_ptr<t_directory>;

// Structure representing a shape .i3d.shapes
struct Shape {
  std::string name = "";
  std::vector<float> vertices = {}; // Assuming each vertex has 3 float values for x, y, and z
  std::vector<uint32_t> indices = {};
};

// Structure representing the shape file
struct ShapesFile {
  std::vector<Shape> shapes = {};
};
