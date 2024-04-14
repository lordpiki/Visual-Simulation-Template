#include "PhysicsEngine.h"
#include "Collision.h"

void PhysicsEngine::addBody(const RigidBody& body) {
    bodies.push_back(body);
}

void PhysicsEngine::addForce(Force* force) {
    forces.push_back(force);
}

void PhysicsEngine::update(float dt) {
    applyForces();
    integrateMotion(dt);
    handleCollisions();
}

void PhysicsEngine::applyForces() {
    for (RigidBody& body : bodies) {
        Vector2D totalForce(0.0f, 0.0f);
        for (Force* force : forces) 
        {
            totalForce = totalForce + force->calculateForce(body);
        }
        body.applyForce(totalForce);
    }
}

void PhysicsEngine::integrateMotion(float dt) {
    for (RigidBody& body : bodies) {
        body.integrate(dt);
    }
}

void PhysicsEngine::handleCollisions() {
    // Existing body-to-body collision handling
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            if (Collision::checkCollision(bodies[i], bodies[j])) {
                Collision::resolveCollision(bodies[i], bodies[j]);
            }
        }
    }

    for (RigidBody& body : bodies) {
        if (Collision::checkWallCollision(body)) {
            Collision::resolveWallCollision(body);
        }
    }

   
}
