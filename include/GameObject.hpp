#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Shape.hpp"
#include <memory>
#include <cmath>

class GameObject {
    protected:
        float x, y;
        int speed;
        std::shared_ptr<Shape> shape;

    public:
        GameObject(float x, float y, int speed, std::shared_ptr<Shape> shape);
        float getX();
        float getY();
        int getSpeed();
        void draw(sf::RenderWindow &window);
        void move(float deltaTime, sf::Vector2f direction);

};

#endif
