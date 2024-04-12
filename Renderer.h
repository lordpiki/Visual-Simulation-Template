#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "RigidBody.h"

class Renderer {
public:
    Renderer(GLFWwindow* window);

    void render(const std::vector<RigidBody>& bodies);

private:
    GLFWwindow* window;
};
