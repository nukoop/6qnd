#ifndef BOAT_HPP
#define BOAT_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "weapon/Cannon.hpp"
#include "system/Animation.hpp"

class Boat {
private:
    sf::Texture texture;
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    sf::Clock clock;

    Cannon* cannon;
    Animation* animation;

    float movementSpeed;
    std::string path;
    int imageCount;
    int defaultImage;
public:
    Boat(float x, float y, int imageCount, int defaultImage);
    virtual ~Boat();

    void updateInput();
    void update(const sf::RenderWindow &window);
    void render(sf::RenderTarget* target);
};

#endif