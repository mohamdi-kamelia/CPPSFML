#include "GameObject.hpp"
#include "Window.hpp"
#include "Block.hpp"
#include "Projectile.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "Collision.hpp"

#include <iostream>

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Window window(screenWidth, screenHeight, "Casse Brique");

    auto rectangleShape = std::make_shared<RectangleShape>(1000, 100, 50, 50, sf::Color::Red);
    auto circleShape = std::make_shared<CircleShape>(200, 200, 25, sf::Color::Blue);

    auto projectile = std::make_shared<Projectile>(550, 600, 400, circleShape, sf::Vector2f(1,-1));
    auto block = std::make_shared<Block>(200, 200, 0, rectangleShape);

    window.addProjectile(projectile);
    window.addBlock(block);

    float deltaTime = 0.0;

    while (window.isOpen()) {
        window.pollEvents();
            
        deltaTime = window.getDeltaTime();
        projectile->move(deltaTime, projectile->getDirection());

        if (Collision::checkCollision(block, projectile)) {
            std::string side = Collision::checkSide(block, projectile);
            if (side == "top" || side == "bottom") {
                projectile->bounceY();
            } else {
                projectile->bounceX();
            }
        }

        if (Collision::checkBorderCollision(projectile, screenWidth, screenHeight) != "") {
            std::string side = Collision::checkBorderCollision(projectile, screenWidth, screenHeight);
            if (side == "top" || side == "bottom") {
                projectile->bounceY();
            } else {
                projectile->bounceX();
            }
        }

        window.draw();
        std::cout << projectile->getDirection().x << " " << projectile->getDirection().y << std::endl;
        
    }
    return 0;
}