#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Helper.h"

#define DRAG_COEFFICIENT 0.2f

bool Collision::checkCollision(const RigidBody& body1, const RigidBody& body2) {
    return Helper::distance(body1.position, body2.position) < 0.01f * 2;
}

void Collision::resolveCollision(RigidBody& body1, RigidBody& body2) {
    body1.velocity = body1.velocity * -1;
    body2.velocity = body2.velocity * -1;
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
    if (body.position.y - radius <= -1.0) {
        body.position.y = -1;
        body.velocity.y = -body.velocity.y;
  //      if (abs(body.velocity.y) < 0.5f) {
		//	body.velocity.y = 0.0f;
		//}
    }
    else if (body.position.y + radius > windowHeight) {
        body.position.y = windowHeight - radius;
        body.velocity.y = -body.velocity.y;
    }

    body.velocity = body.velocity * (1- DRAG_COEFFICIENT);
}
