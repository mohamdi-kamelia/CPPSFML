#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::FloatRect getBounds() = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setColor(sf::Color color) = 0;
};

#endif