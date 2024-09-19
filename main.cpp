#include "GameObject.hpp"
#include "Window.hpp"
#include "Block.hpp"
#include "Projectile.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "Collision.hpp"

#include <iostream>

int main() {
    Window window(1920, 1080, "Casse Brique");

    auto rectangleShape = std::make_shared<RectangleShape>(1000, 100, 50, 50, sf::Color::Red);
    auto circleShape = std::make_shared<CircleShape>(200, 200, 25, sf::Color::Blue);

    auto projectile = std::make_shared<Projectile>(100, 100, 400, circleShape, 0);
    auto block = std::make_shared<Block>(200, 200, 0, rectangleShape);

    window.addProjectile(projectile);
    window.addBlock(block);

    float deltaTime = 0.0;

    while (window.isOpen()) {
        window.pollEvents();
        
        deltaTime = window.getDeltaTime();
        projectile->move(deltaTime, projectile->getDirection());

        if (Collision::checkCollision(block, projectile)) {
            std::cout << "Collision detected" << std::endl;
        }

        window.draw();
        
    }
    return 0;
}