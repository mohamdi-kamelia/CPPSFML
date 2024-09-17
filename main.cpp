#include "GameObject.hpp"
#include <iostream>

int main() {
    GameObject gameObject(0, 0, 100, 100, 5);
    std::cout << "GameObject created!" << std::endl;
    return 0;
}