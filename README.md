# JetBrains internship task

This is a test task for JetBrains internship project "Улучшение интеграции Rider с Unreal Editor", 2021.

# Requirements
Make sure the following is installed on your machine:

- `CMake` 3.1.0 or higher;
- `Qt5` user interface library.

# Build

## Linux
```
mkdir build
cd build
cmake ..
cmake --build .
```
To execute the application run the following from the build folder:
```
./JB2021-test-task
```
## Windows
### Debug
```
mkdir build
cd build
cmake ..
cmake --build .
```
### Release
```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```
To execute the application run the following from the build folder:
```
# if build in debug mode
Debug/JB2021-test-task.exe

# if build in release mode
Release/JB2021-test-task.exe
```
## Troubleshooting
If *CMake* fails to find *Qt5* on your machine then you need to set the CMAKE_PREFIX_PATH to the Qt installation.

Add this flag when configuring cmake build:
`-DCMAKE_PREFIX_PATH="pathToQt/YourQtVersion/YourCompiler"`

### Example
If you have Qt version `5.15.2` built for `MSVC 2019 64-bit` compiler installed at `C:\Qt` then you would run this from build directory:
```
cmake .. -DCMAKE_PREFIX_PATH="C:\Qt\5.15.2\msvc2019_64"
```