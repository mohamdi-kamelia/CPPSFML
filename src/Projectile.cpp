#include "Projectile.hpp"

Projectile::Projectile(float x, float y, int speed, std::shared_ptr<Shape> shape, float direction) : GameObject(x, y, speed, shape) {
    this->direction = direction;
}

std::shared_ptr<Shape> Projectile::getShape() {
    return shape;
}

float Projectile::getDirection() {
    return direction;
}