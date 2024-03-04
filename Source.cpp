#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define M_PI 3.14159265358979323846

const int numParticles = 10;

struct Particle {
    float x, y;
    float vx, vy;
    float mass; // Added mass for realistic gravity
    float color[3];
};

Particle particles[numParticles];
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
    glLineWidth(1.0f);
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw x-axis
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();

    // Draw y-axis
    glBegin(GL_LINES);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
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


void drawArrow(float x1, float y1, float x2, float y2) {
    glLineWidth(1.0f);
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw line from x1,y1 to x2,y2
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Calculate arrowhead position
    float arrowLength = 0.1f;
    float arrowAngle = 0.2f;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float angle = atan2(dy, dx);

    // Draw arrowhead
    glBegin(GL_TRIANGLES);
    glVertex2f(x2, y2);
    glVertex2f(x2 - arrowLength * cos(angle - arrowAngle), y2 - arrowLength * sin(angle - arrowAngle));
    glVertex2f(x2 - arrowLength * cos(angle + arrowAngle), y2 - arrowLength * sin(angle + arrowAngle));
    glEnd();
}

void drawParticle(const Particle& particle) {

    glPointSize(10.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(particle.color[0], particle.color[1], particle.color[2]);

    // Center of the circle
    glVertex2f(particle.x, particle.y);

    // Number of segments in the circle (adjust for smoothness)
    const int numSegments = 30;
    const float particleRadius = 0.02f;
    int windowWidth = 1500, windowHeight = 1125;

    float aspectRatio = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);

    for (int i = 0; i <= numSegments; ++i) {
        float theta = (2.0f * M_PI * static_cast<float>(i)) / static_cast<float>(numSegments);
        float dx = particleRadius * std::cos(theta);
        float dy = particleRadius * std::sin(theta) * aspectRatio;  // Adjust for aspect ratio
        glVertex2f(particle.x + dx, particle.y + dy);
    }

    glEnd();
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
