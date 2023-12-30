#ifndef BETA_BOAT_HPP
#define BETA_BOAT_HPP

#include "boat/Boat.hpp"
#include "weapon/AlphaCannon.hpp"

class BetaBoat : public Boat {
public:
    BetaBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall);
    virtual ~BetaBoat() override;
    virtual void updateRotation() override;
};

#endif