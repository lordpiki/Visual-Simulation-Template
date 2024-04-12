#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "RigidBody.h"

class InputManager {
public:
    InputManager(GLFWwindow* window);

    void processInput(std::vector<RigidBody>& bodies);

private:
    GLFWwindow* window;
};
