#include "CircleShape.hpp"

CircleShape::CircleShape(float x, float y, float radius, sf::Color color) {
    circle.setPosition(x, y);
    circle.setRadius(radius);
    circle.setFillColor(color);
}

void CircleShape::draw(sf::RenderWindow& window) {
    window.draw(circle);
}

sf::FloatRect CircleShape::getBounds() {
    return circle.getGlobalBounds();
}

void CircleShape::setPosition(float x, float y) {
    circle.setPosition(x, y);
}

void CircleShape::setColor(sf::Color color) {
    circle.setFillColor(color);
}