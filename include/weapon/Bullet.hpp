#ifndef BULLET_HPP
#define BULLET_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Bullet {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string path;
    float maxSpeed;
    float scale;
    sf::Vector2f currentVelocity;
public:
    Bullet(std::string path, float maxSpeed = 15.f, float scale = 0.07f, sf::Vector2f currentVelocity = {0.0, 0.0});
    ~Bullet();
    void setOrigin(float x, float y);
    void setCurrentVelocity(sf::Vector2f currentVelocity);
    void setRotation(float angle);
    void setPosition(float x, float y);
    float getMaxSpeed();
    sf::Vector2f getPosition();
    void move();
    void render(sf::RenderTarget* target); 
};

#endif