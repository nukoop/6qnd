#ifndef CANNON_HPP
#define CANNON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Cannon {
private:
    
    
protected:
    

public:
    sf::Texture texture;
    sf::Sprite sprite;

    Cannon(float& x, float& y);
    ~Cannon();

    void render(sf::RenderTarget* target);
};

#endif