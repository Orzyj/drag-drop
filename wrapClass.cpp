#include "wrapClass.hpp"

//private functions
const bool Game::isOpen() const{
    return window->isOpen();
}

/*updating window*/
void Game::update(){
    int idHoldingObject = identifyObject();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(idHoldingObject != 100){
            shapes[idHoldingObject].isDrag = true;
            dragObject(idHoldingObject);
        }
    } else {
        shapes[idHoldingObject].isDrag = false;
    }


    poolEvent();
    fallingCircleShapes();
}

/*rendering window*/
void Game::render(){
    window->clear();

    //draw section
   for(unsigned int i = 0; i < shapes.size(); i++){
       window->draw(shapes[i].shape);
   }

    window->display();
}

/*checking events*/
void Game::poolEvent(){
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    window->close();
                    break;
        }
    }
}
/*returning mouse position*/
sf::Vector2f Game::getMousePosition(){
    return sf::Vector2f(
        sf::Mouse::getPosition(*window).x,
        sf::Mouse::getPosition(*window).y);
}

/*spawning 5 shapes*/
void Game::spawnCircleShapes(){
    for(unsigned short i = 0; i < 5; i++){
        Rect rectShape;

        rectShape.id = i;
        rectShape.shape.setFillColor(sf::Color::Blue);
        rectShape.shape.setSize(sf::Vector2f(100, 50));
        rectShape.shape.setPosition(sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT - 50));

        shapes.push_back(rectShape);
    }
}

//public functions
/*constructor*/
Game::Game(){
    window = nullptr;
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;

    window = new sf::RenderWindow(videoMode, "Foo");
    window->setFramerateLimit(144);
    
    spawnCircleShapes();
}

/*deconstructor*/
Game::~Game(){
    delete window;
}

/*start app*/
void Game::run() {
    while(isOpen()){
        update();
        render();
    }
}

//game functions
/*falling each shape*/
void Game::fallingCircleShapes(){
    for(unsigned int i = 0; i < shapes.size(); i++){
        float y = shapes[i].shape.getPosition().y;
        float x = shapes[i].shape.getPosition().x;

        if(y <= WINDOW_HEIGHT - 50 && !shapes[i].isDrag){
            y += 2.f;
            shapes[i].shape.setPosition(x, y);
        }
        else 
            continue;
    }
}

/*identify shapes en @return the correctly id*/
int Game::identifyObject(){
    sf::Vector2f mousePosition = getMousePosition();

    for(unsigned int i = 0; i < shapes.size(); i++){
       if((shapes[i].shape.getPosition().x <= mousePosition.x &&
          shapes[i].shape.getPosition().x + 100 >= mousePosition.x) &&
          (shapes[i].shape.getPosition().y + 50>= mousePosition.y &&
          shapes[i].shape.getPosition().y <= mousePosition.y))
            return shapes[i].id;     
    }
    return 100;
}

/*dragging and setting new position*/
void Game::dragObject(int idObject){
    sf::Vector2f mousePositon = getMousePosition();
    shapes[idObject].shape.setPosition(mousePositon.x - 50, mousePositon.y - 25);
}