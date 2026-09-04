#include "weather.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Weather::Weather()
    : Application("Weather", AppType::APPLICATION), selected_city("Moscow") {}

void Weather::init() {
    is_running = true;
    fetchWeather(selected_city);
}

void Weather::update() {
    // Weather updates periodically
}

void Weather::render() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║         OSVIA WEATHER v0.1            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    displayWeatherInfo();
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Commands: city <name>, refresh, exit   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
}

void Weather::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
        return;
    }
    
    if (input == "refresh") {
        fetchWeather(selected_city);
        return;
    }
    
    if (input.substr(0, 4) == "city") {
        selected_city = input.substr(5);
        fetchWeather(selected_city);
        return;
    }
}

void Weather::fetchWeather(const std::string& city) {
    selected_city = city;
    
    // Симуляция данных о погоде
    current_weather.city = city;
    
    // Простые симуляции в зависимости от города
    if (city == "Moscow" || city == "moscow") {
        current_weather.temperature = -5.0;
        current_weather.condition = "Snowy";
        current_weather.humidity = 75;
        current_weather.wind_speed = 12.5;
    }
    else if (city == "London" || city == "london") {
        current_weather.temperature = 8.0;
        current_weather.condition = "Rainy";
        current_weather.humidity = 85;
        current_weather.wind_speed = 18.0;
    }
    else if (city == "Tokyo" || city == "tokyo") {
        current_weather.temperature = 15.0;
        current_weather.condition = "Cloudy";
        current_weather.humidity = 60;
        current_weather.wind_speed = 8.0;
    }
    else if (city == "Dubai" || city == "dubai") {
        current_weather.temperature = 35.0;
        current_weather.condition = "Sunny";
        current_weather.humidity = 25;
        current_weather.wind_speed = 5.0;
    }
    else {
        current_weather.temperature = 20.0;
        current_weather.condition = "Clear";
        current_weather.humidity = 50;
        current_weather.wind_speed = 10.0;
    }
    
    // Получить текущее время
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    current_weather.last_update = buffer;
}

void Weather::displayWeatherInfo() {
    std::cout << "║ City: " << std::setw(32) << current_weather.city << " ║" << std::endl;
    std::cout << "║ Temperature: " << std::setw(25) << current_weather.temperature << "°C ║" << std::endl;
    std::cout << "║ Condition: " << std::setw(27) << current_weather.condition << " ║" << std::endl;
    std::cout << "║ Humidity: " << std::setw(28) << current_weather.humidity << "% ║" << std::endl;
    std::cout << "║ Wind Speed: " << std::setw(26) << current_weather.wind_speed << " m/s ║" << std::endl;
    std::cout << "║ Updated: " << std::setw(29) << current_weather.last_update << " ║" << std::endl;
}

void Weather::shutdown() {
    std::cout << "[Weather] Shutting down" << std::endl;
}