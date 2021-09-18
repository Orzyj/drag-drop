#ifndef WRAPCLASS_HPP
#define WRAPCLASS_HPP

#include "headers.hpp"
#include "tile.hpp"

class Game{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;
        std::vector<Rect> shapes;

        const bool isOpen() const;
        void update();
        void render();
        void poolEvent();
        sf::Vector2f getMousePosition();
        void spawnCircleShapes();

    public:
        Game();
        ~Game();
        void run();


        //game functions
        void fallingCircleShapes();
        int identifyObject();
        void dragObject(int idObject);
};

#endif