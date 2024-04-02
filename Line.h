#pragma once
#include "Color.h"
#include "Point.h"

class Line
{
public:
	Line(const Vector2D& start, const Vector2D& end, const Color& color, float width) : _start(start), _end(end), _color(color), _width(width) {};
	Line(const Vector2D& start, const Vector2D& end, const Color& color) : _start(start), _end(end), _color(color), _width(0.1f) {};
	Line() : _start(Vector2D()), _end(Vector2D()), _color(Color()), _width(1.0f) {};
	~Line() {};

	Vector2D getStart() const { return _start; }
	Vector2D getEnd() const { return _end; }
	Color getColor() const { return _color; }
	float getWidth() const { return _width; }

	void setStart(const Vector2D& start) { _start = start; }
	void setEnd(const Vector2D& end) { _end = end; }
	void setColor(const Color& color) { _color = color; }
	void setWidth(float width) { _width = width; }

	void draw() const;

protected:
	Vector2D _start;
	Vector2D _end;
	Color _color;
	float _width;
};
