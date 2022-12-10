#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Toolbox.h"
#include "Button.h"
class Tile{
    public:
        // Represents tile's current UI state 
        enum State { REVEALED, HIDDEN, FLAGGED, EXPLODED };

        sf::Vector2f position;

        const sf::Sprite* tileHidden = Button::generateSprite("../images/tile_hidden.png");
        const sf::Sprite* tileRevealed = Button::generateSprite("../images/tile_revealed.png");

        State tileState = HIDDEN; 
        
        std::array<Tile*, 8> neighbors;

        // Constructs a new tile object at the designated _position
        inline Tile(sf::Vector2f _position){
            this->position = _position;
        }

        // Returns the position of the Tile
        inline sf::Vector2f getLocation(){
            return this->position;
        }

        // Returns current state of this tile
        inline State getState(){
            return this->tileState;
        }

        /*
        Returns a pointer to array of Tile pointers 
        [ 0 ,  1,    2]
        [ 3, SOURCE, 4]
        [5,    6,    7]

        */
       
        inline std::array<Tile*, 8>& getNeighbors(){
            return (this->neighbors);
        }

        // Sets the state of the tile
        inline void setState(State _state){
            this->tileState = _state;
        }

        // Populates / replaces the neighboring tile containers
        inline void setNeighbors(std::array<Tile*, 8> _neighbors){
            this->neighbors = _neighbors;
        }

        // Defines the reveal behavior for a tile when the left mouse button
        inline void onClickLeft(){
            if(this->getState() == HIDDEN){
                this->setState(REVEALED);
            }
        }

        // Toggle this tile's state between FLAGGED and HIDDEN
        inline void onClickRight(){
            if(this->getState() == HIDDEN){
                this->setState(FLAGGED);
            } else if(this->getState() == FLAGGED){
                this->setState(HIDDEN);
            }
        }

        // Render this tile to the screen according to is state
        void draw();

    protected:
        // Based on State and mine content of the tile neighbors, set their state to REVEALED
        void revealNeighbors();
};
