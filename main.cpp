#include "GameObject.hpp"
#include "Window.hpp"
#include "Block.hpp"
#include "Projectile.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"

int main() {
    Window window(1920, 1080, "Casse Brique");

    auto rectangleShape = std::make_shared<RectangleShape>(1000, 100, 50, 50, sf::Color::Red);
    auto circleShape = std::make_shared<CircleShape>(200, 200, 25, sf::Color::Blue);

    auto projectile = std::make_shared<Projectile>(100, 100, 1000, circleShape);
    auto block = std::make_shared<Block>(200, 200, 0, rectangleShape);

    window.addProjectile(projectile);
    window.addBlock(block);

    float deltaTime = 0.0;

    while (window.isOpen()) {
        window.pollEvents();
        
        deltaTime = window.getDeltaTime();
        projectile->move(deltaTime, 45);

        window.draw();

        
    }
    return 0;
}