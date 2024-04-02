#pragma once
#include "Enviroment.h"
#include "Point.h"

class PhysicsEnv : public Enviroment
{
public:
    PhysicsEnv();
private:
    Vector2D _bordersX = {-1, 1};
    Vector2D _bordersY = {-1, 1};
    Vector2D _gravity = {0, -0.0000098f};
};
