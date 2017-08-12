#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
    private:
        int speed;

    public:
        Paddle(int x, int y, int width, int height);
        sf::RectangleShape rectangle{sf::Vector2f(10, 20)};
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        void updatePosition();
};
