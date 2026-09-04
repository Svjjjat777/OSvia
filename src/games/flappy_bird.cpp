#include "flappy_bird.h"
#include <iostream>
#include <algorithm>

FlappyBird::FlappyBird()
    : Application("Flappy Bird", AppType::GAME),
      bird_y(8), bird_x(5), velocity(0), gravity(0.3),
      score(0), game_width(40), game_height(15), game_over(false), frame_count(0) {}

void FlappyBird::init() {
    is_running = true;
    srand(time(0));
    resetGame();
}

void FlappyBird::update() {
    if (!game_over) {
        updatePhysics();
        updatePipes();
        checkCollisions();
        frame_count++;
        
        if (frame_count % 8 == 0) {
            generatePipe();
        }
    }
}

void FlappyBird::render() {
    system("clear");
    std::cout << "\n╔" << std::string(game_width, '═') << "╗" << std::endl;
    
    // рисование окна
    for (int y = 0; y < game_height; y++) {
        std::cout << "║";
        
        for (int x = 0; x < game_width; x++) {
            bool bird_here = (y == bird_y && x == bird_x);
            bool pipe_here = false;
            
            // Проверка наличие труб
            for (const auto& pipe : pipes) {
                if (pipe.x == x) {
                    if (y < pipe.gap_y || y >= pipe.gap_y + 4) {
                        pipe_here = true;
                        break;
                    }
                }
            }
            
            if (bird_here) {
                std::cout << "@";
            } else if (pipe_here) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        
        std::cout << "║" << std::endl;
    }
    
    std::cout << "╚" << std::string(game_width, '═') << "╝" << std::endl;
    std::cout << "\nScore: " << score;
    
    if (game_over) {
        std::cout << " | GAME OVER! Press 'r' to restart or 'exit' to quit";
    } else {
        std::cout << " | Press SPACE to flap, 'exit' to quit";
    }
    std::cout << std::endl;
}

void FlappyBird::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
        return;
    }
    
    if (input == " " || input == "space") {
        if (!game_over) {
            velocity = -8;
        }
        return;
    }
    
    if (input == "r" && game_over) {
        resetGame();
    }
}

void FlappyBird::updatePhysics() {
    velocity += gravity;
    bird_y += velocity;
    
    // Ограничение мовния птицы
    if (bird_y < 0) bird_y = 0;
    if (bird_y >= game_height) {
        game_over = true;
    }
}

void FlappyBird::updatePipes() {
    for (auto& pipe : pipes) {
        pipe.x--;
        
        // Проверка прохода через трубу
        if (pipe.x == bird_x && !pipe.passed) {
            if (bird_y >= pipe.gap_y && bird_y < pipe.gap_y + 4) {
                pipe.passed = true;
                score++;
            }
        }
    }
    
    // Удаление вышедших труб
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
        [this](const Pipe& p) { return p.x < -2; }), pipes.end());
}

void FlappyBird::checkCollisions() {
    for (const auto& pipe : pipes) {
        if (pipe.x == bird_x) {
            if (bird_y < pipe.gap_y || bird_y >= pipe.gap_y + 4) {
                game_over = true;
            }
        }
    }
}

void FlappyBird::generatePipe() {
    Pipe pipe;
    pipe.x = game_width - 1;
    pipe.gap_y = rand() % (game_height - 6);
    pipe.passed = false;
    pipes.push_back(pipe);
}

void FlappyBird::resetGame() {
    bird_y = 8;
    velocity = 0;
    score = 0;
    game_over = false;
    frame_count = 0;
    pipes.clear();
}

void FlappyBird::shutdown() {
    std::cout << "[Flappy Bird] Shutting down" << std::endl;
}