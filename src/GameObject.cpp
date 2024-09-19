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

// Move the GameObject in the direction specified by the parameter
void GameObject::move(float deltaTime, sf::Vector2f direction) {
    x += direction.x * speed * deltaTime;
    y += direction.y * speed * deltaTime;
    shape->setPosition(x, y);
}