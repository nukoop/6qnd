#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "Player.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    Player player;

    void initVariables();
    void initWindow();
public:
    Game();
    virtual ~Game();

    const bool running() const;

    void pollEvent();
    void update();
    void render();
};

#endif