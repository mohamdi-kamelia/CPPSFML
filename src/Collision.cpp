#include "Collision.hpp"

bool Collision::checkCollision(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile) {
    return block->getShape()->getBounds().intersects(projectile->getShape()->getBounds());
}