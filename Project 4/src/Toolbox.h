#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class Toolbox{
    private:
        inline Toolbox(){}


    public:
        // Taken from https://refactoring.guru/design-patterns/singleton/cpp/example#example-1 
        Toolbox(Toolbox const&)        = delete;
        void operator=(Toolbox const&) = delete;

        sf::RenderWindow window =  sf::RenderWindow(sf::VideoMode(800, 600), "P4 - Minesweeper, Bishoy Pramanik"); // SFML application window

        // static GameState* gameState; //Primary game state representation

        static Button* debugButton;
        
        static Button* newGameButton; // Resets / starts new game
        static Button* testButton1;   // Loads test board #1
        static Button* testButton2;   // Loads test board #2

        // Returns reference to Toolbox singleton
        inline static Toolbox& getInstance(){
            static Toolbox toolbox;
            return toolbox;
        }
};

Button* Toolbox::debugButton = new Button(sf::Vector2f(533,530),   Button::debugClick);
Button* Toolbox::testButton1 = new Button(sf::Vector2f(600,530),   Button::test1Click);
Button* Toolbox::testButton2 = new Button(sf::Vector2f(667,530),   Button::test2Click);
Button* Toolbox::newGameButton = new Button(sf::Vector2f(400,530), Button::newGameClick);

//GameState* Toolbox::gameState = nullptr;