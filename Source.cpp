#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Point.h"
#include "Line.h"
#include "Arrow.h"
#include <iostream>
#include "Enviroment.h"

using std::cout;
using std::endl;


#define M_PI 3.14159265358979323846

const int numPoints = 10;

Point Points[numPoints];
Arrow arrows[numPoints];
float deltaTime = 3.5f;
const float gravity = 0.0000098f; // Gravitational constant


int main(void) {


    Enviroment env;

    env.resume();





    glfwTerminate();
    return 0;
}
