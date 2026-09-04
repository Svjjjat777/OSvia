#pragma once

#include "application.h"
#include <cmath>
#include <sstream>
#include <iomanip>

class Calculator : public Application {
private:
    double result;
    double current_number;
    char operation;
    bool new_number;
    std::string display;

public:
    Calculator();
    
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
    
private:
    void performOperation(double num);
    void updateDisplay();
    std::string formatNumber(double num);
};