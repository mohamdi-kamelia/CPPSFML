#include "Grid.hpp"

Grid::Grid(int width, int height, int rows, int cols) {
    this->width = width;
    this->height = height;
    this->rows = rows;
    this->cols = cols;
    std::vector<std::shared_ptr<Block>> blocks;
    blockWidth = width / 20;
    blockHeight = height / 20;
    srand(time(0));

}

void Grid::addBlock(std::shared_ptr<Block> block) {
    blocks.push_back(block);
}

std::vector<std::shared_ptr<Block>> Grid::generateBlocks() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool spawn = rand() % 2;
            if (spawn) {
                int hitpoints = rand() % 3 + 1;
                std::shared_ptr<RectangleShape> shape = std::make_shared<RectangleShape>(j * blockWidth, i * blockHeight, blockWidth, blockHeight, sf::Color::Green);
                std::shared_ptr<Block> block = std::make_shared<Block>(j * blockWidth, i * blockHeight, 0, shape, hitpoints);
                addBlock(block);
            }
        }
    }
    return blocks;
}
    