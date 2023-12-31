#ifndef DELTA_CANNON_HPP
#define DELTA_CANNON_HPP

#include "weapon/Cannon.hpp"

class DeltaCannon : public Cannon {
public:
    DeltaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse = false);
    virtual ~DeltaCannon() override;
    virtual void fire(const sf::RenderWindow& window) override;
};

#endif