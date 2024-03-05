#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>

void Line::draw() const
{
    glLineWidth(1.0f);
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw line from x1,y1 to x2,y2
    glBegin(GL_LINES);
    glVertex2f(_start.x, _start.y);
    glVertex2f(_end.x, _end.y);
    glEnd();
}
