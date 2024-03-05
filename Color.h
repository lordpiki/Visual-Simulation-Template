#pragma once
class Color
{
public:
	Color(int r, int g, int b) : _r(r), _g(g), _b(b) {};
	Color() : _r(255), _g(255), _b(255) {};
	~Color() {};

	float getR() const { return _r / 255.0f; }
	float getG() const { return _g / 255.0f; }
	float getB() const { return _b / 255.0f; }

	void setR(int r) { _r = r; }
	void setG(int g) { _g = g; }
	void setB(int b) { _b = b; }

private:
	int _r;
	int _g;
	int _b;
};

