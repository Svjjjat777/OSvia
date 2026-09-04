#pragma once

#include <vector>
#include <string>
#include <map>

struct Window {
    int id;
    int x, y;
    int width, height;
    std::string title;
    bool is_active;
    
    Window(int id, int x, int y, int w, int h, const std::string& t)
        : id(id), x(x), y(y), width(w), height(h), title(t), is_active(true) {}
};

class WindowManager {
private:
    static WindowManager* instance;
    std::map<int, Window> windows;
    int next_window_id;
    int screen_width;
    int screen_height;
    
    WindowManager(int width = 1024, int height = 768);

public:
    static WindowManager* getInstance();
    
    Window* createWindow(int x, int y, int width, int height, const std::string& title);
    void closeWindow(int window_id);
    Window* getWindow(int window_id);
    void render();
    void setScreenSize(int width, int height) { screen_width = width; screen_height = height; }
    
    int getScreenWidth() const { return screen_width; }
    int getScreenHeight() const { return screen_height; }
};