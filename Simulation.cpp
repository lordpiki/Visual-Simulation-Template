#include "Simulation.h"
#include "GravityForce.h"

Simulation::Simulation(GLFWwindow* window)
    : window(window), renderer(window), inputManager(window) {
    // Initialize the simulation (e.g., add initial bodies and forces)
    RigidBody body1(10.0f, Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f));
    physicsEngine.addBody(body1);

    GravityForce* gravity = new GravityForce(Vector2D(0.0f, -9.8f));
    physicsEngine.addForce(gravity);
}

Simulation::~Simulation() {
    // Clean up resources
}

void Simulation::run() {
    float dt = 0.0001f; // Time step

    while (!glfwWindowShouldClose(window)) {
        // Process input
        inputManager.processInput(physicsEngine.bodies);

        // Update physics simulation
        physicsEngine.update(dt);

        // Render the scene
        renderer.render(physicsEngine.bodies);

        // Handle other events and update the window
        glfwPollEvents();
    }
}