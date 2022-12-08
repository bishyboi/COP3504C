#include <iostream>
#include "minesweeper.h"


int launch(){
    //Toolbox toolbox = Toolbox::getInstance();
    
    // From SFML Tutorials: https://www.sfml-dev.org/tutorials/2.5/window-window.php 
    while(Toolbox::getInstance().window.isOpen()){
        gameLoop();
    }
    
    return 0;
}

bool gameLoop(){
    // check all the window's events that were triggered since the last iteration of the loop

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (Toolbox::getInstance().window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            Toolbox::getInstance().window.close();
            return false;
    }

    // clear the window with black color
    Toolbox::getInstance().window.clear(sf::Color::Black);

    // draw everything here...
    // window.draw(...);

    // end the current frame
    Toolbox::getInstance().window.display();

    return true;
}

int main(){
    launch();
}