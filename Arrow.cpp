#include "Arrow.h"
#include <GLFW/glfw3.h>
#include <cstdlib>

void Arrow::drawArrow() const
{
	draw();
	// Draw arrow head
	
	float angle = atan2(_end.y - _start.y, _end.x - _start.x);
	float length = sqrt((_end.y - _start.y) * (_end.y - _start.y) + (_end.x - _start.x) * (_end.x - _start.x));
	float x = _end.x - 0.1f * cos(angle);
	float y = _end.y - 0.1f * sin(angle);
	glBegin(GL_TRIANGLES);
	glVertex2f(_end.x, _end.y);
}
