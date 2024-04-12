#pragma once
#include "Force.h"

class GravityForce : public Force {
public:
    Vector2D gravity;

    GravityForce(const Vector2D& gravity);

    Vector2D calculateForce(const RigidBody& body) override;
};
