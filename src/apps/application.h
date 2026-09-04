#pragma once

#include <string>
#include <memory>
#include "../common.h"

class Window;

class Application {
protected:
    int id;
    std::string name;
    bool is_running;
    AppType type;
    std::shared_ptr<Window> window;

public:
    Application(const std::string& app_name, AppType app_type = AppType::APPLICATION);
    virtual ~Application();
    
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput(const std::string& input) = 0;
    virtual void shutdown() = 0;
    
    void setId(int app_id) { id = app_id; }
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    bool isRunning() const { return is_running; }
    void stop() { is_running = false; }
    
    virtual void display() { render(); }
};