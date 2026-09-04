#pragma once

#include <string>
#include <vector>

class NetworkUtil {
public:
    static std::string fetchJSON(const std::string& url);
    static std::string parseJSON(const std::string& json, const std::string& key);
};
