#include "Simulation.h"
#include "GravityForce.h"
#include <iostream>



Simulation::Simulation(GLFWwindow* window)
    : window(window), renderer(window), inputManager(window) {
    // Initialize the simulation (e.g., add initial bodies and forces)
    RigidBody body1(10.0f, Vector2D(0.0f, 0.0f), Vector2D(1.10f, 0.10f));
    physicsEngine.addBody(body1);

    GravityForce* gravity = new GravityForce(Vector2D(0.0f, -9.8f));
    physicsEngine.addForce(gravity);
}

Simulation::~Simulation() {
    // Clean up resources
}

void Simulation::run() {
    float dt = 0.0005f; // Time step
    float realTime = glfwGetTime() * dt;

    while (!glfwWindowShouldClose(window)) {
        // Process input
        inputManager.processInput(physicsEngine.bodies);
        std::cout << "realTime: " << glfwGetTime() << std::endl;

        // Update physics simulation
        physicsEngine.update(glfwGetTime());

        // Render the scene
        renderer.render(physicsEngine.bodies);

        // Handle other events and update the window
        glfwPollEvents();
    }
}