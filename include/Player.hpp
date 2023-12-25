#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float movementSpeed;
    float scale;

    void initVariables();
    void initSprite();
public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

#endif