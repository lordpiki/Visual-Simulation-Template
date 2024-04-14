#include "Collision.h"
#include <iostream>

#define DRAG_COEFFICIENT 0.2

bool Collision::checkCollision(const RigidBody& body1, const RigidBody& body2) {
    // Implement collision detection logic
    return false;
}

void Collision::resolveCollision(RigidBody& body1, RigidBody& body2) {
    // Implement collision resolution logic
}

bool Collision::checkWallCollision(RigidBody& body, float windowWidth, float windowHeight) {
    float radius = 0.0f; // Adjust this value based on your body size

    // Check left and right wall collisions
    if (body.position.x - radius < -1.0f || body.position.x + radius > windowWidth) {
        return true;
    }

    // Check top and bottom wall collisions
    if (body.position.y - radius < -1.0f || body.position.y + radius > windowHeight) {
        return true;
    }

    return false;
}

void Collision::resolveWallCollision(RigidBody& body, float windowWidth, float windowHeight) {
    float radius = 0.0f; // Adjust this value based on your body size

    // Resolve left and right wall collisions
    if (body.position.x - radius < -1.0) {
        body.position.x = -1;
        body.velocity.x = -body.velocity.x;
    }
    else if (body.position.x + radius > windowWidth) {
        body.position.x = windowWidth - radius;
        body.velocity.x = -body.velocity.x;
    }

    // Resolve top and bottom wall collisions
    if (body.position.y - radius < -1.0) {
        body.position.y = -1;
        body.velocity.y = -body.velocity.y;
        if (abs(body.velocity.y) < 0.43) {
			body.velocity.y = 0.0f;
		}
    }
    else if (body.position.y + radius > windowHeight) {
        body.position.y = windowHeight - radius;
        body.velocity.y = -body.velocity.y;
    }

    body.velocity = body.velocity * (1- DRAG_COEFFICIENT);
}
