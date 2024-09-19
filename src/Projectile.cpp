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

// Inverts the x direction of the projectile
void Projectile::bounceX() {
    direction.x = -direction.x;
}

// Inverts the y direction of the projectile
void Projectile::bounceY() {
    direction.y = -direction.y;
}