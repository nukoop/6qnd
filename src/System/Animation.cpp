#include <iostream>
#include "system/Animation.hpp"

Animation::Animation(float switchTime, int amount, int minimum, int current) {
    this->totalTime = 0.f;
    this->switchTime = switchTime;
    this->amount = amount;
    this->minimum = minimum;
    this->current = current;
}

Animation::~Animation() {
    
}

void Animation::update(float deltaTime) {
    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime) {

        this->totalTime -= this->switchTime;
        this->current++;

        if (this->current > this->amount) {
            this->current = minimum;
        }
    }
}