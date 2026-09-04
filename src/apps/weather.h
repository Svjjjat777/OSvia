#pragma once

#include "application.h"
#include <string>

struct WeatherData {
    std::string city;
    double temperature;
    std::string condition;
    int humidity;
    double wind_speed;
    std::string last_update;
};

class Weather : public Application {
private:
    WeatherData current_weather;
    std::string selected_city;

public:
    Weather();
    
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
    
private:
    void fetchWeather(const std::string& city);
    void displayWeatherInfo();
    std::string getWeatherIcon(const std::string& condition);
};