#include "Collision.h"
#include <iostream>

#define DRAG_COEFFICIENT 0.1

bool Collision::checkCollision(const RigidBody& body1, const RigidBody& body2) {
    // Implement collision detection logic
    return false;
}

void Collision::resolveCollision(RigidBody& body1, RigidBody& body2) {
    // Implement collision resolution logic
}

bool Collision::checkWallCollision(RigidBody& body)
{
    float maxWidth = 1, maxHeight = 1;
    if (body.position.x < -maxWidth || body.position.x > maxWidth)
    {
        body.velocity.x = -body.velocity.x * (1 - DRAG_COEFFICIENT);
        return true;
	}
    if (body.position.y < -maxHeight || body.position.y > maxHeight)
    {
		body.velocity.y = -body.velocity.y * (1 - DRAG_COEFFICIENT);
        return true;
    }
}

void Collision::resolveWallCollision(RigidBody& body)
{
    body.velocity = body.velocity * - (1 - DRAG_COEFFICIENT);
}
