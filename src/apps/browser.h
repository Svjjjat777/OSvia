#pragma once

#include "application.h"
#include <vector>
#include <map>

struct WebPage {
    std::string url;
    std::string title;
    std::string content;
};

class Browser : public Application {
private:
    std::vector<WebPage> history;
    int current_page_index;
    std::map<std::string, WebPage> cached_pages;

public:
    Browser();
    
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
    
private:
    void navigate(const std::string& url);
    void loadPage(const std::string& url);
    void renderPage();
    WebPage fetchPage(const std::string& url);
};