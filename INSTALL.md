# OSvia Installation Guide

## Quick Start

OSvia is a mini operating system written in C++ with classic applications and games.

## Prerequisites

### Linux (Ubuntu/Debian)

```bash
# Update package manager
sudo apt-get update

# Install build tools and dependencies
sudo apt-get install -y build-essential cmake git
sudo apt-get install -y libcurl4-openssl-dev nlohmann-json3-dev
```

### macOS

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install with Homebrew
brew install cmake curl nlohmann-json
```

### Windows (MinGW)

```bash
# Install MinGW, CMake, and dependencies
# Download from: https://www.mingw-w64.org/
# Download CMake from: https://cmake.org/download/
```

## Installation Steps

### 1. Clone the Repository

```bash
git clone https://github.com/Svjjjat777/OSvia.git
cd OSvia
```

### 2. Create Build Directory

```bash
mkdir build
cd build
```

### 3. Configure and Build

#### Linux/macOS:

```bash
cmake ..
make -j$(nproc)
```

#### Windows (MinGW):

```bash
cmake -G "MinGW Makefiles" ..
mingw32-make
```

#### Windows (Visual Studio):

```bash
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

### 4. Run OSvia

#### Linux/macOS/MinGW:

```bash
./osvia
```

#### Windows (Visual Studio):

```bash
.\Release\osvia.exe
```

## Troubleshooting

### CMake Not Found

```bash
# Linux
sudo apt-get install cmake

# macOS
brew install cmake

# Windows: Download from https://cmake.org/download/
```

### Missing libcurl

```bash
# Linux
sudo apt-get install libcurl4-openssl-dev

# macOS
brew install curl
```

### Missing nlohmann_json

```bash
# Linux
sudo apt-get install nlohmann-json3-dev

# macOS
brew install nlohmann-json
```

### Build Errors

**Error**: `g++: command not found`
- **Solution**: Install build-essential: `sudo apt-get install build-essential`

**Error**: `CMake: invalid use of placeholder constant`
- **Solution**: Update CMake: `sudo apt-get install --upgrade cmake`

### Compilation Issues

**Error**: `undefined reference to 'curl_easy_init'`
- **Solution**: Ensure libcurl is properly installed and linked

**Error**: `nlohmann/json.hpp: No such file or directory`
- **Solution**: Install nlohmann-json development package

## Development Build vs Release Build

### Debug Build (with debug symbols):

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### Release Build (optimized):

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Running Tests (Optional)

Currently, OSvia doesn't have automated tests. To test manually:

1. Run the application: `./osvia`
2. Test each application:
   - Calculator: Perform arithmetic operations
   - Browser: Navigate between pages
   - Weather: Check weather for different cities
   - Flappy Bird: Play the game
   - Snake: Play the game

## Uninstall

```bash
cd OSvia
rm -rf build/
```

## System Requirements

- **Processor**: Any modern CPU (x86, ARM, etc.)
- **Memory**: Minimum 256 MB RAM (comfortable at 512 MB+)
- **Storage**: ~50 MB for source code and build artifacts
- **Terminal**: Terminal with UTF-8 support recommended
- **OS**: Linux, macOS, or Windows (with appropriate tools)

## Optional Enhancements

### IDE Integration

#### VS Code

Install extensions:
- C/C++
- CMake
- CMake Tools

Create `.vscode/settings.json`:

```json
{
    "cmake.buildDirectory": "${workspaceFolder}/build",
    "cmake.configureOnOpen": true
}
```

#### CLion

Open the project folder and CLion will automatically detect CMakeLists.txt.

#### Vim/Neovim

Use `coc-clangd` or similar LSP client for C++ support.

## Performance Optimization

For better performance on slower systems:

1. Use Release build: `cmake -DCMAKE_BUILD_TYPE=Release ..`
2. Reduce frame rate in games (modify `main.cpp`)
3. Close other applications

## Getting Help

If you encounter issues:

1. Check the [GitHub Issues](https://github.com/Svjjjat777/OSvia/issues)
2. Review this installation guide
3. Check system logs for error messages
4. Ensure all dependencies are properly installed

## Next Steps

After successful installation:

1. Read the [README.md](README.md) for usage instructions
2. Explore the application menu
3. Try each application and game
4. Consider extending OSvia with your own applications

---

Happy coding! 🚀
