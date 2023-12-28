#ifndef CANNON_HPP
#define CANNON_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "system/Animation.hpp"
#include "weapon/Bullet.hpp"

class Cannon {
private:
    sf::Texture texture;
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    sf::Texture fireTexture;
    std::vector<sf::Texture> fireTextures;
    sf::Sprite fireSprite;
    sf::Clock clock;

    Animation* animation;

    sf::Clock bulletClock;
    Bullet bullet;
    std::vector<Bullet> bullets;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    float fireRate;

    std::string path;
    std::string firePath;
    int defaultImage;

    void updateMouseInput(const sf::RenderWindow &window);
public:
    bool fire;

    Cannon(float x, float y, int imageCount, int defaultImage);
    ~Cannon();
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
    void setSpritePosition(float x, float y);
    void setFireSpritePosition(float x, float y);
};

#endif