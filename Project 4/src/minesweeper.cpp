#include <iostream>
#include "minesweeper.h"



int launch(){
    // From SFML Tutorials: https://www.sfml-dev.org/tutorials/2.5/window-window.php 
    
    Toolbox::debugButton->setSprite(Button::generateSprite("../images/debug.png"));

    Toolbox::testButton1->setSprite(Button::generateSprite("../images/test_1.png"));

    Toolbox::testButton2->setSprite(Button::generateSprite("../images/test_2.png"));

    Toolbox::newGameButton->setSprite(Button::generateSprite("../images/face_happy.png"));

    //This loop will handle the rendering of the window
    while(Toolbox::getInstance().window.isOpen()){
        gameLoop();
    }
    
    return 0;
}

bool wasClicked(Button* button){
    auto mouse_pos = sf::Mouse::getPosition(Toolbox::getInstance().window); // Mouse position relative to the window
    auto translated_pos = Toolbox::getInstance().window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
    if(button->getSprite()->getGlobalBounds().contains(translated_pos)) // Rectangle-contains-point check
        return true;
    return false;
}

bool wasClicked(sf::Sprite* sprite){
    auto mouse_pos = sf::Mouse::getPosition(Toolbox::getInstance().window); // Mouse position relative to the window
    auto translated_pos = Toolbox::getInstance().window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
    if(sprite->getGlobalBounds().contains(translated_pos)) // Rectangle-contains-point check
        return true;
    return false;
}

bool gameLoop(){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (Toolbox::getInstance().window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed){
            Toolbox::getInstance().window.close();
            return false;
        }

        if (event.type == sf::Event::MouseButtonPressed){

            if(wasClicked(Toolbox::debugButton)){
                Toolbox::debugButton->onClick();
            } else if (wasClicked(Toolbox::testButton1))
            {
                Toolbox::testButton1->onClick();
            } else if (wasClicked(Toolbox::testButton2))
            {
                Toolbox::testButton2->onClick();
            } else if (wasClicked(Toolbox::newGameButton))
            {
                Toolbox::newGameButton->onClick();
            }
            
        }
    }

    // clear the window with black color
    Toolbox::getInstance().window.clear(sf::Color::Black);

    //render everything
    Toolbox::getInstance().window.draw(*(Toolbox::debugButton->getSprite()));
    Toolbox::getInstance().window.draw(*(Toolbox::testButton1->getSprite()));
    Toolbox::getInstance().window.draw(*(Toolbox::testButton2->getSprite()));
    Toolbox::getInstance().window.draw(*(Toolbox::newGameButton->getSprite()));
    // end the current frame
    Toolbox::getInstance().window.display();

    return true;
}

int main(){
    launch();
}