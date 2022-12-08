#pragma once
#include <SFML/Graphics.hpp>

class Tile{
    public:
        // Constructs a new tile object at the designated _position
        Tile(sf::Vector2f _position);

        // Represents tile's current UI state 
        enum State { REVEALED, HIDDEN, FLAGGED, EXPLODED };

        // Returns the position of the Tile
        sf::Vector2f getLocation();

        // Returns current state of this tile
        State getState();

        /*
        Returns a pointer to array of Tile pointers 
        [ 0 ,  1,    2]
        [ 3, SOURCE, 4]
        [5,    6,    7]
        */
        std::array<Tile*, 8>& getNeighbors();

        // Sets the state of the tile
        void setState(State _state);

        // Populates / replaces the neighboring tile containers
        void setNeighbors(std::array<Tile*, 8> _neighbors);

        // Defines the reveal behavior for a tile when the left mouse button
        void onClickLeft();

        // Toggle this tile's state between FLAGGED and HIDDEN
        void onClickRight();

        // Render this tile to the screen according to is state
        void draw();

    protected:
        // Based on State and mine content of the tile neighbors, set their state to REVEALED
        void revealNeighbors();
};