#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>

#include "GameObject.hpp"
#include "Projectile.hpp"
#include "Block.hpp"
#include "Platform.hpp"

class Window {
    private:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock clock;
        float deltaTime;

    public:
        Window(int width, int height, std::string title);
        void draw(std::vector<std::shared_ptr<Projectile>> projectiles, std::vector<std::shared_ptr<Block>> blocks, std::shared_ptr<Platform> platform);
        bool isOpen();
        void pollEvents(std::shared_ptr<Platform>& platform);
        float getDeltaTime();
        int getWidth();
        int getHeight();
        void lose();
};

#endif