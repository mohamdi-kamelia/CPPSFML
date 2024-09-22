#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include "Block.hpp"
#include "Projectile.hpp"
#include "Window.hpp"
#include "Collision.hpp"

class Game {
    public:
        Game();
        void run(Window& window);
        void addBlock(std::shared_ptr<Block> block);
        void addProjectile(std::shared_ptr<Projectile> projectile);
        void removeBlock(std::shared_ptr<Block> block);


    private:
        std::vector<std::shared_ptr<Block>> blocks;
        std::vector<std::shared_ptr<Projectile>> projectiles;
        float deltaTime;
};

#endif