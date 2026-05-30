# Project template for cross-platform C/C++ development.

## Install tools:
- cmake -- build tool
- conan -- dependencies management
- code editor -- clion ide, vim
- gcc, msvc -- compilers

## Pre-build:

```bash
# linux:
sudo apt install libudev-dev \
  libx11-xcb-dev libfontenc-dev libxaw7-dev libxkbfile-dev libxmu-dev libxmuu-dev libxpm-dev libxres-dev libxss-dev \
  libxtst-dev libxv-dev libxxf86vm-dev libxcb-glx0-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev \
  libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev \
  libxcb-xinerama0-dev libxcb-dri3-dev libxcb-cursor-dev libxcb-dri2-0-dev libxcb-dri3-dev libxcb-present-dev \
  libxcb-composite0-dev libxcb-ewmh-dev libxcb-res0-dev \
  libxcb-util-dev libxcb-util0-dev
```

## Build:
```bash
# We will use Conan to install Zlib and generate the files that CMake needs to find this library and build our project
conan install . --output-folder=build --build=missing

cd build

# linux:
cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
cmake --build .
./snake

# windows:
cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
cmake --build . --config Release
Release\2d_game.exe
```

TODO:

- logger instead of printf()
- config
- android app
- smooth movement by pixel, instead of by cell jumping
- scroll the view through the map
- put the food in the rect of visibility with some space
- M to toggle map in the bottom-right corner
- direction control by click
