#include "Window.hpp"

Window::Window(int width, int height, std::string title) {
    window.create(sf::VideoMode(width, height), title);
}

void Window::draw(std::vector<std::shared_ptr<Projectile>> projectiles, std::vector<std::shared_ptr<Block>> blocks, std::shared_ptr<Platform> platform) {
    window.clear();

    for (std::shared_ptr<Projectile> projectile : projectiles) {
        projectile->draw(window);
    }

    for (std::shared_ptr<Block> block : blocks) {
        block->draw(window);
    }
    platform->draw(window);    

    window.display();
}

bool Window::isOpen() {
    return window.isOpen();
}

void Window::pollEvents(std::shared_ptr<Platform>& platform) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                platform->move("left");
            }
            else if (event.key.code == sf::Keyboard::D) {
                platform->move("right");
        }
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

void Window::lose() {
    window.clear();
    sf::Font font;
    font.loadFromFile("../assets/arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("You lost!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, window.getSize().y / 2 - text.getGlobalBounds().height / 2);
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(2));
    window.close();
}