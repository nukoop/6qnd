#ifndef ALPHA_BOAT_HPP
#define ALPHA_BOAT_HPP

#include "boat/Boat.hpp"
#include "weapon/AlphaCannon.hpp"

class AlphaBoat : public Boat {
public:
    AlphaBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall);
    virtual ~AlphaBoat() override;
    virtual void updateRotation() override;
    sf::Sprite getSprite() const;  //算角度用
};

#endif