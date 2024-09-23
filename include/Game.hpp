#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include "Block.hpp"
#include "Projectile.hpp"
#include "Window.hpp"
#include "Collision.hpp"
#include "Platform.hpp"

class Game {
    public:
        Game();
        void run(Window& window);
        void addBlock(std::shared_ptr<Block> block);
        void addProjectile(std::shared_ptr<Projectile> projectile);
        void removeBlock(std::shared_ptr<Block> block);
        void setBlocks(std::vector<std::shared_ptr<Block>> blocks);
        void handleEvents(Window& window);
        void addPlatform(std::shared_ptr<Platform>& platform);


    private:
        std::vector<std::shared_ptr<Block>> blocks;
        std::vector<std::shared_ptr<Block>> blocksToRemove;
        std::vector<std::shared_ptr<Projectile>> projectiles;
        std::vector<std::pair<std::shared_ptr<Block>, std::shared_ptr<Projectile>>> collisions;
        std::shared_ptr<Platform> platform;
        float deltaTime;
};

#endif