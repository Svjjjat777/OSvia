#include "kernel.h"
#include "../apps/application.h"
#include <iostream>
#include <algorithm>

Kernel* Kernel::instance = nullptr;

Kernel::Kernel() : is_running(false), next_app_id(1) {}

Kernel* Kernel::getInstance() {
    if (instance == nullptr) {
        instance = new Kernel();
    }
    return instance;
}

void Kernel::start() {
    is_running = true;
    std::cout << "\n=== OSvia Kernel Started ===\n" << std::endl;
}

void Kernel::shutdown() {
    is_running = false;
    running_apps.clear();
    std::cout << "\n=== OSvia Kernel Shutdown ===\n" << std::endl;
}

void Kernel::registerApp(std::shared_ptr<Application> app) {
    if (app) {
        app->setId(next_app_id++);
        running_apps.push_back(app);
        std::cout << "[Kernel] Registered app: " << app->getName() << " (ID: " << app->getId() << ")" << std::endl;
    }
}

void Kernel::closeApp(int app_id) {
    auto it = std::find_if(running_apps.begin(), running_apps.end(),
        [app_id](const std::shared_ptr<Application>& app) { return app->getId() == app_id; });
    
    if (it != running_apps.end()) {
        std::cout << "[Kernel] Closing app: " << (*it)->getName() << std::endl;
        running_apps.erase(it);
    }
}

void Kernel::update() {
    for (auto& app : running_apps) {
        if (app && app->isRunning()) {
            app->update();
        }
    }
}

Kernel::~Kernel() {
    shutdown();
}