#include "Window.hpp"

Window::Window(int width, int height, std::string title) {
    window.create(sf::VideoMode(width, height), title);
}

void Window::draw() {
    window.clear();

    for (std::shared_ptr<Projectile> projectile : projectiles) {
        projectile->draw(window);
    }

    for (std::shared_ptr<Block> block : blocks) {
        block->draw(window);
    }    

    window.display();
}

bool Window::isOpen() {
    return window.isOpen();
}

void Window::pollEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

// Adds a projectile to the window
void Window::addProjectile(std::shared_ptr<Projectile> projectile) {
    projectiles.push_back(projectile);
}

// Adds a block to the window
void Window::addBlock(std::shared_ptr<Block> block) {
    blocks.push_back(block);
}

float Window::getDeltaTime() {
    return clock.restart().asSeconds();
}