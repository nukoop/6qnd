#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Animation {
private:
    float totalTime;
    float switchTime;
    int amount;
    int minimum;
public:
    int current;

    Animation(float switchTime, int amount, int minimum, int current);
    ~Animation();
    void update(float deltaTime);
};

#endif