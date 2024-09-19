#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "GameObject.hpp"

class Block : public GameObject {
public:
    Block(float x, float y, int speed, std::shared_ptr<Shape> shape);
    std::shared_ptr<Shape> getShape();
};

#endif