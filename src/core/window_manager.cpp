#include "window_manager.h"
#include <iostream>

WindowManager* WindowManager::instance = nullptr;

WindowManager::WindowManager(int width, int height)
    : next_window_id(1), screen_width(width), screen_height(height) {}

WindowManager* WindowManager::getInstance() {
    if (instance == nullptr) {
        instance = new WindowManager();
    }
    return instance;
}

Window* WindowManager::createWindow(int x, int y, int width, int height, const std::string& title) {
    int id = next_window_id++;
    windows[id] = Window(id, x, y, width, height, title);
    std::cout << "[WindowManager] Created window: " << title << " (ID: " << id << ")" << std::endl;
    return &windows[id];
}

void WindowManager::closeWindow(int window_id) {
    if (windows.find(window_id) != windows.end()) {
        std::cout << "[WindowManager] Closed window: " << windows[window_id].title << std::endl;
        windows.erase(window_id);
    }
}

Window* WindowManager::getWindow(int window_id) {
    if (windows.find(window_id) != windows.end()) {
        return &windows[window_id];
    }
    return nullptr;
}

void WindowManager::render() {
    system("clear");
    std::cout << "\n╔" << std::string(screen_width - 2, '═') << "╗" << std::endl;
    for (int i = 0; i < screen_height - 2; i++) {
        std::cout << "║" << std::string(screen_width - 2, ' ') << "║" << std::endl;
    }
    std::cout << "╚" << std::string(screen_width - 2, '═') << "╝" << std::endl;
}