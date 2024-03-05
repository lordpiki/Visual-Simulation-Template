#pragma once
#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>


class Arrow: public Line
{
public:
	Arrow(const Position& start, const Position& end, const Color& color, float width) : Line(start, end, color, width) {};
	Arrow(const Position& start, const Position& end, const Color& color) : Line(start, end, color) {};
	Arrow(const Position& start, const Position& end) : Line(start, end, Color()) {};
	Arrow() : Line() {};
	
	void drawArrow() const;
private:

};

