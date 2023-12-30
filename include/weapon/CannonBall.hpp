#ifndef CANNON_BALL_HPP
#define CANNON_BALL_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class CannonBall {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    float maxSpeed;
    float scale;
    sf::Vector2f currentVelocity;
public:
    CannonBall(float maxSpeed = 15.f, float scale = 0.07f);
    virtual ~CannonBall() {}
    void setOrigin(float x, float y);
    sf::Vector2f getOrigin();
    void setCurrentVelocity(sf::Vector2f currentVelocity);
    sf::Vector2f getCurrentVelocity();
    void setRotation(float angle);
    float getRotation();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void setMaxSpeed(float maxSpeed);
    float getMaxSpeed();
    void update();
    void render(sf::RenderTarget* target); 
};

#endif