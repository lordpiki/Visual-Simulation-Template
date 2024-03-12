#pragma once
#include "Color.h"
#include "Point.h"

class Line
{
public:
	Line(const Position& start, const Position& end, const Color& color, float width) : _start(start), _end(end), _color(color), _width(width) {};
	Line(const Position& start, const Position& end, const Color& color) : _start(start), _end(end), _color(color), _width(0.1f) {};
	Line() : _start(Position()), _end(Position()), _color(Color()), _width(1.0f) {};
	~Line() {};

	Position getStart() const { return _start; }
	Position getEnd() const { return _end; }
	Color getColor() const { return _color; }
	float getWidth() const { return _width; }

	void setStart(const Position& start) { _start = start; }
	void setEnd(const Position& end) { _end = end; }
	void setColor(const Color& color) { _color = color; }
	void setWidth(float width) { _width = width; }

	void draw() const;

protected:
	Position _start;
	Position _end;
	Color _color;
	float _width;
};
