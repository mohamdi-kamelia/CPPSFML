#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "GameObject.hpp"

class Platform : public GameObject {

    public:
        Platform(float x, float y, int speed, std::shared_ptr<Shape> shape);
        std::shared_ptr<Shape> getShape();
        void move(std::string direction);
};

#endif