#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics.hpp>

#include "Block.hpp"
#include "Projectile.hpp"

class Collision {
public:
    static bool checkCollision(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile);
};

#endif