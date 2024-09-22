#include "Window.hpp"

Window::Window(int width, int height, std::string title) {
    window.create(sf::VideoMode(width, height), title);
}

void Window::draw(std::vector<std::shared_ptr<Projectile>> projectiles, std::vector<std::shared_ptr<Block>> blocks) {
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

float Window::getDeltaTime() {
    return clock.restart().asSeconds();
}

int Window::getWidth() {
    return window.getSize().x;
}

int Window::getHeight() {
    return window.getSize().y;
}