Project template for cross-platform C/C++ development.

Tools:
- cmake build tool
- conan dependencies management
- clion ide
- gcc, msvc compilers

```bash
# We will use Conan to install Zlib and generate the files that CMake needs to find this library and build our project
conan install . --output-folder=build --build=missing

cd build

# linux:
cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
cmake --build .
./compressor

# windows:
cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
cmake --build . --config Release
Release\compressor.exe
```
