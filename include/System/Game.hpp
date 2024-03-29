#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "boat/Boat.hpp"
#include "boat/AlphaBoat.hpp"
#include "boat/BetaBoat.hpp"
#include "boat/GammaBoat.hpp"
#include "boat/DeltaBoat.hpp"
#include "weapon/AlphaCannon.hpp"
#include "weapon/BetaCannon.hpp"
#include "weapon/DeltaCannon.hpp"
#include "weapon/GammaCannon.hpp"
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

    sf::Vector2f generateRandomPoints(int dis);
    //GUI
    void quit();
    sf::RenderWindow* getWindow();
    void start();
};

#endif