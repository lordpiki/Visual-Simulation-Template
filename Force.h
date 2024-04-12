#pragma once
#include "RigidBody.h"

class Force {
public:
    virtual Vector2D calculateForce(const RigidBody& body) = 0;
};
