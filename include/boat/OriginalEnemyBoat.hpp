#ifndef ORIGINAL_ENEMY_BOAT_HPP
#define ORIGINAL_ENEMY_BOAT_HPP

#include "boat/Boat.hpp"

class OriginalEnemyBoat : public Boat {
public:
    OriginalEnemyBoat(float x, float y, float movementSpeed, Cannon* cannon, CannonBall* cannonBall);
    virtual ~OriginalEnemyBoat() {}
    virtual void updateRotation();
};

#endif