#include "Renderer.h"
#include <iostream>

using std::cout;
using std::endl;

Renderer::Renderer(GLFWwindow* window) : window(window) {}

void Renderer::render(const std::vector<RigidBody>& bodies) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (const RigidBody& body : bodies) {
        // Render the body (e.g., draw a circle or rectangle)
        glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

        float radius = 0.01f; // Assuming RigidBody has a method to get the radius
        int numSegments = 100; // Number of segments to approximate the circle

        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Calculate angle for each segment
            float x = radius * cosf(theta) + body.position.x; // Calculate x-coordinate
            float y = radius * sinf(theta) + body.position.y; // Calculate y-coordinate
            glVertex2f(x, y); // Add vertex to the polygon
        }
        glEnd();
        cout << "body pos: (" << body.position.x << ", " << body.position.y << ")" << " acc: " << body.acceleration.x << ", " << body.acceleration.y << " vel: " << body.velocity.x << ", " << body.velocity.y << endl;
    }

    glfwSwapBuffers(window);
}
