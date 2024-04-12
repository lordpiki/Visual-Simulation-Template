#include "GravityForce.h"

GravityForce::GravityForce(const Vector2D& gravity) : gravity(gravity) {}

Vector2D GravityForce::calculateForce(const RigidBody& body) {
    return gravity * body.mass;
}
