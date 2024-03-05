#pragma once
class Color
{
public:
	Color(int r, int g, int b) : _r(r), _g(g), _b(b) {};
	Color() : _r(0), _g(0), _b(0) {};
	~Color() {};

	int getR() const { return _r; }
	int getG() const { return _g; }
	int getB() const { return _b; }

	void setR(int r) { _r = r; }
	void setG(int g) { _g = g; }
	void setB(int b) { _b = b; }

private:
	int _r;
	int _g;
	int _b;
};

