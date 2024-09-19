#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "GameObject.hpp"

class Projectile : public GameObject {
    public:
        Projectile(float x, float y, int speed, std::shared_ptr<Shape> shape, sf::Vector2f direction);
        std::shared_ptr<Shape> getShape();
        sf::Vector2f getDirection();
        void bounceX();
        void bounceY();

    private:
        sf::Vector2f direction;

};

#endif