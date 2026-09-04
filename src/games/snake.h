#pragma once

#include "application.h"
#include <vector>
#include <set>

struct Point {
    int x, y;
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

enum class Direction {
    UP, DOWN, LEFT, RIGHT
};

class Snake : public Application {
private:
    std::vector<Point> snake_body;
    Point food;
    Direction current_direction;
    Direction next_direction;
    int score;
    int game_width;
    int game_height;
    bool game_over;
    int frame_count;

public:
    Snake();
    
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
    
private:
    void updateSnake();
    void generateFood();
    void checkCollisions();
    void resetGame();
    bool isPointInSnake(const Point& p) const;
};