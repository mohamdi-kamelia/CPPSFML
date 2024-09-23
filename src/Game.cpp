#include "Game.hpp"

Game::Game() {
}

// Runs the Game
void Game::run(Window& window) {
    while (window.isOpen()) {
        window.pollEvents(platform);

        deltaTime = window.getDeltaTime();

        // Move projectiles and handle border collisions
        for (std::shared_ptr<Projectile> projectile : projectiles) {
            projectile->move(deltaTime, projectile->getDirection());
            std::string side = Collision::checkBorderCollision(projectile, window.getWidth(), window.getHeight());
            if (side == "top") {
                projectile->bounceY();
            } else if (side == "left" || side == "right") {
                projectile->bounceX();
            }
            if (Collision::checkPlatformCollision(platform, projectile)) {
                projectile->bounceY();
            }
        }

        // Store collision results
        std::vector<std::pair<std::shared_ptr<Block>, std::shared_ptr<Projectile>>> collisions;
        std::vector<std::shared_ptr<Block>> blocksToRemove;

        // Detect collisions
        for (std::shared_ptr<Block> block : blocks) {
            for (std::shared_ptr<Projectile> projectile : projectiles) {
                if (Collision::checkCollision(block, projectile)) {
                    collisions.push_back({block, projectile});
                }
            }
        }

        // Handle collisions
        for (auto& collision : collisions) {
            std::shared_ptr<Block> block = collision.first;
            std::shared_ptr<Projectile> projectile = collision.second;

            std::string side = Collision::checkSide(block, projectile);
            // Makes the projectile bounce and move it to the edge of the block to prevent it from getting stuck and trigger the collision again
            if (side == "top" || side == "bottom") {
                projectile->bounceY();
                if (side == "top") {
                    projectile->setY(block->getShape()->getBounds().top - projectile->getShape()->getBounds().height);
                } else {
                    projectile->setY(block->getShape()->getBounds().top + block->getShape()->getBounds().height);
                }
            } else if (side == "left" || side == "right") {
                projectile->bounceX();
                if (side == "left") {
                    projectile->setX(block->getShape()->getBounds().left - projectile->getShape()->getBounds().width);
                } else {
                    projectile->setX(block->getShape()->getBounds().left + block->getShape()->getBounds().width);
                }
            }

            block->handleHit();
            if (block->isDestroyed()) {
                blocksToRemove.push_back(block);
            }
        }

        // Remove destroyed blocks
        for (std::shared_ptr<Block> block : blocksToRemove) {
            removeBlock(block);
        }

        // Draw the window
        window.draw(projectiles, blocks, platform);
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
    blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
}

void Game::setBlocks(std::vector<std::shared_ptr<Block>> blocks) {
    this->blocks = blocks;
}

// Handles events
void Game::handleEvents(Window& window) {
    std::vector<sf::Event> events = window.getEvents();
    for (sf::Event event : events) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                platform->move("left");
                std::cout << "Q" << std::endl;
            }
            else if (event.key.code == sf::Keyboard::D) {
                platform->move("right");
                std::cout << "D" << std::endl;
            }
        }
        }
    events.clear();
}

void Game::addPlatform(std::shared_ptr<Platform>& platform) {
    this->platform = platform;
}