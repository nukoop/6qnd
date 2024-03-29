#ifndef ALPHA_CANNON_HPP
#define ALPHA_CANNON_HPP

#include "weapon/Cannon.hpp"

class AlphaCannon : public Cannon {
public:
    AlphaCannon(float x, float y, CannonBall* cannonBallTemplate, float fireRate, bool isFaceToMouse = false);
    virtual ~AlphaCannon() override;
    virtual void fire(const sf::RenderWindow& window) override;
    void setFiringAngle(float angle);
    float firingAngle;  // 火炮的發射角度
};

#endif