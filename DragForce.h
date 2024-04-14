#pragma once
#include "Force.h"

class DragForce : public Force {
public:
    DragForce(float dragCoefficient);

    Vector2D calculateForce(const RigidBody& body) override;

private:
    float dragCoefficient;
};