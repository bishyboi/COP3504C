#pragma once
#include <SFML/Graphics.hpp>

class Button {
    public:
        sf::Vector2f position;
        sf::Sprite sprite;

        Button(sf::Vector2f _position, std::function<void(void)> _onClick);

        // Returns position of button
        sf::Vector2f getPosition();

        // Returns the current sprite of the button
        sf::Sprite* getSprite();

        // Sets the button's visualization to the specified sprite
        virtual void setSprite(sf::Sprite* _sprite);

        virtual void onClick();
};

class DebugButton : public Button {
    DebugButton() : Button();
    onClick();
}