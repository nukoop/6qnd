#ifndef SIMPLE_CANNON_BALL_HPP
#define SIMPLE_CANNON_BALL_HPP

#include <iostream>
#include "weapon/CannonBall.hpp"

class SimpleCannonBall : public CannonBall {
public:
    SimpleCannonBall(float maxSpeed = 15.f, float scale = 0.07f);
    virtual ~SimpleCannonBall() override;
};

#endif