#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class PlayStatus{
    protected:
        PlayStatus();

    friend class GameState;
};

class GameState{
    public:
        GameState(sf::Vector2f _dimensions = sf::Vector2f(25, 16), int _numberOfMines = 50);

        GameState(const char* filepath);

        int getFlagCount();

        int getMineCount();

        Tile* getTile(int x, int y);

        PlayStatus getPlayStatus();

        void setPlayStatus(PlayStatus _status);
};

