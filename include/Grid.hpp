#ifndef GRID_HPP
#define GRID_HPP

#include "Block.hpp"
#include "RectangleShape.hpp"
#include <random>
#include <vector>
#include <memory>

class Grid {
    public:
        Grid(int width, int height, int rows, int cols);
        std::vector<std::shared_ptr<Block>> generateBlocks();
        void addBlock(std::shared_ptr<Block> block);

    private:
        int width;
        int height;
        int rows;
        int cols;
        std::vector<std::shared_ptr<Block>> blocks;
        int blockWidth;
        int blockHeight;
};
  
#endif