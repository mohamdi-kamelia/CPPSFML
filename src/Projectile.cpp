#include "Projectile.hpp"

Projectile::Projectile(float x, float y, int speed, std::shared_ptr<Shape> shape, sf::Vector2f direction) : GameObject(x, y, speed, shape) {
    this->direction = direction;
}

std::shared_ptr<Shape> Projectile::getShape() {
    return shape;
}

sf::Vector2f Projectile::getDirection() {
    return direction;
}

void Projectile::bounceX() {
    direction.x = -direction.x;
}

void Projectile::bounceY() {
    direction.y = -direction.y;
}