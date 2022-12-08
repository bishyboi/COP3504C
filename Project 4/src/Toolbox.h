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

        GameState* gameState  = nullptr; //Primary game state representation

        Button* debugButton   = nullptr; // Reveals mines in debug mode
        Button* newGameButton = nullptr; // Resets / starts new game
        Button* testButton1   = nullptr; // Loads test board #1
        Button* testButton2   = nullptr; // Loads test board #2

        // Returns reference to Toolbox singleton
        inline static Toolbox& getInstance() {
            static Toolbox toolbox;
            return toolbox;
        }
};