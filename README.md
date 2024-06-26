# i3DE Documentation

## Overview
i3DE is a tool for processing Farming Simulator mods, offering functionalities for extracting, importing, converting, and exporting 3D scenes. It is written in C++ and C and inspired by the [I3DShapesTool](https://github.com/Donkie/I3DShapesTool).

## Features
- Unpack mod files (in memory)
- Import content
- Create scenes with shapes
- Convert scenes to specified formats (currently only .gltf)
- Export scenes to desired file formats (currently only .gltf)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/daanforever/i3DE.git
   ```
2. For now, build only in Visual Studio

## Usage
### Extracting Files
```bash
./i3DE extract input_file output_directory
```

### Converting Files
```bash
./i3DE convert input_file output_file
```


## Base workflow:

```
Extractor >> Importer >> Converter >> Exporter
```

* Extractor - unzip plugin and creates file structure in memory
* Importer  - read plugin content and creates Scene with Shapes
* Converter - convert whole scene to the given format
* Exporter  - save scene in specified file format

## Contributing
1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-branch
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m "Add new feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-branch
   ```
5. Open a pull request.

## License
This project is licensed under the MIT License.

## Contact
For any questions or feedback, please open an issue on the [GitHub repository](https://github.com/daanforever/i3DE/issues).
