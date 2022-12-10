#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <string>

class Button {
    public:
        sf::Vector2f position;
        sf::Sprite *sprite;
        std::function<void(void)> myClick;
        

        inline Button(sf::Vector2f _position, std::function<void(void)> _onClick){
            this->position = _position;
            myClick = _onClick;
        }
        // Returns position of button
        inline sf::Vector2f getPosition() { return this->position;}

        // Returns the current sprite of the button
        inline sf::Sprite* getSprite() {return sprite;}

        // Sets the button's visualization to the specified sprite
        inline void setSprite(sf::Sprite* _sprite) {
            this->sprite = _sprite;
            this->sprite->setPosition(this->position);
        }

        inline void onClick() { myClick();}


        static void debugClick(){
            std::cout<< "Debug";
        }

        static void newGameClick(){
            std::cout << "New Game";
        }

        static void test1Click(){
            std::cout<< "Test 1";
        }

        static void test2Click(){
            std::cout<< "Test 2";
        }

        
        static sf::Sprite* generateSprite(std::string filename)
        {
            sf::Texture* spriteTexture = new sf::Texture;

            if(!spriteTexture->loadFromFile(filename))
                std::cerr<< "Image not loaded for debug texture";

            sf::Sprite* sprite = new sf::Sprite;
            sprite->setTexture(*spriteTexture);

            return sprite;
        }
};
