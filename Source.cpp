#include <GLFW/glfw3.h>
#include "Simulation.h"

int main() {
    if (!glfwInit()) {
        // Handle GLFW initialization error
        return -1;
    }

    // Configure GLFW window properties
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create the GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Physics Simulation", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        // Handle window creation error
        return -1;
    }

    glfwMakeContextCurrent(window);

    float fps = 60.0f;

    // Create and run the simulation
    Simulation simulation(window, 1.0 / fps);
    simulation.run();

    glfwTerminate();
    return 0;
}