#include "Collision.hpp"

// Returns true if the block and projectile are colliding, false otherwise.
bool Collision::checkCollision(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile) {
    return block->getShape()->getBounds().intersects(projectile->getShape()->getBounds());
}

// Returns a string representing the side of the block that the projectile collided with. (top, bottom, left, right)
std::string Collision::checkSide(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile) {
    sf::FloatRect blockBounds = block->getShape()->getBounds();
    sf::FloatRect projectileBounds = projectile->getShape()->getBounds();

    float blockCenterX = blockBounds.left + blockBounds.width / 2.0f;
    float blockCenterY = blockBounds.top + blockBounds.height / 2.0f;
    float projectileCenterX = projectileBounds.left + projectileBounds.width / 2.0f;
    float projectileCenterY = projectileBounds.top + projectileBounds.height / 2.0f;

    float dx = projectileCenterX - blockCenterX;
    float dy = projectileCenterY - blockCenterY;

    float absDX = std::abs(dx);
    float absDY = std::abs(dy);

    if (absDX > absDY) {
        return dx > 0 ? "right" : "left";
    } else {
        return dy > 0 ? "bottom" : "top";
    }
}