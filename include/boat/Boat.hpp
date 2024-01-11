#ifndef BOAT_HPP
#define BOAT_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "weapon/Cannon.hpp"
#include "weapon/CannonBall.hpp"
#include "system/Animation.hpp"

class Boat {
protected:
    sf::Texture texture;
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    sf::Clock clock;

    Cannon* cannon;
    CannonBall* cannonBall;
    Animation animation;

    float movementSpeed;
public:
    // Boat(float x, float y, float movementSpeed, float switchTime, std::string path, int imageCount, int defaultImage);
    Boat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* CannonBall, float frameSwitchTime, int frameAmount, int frameMinimum, int frameDefault);
    virtual ~Boat() {}
    void upward();
    void downward();
    void forward();
    void backward();
    void setIsFire(bool isFire);
    bool getIsFire();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    virtual void updateRotation() = 0;
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);


    virtual float getMovementSpeed() const;
    virtual void moveTowardsPlayer(const sf::Vector2f& playerPosition);
};

#endif