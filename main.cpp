#include "headers.hpp"
#include "wrapClass.hpp"

int main(int arg, char** argv){
    //setting random
    srand(time(NULL));
    //creating main objects
    Game game;
    //start app
    game.run();
    
    return 0;
}