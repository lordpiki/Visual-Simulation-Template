#pragma once
#include "Line.h"


class Arrow: public Line
{
public:
	Arrow(const Position& start, const Position& end, const Color& color, float width) : Line(start, end, color, width) {};
	Arrow(const Position& start, const Position& end, const Color& color) : Line(start, end, color) {};
	
private:
	void drawArrow() const;

};

