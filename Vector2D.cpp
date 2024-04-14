#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(float scalar) const {
    return Vector2D(x / scalar, y / scalar);
}

Vector2D Vector2D::perpendicular() const {
    return Vector2D(-y, x);
}

Vector2D Vector2D::normalized() const {
    float len = length();
    return len > 0.0f ? Vector2D(x / len, y / len) : Vector2D(0.0f, 0.0f);
}

float Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}