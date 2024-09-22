#include "Game.hpp"

// Constructor
Game::Game() {
}

// Runs the Game
void Game::run(Window& window) {
    while (window.isOpen()) {
        window.pollEvents();

        deltaTime = window.getDeltaTime();

        for (std::shared_ptr<Projectile> projectile : projectiles) {
            projectile->move(deltaTime, projectile->getDirection());
            if (Collision::checkBorderCollision(projectile, window.getWidth(), window.getHeight()) != "") {
                std::string side = Collision::checkBorderCollision(projectile, window.getWidth(), window.getHeight());
                if (side == "top" || side == "bottom") {
                    projectile->bounceY();
                } else {
                    projectile->bounceX();
                }
            }
    }

        for (std::shared_ptr<Block> block : blocks) {
            for (std::shared_ptr<Projectile> projectile : projectiles) {
                 if (Collision::checkCollision(block, projectile)) {
                    std::string side = Collision::checkSide(block, projectile);
                    if (side == "top" || side == "bottom") {
                        projectile->bounceY();
                    } else {
                        projectile->bounceX();
                    }
                    block->handleHit();
                    if (block->isDestroyed()) {
                        removeBlock(block);
                    }
                }
            }
        }     

        window.draw(projectiles, blocks);
        
    }
}


// Adds a projectile to the Game
void Game::addProjectile(std::shared_ptr<Projectile> projectile) {
    projectiles.push_back(projectile);
}

// Adds a block to the Game
void Game::addBlock(std::shared_ptr<Block> block) {
    blocks.push_back(block);
}

// Removes a block from the Game
void Game::removeBlock(std::shared_ptr<Block> block) {
    blocks.erase(std::remove(blocks.begin(), blocks.end(), block));
}