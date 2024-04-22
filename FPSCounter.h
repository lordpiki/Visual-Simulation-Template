// FPSCounter.h
#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

using std::vector;

class FPSCounter {
public:
    FPSCounter(GLFWwindow* window);
    ~FPSCounter();

    void update();
    void render();
    float getFPS() const { return fixedFPS; }

private:
    GLFWwindow* window;
    double lastTime;
    int framesCounter;
    int fixedFPS;
};