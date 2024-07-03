cmake_minimum_required (VERSION 3.28)

project(i3DE)

if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.12.25835)
  set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++20")
  set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++20")
endif()

add_subdirectory(libs/endian)
add_subdirectory(libs/Lorem)
add_subdirectory(libs/pugixml)
add_subdirectory(libs/tinygltf)
add_subdirectory(libs/zip)
