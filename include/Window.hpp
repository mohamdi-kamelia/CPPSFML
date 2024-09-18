#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>

#include "GameObject.hpp"
#include "Projectile.hpp"
#include "Block.hpp"

class Window {
    private:
        sf::RenderWindow window;
        sf::Event event;
        std::vector<std::shared_ptr<Projectile>> projectiles;
        std::vector<std::shared_ptr<Block>> blocks;
        sf::Clock clock;
        float deltaTime;

    public:
        Window(int width, int height, std::string title);
        void draw();
        bool isOpen();
        void pollEvents();
        void addProjectile(std::shared_ptr<Projectile> projectile);
        void addBlock(std::shared_ptr<Block> block);
        float getDeltaTime();
};

#endif