#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "GameObject.hpp"

class Projectile : public GameObject {
public:
    Projectile(float x, float y, int speed, std::shared_ptr<Shape> shape);
};

#endif