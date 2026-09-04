#include "browser.h"
#include "../utils/network.h"
#include <iostream>
#include <algorithm>

Browser::Browser()
    : Application("Browser", AppType::APPLICATION), current_page_index(-1) {}

void Browser::init() {
    is_running = true;
    WebPage home;
    home.url = "osvia://home";
    home.title = "OSvia Home";
    home.content = "Welcome to OSvia Browser!\nAvailable commands:\n  - navigate <url>\n  - back\n  - forward\n  - reload\n  - exit";
    history.push_back(home);
    current_page_index = 0;
}

void Browser::update() {
    // Browser updates when navigating
}

void Browser::render() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║         OSVIA BROWSER v0.1            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    if (current_page_index >= 0 && current_page_index < history.size()) {
        std::cout << "║ URL: " << history[current_page_index].url << std::endl;
        std::cout << "╠════════════════════════════════════════╣" << std::endl;
        renderPage();
    }
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Commands: navigate, back, forward, exit ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
}

void Browser::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
        return;
    }
    
    if (input == "back") {
        if (current_page_index > 0) {
            current_page_index--;
        }
        return;
    }
    
    if (input == "forward") {
        if (current_page_index < history.size() - 1) {
            current_page_index++;
        }
        return;
    }
    
    if (input == "reload") {
        if (current_page_index >= 0) {
            loadPage(history[current_page_index].url);
        }
        return;
    }
    
    if (input.substr(0, 8) == "navigate") {
        std::string url = input.substr(9);
        navigate(url);
        return;
    }
}

void Browser::navigate(const std::string& url) {
    // Удаляем все страницы после текущей (как в реальном браузере)
    if (current_page_index < history.size() - 1) {
        history.erase(history.begin() + current_page_index + 1, history.end());
    }
    
    loadPage(url);
    current_page_index = history.size() - 1;
}

void Browser::loadPage(const std::string& url) {
    WebPage page;
    page.url = url;
    
    // Простой кеш для популярных сайтов
    if (url == "osvia://home") {
        page.title = "OSvia Home";
        page.content = "Welcome to OSvia Browser!\n\nThis is a simple browser engine.\nYou can navigate to basic pages.";
    }
    else if (url == "osvia://about") {
        page.title = "About";
        page.content = "OSvia v0.1\nA mini operating system written in C++\nFeatures: Calculator, Browser, Weather, Games";
    }
    else if (url.find("osvia://") == 0) {
        page.title = "Local Page";
        page.content = "Page: " + url;
    }
    else {
        // Попытка загрузить реальный сайт (если доступен интернет)
        page.title = "Web Page";
        page.content = "[Simulated content from " + url + "]\n\nNote: Full web browsing not available in this version.";
    }
    
    history.push_back(page);
}

void Browser::renderPage() {
    if (current_page_index < 0 || current_page_index >= history.size()) {
        return;
    }
    
    const WebPage& page = history[current_page_index];
    std::cout << "║ Title: " << page.title << std::endl;
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    
    // Вывод содержимого с переносом строк
    size_t pos = 0;
    std::string line;
    const std::string& content = page.content;
    
    while (pos < content.length()) {
        size_t end = content.find('\n', pos);
        if (end == std::string::npos) {
            line = content.substr(pos);
            pos = content.length();
        } else {
            line = content.substr(pos, end - pos);
            pos = end + 1;
        }
        std::cout << "║ " << line << std::endl;
    }
}

void Browser::shutdown() {
    std::cout << "[Browser] Shutting down" << std::endl;
}