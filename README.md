# OSvia - Mini Operating System in C++

![OSvia](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Version](https://img.shields.io/badge/Version-0.1-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

**OSvia** is a mini operating system written in C++ featuring classic applications and games. It demonstrates core OS concepts like kernel management, window management, and multi-application support.

## Features

### 📱 Applications
- **Calculator** - Basic calculator with arithmetic operations
- **Browser** - Simple text-based web browser with navigation history
- **Weather** - Weather application with city-based forecasts

### 🎮 Games
- **Flappy Bird** - Classic bird jumping game
- **Snake** - Classic snake game with growth mechanics

## System Architecture

```
┌─────────────────────────────┐
│      OSvia Kernel           │
│  - Process Management       │
│  - Application Registry     │
└─────────────────────────────┘
           ↓
┌─────────────────────────────┐
│   Window Manager            │
│  - Window Creation          │
│  - Window Rendering         │
└─────────────────────────────┘
           ↓
┌─────────────────────────────┐
│   Applications & Games      │
│  - Calculator               │
│  - Browser                  │
│  - Weather                  │
│  - Flappy Bird              │
│  - Snake                    │
└─────────────────────────────┘
```

## Project Structure

```
OSvia/
├── src/
│   ├── main.cpp              # Main entry point
│   ├── common.h              # Common definitions
│   ├── core/
│   │   ├── kernel.h/.cpp     # OS Kernel
│   │   └── window_manager.h/.cpp  # Window Management
│   ├── apps/
│   │   ├── application.h/.cpp     # Base Application class
│   │   ├── calculator.h/.cpp      # Calculator app
│   │   ├── browser.h/.cpp         # Browser app
│   │   └── weather.h/.cpp         # Weather app
│   ├── games/
│   │   ├── flappy_bird.h/.cpp     # Flappy Bird game
│   │   └── snake.h/.cpp           # Snake game
│   └── utils/
│       ├── network.h/.cpp    # Network utilities
│       └── ui.h/.cpp         # UI utilities
├── CMakeLists.txt            # Build configuration
└── README.md                 # This file
```

## Requirements

- **C++17** or higher
- **CMake** 3.10+
- **libcurl** (for potential network features)
- **nlohmann_json** (for JSON parsing)

## Building

### Using CMake

```bash
# Clone the repository
git clone https://github.com/Svjjjat777/OSvia.git
cd OSvia

# Create build directory
mkdir build
cd build

# Build the project
cmake ..
make

# Run OSvia
./osvia
```

### Linux/macOS

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install libcurl4-openssl-dev nlohmann-json3-dev

# Build and run
mkdir build && cd build
cmake ..
make
./osvia
```

### Windows (with MinGW)

```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
osvia.exe
```

## Usage

### Main Menu

When you launch OSvia, you'll see the main menu:

```
╔════════════════════════════════════════╗
║        OSvia v0.1 - Main Menu          ║
╠════════════════════════════════════════╣
║ 1. Calculator       2. Browser         ║
║ 3. Weather         4. Flappy Bird      ║
║ 5. Snake           0. Shutdown         ║
╚════════════════════════════════════════╝
```

Enter the number corresponding to the application or game you want to launch.

### Calculator

- **Operations**: `+`, `-`, `*`, `/`
- **Clear**: `C`
- **Decimal**: `.`
- **Equals**: `=`
- **Exit**: `exit`

### Browser

- **Navigate**: `navigate <url>`
- **Back**: `back`
- **Forward**: `forward`
- **Reload**: `reload`
- **Exit**: `exit`

Example:
```
navigate osvia://about
```

### Weather

- **Change city**: `city <city_name>`
- **Refresh**: `refresh`
- **Exit**: `exit`

Supported cities: Moscow, London, Tokyo, Dubai

### Flappy Bird

- **Flap**: `space` or `SPACE`
- **Restart**: `r` (after game over)
- **Exit**: `exit`

### Snake

- **Move**: `w/a/s/d` or `up/down/left/right`
- **Restart**: `r` (after game over)
- **Exit**: `exit`

## Application Development Guide

### Creating a New Application

To add a new application to OSvia, follow these steps:

1. **Create header file** (`src/apps/myapp.h`):

```cpp
#pragma once
#include "application.h"

class MyApp : public Application {
public:
    MyApp();
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
};
```

2. **Create implementation** (`src/apps/myapp.cpp`):

```cpp
#include "myapp.h"
#include <iostream>

MyApp::MyApp() : Application("My App", AppType::APPLICATION) {}

void MyApp::init() {
    is_running = true;
    // Initialize your app
}

void MyApp::update() {
    // Update logic
}

void MyApp::render() {
    std::cout << "My App Interface" << std::endl;
}

void MyApp::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
    }
}

void MyApp::shutdown() {
    std::cout << "[My App] Shutting down" << std::endl;
}
```

3. **Update CMakeLists.txt** to include your new files:

```cmake
set(SOURCES
    src/main.cpp
    # ... existing files ...
    src/apps/myapp.cpp  # Add your file
)
```

4. **Add to main menu** in `src/main.cpp`

## Core Concepts

### Kernel
Manages all running applications and their lifecycle.

### Window Manager
Handles window creation and rendering for terminal-based UI.

### Application Base Class
All applications inherit from `Application` class which provides:
- Lifecycle management (`init`, `update`, `render`, `shutdown`)
- Input handling
- Application ID and state tracking

## Future Enhancements

- [ ] File Manager
- [ ] Text Editor
- [ ] System Settings
- [ ] Process Monitor
- [ ] Improved graphics with SDL/SFML
- [ ] Real network support
- [ ] Multi-threading improvements
- [ ] Sound effects
- [ ] Custom themes

## Known Limitations

- Text-based UI only (terminal)
- Limited file system operations
- Basic network simulation
- No persistent storage
- Single-user only

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

**Svjjjat777** - Initial development

## Contributing

Contributions are welcome! Feel free to:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Troubleshooting

### Build Errors

**Problem**: `CMake: command not found`
- **Solution**: Install CMake: `sudo apt-get install cmake`

**Problem**: Missing libcurl
- **Solution**: Install libcurl-dev: `sudo apt-get install libcurl4-openssl-dev`

**Problem**: Missing nlohmann_json
- **Solution**: Install json library: `sudo apt-get install nlohmann-json3-dev`

### Runtime Errors

**Problem**: Applications crash on startup
- **Solution**: Ensure your terminal supports UTF-8 encoding

**Problem**: Games run too fast/slow
- **Solution**: Adjust frame timing in `src/main.cpp` (search for `sleep_for`)

## Contact

For issues, questions, or suggestions, please open an issue on GitHub.

---

**Happy coding! 🚀**
