#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

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

class HealthBar{
protected:
    sf::RectangleShape health;//血條方塊
public:
    HealthBar();
    ~HealthBar();
    sf::RectangleShape &getHealth();//危險
};


#endif