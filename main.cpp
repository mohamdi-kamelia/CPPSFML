#include "GameObject.hpp"
#include "Window.hpp"
#include "Block.hpp"
#include "Projectile.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "Collision.hpp"
#include "Game.hpp"

#include <iostream>

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Window window(screenWidth, screenHeight, "Casse Brique");
    Game game;

    auto rectangleShape = std::make_shared<RectangleShape>(1000, 100, 50, 50, sf::Color::Red);
    auto circleShape = std::make_shared<CircleShape>(200, 200, 25, sf::Color::Blue);

    auto projectile = std::make_shared<Projectile>(550, 600, 400, circleShape, sf::Vector2f(1,-1));
    auto block = std::make_shared<Block>(200, 200, 0, rectangleShape, 3);

    game.addProjectile(projectile);
    game.addBlock(block);

    game.run(window);
    
    return 0;
}