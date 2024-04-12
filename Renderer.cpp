#include "Renderer.h"

Renderer::Renderer(GLFWwindow* window) : window(window) {}

void Renderer::render(const std::vector<RigidBody>& bodies) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (const RigidBody& body : bodies) {
        // Render the body (e.g., draw a circle or rectangle)
        glBegin(GL_POLYGON);
        // ... (draw the body shape based on its position and other properties)
        glEnd();
    }

    glfwSwapBuffers(window);
}
