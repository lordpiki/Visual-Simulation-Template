#include "Helper.h"

float Helper::distance(const Vector2D& a, const Vector2D& b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

float Helper::getRand(float min, float max)
{
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
