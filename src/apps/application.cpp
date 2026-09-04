#include "application.h"

Application::Application(const std::string& app_name, AppType app_type)
    : id(-1), name(app_name), is_running(false), type(app_type) {}

Application::~Application() {
    shutdown();
}