#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Bullet{
public:
    sf::CircleShape shape;
    sf::Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(15.f) {
        this->shape.setRadius(radius);
        this->shape.setFillColor(sf::Color::Red);
    }
};

#endif