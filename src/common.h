#pragma once

#include <string>
#include <iostream>

namespace OSvia {
    const int VERSION_MAJOR = 0;
    const int VERSION_MINOR = 1;
    const std::string OS_NAME = "OSvia";
}

enum class AppType {
    SYSTEM,
    APPLICATION,
    GAME,
    UTILITY
};