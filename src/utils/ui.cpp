#include "ui.h"
#include <cstdlib>

void UIUtil::printHeader(const std::string& title) {
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║" << std::string((40 - title.length()) / 2, ' ') << title;
    std::cout << std::string(40 - (40 - title.length()) / 2 - title.length(), ' ') << "║" << std::endl;
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
}

void UIUtil::printFooter() {
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
}

void UIUtil::printMenu() {
    std::cout << "║ 1. Calculator       2. Browser          ║" << std::endl;
    std::cout << "║ 3. Weather         4. Flappy Bird      ║" << std::endl;
    std::cout << "║ 5. Snake           0. Shutdown         ║" << std::endl;
}

void UIUtil::clearScreen() {
    system("clear");
}
