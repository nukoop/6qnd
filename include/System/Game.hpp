#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <string>

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
    //DeltaCannon deltaCannon;
    //DeltaBoat player;
    
    //AlphaCannon alphaCannon;
    //AlphaBoat player;
    BetaCannon betaCannon;
    BetaBoat player;
    //GammaCannon gammaCannon;
    ///GammaBoat player;
    
public:
    Game();
    virtual ~Game();

    const bool running() const;

    void pollEvent();
    void updateInput();
    void update();
    void render();

    //GUI
    void quit();
    sf::RenderWindow* getWindow();
    void start();
};

#endif