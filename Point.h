#pragma once
#include "Color.h"
#include <initializer_list>
#include <stdexcept>


class Vector2D
{
public:
    Vector2D(double x, double y) : x(x), y(y) {};
    Vector2D() : x(0), y(0) {};
    ~Vector2D() {};

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(int x) { x = x; }
    void setY(int y) { y = y; }

    void move(double x, double  y) { setX(x); setY(y); };

	Vector2D operator=(const Vector2D& other) { this->x = other.x; this->y = other.y; return *this; }
    Vector2D operator+(const Vector2D& other) { return Vector2D(this->x + other.x, this->y + other.y); }
    Vector2D operator-(const Vector2D& other) { return Vector2D(this->x - other.x, this->y - other.y); }
    Vector2D operator*(double scalar) { return Vector2D(this->x * scalar, this->y * scalar); }
    Vector2D operator/(double scalar) { return Vector2D(this->x / scalar, this->y / scalar); }
    bool operator==(const Vector2D& other) { return (this->x == other.x) && (this->y == other.y); }
    bool operator!=(const Vector2D& other) { return !(*this == other); }
	Vector2D& operator=(const std::initializer_list<double>& list) {
		if (list.size() != 2) {
			throw std::invalid_argument("Initializer list must contain exactly two elements.");
		}
		this->x = list.begin()[0];
		this->y = list.begin()[1];
		return *this;
	}

    double x;
    double y;
private:
};

class Point
{
public:
	Point(const Vector2D& position) : _position(position), _color(Color()), _radius(0.02f), _vx(0), _vy(0), _density(0), _mass(1), _pressure(0) {};
	Point() : Point(Vector2D()) {}
	~Point() {};

	Vector2D& getVector2D() { return _position; }
	Color& getColor() { return _color; }
	float& getRadius() { return _radius; }
	float& getVx() { return _vx; }
	float& getVy() { return _vy; }
	float& getDensity() { return _density; }
	float& getMass() { return _mass; }
	float& getPressure() { return _pressure; }


	void setVector2D(const Vector2D& position) { _position = position; }
	void setColor(const Color& color) { _color = color; }
	void setRadius(float radius) { _radius = radius; }
	void setVx(float vx) { _vx = vx; }
	void setVy(float vy) { _vy = vy; }
	void setDensity(float density) { _density = density; }
	void setMass(float mass) { _mass = mass; }
	void setPressure(float pressure) { _pressure = pressure; }


	void move(int x, int y) { _position.move(x, y); };

	void draw();

protected:
	float _radius;
	Vector2D _position;
	Color _color;
	float _vx;
	float _vy;
	float _density;
	float _mass;
	float _pressure;
};