#pragma once
#include <vector>
#include "RigidBody.h"
#include "Force.h"

class PhysicsEngine {
public:
    std::vector<RigidBody> bodies;
    std::vector<Force*> forces;

    void addBody(const RigidBody& body);
    void addForce(Force* force);

    void update(float dt);

private:
    void applyForces();
    void integrateMotion(float dt);
    void handleCollisions();
};
