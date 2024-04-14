#include "Simulation.h"
#include "GravityForce.h"
#include <iostream>
#include "PhysicsEngine.h"



Simulation::Simulation(GLFWwindow* window, float fixedTimeStep)
    : window(window), renderer(window), inputManager(window), fixedTimeStep(fixedTimeStep),
    lastTime(glfwGetTime()), accumulatedTime(0.0) {
    // Initialize the simulation (e.g., add initial bodies and forces)
    RigidBody body1(10.0f, Vector2D(0.0f, 0.0f), Vector2D(1.0f, 0.10f));
    physicsEngine.addBody(body1);

    GravityForce* gravity = new GravityForce(Vector2D(0.0f, -9.8f));
    physicsEngine.addForce(gravity);
}

Simulation::~Simulation() {
    // Clean up resources
}

void Simulation::run() {
    while (!glfwWindowShouldClose(window)) {
        // Process input
        inputManager.processInput(physicsEngine.bodies);

        // Calculate the elapsed time since the last frame
        double currentTime = glfwGetTime();
        double elapsedTime = currentTime - lastTime;
        lastTime = currentTime;

        // Accumulate the elapsed time
        accumulatedTime += elapsedTime;

        // Update the physics simulation using the fixed time step
        while (accumulatedTime >= fixedTimeStep)
        {
            physicsEngine.update(fixedTimeStep);
            accumulatedTime -= fixedTimeStep;

        }

        // Render the scene
        renderer.render(physicsEngine.bodies);

        // Handle other events and update the window
        glfwPollEvents();
    }
}