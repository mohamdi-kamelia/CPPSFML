#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "GameObject.hpp"

class Block : public GameObject {
private:
    int life;

public:
    Block(float x, float y, int speed, std::shared_ptr<Shape> shape, int life);
    std::shared_ptr<Shape> getShape();
    void handleHit();
    bool isDestroyed();
    void setColor(sf::Color color);
    void calculateColor();
};

#endif