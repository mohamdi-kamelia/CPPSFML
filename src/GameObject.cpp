#include "GameObject.hpp"

GameObject::GameObject(float x, float y, int speed, std::shared_ptr<Shape> shape) 
    : x(x), y(y), speed(speed), shape(shape) {
    if (!shape) {
        throw std::invalid_argument("Shape cannot be null");
    }
}

float GameObject::getX() {
    return x;
}

float GameObject::getY() {
    return y;
}

int GameObject::getSpeed() {
    return speed;
}

void GameObject::draw(sf::RenderWindow &window) {
    shape->draw(window);
}

void GameObject::move(float deltaTime, float direction) {
    float radians = direction * (3.14159265 / 180.0);
    float dx = speed * deltaTime * cos(radians);
    float dy = speed * deltaTime * sin(radians);
    x += dx;
    y += dy;

    shape->setPosition(x, y);
}