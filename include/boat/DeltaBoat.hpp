#ifndef DELTA_BOAT_HPP
#define DELTA_BOAT_HPP

#include "boat/Boat.hpp"
#include "weapon/AlphaCannon.hpp"
#include "weapon/DeltaCannon.hpp"
#include "weapon/BetaCannon.hpp"

class DeltaBoat : public Boat {
public:
    DeltaBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall);
    virtual ~DeltaBoat() override;
    virtual void updateRotation() override;
};

#endif