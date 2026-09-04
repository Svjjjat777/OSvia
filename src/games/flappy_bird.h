#pragma once

#include "application.h"
#include <vector>
#include <cstdlib>
#include <ctime>

struct Pipe {
    int x;
    int gap_y;
    bool passed;
};

class FlappyBird : public Application {
private:
    int bird_y;
    int bird_x;
    double velocity;
    double gravity;
    std::vector<Pipe> pipes;
    int score;
    int game_width;
    int game_height;
    bool game_over;
    int frame_count;

public:
    FlappyBird();
    
    void init() override;
    void update() override;
    void render() override;
    void handleInput(const std::string& input) override;
    void shutdown() override;
    
private:
    void updatePhysics();
    void updatePipes();
    void checkCollisions();
    void generatePipe();
    void resetGame();
};