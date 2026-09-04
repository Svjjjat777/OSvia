#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Snake::Snake()
    : Application("Snake", AppType::GAME),
      current_direction(Direction::RIGHT), next_direction(Direction::RIGHT),
      score(0), game_width(40), game_height(15), game_over(false), frame_count(0) {}

void Snake::init() {
    is_running = true;
    srand(time(0));
    resetGame();
}

void Snake::update() {
    if (!game_over) {
        frame_count++;
        
        // Обновление каждые 3 фрейма
        if (frame_count % 3 == 0) {
            current_direction = next_direction;
            updateSnake();
            checkCollisions();
        }
    }
}

void Snake::render() {
    system("clear");
    std::cout << "\n╔" << std::string(game_width, '═') << "╗" << std::endl;
    
    for (int y = 0; y < game_height; y++) {
        std::cout << "║";
        
        for (int x = 0; x < game_width; x++) {
            Point current = {x, y};
            
            bool is_head = (snake_body[0] == current);
            bool is_body = false;
            
            for (size_t i = 1; i < snake_body.size(); i++) {
                if (snake_body[i] == current) {
                    is_body = true;
                    break;
                }
            }
            
            bool is_food = (food == current);
            
            if (is_head) {
                std::cout << "@";
            } else if (is_body) {
                std::cout << "o";
            } else if (is_food) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        
        std::cout << "║" << std::endl;
    }
    
    std::cout << "╚" << std::string(game_width, '═') << "╝" << std::endl;
    std::cout << "\nScore: " << score << " | Length: " << snake_body.size();
    
    if (game_over) {
        std::cout << " | GAME OVER! Press 'r' to restart or 'exit' to quit";
    } else {
        std::cout << " | WASD/Arrows to move, 'exit' to quit";
    }
    std::cout << std::endl;
}

void Snake::handleInput(const std::string& input) {
    if (input == "exit") {
        is_running = false;
        return;
    }
    
    if (input == "r" && game_over) {
        resetGame();
        return;
    }
    
    if (!game_over) {
        if (input == "w" || input == "up") {
            if (current_direction != Direction::DOWN) {
                next_direction = Direction::UP;
            }
        } else if (input == "s" || input == "down") {
            if (current_direction != Direction::UP) {
                next_direction = Direction::DOWN;
            }
        } else if (input == "a" || input == "left") {
            if (current_direction != Direction::RIGHT) {
                next_direction = Direction::LEFT;
            }
        } else if (input == "d" || input == "right") {
            if (current_direction != Direction::LEFT) {
                next_direction = Direction::RIGHT;
            }
        }
    }
}

void Snake::updateSnake() {
    Point head = snake_body[0];
    
    // Фира жалости
    switch (current_direction) {
        case Direction::UP:
            head.y--;
            break;
        case Direction::DOWN:
            head.y++;
            break;
        case Direction::LEFT:
            head.x--;
            break;
        case Direction::RIGHT:
            head.x++;
            break;
    }
    
    // Обтекание стен
    if (head.x < 0) head.x = game_width - 1;
    if (head.x >= game_width) head.x = 0;
    if (head.y < 0) head.y = game_height - 1;
    if (head.y >= game_height) head.y = 0;
    
    // Проверка это еда
    if (head == food) {
        score += 10;
        snake_body.insert(snake_body.begin(), head);
        generateFood();
    } else {
        snake_body.insert(snake_body.begin(), head);
        snake_body.pop_back();
    }
}

void Snake::generateFood() {
    Point new_food;
    
    do {
        new_food = {rand() % game_width, rand() % game_height};
    } while (isPointInSnake(new_food));
    
    food = new_food;
}

void Snake::checkCollisions() {
    Point head = snake_body[0];
    
    // Проверка коллизии с телом
    for (size_t i = 1; i < snake_body.size(); i++) {
        if (head == snake_body[i]) {
            game_over = true;
            return;
        }
    }
}

void Snake::resetGame() {
    snake_body.clear();
    snake_body.push_back({game_width / 2, game_height / 2});
    current_direction = Direction::RIGHT;
    next_direction = Direction::RIGHT;
    score = 0;
    game_over = false;
    frame_count = 0;
    generateFood();
}

bool Snake::isPointInSnake(const Point& p) const {
    for (const auto& segment : snake_body) {
        if (segment == p) {
            return true;
        }
    }
    return false;
}

void Snake::shutdown() {
    std::cout << "[Snake] Shutting down" << std::endl;
}