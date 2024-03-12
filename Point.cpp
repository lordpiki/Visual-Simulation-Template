#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1125

#define M_PI 3.14159265358979323846
#include "Point.h"

void Point::draw()
{
    glPointSize(_radius);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(_color.getR(), _color.getG(), _color.getB());

    // Center of the circle
    glVertex2f(_position.getX(), _position.getY());

    // Number of segments in the circle (adjust for smoothness)
    const int numSegments = 30;

    float aspectRatio = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT);

    for (int i = 0; i <= numSegments; ++i) {
        float theta = (2.0f * M_PI * static_cast<float>(i)) / static_cast<float>(numSegments);
        float dx = _radius * std::cos(theta);
        float dy = _radius * std::sin(theta) * aspectRatio;  // Adjust for aspect ratio
        glVertex2f(_position.getX() + dx, _position.getY() + dy);
    }

    glEnd();
}
