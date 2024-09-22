#ifndef CIRCLESHAPE_HPP
#define CIRCLESHAPE_HPP

#include "Shape.hpp"

class CircleShape : public Shape {
private:
    sf::CircleShape circle;

public:
    CircleShape(float x, float y, float radius, sf::Color color);
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() override;
    void setPosition(float x, float y) override;
    void setColor(sf::Color color);
};

#endif