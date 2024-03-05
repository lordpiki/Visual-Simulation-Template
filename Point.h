#pragma once
#include "Color.h"

class Position
{
public:
	Position(double x, double y) : x(x), y(y) {};
	Position() : x(0), y(0) {};
	~Position() {};

	int getX() const { return x; }
	int getY() const { return y; }

	void setX(int x) { x = x; }
	void setY(int y) { y = y; }

	void move(double x, double  y) { setX(x); setY(y); };

	double x;
	double y;
private:
};

class Point
{
public:
	Point(const Position& position, const Color& color, float radius, float vx, float vy, float mass) : _position(position), _color(color), _radius(radius), _mass(mass), _vx(vx), _vy(vy) {};
	Point(const Position& position, const Color& color, float radius, float mass) : _position(position), _color(color), _radius(radius), _mass(mass), _vx(0), _vy(0) {};
	Point() : _position(Position()), _color(Color()), _radius(0.02f), _mass(0), _vx(0), _vy(0) {};
	~Point() {};

	Position getPosition() const { return _position; }
	Color getColor() const { return _color; }
	float getRadius() const { return _radius; }
	float getMass() const { return _mass; }
	float getVx() const { return _vx; }
	float getVy() const { return _vy; }

	void setPosition(const Position& position) { _position = position; }
	void setColor(const Color& color) { _color = color; }
	void setRadius(float radius) { _radius = radius; }
	void setMass(float mass) { _mass = mass; }
	void setVx(float vx) { _vx = vx; }
	void setVy(float vy) { _vy = vy; }

	void move(int x, int y) { _position.move(x, y); };

	void draw();

protected:
	float _radius;
	Position _position;
	Color _color;
	float _mass;
	float _vx;
	float _vy;
};