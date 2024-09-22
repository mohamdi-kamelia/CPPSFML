#include "RectangleShape.hpp"

RectangleShape::RectangleShape(float x, float y, int width, int height, sf::Color color) {
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
}

void RectangleShape::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

sf::FloatRect RectangleShape::getBounds() {
    return rectangle.getGlobalBounds();
}

void RectangleShape::setPosition(float x, float y) {
    rectangle.setPosition(x, y);
}

void RectangleShape::setColor(sf::Color color) {
    rectangle.setFillColor(color);
}