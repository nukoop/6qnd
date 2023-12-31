#ifndef BETA_CANNON_HPP
#define BETA_CANNON_HPP

#include "weapon/Cannon.hpp"

class BetaCannon : public Cannon {
public:
    BetaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse = false);
    virtual ~BetaCannon() override;
    virtual void fire(const sf::RenderWindow& window) override;
};

#endif