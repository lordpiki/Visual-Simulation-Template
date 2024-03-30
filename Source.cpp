#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Point.h"
#include "Line.h"
#include "Arrow.h"
#include <iostream>
#include "Enviroment.h"

using std::cout;
using std::endl;


#define M_PI 3.14159265358979323846

const int numPoints = 10;

Point Points[numPoints];
Arrow arrows[numPoints];
float deltaTime = 3.5f;
const float gravity = 0.0000098f; // Gravitational constant

void drawCoordinateSystem(GLFWwindow* window);

void updatePoints() {

    deltaTime = glfwGetTime(); // Get elapsed time
    for (int i = 0; i < numPoints; ++i) {
        // Update position based on velocity and deltaTime
        Points[i].getPosition().x += Points[i].getVx() * deltaTime;
        Points[i].getPosition().y += Points[i].getVy() * deltaTime;

        // Apply gravity force based on mass
        Points[i].getVy() -= gravity * deltaTime / 1.0f;

        // Reflect Points off the ground
        if (Points[i].getPosition().y < 0.0f) {
            Points[i].getPosition().y = 0.0f;
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

void drawSpiralOfArrows(int numArrows) {
    // Set up your GUI or OpenGL context

    float angle = 0.0f;
    float radiusIncrement = 0.15f;  // Adjust this value based on the desired spacing between arrows
    Position start(0.0f, 0.0f);
    Position end(0.0f, 0.0f);


    for (int i = 0; i < numArrows; ++i) {
        // Calculate the position of the arrow in polar coordinates
        float x = radiusIncrement * angle * cos(angle);
        float y = radiusIncrement * angle * sin(angle);
        start = end;
        end = Position(x, y);

        // Create an Arrow object with the calculated position
        Arrow arrow(start, end, Color(255, 0, 0), 1.0f);

        // Draw the arrow
        arrow.drawArrow();

        // Increment the angle for the next arrow
        angle += 0.05f;  // Adjust this value based on the desired rotation rate
    }

    // Finish drawing and display
}

void drawCoordinateSystem(GLFWwindow* window)
{
    Arrow xArrow(Position(-1, 0), Position(1, 0), Color(255, 255, 255));
    Arrow yArrow(Position(0, -1), Position(0, 1), Color(255, 255, 255));

    xArrow.drawArrow();
    yArrow.drawArrow();
}

int main(void) {


    Enviroment env;

    env.resume();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    env.stop();

    return 0;


    srand(time(NULL));

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    int windowWidth = 1000, windowHeight = 750;

    window = glfwCreateWindow(windowWidth, windowHeight, "Point Simulation", NULL, NULL);

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

    for (auto& Point : Points) {
        Point.setPosition(Position(getRandomValue(), getRandomValue() + 1));
        Point.setColor(Color(0, 0, 255));
    }

    

    return 0;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawCoordinateSystem(window);

        updatePoints();
        
        drawSpiralOfArrows(100);   

        for (int i = 0; i < numPoints; ++i) {
            Points[i].draw();
            arrows[i].drawArrow();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
