#ifndef RECTANGLESHAPE_HPP
#define RECTANGLESHAPE_HPP

#include "Shape.hpp"

class RectangleShape : public Shape {
private:
    sf::RectangleShape rectangle;

public:
    RectangleShape(float x, float y, int width, int height, sf::Color color);
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() override;
    void setPosition(float x, float y) override;
};

#endif