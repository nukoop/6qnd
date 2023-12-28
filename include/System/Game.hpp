#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "boat/Boat.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    Boat player;
public:
    Game();
    virtual ~Game();

    const bool running() const;

    void pollEvent();
    void update();
    void render();
};

#endif