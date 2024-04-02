#pragma once
#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>


class Arrow: public Line
{
public:
	Arrow(const Vector2D& start, const Vector2D& end, const Color& color, float width) : Line(start, end, color, width) {};
	Arrow(const Vector2D& start, const Vector2D& end, const Color& color) : Line(start, end, color) {};
	Arrow(const Vector2D& start, const Vector2D& end) : Line(start, end, Color()) {};
	Arrow() : Line() {};
	
	void drawArrow() const;
private:

};

