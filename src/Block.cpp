#include "Block.hpp"

Block::Block(float x, float y, int speed, std::shared_ptr<Shape> shape, int life) : GameObject(x, y, speed, shape) {
    this->life = life;
    calculateColor();
}

std::shared_ptr<Shape> Block::getShape() {
    return shape;
}

void Block::handleHit() {
    life--;
    calculateColor();
}

bool Block::isDestroyed() {
    return life <= 0;
}

void Block::setColor(sf::Color color) {
    shape->setColor(color);
}

void Block::calculateColor() {
    if (life == 3) {
        setColor(sf::Color::Green);
    } else if (life == 2) {
        setColor(sf::Color::Blue);
    } else if (life == 1) {
        setColor(sf::Color::Red);
    }
}