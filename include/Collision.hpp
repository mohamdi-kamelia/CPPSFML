#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics.hpp>

#include "Block.hpp"
#include "Projectile.hpp"
#include "Platform.hpp"

class Collision {
public:
    static bool checkCollision(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile);
    static std::string checkBorderCollision(std::shared_ptr<Projectile> projectile, int width, int height);
    static std::string checkSide(std::shared_ptr<Block> block, std::shared_ptr<Projectile> projectile);
    static bool checkPlatformCollision(std::shared_ptr<Platform> platform, std::shared_ptr<Projectile> projectile);
};

#endif