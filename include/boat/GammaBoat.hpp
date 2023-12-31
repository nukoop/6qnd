#ifndef GAMMA_BOAT_HPP
#define GAMMA_BOAT_HPP

#include "boat/Boat.hpp"
#include "weapon/AlphaCannon.hpp"

class GammaBoat : public Boat {
public:
    GammaBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall);
    virtual ~GammaBoat() override;
    virtual void updateRotation() override;
};

#endif