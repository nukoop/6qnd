#ifndef BOAT_HPP
#define BOAT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "weapon/Cannon.hpp"

class Boat {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;

    Cannon* cannon;

    float movementSpeed;
    float scale;
    float totalTime;
    float switchTime;
    int imageCount;
    int curretImage;

    void initVariables();
    void initSprite();
public:
    Boat(float x = 0.f, float y = 0.f);
    virtual ~Boat();

    void animate(float deltaTime);
    void updateInput();
    void updateMouseInput(const sf::RenderWindow &window);
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
};

#endif