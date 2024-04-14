#include "DragForce.h"

DragForce::DragForce(float dragCoefficient) : dragCoefficient(dragCoefficient) {}

Vector2D DragForce::calculateForce(const RigidBody& body) {
    Vector2D dragForce = body.velocity.normalized() * dragCoefficient * body.velocity.length() * body.velocity.length() * -1;
    return dragForce;
}