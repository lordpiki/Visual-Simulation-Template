#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

void Line::draw() const
{
    glLineWidth(1.0f);
    glColor3f(_color.getR(), _color.getG(), _color.getB()); // Set the color of the line
    // Draw line from x1,y1 to x2,y2
    glBegin(GL_LINES);
    glVertex2f(_start.x, _start.y);
    glVertex2f(_end.x, _end.y);
    glEnd();
}
