#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <string>

#include "boat/AlphaBoat.hpp"
#include "weapon/AlphaCannon.hpp"
#include "weapon/SimpleCannonBall.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    SimpleCannonBall simpleCannonBall;
    AlphaCannon alphaCannon;
    AlphaBoat player;
public:
    Game();
    virtual ~Game();

    const bool running() const;

    void pollEvent();
    void updateInput();
    void update();
    void render();
};

#endif