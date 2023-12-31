#ifndef GAMMACANNON_HPP
#define GAMMA_CANNON_HPP

#include "weapon/Cannon.hpp"

class GammaCannon : public Cannon {
public:
    GammaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse = false);
    virtual ~GammaCannon() override;
    virtual void fire(const sf::RenderWindow& window) override;
};

#endif