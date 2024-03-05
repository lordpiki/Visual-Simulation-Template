#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Point.h"
#include "Line.h"
#include "Arrow.h"

#define M_PI 3.14159265358979323846

const int numParticles = 10;

Point particles[numParticles];
float deltaTime = 3.5f;
const float gravity = 0.0000098f; // Gravitational constant

void drawCoordinateSystem();

void updateParticles() {

    deltaTime = glfwGetTime(); // Get elapsed time
    for (int i = 0; i < numParticles; ++i) {
        // Update position based on velocity and deltaTime
        particles[i].x += particles[i].vx * deltaTime;
        particles[i].y += particles[i].vy * deltaTime;

        // Apply gravity force based on mass
        particles[i].vy -= gravity * deltaTime / particles[i].mass;

        // Reflect particles off the ground
        if (particles[i].y < 0.0f) {
            particles[i].y = 0.0f;
        }
    }
}


void drawCoordinateSystem() {
    Line xLine(Position(-1, 0), Position(1, 0), Color(255, 255, 255));
    Line yLine(Position(0, -1), Position(0, 1), Color(255, 255, 255));
    xLine.draw();
    yLine.draw();
}

void initParticles() {
    for (int i = 0; i < numParticles; ++i) {
        particles[i].x = static_cast<float>(rand()) / RAND_MAX;
        particles[i].y = static_cast<float>(rand()) / RAND_MAX;
        particles[i].vx = 0.0f; // Initial horizontal velocity is 0
        particles[i].vy = 0.0f; // Initial vertical velocity is 0
        particles[i].mass = 80.0f; // Assume the same mass for all particles
        particles[i].color[0] = 1.0f;
        particles[i].color[1] = 1.0f;
        particles[i].color[2] = 1.0f;
    }
}

int main(void) {

    srand(time(NULL));

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    int windowWidth = 1000, windowHeight = 750;

    window = glfwCreateWindow(windowWidth, windowHeight, "Particle Simulation", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    initParticles();


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawCoordinateSystem();

        Point point(Position(0, 0), Color(255, 0, 0));
        point.draw();

        Line line(Position(0, 0), Position(1, 1), Color(0, 255, 0));
        line.draw();

        updateParticles();

        for (int i = 0; i < numParticles; ++i) {
            drawParticle(particles[i]);
        }
        drawArrow(0.0f, 0.0f, 0.0f, 1.0f); 
        drawArrow(0.0f, 0.0f, 1.0f, 0.0f); 

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
