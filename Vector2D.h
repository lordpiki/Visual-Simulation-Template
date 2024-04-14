#pragma once

class Vector2D {
public:
    float x, y;

    Vector2D(float x = 0.0f, float y = 0.0f);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator/(float scalar) const;

    Vector2D perpendicular() const;
    Vector2D normalized() const;
    float length() const;
};
