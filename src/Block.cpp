#include "Block.hpp"

Block::Block(float x, float y, int speed, std::shared_ptr<Shape> shape) : GameObject(x, y, speed, shape) {
}