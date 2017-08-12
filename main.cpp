#include <chrono>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace std::chrono_literals;
// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

int main() {
    Paddle leftPaddle(10, 10, 10, 100);
    Paddle rightPaddle(40, 40, 10, 10);

    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Pong");

    using clock = std::chrono::high_resolution_clock;
    std::chrono::nanoseconds lag(0ns);
    auto time_start = clock::now();

    while (window.isOpen()) {
        auto delta_time = clock::now() - time_start;
        time_start = clock::now();
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

        // std::cout << lag.count() << std::endl;

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::W))) {
            leftPaddle.setY(leftPaddle.getY() - 0.00000000005f * lag.count());
        }

        if (sf::Keyboard::isKeyPressed((sf::Keyboard::S))) {
            leftPaddle.setY(leftPaddle.getY() + 0.00000000005f * lag.count());
        }

        window.clear();

        window.draw(leftPaddle.rectangle);

        window.display();
    }

    return 0;
}
