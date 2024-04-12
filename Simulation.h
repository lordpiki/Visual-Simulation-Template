#pragma once
#include <GLFW/glfw3.h>
#include "PhysicsEngine.h"
#include "Renderer.h"
#include "InputManager.h"

class Simulation {
public:
    Simulation(GLFWwindow* window);
    ~Simulation();

    void run();

private:
    GLFWwindow* window;
    PhysicsEngine physicsEngine;
    Renderer renderer;
    InputManager inputManager;
};
