#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
    private:
        int x, y;
        int width, height;
        int speed;
        sf::Color color;

    public:
        GameObject(int x, int y, int width, int height, int speed);

};

#endif
