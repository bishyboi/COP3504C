#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"
#include "Tile.h"
#include "Toolbox.h"

int launch();

void restart();

void render();

void toggleDebugMode();

bool getDebugMode();

bool gameLoop();

bool wasClicked(Button* button);

bool wasClicked(sf::Sprite* sprite);