#include "Platform.hpp"

Platform::Platform(float x, float y, int speed, std::shared_ptr<Shape> shape) : GameObject(x, y, speed, shape) {
}

std::shared_ptr<Shape> Platform::getShape() {
    return shape;
}

void Platform::move(std::string direction) {
    if (direction == "left") {
        x -= speed;
    } else if (direction == "right") {
        x += speed;
    }
    shape->setPosition(x, y);
}