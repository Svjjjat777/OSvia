#pragma once

#include <vector>
#include <memory>
#include <string>
#include <queue>
#include "../common.h"

class Application;

class Kernel {
private:
    static Kernel* instance;
    std::vector<std::shared_ptr<Application>> running_apps;
    bool is_running;
    int next_app_id;

    Kernel();

public:
    static Kernel* getInstance();
    
    void start();
    void shutdown();
    void registerApp(std::shared_ptr<Application> app);
    void closeApp(int app_id);
    void update();
    bool isRunning() const { return is_running; }
    
    ~Kernel();
};