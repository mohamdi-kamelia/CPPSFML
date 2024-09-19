#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "GameObject.hpp"

class Projectile : public GameObject {
    public:
        Projectile(float x, float y, int speed, std::shared_ptr<Shape> shape, float direction);
        std::shared_ptr<Shape> getShape();
        float getDirection();

    private:
        float direction;

};

#endif