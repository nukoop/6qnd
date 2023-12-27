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
    float totalTime;
    float switchTime;
    int imageCount;
    int curretImage;
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Cannon(float& x, float& y);
    ~Cannon();

    void animate(float deltaTime);
    void updateMouseInput(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
};

#endif