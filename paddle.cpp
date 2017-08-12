#include "paddle.h"

Paddle::Paddle(int x, int y, int width, int height) {
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, height));
}

int Paddle::getX() {
    return rectangle.getPosition().x;
}

int Paddle::getY() {
    return rectangle.getPosition().y;
}

void Paddle::setX(int x) {
    rectangle.setPosition(x, rectangle.getPosition().y);
}

void Paddle::setY(int y) {
    rectangle.setPosition(rectangle.getPosition().x, y);
}

void Paddle::updatePosition() {

}
