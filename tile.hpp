#ifndef TILE_HPP
#define TILE_HPP

#include "headers.hpp"

class Rect{
    public:
        int id;
        sf::RectangleShape shape;
        bool isDrag = false;
};

#endif