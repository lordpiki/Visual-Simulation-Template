#include "Arrow.h"
#include <GLFW/glfw3.h>
#include <cstdlib>

#define M_PI 3.14159265358979323846

void Arrow::drawArrow() const
{
    draw();
    int windowWidth = 1000, windowHeight = 750;

    const float arrowHeadSize = 0.02;

    // Calculate the coordinates of the arrow head
    float arrowHeadX = _end.x;
    float arrowHeadY = _end.y;

    // Calculate the direction of the arrow
    float arrowDirectionX = _end.x - _start.x;
    float arrowDirectionY = _end.y - _start.y;

    // Normalize the direction vector
    float length = sqrt(arrowDirectionX * arrowDirectionX + arrowDirectionY * arrowDirectionY);
    arrowDirectionX /= length;
    arrowDirectionY /= length;

    // Calculate the angle of the arrow direction
    float angle = atan2(arrowDirectionY, arrowDirectionX);

    // Calculate the coordinates of the arrow head aligned with the direction
    float alignedArrowHeadX = arrowHeadX - arrowHeadSize * cos(angle);
    float alignedArrowHeadY = arrowHeadY - arrowHeadSize * sin(angle);

    // Draw the arrow head
    glBegin(GL_TRIANGLES);
    glVertex2f(arrowHeadX, arrowHeadY);
    glVertex2f(alignedArrowHeadX - arrowHeadSize * cos(angle + M_PI / 4), alignedArrowHeadY - arrowHeadSize * sin(angle + M_PI / 4));
    glVertex2f(alignedArrowHeadX - arrowHeadSize * cos(angle - M_PI / 4), alignedArrowHeadY - arrowHeadSize * sin(angle - M_PI / 4));
    glEnd();
}