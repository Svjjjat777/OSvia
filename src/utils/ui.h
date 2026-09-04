#pragma once

#include <string>
#include <iostream>

class UIUtil {
public:
    static void printHeader(const std::string& title);
    static void printFooter();
    static void printMenu();
    static void clearScreen();
};
