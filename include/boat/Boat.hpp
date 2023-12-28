#ifndef BOAT_HPP
#define BOAT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "weapon/Weapon.hpp"  // 包含射擊功能

#include "weapon/Cannon.hpp"
#include "system/Animation.hpp"

class Boat {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;

    Cannon* cannon;
    Animation* animation;

    float movementSpeed;
    std::string path;
public:
    Boat(float x, float y);
    virtual ~Boat();

    void updateInput();
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
};

#endif