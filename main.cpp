#include "Window.hpp"
#include "Game.hpp"
#include "Projectile.hpp"
#include "Block.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "Grid.hpp"


#include <iostream>

int main() {
    const int screenWidth = 2000;
    const int screenHeight = 1400;

    Window window(screenWidth, screenHeight, "Casse Brique");
    Game game;

    Grid grid(screenWidth, screenHeight, 5, screenWidth/20);
    game.setBlocks(grid.generateBlocks());
    

    auto circleShape = std::make_shared<CircleShape>(200, 200, 25, sf::Color::Blue);

    auto projectile = std::make_shared<Projectile>(550, 600, 400, circleShape, sf::Vector2f(1,-1));

    game.addProjectile(projectile);


    game.run(window);

    return 0;
}