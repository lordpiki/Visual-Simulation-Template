#include "Simulation.h"
#include "GravityForce.h"
#include <iostream>
#include "FPSCounter.h"
#include "PhysicsEngine.h"
#include "Helper.h"


Simulation::Simulation(GLFWwindow* window, float fixedTimeStep)
    : window(window), renderer(window), inputManager(window), fixedTimeStep(fixedTimeStep),
    lastTime(glfwGetTime()), accumulatedTime(0.0), fpsCounter(window) {

    
    for (int i = 0; i < 5000; i++) {
		RigidBody body(10.0f, Vector2D(Helper::getRand(-1, 1), Helper::getRand(-1, 1)), Vector2D(Helper::getRand(-1, 1), Helper::getRand(-1, 1)));
		physicsEngine.addBody(body);
	}


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

        fpsCounter.update();

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

        // Render the FPS counter
        fpsCounter.render();

        // Handle other events and update the window
        glfwPollEvents();
    }
}