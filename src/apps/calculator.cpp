#include "calculator.h"
#include <iostream>

Calculator::Calculator() 
    : Application("Calculator", AppType::UTILITY),
      result(0), current_number(0), operation('\0'), new_number(true) {}

void Calculator::init() {
    is_running = true;
    result = 0;
    current_number = 0;
    operation = '\0';
    new_number = true;
    display = "0";
}

void Calculator::update() {
    // Calculator updates when user inputs
}

void Calculator::render() {
    std::cout << "\n╔════════════════════╗" << std::endl;
    std::cout << "║     CALCULATOR     ║" << std::endl;
    std::cout << "╠════════════════════╣" << std::endl;
    std::cout << "║  Display: " << std::setw(10) << display << "  ║" << std::endl;
    std::cout << "╠════════════════════╣" << std::endl;
    std::cout << "║ [7][8][9][/][C]   ║" << std::endl;
    std::cout << "║ [4][5][6][*][<-]  ║" << std::endl;
    std::cout << "║ [1][2][3][-]      ║" << std::endl;
    std::cout << "║ [0][.][+][=]      ║" << std::endl;
    std::cout << "║ Type 'exit' to quit ║" << std::endl;
    std::cout << "╚════════════════════╝" << std::endl;
}

void Calculator::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
        return;
    }
    
    if (input == "C") {
        result = 0;
        current_number = 0;
        operation = '\0';
        new_number = true;
        display = "0";
        updateDisplay();
        return;
    }
    
    if (input == ".") {
        if (display.find('.') == std::string::npos) {
            display += ".";
        }
        return;
    }
    
    if (input == "+" || input == "-" || input == "*" || input == "/") {
        if (!new_number) {
            current_number = std::stod(display);
            performOperation(current_number);
        }
        operation = input[0];
        new_number = true;
        return;
    }
    
    if (input == "=") {
        current_number = std::stod(display);
        performOperation(current_number);
        display = formatNumber(result);
        new_number = true;
        operation = '\0';
        return;
    }
    
    // Handle numbers 0-9
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '9') {
        if (new_number) {
            display = input;
            new_number = false;
        } else {
            display += input;
        }
    }
}

void Calculator::performOperation(double num) {
    switch (operation) {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            if (num != 0) result /= num;
            break;
        default:
            result = num;
    }
}

void Calculator::updateDisplay() {
    display = formatNumber(std::stod(display));
}

std::string Calculator::formatNumber(double num) {
    // Удаляем ненужные нули после точки
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(6) << num;
    std::string str = ss.str();
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str.back() == '.') str.pop_back();
    return str.empty() ? "0" : str;
}

void Calculator::shutdown() {
    std::cout << "[Calculator] Shutting down" << std::endl;
}