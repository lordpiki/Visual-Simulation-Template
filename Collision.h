#pragma once
#include "RigidBody.h"

class Collision {
public:
    static bool checkCollision(const RigidBody& body1, const RigidBody& body2);
    static void resolveCollision(RigidBody& body1, RigidBody& body2);
    static bool checkWallCollision(RigidBody& body, float windowWidth = 1, float windowHeight = 1);
    static void resolveWallCollision(RigidBody& body, float windowWidth = 1, float windowHeight = 1);
};
