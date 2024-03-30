#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Point.h"
#include "Line.h"
#include "Arrow.h"
#include <iostream>

using std::cout;
using std::endl;


#define M_PI 3.14159265358979323846

const int numParticles = 10;

Point particles[numParticles];
Arrow arrows[numParticles];
float deltaTime = 3.5f;
const float gravity = 0.0000098f; // Gravitational constant

void drawCoordinateSystem(GLFWwindow* window);

void updateParticles() {

    deltaTime = glfwGetTime(); // Get elapsed time
    for (int i = 0; i < numParticles; ++i) {
        // Update position based on velocity and deltaTime
        particles[i].getPosition().x += particles[i].getVx() * deltaTime;
        particles[i].getPosition().y += particles[i].getVy() * deltaTime;

        // Apply gravity force based on mass
        particles[i].getVy() -= gravity * deltaTime / particles[i].getMass();

        // Reflect particles off the ground
        if (particles[i].getPosition().y < 0.0f) {
            particles[i].getPosition().y = 0.0f;
        }
    }
}

float getRandomValue(float min, float max)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return  min + r;
}

float getRandomValue()
{
	return getRandomValue(-1, 1);
}

void drawCoordinateSystem(GLFWwindow* window)
{
    Arrow xArrow(Position(-1, 0), Position(1, 0), Color(255, 255, 255));
    Arrow yArrow(Position(0, -1), Position(0, 1), Color(255, 255, 255));

    xArrow.drawArrow();
    yArrow.drawArrow();
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

    for (Arrow& arrow : arrows)
    {
		arrow.setStart(Position(getRandomValue(), getRandomValue()));
		arrow.setEnd(Position(getRandomValue(), getRandomValue()));
		arrow.setColor(Color((int) getRandomValue(0, 255), (int) getRandomValue(0, 255), (int)getRandomValue(0, 255)));
        
	}

    for (auto& particle : particles) {
        particle.setPosition(Position(getRandomValue(), getRandomValue() + 1));
        particle.setColor(Color(0, 0, 255));
        particle.setMass(0.1f);
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawCoordinateSystem(window);

        updateParticles();

        for (int i = 0; i < numParticles; ++i) {
            particles[i].draw();
            arrows[i].drawArrow();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
