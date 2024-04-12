#include "RigidBody.h"

RigidBody::RigidBody(float mass, const Vector2D& position, const Vector2D& velocity)
    : mass(mass), position(position), velocity(velocity), acceleration(0.0f, 0.0f) {}

void RigidBody::applyForce(const Vector2D& force) {
    acceleration = force / mass;
}

void RigidBody::integrate(float dt) {
    position = position + velocity * dt + acceleration * 0.5f * dt * dt;
    velocity = velocity + acceleration * dt;
}
