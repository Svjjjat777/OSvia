#include "core/kernel.h"
#include "core/window_manager.h"
#include "apps/calculator.h"
#include "apps/browser.h"
#include "apps/weather.h"
#include "games/flappy_bird.h"
#include "games/snake.h"
#include "utils/ui.h"
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>

class OSvia {
private:
    Kernel* kernel;
    WindowManager* window_manager;
    std::shared_ptr<Application> current_app;
    bool system_running;

public:
    OSvia() : system_running(false) {
        kernel = Kernel::getInstance();
        window_manager = WindowManager::getInstance();
    }

    void start() {
        system_running = true;
        kernel->start();
        showMainMenu();
    }

    void showMainMenu() {
        while (system_running) {
            UIUtil::printHeader("OSvia v0.1 - Main Menu");
            UIUtil::printMenu();
            UIUtil::printFooter();
            
            std::cout << "\nSelect application (0-5): ";
            std::string choice;
            std::getline(std::cin, choice);
            
            launchApplication(choice);
        }
    }

    void launchApplication(const std::string& choice) {
        if (choice == "1") {
            runCalculator();
        }
        else if (choice == "2") {
            runBrowser();
        }
        else if (choice == "3") {
            runWeather();
        }
        else if (choice == "4") {
            runFlappyBird();
        }
        else if (choice == "5") {
            runSnake();
        }
        else if (choice == "0") {
            shutdown();
        }
        else {
            std::cout << "Invalid choice. Press Enter to continue...";
            std::cin.ignore();
        }
    }

    void runCalculator() {
        auto calc = std::make_shared<Calculator>();
        calc->init();
        runApp(calc);
    }

    void runBrowser() {
        auto browser = std::make_shared<Browser>();
        browser->init();
        runApp(browser);
    }

    void runWeather() {
        auto weather = std::make_shared<Weather>();
        weather->init();
        runApp(weather);
    }

    void runFlappyBird() {
        auto bird = std::make_shared<FlappyBird>();
        bird->init();
        runGameApp(bird);
    }

    void runSnake() {
        auto snake = std::make_shared<Snake>();
        snake->init();
        runGameApp(snake);
    }

    void runApp(std::shared_ptr<Application> app) {
        kernel->registerApp(app);
        
        while (app->isRunning()) {
            system("clear");
            app->render();
            
            std::cout << "\nInput: ";
            std::string input;
            std::getline(std::cin, input);
            
            if (!input.empty()) {
                app->handleInput(input);
            }
        }
        
        kernel->closeApp(app->getId());
        std::cout << "\nReturning to main menu..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void runGameApp(std::shared_ptr<Application> app) {
        kernel->registerApp(app);
        
        while (app->isRunning()) {
            app->render();
            
            std::cout << "\nInput: ";
            std::string input;
            std::getline(std::cin, input);
            
            if (!input.empty()) {
                app->handleInput(input);
            } else {
                // Если ввода нет, просто обновляем игру
                app->update();
            }
            
            app->update();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
        kernel->closeApp(app->getId());
        std::cout << "\nReturning to main menu..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void shutdown() {
        std::cout << "\nShutting down OSvia..." << std::endl;
        system_running = false;
        kernel->shutdown();
    }
};

int main() {
    OSvia os;
    os.start();
    return 0;
}