cmake_minimum_required (VERSION 3.28)

project(Lorem)

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(lorem STATIC 
	src/Lorem/Converter.cpp
	src/Lorem/Extractor.cpp
	src/Lorem/Importer/FS/Base.cpp
	src/Lorem/Importer/FS/i3d.cpp
	src/Lorem/Importer/FS/i3d.shapes.cpp
	src/Lorem/Importer/FS/ModDesc.cpp
	src/Lorem/MyFirstModule.cpp
	src/Lorem/Reader/Base.cpp
	src/Lorem/Scene.cpp
	src/Lorem/Utils.cpp
	src/pch.cpp
)

target_include_directories(lorem
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)