#include "GravityForce.h"

GravityForce::GravityForce(const Vector2D& gravity) : gravity(gravity) {}

Vector2D GravityForce::calculateForce(const RigidBody& body) {
    if (body.mass == 0.0f) return Vector2D(0.0f, 0.0f); // Prevent division by zero (infinite acceleration
    return gravity * body.mass;
}
